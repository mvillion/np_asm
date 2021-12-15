#include "Python.h"
#include "math.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/ndarraytypes.h"
#include "numpy/ufuncobject.h"
#include "numpy/halffloat.h"
#include "xmmintrin.h"

static PyMethodDef np_asm_method[] = {
    {NULL, NULL, 0, NULL}
};

//______________________________________________________________________________
// float operation with 1 or 2 input(s)
#define INSTF_LIST \
    etype(rcp_ps, macro_if1) \
    etype(rcp_ss, macro_if1) \
    etype(rsqrt_ps, macro_if1) \
    etype(rsqrt_ss, macro_if1) \
    etype(sqrt_ps, macro_if1) \
    etype(sqrt_ss, macro_if1) \
    etype(add_ps, macro_if2) \
    etype(add_ss, macro_if2) \
    etype(div_ps, macro_if2) \
    etype(div_ss, macro_if2) \
    etype(max_ps, macro_if2) \
    etype(max_ss, macro_if2) \
    etype(min_ps, macro_if2) \
    etype(min_ss, macro_if2) \
    etype(mul_ps, macro_if2) \
    etype(mul_ss, macro_if2) \
    etype(sub_ps, macro_if2) \
    etype(sub_ss, macro_if2) \
    etype(cmpeq_ps, macro_if2) \
    etype(cmpeq_ss, macro_if2) \
    etype(cmpge_ps, macro_if2) \
    etype(cmpge_ss, macro_if2) \
    etype(cmpgt_ps, macro_if2) \
    etype(cmpgt_ss, macro_if2) \
    etype(cmple_ps, macro_if2) \
    etype(cmple_ss, macro_if2) \
    etype(cmplt_ps, macro_if2) \
    etype(cmplt_ss, macro_if2) \
    etype(cmpneq_ps, macro_if2) \
    etype(cmpneq_ss, macro_if2) \
    etype(cmpnge_ps, macro_if2) \
    etype(cmpnge_ss, macro_if2) \
    etype(cmpngt_ps, macro_if2) \
    etype(cmpngt_ss, macro_if2) \
    etype(cmpnle_ps, macro_if2) \
    etype(cmpnle_ss, macro_if2) \
    etype(cmpnlt_ps, macro_if2) \
    etype(cmpnlt_ss, macro_if2) \
    etype(andnot_ps, macro_if2) \
    etype(and_ps, macro_if2) \
    etype(or_ps, macro_if2) \
    etype(xor_ps, macro_if2) \
    etype(movehl_ps, macro_if2) \
    etype(movelh_ps, macro_if2) \
    etype(move_ss, macro_if2) \
    etype(unpackhi_ps, macro_if2) \
    etype(unpacklo_ps, macro_if2) \

#define N_INSTF (63-16)

// etype(movemask_ps) // returns int
//    etype(cmpord_ss)
//    etype(cmpunord_ss)
//    etype(cmpord_ps)
//    etype(cmpunord_ps)
//    etype(comieq_ss)
//    etype(comilt_ss)
//    etype(comile_ss)
//    etype(comigt_ss)
//    etype(comige_ss)
//    etype(comineq_ss)
//    etype(ucomieq_ss)
//    etype(ucomilt_ss)
//    etype(ucomile_ss)
//    etype(ucomigt_ss)
//    etype(ucomige_ss)
//    etype(ucomineq_ss)

// inst1f_str is the list of instruction names
#define etype(x, macro_cond) #x,
static const char *inst1f_str[N_INSTF] = {INSTF_LIST};
#undef etype

// n_in_f is the number of inputs for each instruction
#define macro_if1 1
#define macro_if2 2
#define etype(x, macro_cond) macro_cond,
static const char n_in_f[N_INSTF] = {INSTF_LIST};
#undef etype
#undef macro_if2
#undef macro_if1

// create a function np_<op> for each instruction <op>
#define INSTF(inst, macro_cond) \
static void np_ ## inst( \
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data) \
{ \
    npy_intp i; \
    npy_intp n = dimensions[0]; \
    float *in1 = (float *)args[0]; \
    float *in2 = (float *)args[1]; \
    float *out = (float *)args[2]; \
    int size_ratio = sizeof(__m128)/sizeof(float); \
    npy_intp in1_step = steps[0]/size_ratio; \
    npy_intp in2_step = steps[1]/size_ratio; \
    npy_intp out_step = steps[2]/size_ratio; \
    for (i = 0; i < n/size_ratio; i++) { \
        /* BEGIN main ufunc computation */ \
        _mm_storeu_ps(out, _mm_ ## inst( \
            macro_cond(_mm_loadu_ps(in1), _mm_loadu_ps(in2)))); \
        /* END main ufunc computation */ \
        in1 += in1_step*size_ratio; \
        in2 += in2_step*size_ratio; \
        out += out_step*size_ratio; \
    } \
}

#define macro_if1(x, y) x
#define macro_if2(x, y) x, y
#define etype(x, macro_cond) INSTF(x, macro_cond)
INSTF_LIST
#undef etype
#undef macro_if2
#undef macro_if1

// funf is the list of all npy_<op> functions
#define etype(x, macro_cond) {& np_ ## x},
PyUFuncGenericFunction funf[N_INSTF][1] = {INSTF_LIST};
#undef etype

static char typef[3] = {NPY_FLOAT, NPY_FLOAT, NPY_FLOAT};

//______________________________________________________________________________
// integer operation with 2 inputs
#define INST2I_LIST \
    etype(add_epi8) \

#define N_INST2I (180-179)

//    etype(cmpord_ss)
//    etype(cmpunord_ss)
//    etype(cmpord_ps)
//    etype(cmpunord_ps)
//    etype(comieq_ss)
//    etype(comilt_ss)
//    etype(comile_ss)
//    etype(comigt_ss)
//    etype(comige_ss)
//    etype(comineq_ss)
//    etype(ucomieq_ss)
//    etype(ucomilt_ss)
//    etype(ucomile_ss)
//    etype(ucomigt_ss)
//    etype(ucomige_ss)
//    etype(ucomineq_ss)

#define etype(x) #x,
static const char *inst2i_str[N_INST2I] = {INST2I_LIST};
#undef etype

#define INST2I(inst) \
static void np_ ## inst( \
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data) \
{ \
    npy_intp i; \
    npy_intp n = dimensions[0]; \
    __m128i *in1 = (__m128i *)args[0]; \
    __m128i *in2 = (__m128i *)args[1]; \
    __m128i *out = (__m128i *)args[2]; \
    int size_ratio = sizeof(__m128)/sizeof(float); \
    npy_intp in1_step = steps[0]/size_ratio; \
    npy_intp in2_step = steps[1]/size_ratio; \
    npy_intp out_step = steps[2]/size_ratio; \
    for (i = 0; i < n/size_ratio; i++) { \
        /* BEGIN main ufunc computation */ \
        _mm_store_si128( \
            out, _mm_ ## inst(_mm_load_si128(in1), _mm_load_si128(in2))); \
        /* END main ufunc computation */ \
        in1 += in1_step*size_ratio; \
        in2 += in2_step*size_ratio; \
        out += out_step*size_ratio; \
    } \
}

#define etype(x) INST2I(x)
INST2I_LIST
#undef etype

/*This gives pointers to the above functions*/
#define etype(x) {& np_ ## x, & np_ ## x, & np_ ## x, & np_ ## x},
PyUFuncGenericFunction fun2i[N_INST2I][4] = {INST2I_LIST};
#undef etype

static char type2i[3*4] = {
    NPY_INT8, NPY_INT8, NPY_INT8,
    NPY_INT16, NPY_INT16, NPY_INT16,
    NPY_INT32, NPY_INT32, NPY_INT32,
    NPY_INT64, NPY_INT64, NPY_INT64,
};

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
            inst1f_str[i], "not documented yet", 0);
        PyDict_SetItemString(d, inst1f_str[i], op);
        Py_DECREF(op);
    }
    for (int i = 0; i < N_INST2I; i++)
    {
        op = PyUFunc_FromFuncAndData(
            fun2i[i], NULL, type2i, 4, 2, 1, PyUFunc_None,
            inst2i_str[i], "not documented yet", 0);
        PyDict_SetItemString(d, inst2i_str[i], op);
        Py_DECREF(op);
    }
    return m;
}
