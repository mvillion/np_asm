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
    sse_fun_t *fun)
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

void *failure(PyObject *type, const char *message)
{
    PyErr_SetString(type, message);
    return NULL;
}

#if 0
static PyObject *np_sse_like(
        PyObject *self, PyObject *arg, const sse1_fun_t *fun)
{
    PyArrayObject *arr_in1;

    if (!PyArg_ParseTuple(arg, "O!", &PyArray_Type, &arr_in1))
        return failure(PyExc_RuntimeError, "Failed to parse parameters.");

    uint64_t n_data1 = PyArray_SIZE(arr_in1)/sizeof(__m128i);

    // create output dimensions
    // last axis is removed, replaced by complex data i&q
    PyObject *arr_out = PyArray_NewLikeArray(arr_in, NPY_ANYORDER, NULL, 0);
    if (arr_out == NULL)
        return failure(PyExc_RuntimeError, "Failed to create output array.");

    __128i *out = (__128i *)PyArray_DATA(arr_out);
    for (uint64_t i_data = 0; i_data < n_data1; i_data++)
    {
        _mm_store_si128(out, fun());
        out++;
    }

    return arr_out;
}
#endif

static PyObject *np_sse_m128i(
        PyObject *self, PyObject *arg, sse1_fun_t *fun)
{
    PyArrayObject *arr_in1;

    if (!PyArg_ParseTuple(arg, "O!", &PyArray_Type, &arr_in1))
        return failure(PyExc_RuntimeError, "Failed to parse parameters.");

    // Ensure the input array is contiguous.
    // PyArray_GETCONTIGUOUS will increase the reference count.
    arr_in1 = PyArray_GETCONTIGUOUS(arr_in1);
    uint64_t n_data1 = PyArray_SIZE(arr_in1)/sizeof(__m128i);

    // create output dimensions
    // last axis is removed, replaced by complex data i&q
    PyObject *arr_out = PyArray_NewLikeArray(arr_in1, NPY_ANYORDER, NULL, 0);
    if (arr_out == NULL)
        return failure(PyExc_RuntimeError, "Failed to create output array.");

    __m128i *in1 = (__m128i *)PyArray_DATA(arr_in1);
    __m128i *out = (__m128i *)PyArray_DATA((PyArrayObject *)arr_out);
    for (uint64_t i_data = 0; i_data < n_data1; i_data++)
    {
        _mm_store_si128(out, fun(_mm_load_si128(in1)));
        in1++;
        out++;
    }

    // Decrease reference count
    Py_DECREF(arr_in1);
    return arr_out;
}

static PyObject *np_sse_m128i_m128i(
        PyObject *self, PyObject *arg, sse2_fun_t *fun)
{
    PyArrayObject *arr_in1;
    PyArrayObject *arr_in2;
    PyArrayObject *arr_like;

    if (!PyArg_ParseTuple(
            arg, "O!O!", &PyArray_Type, &arr_in1, &PyArray_Type, &arr_in2))
        return failure(PyExc_RuntimeError, "Failed to parse parameters.");

    // Ensure the input array is contiguous.
    // PyArray_GETCONTIGUOUS will increase the reference count.
    arr_in1 = PyArray_GETCONTIGUOUS(arr_in1);
    arr_in2 = PyArray_GETCONTIGUOUS(arr_in2);
    uint64_t n_data1 = PyArray_SIZE(arr_in1)/sizeof(__m128i);
    uint64_t n_data2 = PyArray_SIZE(arr_in2)/sizeof(__m128i);

    if (n_data1 != n_data2 && n_data1 != 1 && n_data2 != 1)
        return failure(PyExc_RuntimeError, "input dimensions mismatch.");

    if (n_data1 == 1)
        arr_like = arr_in2;
    else
        arr_like = arr_in1;

    // create output dimensions
    // last axis is removed, replaced by complex data i&q
    PyObject *arr_out = PyArray_NewLikeArray(arr_like, NPY_ANYORDER, NULL, 0);
    if (arr_out == NULL)
        return failure(PyExc_RuntimeError, "Failed to create output array.");

    __m128i *in1 = (__m128i *)PyArray_DATA(arr_in1);
    __m128i *in2 = (__m128i *)PyArray_DATA(arr_in2);
    __m128i *out = (__m128i *)PyArray_DATA((PyArrayObject *)arr_out);
    for (uint64_t i_data = 0; i_data < n_data2; i_data++)
    {
        _mm_store_si128(out, fun(_mm_load_si128(in1), _mm_load_si128(in2)));
        in1 += n_data1 != 1;
        in2 += n_data2 != 1;
        out++;
    }

    // Decrease reference count
    Py_DECREF(arr_in2);
    Py_DECREF(arr_in1);
    return arr_out;
}
