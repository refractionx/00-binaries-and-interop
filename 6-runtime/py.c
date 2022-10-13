#define PY_SSIZE_T_CLEAN
#include "py.h"
#include <Python.h>

static PyObject *pFunc, *pValue, *pResult;
static PyObject *pName, *pModule;

void tickC(char *data) {
    printf("C: %s", data);
}

int loadPython(int argc, char **argv)
{
    int i;

    wchar_t** _argv = PyMem_Malloc(sizeof(wchar_t*)*argc);
    for (int j=0; j<argc; j++) {
        wchar_t* arg = Py_DecodeLocale(argv[j], NULL);
        _argv[j] = arg;
    }
    
    Py_SetProgramName((wchar_t *)argv[0]);
    Py_Initialize();

    PySys_SetArgv(argc, _argv);

    pName = PyUnicode_DecodeFSDefault(argv[1]);
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {

        pFunc = PyObject_GetAttrString(pModule, "tick");

        if (!pFunc || !PyCallable_Check(pFunc)) {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", "tick");
        }
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }
    return 0;
}

void tickPython(char *data) {
    pValue = PyUnicode_FromString(data);
    pResult = PyObject_CallFunction(pFunc, "O", pValue);
    Py_DecRef(pValue);
    Py_DecRef(pResult);
}