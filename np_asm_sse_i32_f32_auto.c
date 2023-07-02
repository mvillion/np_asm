// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// inst_i32_f32_str is the list of instruction names
#define N_INST_I32_F32 12

static const char *inst_i32_f32_str[N_INST_I32_F32] =
{
    "_mm_comieq_ss", 
    "_mm_comilt_ss", 
    "_mm_comile_ss", 
    "_mm_comigt_ss", 
    "_mm_comige_ss", 
    "_mm_comineq_ss", 
    "_mm_ucomieq_ss", 
    "_mm_ucomilt_ss", 
    "_mm_ucomile_ss", 
    "_mm_ucomigt_ss", 
    "_mm_ucomige_ss", 
    "_mm_ucomineq_ss", 
};

// n_in_i32_f32 is the number of inputs for each instruction
static const char n_in_i32_f32[N_INST_I32_F32] =
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
};

// create a function np_<op> for each instruction <op>
static void np_comieq_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_comieq_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_comilt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_comilt_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_comile_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_comile_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_comigt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_comigt_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_comige_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_comige_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_comineq_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_comineq_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_ucomieq_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_ucomieq_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_ucomilt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_ucomilt_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_ucomile_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_ucomile_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_ucomigt_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_ucomigt_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_ucomige_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_ucomige_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

static void np_ucomineq_ss(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_ucomineq_ss(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}

// fun_i32_f32 is the list of all npy_<op> functions
PyUFuncGenericFunction fun_i32_f32[N_INST_I32_F32][1] =
{
    {&np_comieq_ss},
    {&np_comilt_ss},
    {&np_comile_ss},
    {&np_comigt_ss},
    {&np_comige_ss},
    {&np_comineq_ss},
    {&np_ucomieq_ss},
    {&np_ucomilt_ss},
    {&np_ucomile_ss},
    {&np_ucomigt_ss},
    {&np_ucomige_ss},
    {&np_ucomineq_ss},
};

static char type_i32_f32[3] = {NPY_INT32, NPY_FLOAT, NPY_FLOAT};
