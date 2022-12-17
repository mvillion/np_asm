#include "Python.h"
#include "emmintrin.h"
#include "math.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/ndarraytypes.h"
#include "numpy/ufuncobject.h"
#include "numpy/halffloat.h"
#include "xmmintrin.h"

static PyMethodDef np_asm_method[] = {
    {NULL, NULL, 0, NULL}
};

#include "np_asm_sse_f32.c"
#include "np_asm_sse_int.c"

//______________________________________________________________________________
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "np_asm",
    NULL,
    -1,
    np_asm_method,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_np_asm(void)
{
    char *doc_str = "binding of intrinsic _mm_<function_name>";
    PyObject *d;
    PyObject *op;
    PyObject *m;
    m = PyModule_Create(&moduledef);
    if (!m) {
        return NULL;
    }

    import_array();
    import_umath();

    d = PyModule_GetDict(m);

    for (int i = 0; i < N_INSTF; i++)
    {
        op = PyUFunc_FromFuncAndData(
            funf[i], NULL, typef, 1, n_in_f[i], 1, PyUFunc_None,
            inst1f_str[i], doc_str, 0);
        PyDict_SetItemString(d, inst1f_str[i], op);
        Py_DECREF(op);
    }
    for (int i = 0; i < N_INST2I; i++)
    {
        op = PyUFunc_FromFuncAndData(
            fun2i[i], NULL, type2i, 4, 2, 1, PyUFunc_None,
            inst2i_str[i], doc_str, 0);
        PyDict_SetItemString(d, inst2i_str[i], op);
        Py_DECREF(op);
    }
    return m;
}
