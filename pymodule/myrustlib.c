#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "myrustlib.h"

static PyObject*
py_triple(PyObject *self, PyObject *args)
{
    long value;
    
    if (!PyArg_ParseTuple(args, "l", &value)) {
        return NULL;
    }
    
    value = triple(value);    
    return PyLong_FromLong(value);
}

static PyObject*
py_stack_push(PyObject *self, PyObject *args)
{
    long value, res;
    
    if (!PyArg_ParseTuple(args, "l", &value)) {
        return NULL;
    }
    
    res = stack_push(value);    
    return PyLong_FromLong(res);
}

static PyObject*
py_stack_pull(PyObject *self, PyObject *args)
{
    long res;
    
    res = stack_pull();    
    return PyLong_FromLong(res);
}

static PyMethodDef MyRustLibMethods[] = {
    {"triple",  py_triple, METH_VARARGS},
    {"stack_push",  py_stack_push, METH_VARARGS},
    {"stack_pull",  py_stack_pull, METH_VARARGS},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef MyRustLibDef = {
    PyModuleDef_HEAD_INIT,
    "_myrustlib",
    NULL,
    -1,
    MyRustLibMethods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyObject *
PyInit__myrustlib(void)
{
    PyObject *m = PyModule_Create(&MyRustLibDef);
    if (m == NULL) {
        return NULL;
    }
    return m;
}

