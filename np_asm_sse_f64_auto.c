// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instd_str is the list of instruction names
#define N_INSTD 7

static const char *instd_str[N_INSTD] =
{
    "move_sd", 
    "unpackhi_pd", 
    "unpacklo_pd", 
    "addsub_pd", 
    "hadd_pd", 
    "hsub_pd", 
    "movedup_pd", 
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
        _mm_store_pd(out, _mm_move_sd(
            _mm_load_pd(in1), _mm_load_pd(in2)));
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
        _mm_store_pd(out, _mm_unpackhi_pd(
            _mm_load_pd(in1), _mm_load_pd(in2)));
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
        _mm_store_pd(out, _mm_unpacklo_pd(
            _mm_load_pd(in1), _mm_load_pd(in2)));
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
        _mm_store_pd(out, _mm_addsub_pd(
            _mm_load_pd(in1), _mm_load_pd(in2)));
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
        _mm_store_pd(out, _mm_hadd_pd(
            _mm_load_pd(in1), _mm_load_pd(in2)));
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
        _mm_store_pd(out, _mm_hsub_pd(
            _mm_load_pd(in1), _mm_load_pd(in2)));
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
    double *in2 = (double *)args[1];
    double *out = (double *)args[2];
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
        in2 += size_ratio;
        out += size_ratio;
    }
}

// fund is the list of all npy_<op> functions
PyUFuncGenericFunction fund[N_INSTD][1] =
{
    {&np_move_sd},
    {&np_unpackhi_pd},
    {&np_unpacklo_pd},
    {&np_addsub_pd},
    {&np_hadd_pd},
    {&np_hsub_pd},
    {&np_movedup_pd},
};

static char typed[3] = {NPY_DOUBLE, NPY_DOUBLE, NPY_DOUBLE};
