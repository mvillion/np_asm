// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instf_str is the list of instruction names
#define N_INSTF 56

static const char *instf_str[N_INSTF] =
{
    "add_ps", 
    "add_ss", 
    "div_ps", 
    "div_ss", 
    "max_ps", 
    "max_ss", 
    "min_ps", 
    "min_ss", 
    "mul_ps", 
    "mul_ss", 
    "rcp_ps", 
    "rcp_ss", 
    "rsqrt_ps", 
    "rsqrt_ss", 
    "sqrt_ps", 
    "sqrt_ss", 
    "sub_ps", 
    "sub_ss", 
    "cmpeq_ps", 
    "cmpeq_ss", 
    "cmpge_ps", 
    "cmpge_ss", 
    "cmpgt_ps", 
    "cmpgt_ss", 
    "cmple_ps", 
    "cmple_ss", 
    "cmplt_ps", 
    "cmplt_ss", 
    "cmpord_ps", 
    "cmpord_ss", 
    "cmpunord_ps", 
    "cmpunord_ss", 
    "cmpneq_ps", 
    "cmpneq_ss", 
    "cmpnge_ps", 
    "cmpnge_ss", 
    "cmpngt_ps", 
    "cmpngt_ss", 
    "cmpnle_ps", 
    "cmpnle_ss", 
    "cmpnlt_ps", 
    "cmpnlt_ss", 
    "andnot_ps", 
    "and_ps", 
    "or_ps", 
    "xor_ps", 
    "movehl_ps", 
    "movelh_ps", 
    "move_ss", 
    "unpackhi_ps", 
    "unpacklo_ps", 
    "addsub_ps", 
    "hadd_ps", 
    "hsub_ps", 
    "movehdup_ps", 
    "moveldup_ps", 
};

// n_in_f is the number of inputs for each instruction
static const char n_in_f[N_INSTF] =
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
    1,
    1,
    1,
    1,
    1,
    1,
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
    1,
};

// create a function np_<op> for each instruction <op>
static void np_add_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_add_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_add_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_add_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_div_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_div_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_div_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_div_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_max_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_max_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_max_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_max_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_min_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_min_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_min_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_min_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_mul_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_mul_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_mul_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_mul_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_rcp_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_rcp_ps(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_rcp_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_rcp_ss(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_rsqrt_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_rsqrt_ps(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_rsqrt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_rsqrt_ss(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_sqrt_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_sqrt_ps(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_sqrt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_sqrt_ss(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_sub_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_sub_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_sub_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_sub_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpeq_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpeq_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpeq_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpeq_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpge_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpge_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpge_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpge_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpgt_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpgt_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpgt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpgt_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmple_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmple_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmple_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmple_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmplt_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmplt_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmplt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmplt_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpord_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpord_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpord_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpord_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpunord_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpunord_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpunord_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpunord_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpneq_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpneq_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpneq_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpneq_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnge_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpnge_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnge_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpnge_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpngt_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpngt_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpngt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpngt_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnle_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpnle_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnle_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpnle_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnlt_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpnlt_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnlt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_cmpnlt_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_andnot_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_andnot_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_and_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_and_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_or_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_or_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_xor_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_xor_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_movehl_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_movehl_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_movelh_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_movelh_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_move_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_move_ss(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_unpackhi_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_unpackhi_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_unpacklo_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_unpacklo_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_addsub_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_addsub_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_hadd_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_hadd_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_hsub_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_hsub_ps(
            _mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_movehdup_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_movehdup_ps(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_moveldup_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_moveldup_ps(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

// funf is the list of all npy_<op> functions
PyUFuncGenericFunction funf[N_INSTF][1] =
{
    {&np_add_ps},
    {&np_add_ss},
    {&np_div_ps},
    {&np_div_ss},
    {&np_max_ps},
    {&np_max_ss},
    {&np_min_ps},
    {&np_min_ss},
    {&np_mul_ps},
    {&np_mul_ss},
    {&np_rcp_ps},
    {&np_rcp_ss},
    {&np_rsqrt_ps},
    {&np_rsqrt_ss},
    {&np_sqrt_ps},
    {&np_sqrt_ss},
    {&np_sub_ps},
    {&np_sub_ss},
    {&np_cmpeq_ps},
    {&np_cmpeq_ss},
    {&np_cmpge_ps},
    {&np_cmpge_ss},
    {&np_cmpgt_ps},
    {&np_cmpgt_ss},
    {&np_cmple_ps},
    {&np_cmple_ss},
    {&np_cmplt_ps},
    {&np_cmplt_ss},
    {&np_cmpord_ps},
    {&np_cmpord_ss},
    {&np_cmpunord_ps},
    {&np_cmpunord_ss},
    {&np_cmpneq_ps},
    {&np_cmpneq_ss},
    {&np_cmpnge_ps},
    {&np_cmpnge_ss},
    {&np_cmpngt_ps},
    {&np_cmpngt_ss},
    {&np_cmpnle_ps},
    {&np_cmpnle_ss},
    {&np_cmpnlt_ps},
    {&np_cmpnlt_ss},
    {&np_andnot_ps},
    {&np_and_ps},
    {&np_or_ps},
    {&np_xor_ps},
    {&np_movehl_ps},
    {&np_movelh_ps},
    {&np_move_ss},
    {&np_unpackhi_ps},
    {&np_unpacklo_ps},
    {&np_addsub_ps},
    {&np_hadd_ps},
    {&np_hsub_ps},
    {&np_movehdup_ps},
    {&np_moveldup_ps},
};

static char typef[3] = {NPY_FLOAT, NPY_FLOAT, NPY_FLOAT};
