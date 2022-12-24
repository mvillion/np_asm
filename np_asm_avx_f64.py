#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np

from np_asm_sse_f64 import unpackhi_pd
from np_asm_sse_f64 import unpacklo_pd

# ______________________________________________________________________________
# double operations with 1 or 2 input(s)
inst_list = [
    ("add_pd", 2, np.add),  # AVX
    ("addsub_pd", 2, None),
    ("and_pd", 2, None),
    ("andnot_pd", 2, None),
    ("div_pd", 2, np.divide),
    ("hadd_pd", 2, None),
    ("hsub_pd", 2, None),
    ("max_pd", 2, np.maximum),
    ("min_pd", 2, np.minimum),
    ("mul_pd", 2, np.multiply),
    ("or_pd", 2, None),
    ("sub_pd", 2, np.subtract),
    ("xor_pd", 2, None),
    ("movedup_pd", 1, None),
    ("sqrt_pd", 1, np.sqrt),
    ("unpackhi_pd", 2, unpackhi_pd),
    ("unpacklo_pd", 2, unpacklo_pd),
]


def gen_c(file_name="np_asm_avx_f64_auto.c"):
    n_inst = len(inst_list)

    fid = open(file_name, "w")

    fid.write("""// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instd256_str is the list of instruction names
#define N_INSTD256 %d

static const char *instd256_str[N_INSTD256] =
{""" % n_inst)
    fid.writelines(['''
    "_mm256_%s", ''' % k[0] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// n_in_d256 is the number of inputs for each instruction
static const char n_in_d256[N_INSTD256] =
{""")
    fid.writelines(["""
    %d,""" % k[1] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// create a function np_<op> for each instruction <op>""")

    # note: use _mm256_store_pd and _mm256_load_pd
    # use _mm_storeu_pd and _mm_loadu_pd if alignment is an issue
    for inst_name, n_input, _ in inst_list:
        if n_input == 1:
            fun_str = """
static void np256_%s(
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
        _mm256_storeu_pd(out, _mm256_%s(_mm256_loadu_pd(in1)));
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
            out, _mm256_%s(_mm256_loadu_pd(in1), _mm256_loadu_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}
""" % (inst_name, inst_name)
        fid.write(fun_str)

    fid.write("""
// fund256 is the list of all npy_<op> functions
PyUFuncGenericFunction fund256[N_INSTD256][1] =
{""")
    fid.writelines(["""
    {&np256_%s},""" % k[0] for k in inst_list])
    fid.write("""
};

// static char typed[3] = {NPY_double, NPY_double, NPY_double};
""")
    fid.close()


if __name__ == "__main__":
    gen_c()
