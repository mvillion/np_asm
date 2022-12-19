// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// insti_str is the list of instruction names
#define N_INSTI 61

static const char *insti_str[N_INSTI] =
{
    "packs_epi16", 
    "packs_epi32", 
    "packus_epi16", 
    "unpackhi_epi8", 
    "unpackhi_epi16", 
    "unpackhi_epi32", 
    "unpackhi_epi64", 
    "unpacklo_epi8", 
    "unpacklo_epi16", 
    "unpacklo_epi32", 
    "unpacklo_epi64", 
    "add_epi8", 
    "add_epi16", 
    "add_epi32", 
    "add_epi64", 
    "adds_epi8", 
    "adds_epi16", 
    "adds_epu8", 
    "adds_epu16", 
    "sub_epi8", 
    "sub_epi16", 
    "sub_epi32", 
    "sub_epi64", 
    "subs_epi8", 
    "subs_epi16", 
    "subs_epu8", 
    "subs_epu16", 
    "madd_epi16", 
    "mulhi_epi16", 
    "mullo_epi16", 
    "mul_epu32", 
    "sll_epi16", 
    "sll_epi32", 
    "sll_epi64", 
    "sra_epi16", 
    "sra_epi32", 
    "srl_epi16", 
    "srl_epi32", 
    "srl_epi64", 
    "and_si128", 
    "andnot_si128", 
    "or_si128", 
    "xor_si128", 
    "cmpeq_epi8", 
    "cmpeq_epi16", 
    "cmpeq_epi32", 
    "cmplt_epi8", 
    "cmplt_epi16", 
    "cmplt_epi32", 
    "cmpgt_epi8", 
    "cmpgt_epi16", 
    "cmpgt_epi32", 
    "max_epi16", 
    "max_epu8", 
    "min_epi16", 
    "min_epu8", 
    "mulhi_epu16", 
    "avg_epu8", 
    "avg_epu16", 
    "sad_epu8", 
    "move_epi64", 
};

// n_in_i is the number of inputs for each instruction
static const char n_in_i[N_INSTI] =
{
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    1,
};

// create a function np_<op> for each instruction <op>
static void np_packs_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_packs_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_packs_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_packs_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_packus_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_packus_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_unpackhi_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_unpackhi_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_unpackhi_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_unpackhi_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_unpackhi_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_unpackhi_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_unpackhi_epi64(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_unpackhi_epi64(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_unpacklo_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_unpacklo_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_unpacklo_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_unpacklo_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_unpacklo_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_unpacklo_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_unpacklo_epi64(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_unpacklo_epi64(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_add_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_add_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_add_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_add_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_add_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_add_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_add_epi64(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_add_epi64(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_adds_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_adds_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_adds_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_adds_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_adds_epu8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_adds_epu8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_adds_epu16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_adds_epu16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sub_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sub_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sub_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sub_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sub_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sub_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sub_epi64(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sub_epi64(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_subs_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_subs_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_subs_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_subs_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_subs_epu8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_subs_epu8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_subs_epu16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_subs_epu16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_madd_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_madd_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_mulhi_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_mulhi_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_mullo_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_mullo_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_mul_epu32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_mul_epu32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sll_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sll_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sll_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sll_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sll_epi64(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sll_epi64(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sra_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sra_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sra_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sra_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_srl_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_srl_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_srl_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_srl_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_srl_epi64(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_srl_epi64(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_and_si128(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_and_si128(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_andnot_si128(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_andnot_si128(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_or_si128(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_or_si128(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_xor_si128(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_xor_si128(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmpeq_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmpeq_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmpeq_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmpeq_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmpeq_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmpeq_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmplt_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmplt_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmplt_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmplt_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmplt_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmplt_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmpgt_epi8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmpgt_epi8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmpgt_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmpgt_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_cmpgt_epi32(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_cmpgt_epi32(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_max_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_max_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_max_epu8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_max_epu8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_min_epi16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_min_epi16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_min_epu8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_min_epu8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_mulhi_epu16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_mulhi_epu16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_avg_epu8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_avg_epu8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_avg_epu16(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_avg_epu16(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_sad_epu8(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_sad_epu8(
            _mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

static void np_move_epi64(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    __m128i *in1 = (__m128i *)args[0];
    __m128i *in2 = (__m128i *)args[1];
    __m128i *out = (__m128i *)args[2];
    int size_ratio = sizeof(__m128i)/steps[0];
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_move_epi64(_mm_load_si128(in1)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}

// funf is the list of all npy_<op> functions
PyUFuncGenericFunction funi[N_INSTI][4] =
{
    {&np_packs_epi16, &np_packs_epi16, &np_packs_epi16, &np_packs_epi16},
    {&np_packs_epi32, &np_packs_epi32, &np_packs_epi32, &np_packs_epi32},
    {&np_packus_epi16, &np_packus_epi16, &np_packus_epi16, &np_packus_epi16},
    {&np_unpackhi_epi8, &np_unpackhi_epi8, &np_unpackhi_epi8, &np_unpackhi_epi8},
    {&np_unpackhi_epi16, &np_unpackhi_epi16, &np_unpackhi_epi16, &np_unpackhi_epi16},
    {&np_unpackhi_epi32, &np_unpackhi_epi32, &np_unpackhi_epi32, &np_unpackhi_epi32},
    {&np_unpackhi_epi64, &np_unpackhi_epi64, &np_unpackhi_epi64, &np_unpackhi_epi64},
    {&np_unpacklo_epi8, &np_unpacklo_epi8, &np_unpacklo_epi8, &np_unpacklo_epi8},
    {&np_unpacklo_epi16, &np_unpacklo_epi16, &np_unpacklo_epi16, &np_unpacklo_epi16},
    {&np_unpacklo_epi32, &np_unpacklo_epi32, &np_unpacklo_epi32, &np_unpacklo_epi32},
    {&np_unpacklo_epi64, &np_unpacklo_epi64, &np_unpacklo_epi64, &np_unpacklo_epi64},
    {&np_add_epi8, &np_add_epi8, &np_add_epi8, &np_add_epi8},
    {&np_add_epi16, &np_add_epi16, &np_add_epi16, &np_add_epi16},
    {&np_add_epi32, &np_add_epi32, &np_add_epi32, &np_add_epi32},
    {&np_add_epi64, &np_add_epi64, &np_add_epi64, &np_add_epi64},
    {&np_adds_epi8, &np_adds_epi8, &np_adds_epi8, &np_adds_epi8},
    {&np_adds_epi16, &np_adds_epi16, &np_adds_epi16, &np_adds_epi16},
    {&np_adds_epu8, &np_adds_epu8, &np_adds_epu8, &np_adds_epu8},
    {&np_adds_epu16, &np_adds_epu16, &np_adds_epu16, &np_adds_epu16},
    {&np_sub_epi8, &np_sub_epi8, &np_sub_epi8, &np_sub_epi8},
    {&np_sub_epi16, &np_sub_epi16, &np_sub_epi16, &np_sub_epi16},
    {&np_sub_epi32, &np_sub_epi32, &np_sub_epi32, &np_sub_epi32},
    {&np_sub_epi64, &np_sub_epi64, &np_sub_epi64, &np_sub_epi64},
    {&np_subs_epi8, &np_subs_epi8, &np_subs_epi8, &np_subs_epi8},
    {&np_subs_epi16, &np_subs_epi16, &np_subs_epi16, &np_subs_epi16},
    {&np_subs_epu8, &np_subs_epu8, &np_subs_epu8, &np_subs_epu8},
    {&np_subs_epu16, &np_subs_epu16, &np_subs_epu16, &np_subs_epu16},
    {&np_madd_epi16, &np_madd_epi16, &np_madd_epi16, &np_madd_epi16},
    {&np_mulhi_epi16, &np_mulhi_epi16, &np_mulhi_epi16, &np_mulhi_epi16},
    {&np_mullo_epi16, &np_mullo_epi16, &np_mullo_epi16, &np_mullo_epi16},
    {&np_mul_epu32, &np_mul_epu32, &np_mul_epu32, &np_mul_epu32},
    {&np_sll_epi16, &np_sll_epi16, &np_sll_epi16, &np_sll_epi16},
    {&np_sll_epi32, &np_sll_epi32, &np_sll_epi32, &np_sll_epi32},
    {&np_sll_epi64, &np_sll_epi64, &np_sll_epi64, &np_sll_epi64},
    {&np_sra_epi16, &np_sra_epi16, &np_sra_epi16, &np_sra_epi16},
    {&np_sra_epi32, &np_sra_epi32, &np_sra_epi32, &np_sra_epi32},
    {&np_srl_epi16, &np_srl_epi16, &np_srl_epi16, &np_srl_epi16},
    {&np_srl_epi32, &np_srl_epi32, &np_srl_epi32, &np_srl_epi32},
    {&np_srl_epi64, &np_srl_epi64, &np_srl_epi64, &np_srl_epi64},
    {&np_and_si128, &np_and_si128, &np_and_si128, &np_and_si128},
    {&np_andnot_si128, &np_andnot_si128, &np_andnot_si128, &np_andnot_si128},
    {&np_or_si128, &np_or_si128, &np_or_si128, &np_or_si128},
    {&np_xor_si128, &np_xor_si128, &np_xor_si128, &np_xor_si128},
    {&np_cmpeq_epi8, &np_cmpeq_epi8, &np_cmpeq_epi8, &np_cmpeq_epi8},
    {&np_cmpeq_epi16, &np_cmpeq_epi16, &np_cmpeq_epi16, &np_cmpeq_epi16},
    {&np_cmpeq_epi32, &np_cmpeq_epi32, &np_cmpeq_epi32, &np_cmpeq_epi32},
    {&np_cmplt_epi8, &np_cmplt_epi8, &np_cmplt_epi8, &np_cmplt_epi8},
    {&np_cmplt_epi16, &np_cmplt_epi16, &np_cmplt_epi16, &np_cmplt_epi16},
    {&np_cmplt_epi32, &np_cmplt_epi32, &np_cmplt_epi32, &np_cmplt_epi32},
    {&np_cmpgt_epi8, &np_cmpgt_epi8, &np_cmpgt_epi8, &np_cmpgt_epi8},
    {&np_cmpgt_epi16, &np_cmpgt_epi16, &np_cmpgt_epi16, &np_cmpgt_epi16},
    {&np_cmpgt_epi32, &np_cmpgt_epi32, &np_cmpgt_epi32, &np_cmpgt_epi32},
    {&np_max_epi16, &np_max_epi16, &np_max_epi16, &np_max_epi16},
    {&np_max_epu8, &np_max_epu8, &np_max_epu8, &np_max_epu8},
    {&np_min_epi16, &np_min_epi16, &np_min_epi16, &np_min_epi16},
    {&np_min_epu8, &np_min_epu8, &np_min_epu8, &np_min_epu8},
    {&np_mulhi_epu16, &np_mulhi_epu16, &np_mulhi_epu16, &np_mulhi_epu16},
    {&np_avg_epu8, &np_avg_epu8, &np_avg_epu8, &np_avg_epu8},
    {&np_avg_epu16, &np_avg_epu16, &np_avg_epu16, &np_avg_epu16},
    {&np_sad_epu8, &np_sad_epu8, &np_sad_epu8, &np_sad_epu8},
    {&np_move_epi64, &np_move_epi64, &np_move_epi64, &np_move_epi64},
};

static char typei[3*4] =
{
    NPY_INT8, NPY_INT8, NPY_INT8,
    NPY_INT16, NPY_INT16, NPY_INT16,
    NPY_INT32, NPY_INT32, NPY_INT32,
    NPY_INT64, NPY_INT64, NPY_INT64,
};
