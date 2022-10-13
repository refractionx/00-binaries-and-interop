#include <node.h>

extern "C" {
    #include <greetings.h>
}


namespace greetings {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Method(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(
            isolate, getGreetingMessage()).ToLocalChecked());
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "getGreetingMessage", Method);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}