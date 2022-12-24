#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np

from np_asm_sse_f32 import unpackhi_ps
from np_asm_sse_f32 import unpacklo_ps

# ______________________________________________________________________________
# float operations with 1 or 2 input(s)
inst_list = [
    ("add_ps", 2, np.add),  # AVX
    ("addsub_ps", 2, None),
    ("and_ps", 2, None),
    ("andnot_ps", 2, None),
    ("div_ps", 2, np.divide),
    ("hadd_ps", 2, None),
    ("hsub_ps", 2, None),
    ("max_ps", 2, np.maximum),
    ("min_ps", 2, np.minimum),
    ("mul_ps", 2, np.multiply),
    ("or_ps", 2, None),
    ("sub_ps", 2, np.subtract),
    ("xor_ps", 2, None),
    ("movehdup_ps", 1, None),
    ("moveldup_ps", 1, None),
    ("rcp_ps", 1, np.reciprocal),
    ("rsqrt_ps", 1, lambda x: np.reciprocal(np.sqrt(x))),
    ("sqrt_ps", 1, np.sqrt),
    ("unpackhi_ps", 2, unpackhi_ps),
    ("unpacklo_ps", 2, unpacklo_ps),
]


def gen_c(file_name="np_asm_avx_f32_auto.c"):
    n_inst = len(inst_list)

    fid = open(file_name, "w")

    fid.write("""// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instf256_str is the list of instruction names
#define N_INSTF256 %d

static const char *instf256_str[N_INSTF256] =
{""" % n_inst)
    fid.writelines(['''
    "_mm256_%s", ''' % k[0] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// n_in_f256 is the number of inputs for each instruction
static const char n_in_f256[N_INSTF256] =
{""")
    fid.writelines(["""
    %d,""" % k[1] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// create a function np_<op> for each instruction <op>""")

    # note: use _mm256_store_ps and _mm256_load_ps
    # use _mm_storeu_ps and _mm_loadu_ps if alignment is an issue
    for inst_name, n_input, _ in inst_list:
        if n_input == 1:
            fun_str = """
static void np256_%s(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *out = (float *)args[1];
    int size_ratio = sizeof(__m256)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        _mm256_storeu_ps(out, _mm256_%s(_mm256_loadu_ps(in1)));
        // END main ufunc computation
        in1 += size_ratio;
        out += size_ratio;
    }
}
""" % (inst_name, inst_name)
        else:
            fun_str = """
static void np256_%s(
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
            out, _mm256_%s(_mm256_loadu_ps(in1), _mm256_loadu_ps(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}
""" % (inst_name, inst_name)
        fid.write(fun_str)

    fid.write("""
// funf256 is the list of all npy_<op> functions
PyUFuncGenericFunction funf256[N_INSTF256][1] =
{""")
    fid.writelines(["""
    {&np256_%s},""" % k[0] for k in inst_list])
    fid.write("""
};

// static char typef[3] = {NPY_FLOAT, NPY_FLOAT, NPY_FLOAT};
""")
    fid.close()


if __name__ == "__main__":
    gen_c()
