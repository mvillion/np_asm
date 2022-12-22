#include "Python.h"
#include "math.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/ndarraytypes.h"
#include "numpy/ufuncobject.h"
#include "numpy/halffloat.h"

#include "xmmintrin.h"
#include "emmintrin.h"
#include "pmmintrin.h"
#include "smmintrin.h"
#include "immintrin.h"

static PyMethodDef np_asm_method[] = {
    {NULL, NULL, 0, NULL}
};

#include "np_asm_sse_f32_auto.c"
#include "np_asm_sse_int_auto.c"
#include "np_asm_sse_f64_auto.c"
#include "np_asm_avx_f32_auto.c"
#include "np_asm_avx_f64_auto.c"

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
            funf[i], NULL, typef, 1, n_in_f[i], 1, PyUFunc_None, instf_str[i],
            doc_str, 0);
        PyDict_SetItemString(d, instf_str[i], op);
        Py_DECREF(op);
    }
    for (int i = 0; i < N_INSTI; i++)
    {
        op = PyUFunc_FromFuncAndData(
            funi[i], NULL, typei, 4, n_in_i[i], 1, PyUFunc_None, insti_str[i],
            doc_str, 0);
        PyDict_SetItemString(d, insti_str[i], op);
        Py_DECREF(op);
    }
    for (int i = 0; i < N_INSTD; i++)
    {
        op = PyUFunc_FromFuncAndData(
            fund[i], NULL, typed, 1, n_in_d[i], 1, PyUFunc_None, instd_str[i],
            doc_str, 0);
        PyDict_SetItemString(d, instd_str[i], op);
        Py_DECREF(op);
    }

    for (int i = 0; i < N_INSTF256; i++)
    {
        op = PyUFunc_FromFuncAndData(
            funf256[i], NULL, typef, 1, n_in_f256[i], 1, PyUFunc_None,
            instf256_str[i], doc_str, 0);
        PyDict_SetItemString(d, instf256_str[i], op);
        Py_DECREF(op);
    }
    for (int i = 0; i < N_INSTD256; i++)
    {
        op = PyUFunc_FromFuncAndData(
            fund256[i], NULL, typed, 1, n_in_d256[i], 1, PyUFunc_None,
            instd256_str[i], doc_str, 0);
        PyDict_SetItemString(d, instd256_str[i], op);
        Py_DECREF(op);
    }

    return m;
}
