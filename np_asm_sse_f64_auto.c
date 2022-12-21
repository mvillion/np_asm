// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instd_str is the list of instruction names
#define N_INSTD 49

static const char *instd_str[N_INSTD] =
{
    "_mm_move_sd", 
    "_mm_add_pd", 
    "_mm_add_sd", 
    "_mm_sub_pd", 
    "_mm_sub_sd", 
    "_mm_mul_pd", 
    "_mm_mul_sd", 
    "_mm_div_pd", 
    "_mm_div_sd", 
    "_mm_sqrt_pd", 
    "_mm_sqrt_sd", 
    "_mm_min_pd", 
    "_mm_min_sd", 
    "_mm_max_pd", 
    "_mm_max_sd", 
    "_mm_and_pd", 
    "_mm_andnot_pd", 
    "_mm_or_pd", 
    "_mm_xor_pd", 
    "_mm_cmpeq_pd", 
    "_mm_cmplt_pd", 
    "_mm_cmple_pd", 
    "_mm_cmpgt_pd", 
    "_mm_cmpge_pd", 
    "_mm_cmpneq_pd", 
    "_mm_cmpnlt_pd", 
    "_mm_cmpnle_pd", 
    "_mm_cmpngt_pd", 
    "_mm_cmpnge_pd", 
    "_mm_cmpord_pd", 
    "_mm_cmpunord_pd", 
    "_mm_cmpeq_sd", 
    "_mm_cmplt_sd", 
    "_mm_cmple_sd", 
    "_mm_cmpgt_sd", 
    "_mm_cmpge_sd", 
    "_mm_cmpneq_sd", 
    "_mm_cmpnlt_sd", 
    "_mm_cmpnle_sd", 
    "_mm_cmpngt_sd", 
    "_mm_cmpnge_sd", 
    "_mm_cmpord_sd", 
    "_mm_cmpunord_sd", 
    "_mm_unpackhi_pd", 
    "_mm_unpacklo_pd", 
    "_mm_addsub_pd", 
    "_mm_hadd_pd", 
    "_mm_hsub_pd", 
    "_mm_movedup_pd", 
};

// n_in_d is the number of inputs for each instruction
static const char n_in_d[N_INSTD] =
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
};

// create a function np_<op> for each instruction <op>
static void np_move_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_move_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_add_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_add_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_add_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_add_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_sub_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_sub_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_sub_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_sub_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_mul_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_mul_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_mul_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_mul_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_div_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_div_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_div_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_div_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_sqrt_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *out = (double *)args[1];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_sqrt_pd(_mm_load_pd(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        out += size_ratio;
    }
}

static void np_sqrt_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_sqrt_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_min_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_min_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_min_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_min_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_max_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_max_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_max_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_max_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_and_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_and_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_andnot_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_andnot_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_or_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_or_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_xor_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_xor_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpeq_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpeq_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmplt_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmplt_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmple_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmple_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpgt_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpgt_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpge_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpge_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpneq_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpneq_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnlt_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpnlt_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnle_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpnle_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpngt_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpngt_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnge_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpnge_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpord_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpord_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpunord_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpunord_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpeq_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpeq_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmplt_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmplt_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmple_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmple_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpgt_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpgt_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpge_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpge_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpneq_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpneq_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnlt_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpnlt_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnle_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpnle_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpngt_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpngt_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpnge_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpnge_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpord_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpord_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_cmpunord_sd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_cmpunord_sd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_unpackhi_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_unpackhi_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_unpacklo_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_unpacklo_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_addsub_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_addsub_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_hadd_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_hadd_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_hsub_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_hsub_pd(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np_movedup_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *out = (double *)args[1];
    int size_ratio = sizeof(__m128)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_pd(out, _mm_movedup_pd(_mm_load_pd(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        out += size_ratio;
    }
}

// fund is the list of all npy_<op> functions
PyUFuncGenericFunction fund[N_INSTD][1] =
{
    {&np_move_sd},
    {&np_add_pd},
    {&np_add_sd},
    {&np_sub_pd},
    {&np_sub_sd},
    {&np_mul_pd},
    {&np_mul_sd},
    {&np_div_pd},
    {&np_div_sd},
    {&np_sqrt_pd},
    {&np_sqrt_sd},
    {&np_min_pd},
    {&np_min_sd},
    {&np_max_pd},
    {&np_max_sd},
    {&np_and_pd},
    {&np_andnot_pd},
    {&np_or_pd},
    {&np_xor_pd},
    {&np_cmpeq_pd},
    {&np_cmplt_pd},
    {&np_cmple_pd},
    {&np_cmpgt_pd},
    {&np_cmpge_pd},
    {&np_cmpneq_pd},
    {&np_cmpnlt_pd},
    {&np_cmpnle_pd},
    {&np_cmpngt_pd},
    {&np_cmpnge_pd},
    {&np_cmpord_pd},
    {&np_cmpunord_pd},
    {&np_cmpeq_sd},
    {&np_cmplt_sd},
    {&np_cmple_sd},
    {&np_cmpgt_sd},
    {&np_cmpge_sd},
    {&np_cmpneq_sd},
    {&np_cmpnlt_sd},
    {&np_cmpnle_sd},
    {&np_cmpngt_sd},
    {&np_cmpnge_sd},
    {&np_cmpord_sd},
    {&np_cmpunord_sd},
    {&np_unpackhi_pd},
    {&np_unpacklo_pd},
    {&np_addsub_pd},
    {&np_hadd_pd},
    {&np_hsub_pd},
    {&np_movedup_pd},
};

static char typed[3] = {NPY_DOUBLE, NPY_DOUBLE, NPY_DOUBLE};
