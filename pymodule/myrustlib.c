#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "myrustlib.h"

static PyObject*
py_triple(PyObject *self, PyObject *args)
{
    long value;
    Py_ssize_t char_count, color_count, i;
    PyObject *result;
    
    if (!PyArg_ParseTuple(args, "l", &value)) {
        return NULL;
    }
    
    value = triple(value);    
    return PyLong_FromLong(value);
}

static PyMethodDef MyRustLibMethods[] = {
    {"triple",  py_triple, METH_VARARGS,
     "Triples `value`"},
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

