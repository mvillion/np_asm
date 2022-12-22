// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instf256_str is the list of instruction names
#define N_INSTF256 13

static const char *instf256_str[N_INSTF256] =
{
    "_mm256_add_ps", 
    "_mm256_addsub_ps", 
    "_mm256_and_ps", 
    "_mm256_andnot_ps", 
    "_mm256_div_ps", 
    "_mm256_hadd_ps", 
    "_mm256_hsub_ps", 
    "_mm256_max_ps", 
    "_mm256_min_ps", 
    "_mm256_mul_ps", 
    "_mm256_or_ps", 
    "_mm256_sub_ps", 
    "_mm256_xor_ps", 
};

// n_in_f256 is the number of inputs for each instruction
static const char n_in_f256[N_INSTF256] =
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
};

// create a function np_<op> for each instruction <op>
static void np256_add_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_add_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_addsub_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_addsub_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_and_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_and_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_andnot_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_andnot_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_div_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_div_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_hadd_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_hadd_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_hsub_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_hsub_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_max_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_max_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_min_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_min_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_mul_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_mul_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_or_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_or_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_sub_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_sub_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

static void np256_xor_ps(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(
            out, _mm256_xor_ps(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}

// funf256 is the list of all npy_<op> functions
PyUFuncGenericFunction funf256[N_INSTF256][1] =
{
    {&np256_add_ps},
    {&np256_addsub_ps},
    {&np256_and_ps},
    {&np256_andnot_ps},
    {&np256_div_ps},
    {&np256_hadd_ps},
    {&np256_hsub_ps},
    {&np256_max_ps},
    {&np256_min_ps},
    {&np256_mul_ps},
    {&np256_or_ps},
    {&np256_sub_ps},
    {&np256_xor_ps},
};

// static char typef[3] = {NPY_FLOAT, NPY_FLOAT, NPY_FLOAT};
