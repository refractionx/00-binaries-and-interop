#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <libplatform/libplatform.h>
#include <v8.h>
#include "js.h"


void tickCPP(char *data) {
    printf("C++: %s", data);
}

v8::Isolate* isolate;
v8::Global<v8::Context> context_;
v8::Global<v8::Function> process_;
v8::Isolate::CreateParams create_params;
std::unique_ptr<v8::Platform> platform;

class Console {
    public:
        Console() {}
		~Console() {}
	private:
	public:

};


const char* ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

void log(const v8::FunctionCallbackInfo<v8::Value>& args){
	v8::String::Utf8Value str(isolate, args[0]);    
	const char* cstr = ToCString(str);     
	printf("%s", cstr);
}
void error(const v8::FunctionCallbackInfo<v8::Value>& args){
	v8::String::Utf8Value str(isolate, args[0]);
	const char* cstr = ToCString(str);
	fprintf(stderr,"%s\n", cstr);
}


void tickJS(char *data) {
    
    v8::HandleScope handle_scope(isolate);
    v8::Local<v8::Context> context = v8::Local<v8::Context>::New(isolate, context_);
    
    v8::Context::Scope context_scope(context);

    v8::Handle<v8::Value> args[1];
    args[0] = v8::String::NewFromUtf8(isolate, data,v8::NewStringType::kNormal)
            .ToLocalChecked();
    
    v8::Local<v8::Value> result;
    v8::Local<v8::Function> process =
      v8::Local<v8::Function>::New(isolate, process_);
    
    if (!process->Call(context, context->Global(), 1, args).ToLocal(&result)) {
        return;
    };
    // v8::String::Utf8Value utf8(isolate, result);
    // printf("%s\n", *utf8);
}

v8::Local<v8::Object> WrapObject(Console *c) {

	v8::EscapableHandleScope handle_scope(isolate);

	v8::Local<v8::ObjectTemplate> class_t;
	v8::Local<v8::ObjectTemplate> raw_t = v8::ObjectTemplate::New(isolate);
    raw_t->SetInternalFieldCount(1);
    raw_t->Set(
		v8::String::NewFromUtf8(isolate, "log", v8::NewStringType::kNormal).ToLocalChecked(),
		v8::FunctionTemplate::New(isolate, log));
	raw_t->Set(
		v8::String::NewFromUtf8(isolate, "error", v8::NewStringType::kNormal).ToLocalChecked(),
		v8::FunctionTemplate::New(isolate, error));
	class_t = v8::Local<v8::ObjectTemplate>::New(isolate, raw_t);
    v8::Local<v8::Object> result = class_t->NewInstance(isolate->GetCurrentContext()).ToLocalChecked();
    v8::Local<v8::External> ptr = v8::External::New(isolate, c);
	result->SetInternalField(0,ptr);
	return handle_scope.Escape(result);
}

int loadJS(int argc, char* argv[]) {
  // Initialize V8.
  v8::V8::InitializeICUDefaultLocation(argv[0]);
  v8::V8::InitializeExternalStartupData(argv[0]);
  platform = v8::platform::NewDefaultPlatform();
  v8::V8::InitializePlatform(platform.get());
  v8::V8::Initialize();
  // Create a new Isolate and make it the current one.

  create_params.array_buffer_allocator =
      v8::ArrayBuffer::Allocator::NewDefaultAllocator();
  isolate = v8::Isolate::New(create_params);
  {
    // Create a stack-allocated handle scope.
    v8::HandleScope handle_scope(isolate);
    // Create a new context.
    v8::Local<v8::Context> context = v8::Context::New(isolate);
    // Enter the context for compiling and running the hello world script.
    v8::Context::Scope context_scope(context);
    // Create a string containing the JavaScript source code.
    std::ifstream t("./plugins/driveInPlugin.js");
    std::stringstream buffer;
    buffer << t.rdbuf();

    v8::Local<v8::String> source =
        v8::String::NewFromUtf8(isolate, buffer.str().c_str(),
                                v8::NewStringType::kNormal)
            .ToLocalChecked();
    // Compile the source code.
    v8::Local<v8::Script>  script =
        v8::Script::Compile(context, source).ToLocalChecked();
    // Run the script to get the result.
    v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();
    // Convert the result to an UTF8 string and print it.
    // v8::String::Utf8Value utf8(isolate, result);
    // printf("%s\n", *utf8);

    v8::Local<v8::String> process_name =
      v8::String::NewFromUtf8(isolate, "tick", v8::NewStringType::kNormal)
          .ToLocalChecked();


    v8::Local<v8::Value> process_val;

    if (!context->Global()->Get(context, process_name).ToLocal(&process_val) ||
        !process_val->IsFunction()) {
        printf("%s\n", "no function found");
    }

    Console* c = new Console();
    v8::Local<v8::Object> con = WrapObject(c);
	
    v8::Maybe<bool> success = context->Global()->Set(
    context, v8::String::NewFromUtf8(isolate,"console", v8::NewStringType::kNormal).ToLocalChecked(),
    con);

    if (success == v8::Just(false)) {
        printf("%s\n", "failed to set console");
    };
    
    
    v8::Local<v8::Function> process_fun = v8::Local<v8::Function>::Cast(process_val);

    context_.Reset(isolate, context);
    process_.Reset(isolate, process_fun);
  }

  return 0;
}

void unloadJS() {
  process_.Reset();
  context_.Reset();
  isolate->Dispose();
  v8::V8::Dispose();
  v8::V8::ShutdownPlatform();
  delete create_params.array_buffer_allocator;
}

