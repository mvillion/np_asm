// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instd256_str is the list of instruction names
#define N_INSTD256 17

static const char *instd256_str[N_INSTD256] =
{
    "_mm256_add_pd", 
    "_mm256_addsub_pd", 
    "_mm256_and_pd", 
    "_mm256_andnot_pd", 
    "_mm256_div_pd", 
    "_mm256_hadd_pd", 
    "_mm256_hsub_pd", 
    "_mm256_max_pd", 
    "_mm256_min_pd", 
    "_mm256_mul_pd", 
    "_mm256_or_pd", 
    "_mm256_sub_pd", 
    "_mm256_xor_pd", 
    "_mm256_movedup_pd", 
    "_mm256_sqrt_pd", 
    "_mm256_unpackhi_pd", 
    "_mm256_unpacklo_pd", 
};

// n_in_d256 is the number of inputs for each instruction
static const char n_in_d256[N_INSTD256] =
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
    1,
    1,
    2,
    2,
};

// create a function np_<op> for each instruction <op>
static void np256_add_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_add_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_addsub_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_addsub_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_and_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_and_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_andnot_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_andnot_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_div_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_div_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_hadd_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_hadd_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_hsub_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_hsub_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_max_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_max_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_min_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_min_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_mul_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_mul_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_or_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_or_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_sub_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_sub_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_xor_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_xor_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_movedup_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *out = (double *)args[1];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(out, _mm256_movedup_pd(_mm256_loadu_pd(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        out += size_ratio;
    }
}

static void np256_sqrt_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *out = (double *)args[1];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(out, _mm256_sqrt_pd(_mm256_loadu_pd(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        out += size_ratio;
    }
}

static void np256_unpackhi_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_unpackhi_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_unpacklo_pd(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    double *in1 = (double *)args[0];
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(double);
    // steps[k] == sizeof(double)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_pd(
            out, _mm256_unpacklo_pd(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

// fund256 is the list of all npy_<op> functions
PyUFuncGenericFunction fund256[N_INSTD256][1] =
{
    {&np256_add_pd},
    {&np256_addsub_pd},
    {&np256_and_pd},
    {&np256_andnot_pd},
    {&np256_div_pd},
    {&np256_hadd_pd},
    {&np256_hsub_pd},
    {&np256_max_pd},
    {&np256_min_pd},
    {&np256_mul_pd},
    {&np256_or_pd},
    {&np256_sub_pd},
    {&np256_xor_pd},
    {&np256_movedup_pd},
    {&np256_sqrt_pd},
    {&np256_unpackhi_pd},
    {&np256_unpacklo_pd},
};

// static char typed[3] = {NPY_double, NPY_double, NPY_double};
