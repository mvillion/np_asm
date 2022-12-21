#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np

# ______________________________________________________________________________
# float operations with 1 or 2 input(s)
inst_list = [
    ("add_ps", 2, np.add),  # SSE
    ("add_ss", 2, None),
    ("div_ps", 2, np.divide),
    ("div_ss", 2, None),
    ("max_ps", 2, None),
    ("max_ss", 2, None),
    ("min_ps", 2, None),
    ("min_ss", 2, None),
    ("mul_ps", 2, np.multiply),
    ("mul_ss", 2, None),
    ("rcp_ps", 1, np.reciprocal),
    ("rcp_ss", 1, None),
    ("rsqrt_ps", 1, None),
    ("rsqrt_ss", 1, None),
    ("sqrt_ps", 1, np.sqrt),
    ("sqrt_ss", 1, None),
    ("sub_ps", 2, np.subtract),
    ("sub_ss", 2, None),
    ("cmpeq_ps", 2, lambda x, y: np.equal(x, y).astype(np.float32)),
    ("cmpeq_ss", 2, None),
    ("cmpge_ps", 2, lambda x, y: np.greater_equal(x, y).astype(np.float32)),
    ("cmpge_ss", 2, None),
    ("cmpgt_ps", 2, lambda x, y: np.greater(x, y).astype(np.float32)),
    ("cmpgt_ss", 2, None),
    ("cmple_ps", 2, lambda x, y: np.less_equal(x, y).astype(np.float32)),
    ("cmple_ss", 2, None),
    ("cmplt_ps", 2, lambda x, y: np.less(x, y).astype(np.float32)),
    ("cmplt_ss", 2, None),
    ("cmpord_ps", 2, None),
    ("cmpord_ss", 2, None),
    ("cmpunord_ps", 2, None),
    ("cmpunord_ss", 2, None),
    ("cmpneq_ps", 2, lambda x, y: np.not_equal(x, y).astype(np.float32)),
    ("cmpneq_ss", 2, None),
    ("cmpnge_ps", 2, None),
    ("cmpnge_ss", 2, None),
    ("cmpngt_ps", 2, None),
    ("cmpngt_ss", 2, None),
    ("cmpnle_ps", 2, None),
    ("cmpnle_ss", 2, None),
    ("cmpnlt_ps", 2, None),
    ("cmpnlt_ss", 2, None),
    ("andnot_ps", 2, None),
    ("and_ps", 2, None),
    ("or_ps", 2, None),
    ("xor_ps", 2, None),
    ("movehl_ps", 2, None),
    ("movelh_ps", 2, None),
    ("move_ss", 2, None),
    ("unpackhi_ps", 2, None),
    ("unpacklo_ps", 2, None),
    ("addsub_ps", 2, None),  # SSE3
    ("hadd_ps", 2, None),
    ("hsub_ps", 2, None),
    ("movehdup_ps", 1, None),
    ("moveldup_ps", 1, None),
]


def gen_c(file_name="np_asm_sse_f32_auto.c"):
    n_inst = len(inst_list)

    fid = open(file_name, "w")

    fid.write("""// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instf_str is the list of instruction names
#define N_INSTF %d

static const char *instf_str[N_INSTF] =
{""" % n_inst)
    fid.writelines(['''
    "_mm_%s", ''' % k[0] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// n_in_f is the number of inputs for each instruction
static const char n_in_f[N_INSTF] =
{""")
    fid.writelines(["""
    %d,""" % k[1] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// create a function np_<op> for each instruction <op>""")

    # note: use _mm_store_ps and _mm_load_ps
    # use _mm_storeu_ps and _mm_loadu_ps if alignment is an issue
    for inst_name, n_input, _ in inst_list:
        if n_input == 1:
            fun_str = """
static void np_%s(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *out = (float *)args[1];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm_store_ps(out, _mm_%s(_mm_load_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        out += size_ratio;
    }
}
""" % (inst_name, inst_name)
        else:
            fun_str = """
static void np_%s(
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
        _mm_store_ps(out, _mm_%s(_mm_load_ps(in1), _mm_load_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}
""" % (inst_name, inst_name)
        fid.write(fun_str)

    fid.write("""
// funf is the list of all npy_<op> functions
PyUFuncGenericFunction funf[N_INSTF][1] =
{""")
    fid.writelines(["""
    {&np_%s},""" % k[0] for k in inst_list])
    fid.write("""
};

static char typef[3] = {NPY_FLOAT, NPY_FLOAT, NPY_FLOAT};
""")
    fid.close()


if __name__ == "__main__":
    gen_c()
