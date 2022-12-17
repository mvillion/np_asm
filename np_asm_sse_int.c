//______________________________________________________________________________
// integer operation with 2 inputs
#define INST2I_LIST \
    etype(add_epi8) \

#define N_INST2I (5-4)

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

// This gives pointers to the above functions
#define etype(x) {& np_ ## x, & np_ ## x, & np_ ## x, & np_ ## x},
PyUFuncGenericFunction fun2i[N_INST2I][4] = {INST2I_LIST};
#undef etype

static char type2i[3*4] = {
    NPY_INT8, NPY_INT8, NPY_INT8,
    NPY_INT16, NPY_INT16, NPY_INT16,
    NPY_INT32, NPY_INT32, NPY_INT32,
    NPY_INT64, NPY_INT64, NPY_INT64,
};
