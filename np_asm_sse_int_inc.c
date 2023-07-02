typedef __m128i sse0_fun_t(void);
typedef __m128i sse1_fun_t(__m128i in1);
typedef __m128i sse2_fun_t(__m128i in1, __m128i in2);

typedef struct
{
    uint32_t n_in;
    const char *name;
    const char *doc;
    union
    {
        sse0_fun_t *sse0;
        sse1_fun_t *sse1;
        sse2_fun_t *sse2;
    };
} sse_fun_t;

// create a function np_<op> for each instruction <op>
static void inline np_sse(
    char **args, const npy_intp *dimensions, const npy_intp *steps,
    const sse_fun_t *fun)
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
        if (fun->n_in == 0)
            _mm_store_si128(out, fun->sse0());
        else if (fun->n_in == 1)
            _mm_store_si128(out, fun->sse1(_mm_load_si128(in1)));
        else // if (fun->n_in == 2)
            _mm_store_si128(
                out, fun->sse2(_mm_load_si128(in1), _mm_load_si128(in2)));
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}
