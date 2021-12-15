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
// float operation with / input
#define INST1F_LIST \
    etype(rcp_ps) \
    etype(rcp_ss) \
    etype(rsqrt_ps) \
    etype(rsqrt_ss) \
    etype(sqrt_ps) \
    etype(sqrt_ss) \

#define N_INST1F (22-16)

// etype(movemask_ps) // returns int

#define etype(x) #x,
static const char *inst1f_str[N_INST1F] = {INST1F_LIST};
#undef etype

#define INST1F(inst) \
static void np_ ## inst( \
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data) \
{ \
    npy_intp i; \
    npy_intp n = dimensions[0]; \
    float *in1 = (float *)args[0]; \
    float *out = (float *)args[1]; \
    int size_ratio = sizeof(__m128)/sizeof(float); \
    npy_intp in1_step = steps[0]/size_ratio; \
    npy_intp out_step = steps[1]/size_ratio; \
    for (i = 0; i < n/size_ratio; i++) { \
        /* BEGIN main ufunc computation */ \
        _mm_storeu_ps(out, _mm_ ## inst(_mm_loadu_ps(in1))); \
        /* END main ufunc computation */ \
        in1 += in1_step*size_ratio; \
        out += out_step*size_ratio; \
    } \
}

#define etype(x) INST1F(x)
INST1F_LIST
#undef etype

/*This gives pointers to the above functions*/
#define etype(x) {& np_ ## x},
PyUFuncGenericFunction fun1f[N_INST1F][1] = {INST1F_LIST};
#undef etype

#define etype(x) NPY_FLOAT, NPY_FLOAT,
static char type1f[2*N_INST1F] = {INST1F_LIST};
#undef etype

#define etype(x) NULL,
static void *data1f[N_INST1F] = {INST1F_LIST};
#undef etype

//______________________________________________________________________________
// float operation with 2 inputs
#define INST2F_LIST \
    etype(add_ps) \
    etype(add_ss) \
    etype(div_ps) \
    etype(div_ss) \
    etype(max_ps) \
    etype(max_ss) \
    etype(min_ps) \
    etype(min_ss) \
    etype(mul_ps) \
    etype(mul_ss) \
    etype(sub_ps) \
    etype(sub_ss) \
    etype(cmpeq_ps) \
    etype(cmpeq_ss) \
    etype(cmpge_ps) \
    etype(cmpge_ss) \
    etype(cmpgt_ps) \
    etype(cmpgt_ss) \
    etype(cmple_ps) \
    etype(cmple_ss) \
    etype(cmplt_ps) \
    etype(cmplt_ss) \
    etype(cmpneq_ps) \
    etype(cmpneq_ss) \
    etype(cmpnge_ps) \
    etype(cmpnge_ss) \
    etype(cmpngt_ps) \
    etype(cmpngt_ss) \
    etype(cmpnle_ps) \
    etype(cmpnle_ss) \
    etype(cmpnlt_ps) \
    etype(cmpnlt_ss) \
    etype(andnot_ps) \
    etype(and_ps) \
    etype(or_ps) \
    etype(xor_ps) \
    etype(movehl_ps) \
    etype(movelh_ps) \
    etype(move_ss) \
    etype(unpackhi_ps) \
    etype(unpacklo_ps) \

#define N_INST2F (111-70)

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
static const char *inst2f_str[N_INST2F] = {INST2F_LIST};
#undef etype

#define INST2F(inst) \
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
        _mm_storeu_ps( \
            out, _mm_ ## inst(_mm_loadu_ps(in1), _mm_loadu_ps(in2))); \
        /* END main ufunc computation */ \
        in1 += in1_step*size_ratio; \
        in2 += in2_step*size_ratio; \
        out += out_step*size_ratio; \
    } \
}

#define etype(x) INST2F(x)
INST2F_LIST
#undef etype

/*This gives pointers to the above functions*/
#define etype(x) {& np_ ## x},
PyUFuncGenericFunction fun2f[N_INST2F][1] = {INST2F_LIST};
#undef etype

#define etype(x) NPY_FLOAT, NPY_FLOAT, NPY_FLOAT,
static char type2f[3*N_INST2F] = {INST2F_LIST};
#undef etype

#define etype(x) NULL,
static void *data2f[N_INST2F] = {INST2F_LIST};
#undef etype

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

#define etype(x) \
    NPY_INT8, NPY_INT8, NPY_INT8, \
    NPY_INT16, NPY_INT16, NPY_INT16, \
    NPY_INT32, NPY_INT32, NPY_INT32, \
    NPY_INT64, NPY_INT64, NPY_INT64, \

static char type2i[3*4*N_INST2I] = {INST2I_LIST};
#undef etype

#define etype(x) NULL,
static void *data2i[N_INST2I] = {INST2I_LIST};
#undef etype

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

    for (int i = 0; i < N_INST1F; i++)
    {
        op = PyUFunc_FromFuncAndData(
            fun1f[i], data1f, type1f, N_INST1F, 1, 1, PyUFunc_None,
            inst1f_str[i], "not documented yet", 0);
        PyDict_SetItemString(d, inst1f_str[i], op);
        Py_DECREF(op);
    }
    for (int i = 0; i < N_INST2F; i++)
    {
        op = PyUFunc_FromFuncAndData(
            fun2f[i], data2f, type2f, N_INST2F, 2, 1, PyUFunc_None,
            inst2f_str[i], "not documented yet", 0);
        PyDict_SetItemString(d, inst2f_str[i], op);
        Py_DECREF(op);
    }
    for (int i = 0; i < N_INST2I; i++)
    {
        op = PyUFunc_FromFuncAndData(
            fun2i[i], data2i, type2i, N_INST2I, 2, 1, PyUFunc_None,
            inst2i_str[i], "not documented yet", 0);
        PyDict_SetItemString(d, inst2i_str[i], op);
        Py_DECREF(op);
    }
    return m;
}
