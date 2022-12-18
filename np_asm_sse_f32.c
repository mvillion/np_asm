//______________________________________________________________________________
// float operation with 1 or 2 input(s)
#define INSTF_LIST \
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
    etype(rcp_ps, macro_if1) \
    etype(rcp_ss, macro_if1) \
    etype(rsqrt_ps, macro_if1) \
    etype(rsqrt_ss, macro_if1) \
    etype(sqrt_ps, macro_if1) \
    etype(sqrt_ss, macro_if1) \
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
    etype(cmpord_ps, macro_if2) \
    etype(cmpord_ss, macro_if2) \
    etype(cmpunord_ps, macro_if2) \
    etype(cmpunord_ss, macro_if2) \
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

#define N_INSTF (55-4)

// instf_str is the list of instruction names
#define etype(x, macro_cond) #x,
static const char *instf_str[N_INSTF] = {INSTF_LIST};
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
