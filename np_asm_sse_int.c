//______________________________________________________________________________
// integer operation with 1 or 2 inputs
#define INSTI_LIST \
    etype(packs_epi16, macro_if2) \
    etype(packs_epi32, macro_if2) \
    etype(packus_epi16, macro_if2) \
    etype(unpackhi_epi8, macro_if2) \
    etype(unpackhi_epi16, macro_if2) \
    etype(unpackhi_epi32, macro_if2) \
    etype(unpackhi_epi64, macro_if2) \
    etype(unpacklo_epi8, macro_if2) \
    etype(unpacklo_epi16, macro_if2) \
    etype(unpacklo_epi32, macro_if2) \
    etype(unpacklo_epi64, macro_if2) \
    etype(add_epi8, macro_if2) \
    etype(add_epi16, macro_if2) \
    etype(add_epi32, macro_if2) \
    etype(add_epi64, macro_if2) \
    etype(adds_epi8, macro_if2) \
    etype(adds_epi16, macro_if2) \
    etype(adds_epu8, macro_if2) \
    etype(adds_epu16, macro_if2) \
    etype(sub_epi8, macro_if2) \
    etype(sub_epi16, macro_if2) \
    etype(sub_epi32, macro_if2) \
    etype(sub_epi64, macro_if2) \
    etype(subs_epi8, macro_if2) \
    etype(subs_epi16, macro_if2) \
    etype(subs_epu8, macro_if2) \
    etype(subs_epu16, macro_if2) \
    etype(madd_epi16, macro_if2) \
    etype(mulhi_epi16, macro_if2) \
    etype(mullo_epi16, macro_if2) \
    etype(mul_epu32, macro_if2) \
    etype(sll_epi16, macro_if2) \
    etype(sll_epi32, macro_if2) \
    etype(sll_epi64, macro_if2) \
    etype(sra_epi16, macro_if2) \
    etype(sra_epi32, macro_if2) \
    etype(srl_epi16, macro_if2) \
    etype(srl_epi32, macro_if2) \
    etype(srl_epi64, macro_if2) \
    etype(and_si128, macro_if2) \
    etype(andnot_si128, macro_if2) \
    etype(or_si128, macro_if2) \
    etype(xor_si128, macro_if2) \
    etype(cmpeq_epi8, macro_if2) \
    etype(cmpeq_epi16, macro_if2) \
    etype(cmpeq_epi32, macro_if2) \
    etype(cmplt_epi8, macro_if2) \
    etype(cmplt_epi16, macro_if2) \
    etype(cmplt_epi32, macro_if2) \
    etype(cmpgt_epi8, macro_if2) \
    etype(cmpgt_epi16, macro_if2) \
    etype(cmpgt_epi32, macro_if2) \
    etype(max_epi16, macro_if2) \
    etype(max_epu8, macro_if2) \
    etype(min_epi16, macro_if2) \
    etype(min_epu8, macro_if2) \
    etype(mulhi_epu16, macro_if2) \
    etype(avg_epu8, macro_if2) \
    etype(avg_epu16, macro_if2) \
    etype(sad_epu8, macro_if2) \
    etype(move_epi64, macro_if1) \

#define N_INSTI (65-4)

// insti_str is the list of instruction names
#define etype(x, macro_cond) #x,
static const char *insti_str[N_INSTI] = {INSTI_LIST};
#undef etype

// n_in_i is the number of inputs for each instruction
#define macro_if1 1
#define macro_if2 2
#define etype(x, macro_cond) macro_cond,
static const char n_in_i[N_INSTI] = {INSTI_LIST};
#undef etype
#undef macro_if2
#undef macro_if1

// create a function np_<op> for each instruction <op>
// note: use _mm_load_si128 and _mm_store_si128 for data access
// use _mm_loadu_si128 and _mm_storeu_si128 if alignment is an issue
#define INSTI(inst, macro_cond) \
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
        _mm_store_si128(out, _mm_ ## inst( \
            macro_cond(_mm_load_si128(in1), _mm_load_si128(in2)))); \
        /* END main ufunc computation */ \
        in1 += in1_step*size_ratio; \
        in2 += in2_step*size_ratio; \
        out += out_step*size_ratio; \
    } \
}

#define macro_if1(x, y) x
#define macro_if2(x, y) x, y
#define etype(x, macro_cond) INSTI(x, macro_cond)
INSTI_LIST
#undef etype
#undef macro_if2
#undef macro_if1

// funf is the list of all npy_<op> functions
#define etype(x, macro_cond) {& np_ ## x, & np_ ## x, & np_ ## x, & np_ ## x},
PyUFuncGenericFunction fun2i[N_INSTI][4] = {INSTI_LIST};
#undef etype

static char typei[3*4] = {
    NPY_INT8, NPY_INT8, NPY_INT8,
    NPY_INT16, NPY_INT16, NPY_INT16,
    NPY_INT32, NPY_INT32, NPY_INT32,
    NPY_INT64, NPY_INT64, NPY_INT64,
};
