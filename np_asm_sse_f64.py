#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np

# ______________________________________________________________________________
# double operations with 1 or 2 input(s)
inst_list = [
    ("move_sd", 2, None),  # SSE2
    ("add_pd", 2, np.add),
    ("add_sd", 2, None),
    ("sub_pd", 2, np.subtract),
    ("sub_sd", 2, None),
    ("mul_pd", 2, np.multiply),
    ("mul_sd", 2, None),
    ("div_pd", 2, np.divide),
    ("div_sd", 2, None),
    ("sqrt_pd", 1, np.sqrt),
    ("sqrt_sd", 2, None),
    ("min_pd", 2, None),
    ("min_sd", 2, None),
    ("max_pd", 2, None),
    ("max_sd", 2, None),
    ("and_pd", 2, None),
    ("andnot_pd", 2, None),
    ("or_pd", 2, None),
    ("xor_pd", 2, None),
    ("cmpeq_pd", 2, lambda x, y: np.equal(x, y).astype(np.float64)),
    ("cmplt_pd", 2, None),
    ("cmple_pd", 2, None),
    ("cmpgt_pd", 2, None),
    ("cmpge_pd", 2, None),
    ("cmpneq_pd", 2, None),
    ("cmpnlt_pd", 2, None),
    ("cmpnle_pd", 2, None),
    ("cmpngt_pd", 2, None),
    ("cmpnge_pd", 2, None),
    ("cmpord_pd", 2, None),
    ("cmpunord_pd", 2, None),
    ("cmpeq_sd", 2, None),
    ("cmplt_sd", 2, None),
    ("cmple_sd", 2, None),
    ("cmpgt_sd", 2, None),
    ("cmpge_sd", 2, None),
    ("cmpneq_sd", 2, None),
    ("cmpnlt_sd", 2, None),
    ("cmpnle_sd", 2, None),
    ("cmpngt_sd", 2, None),
    ("cmpnge_sd", 2, None),
    ("cmpord_sd", 2, None),
    ("cmpunord_sd", 2, None),
    ("unpackhi_pd", 2, None),
    ("unpacklo_pd", 2, None),
    ("addsub_pd", 2, None),  # SSE3
    ("hadd_pd", 2, None),
    ("hsub_pd", 2, None),
    ("movedup_pd", 1, None),
]


def gen_c(file_name="np_asm_sse_f64_auto.c"):
    n_inst = len(inst_list)

    fid = open(file_name, "w")

    fid.write("""// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instd_str is the list of instruction names
#define N_INSTD %d

static const char *instd_str[N_INSTD] =
{""" % n_inst)
    fid.writelines(['''
    "_mm_%s", ''' % k[0] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// n_in_d is the number of inputs for each instruction
static const char n_in_d[N_INSTD] =
{""")
    fid.writelines(["""
    %d,""" % k[1] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// create a function np_<op> for each instruction <op>""")

    # note: use _mm_store_pd and _mm_load_pd
    # use _mm_storeu_pd and _mm_loadu_pd if alignment is an issue
    for inst_name, n_input, _ in inst_list:
        if n_input == 1:
            fun_str = """
static void np_%s(
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
        _mm_store_pd(out, _mm_%s(_mm_load_pd(in1)));
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
        _mm_store_pd(out, _mm_%s(_mm_load_pd(in1), _mm_load_pd(in2)));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}
""" % (inst_name, inst_name)
        fid.write(fun_str)

    fid.write("""
// fund is the list of all npy_<op> functions
PyUFuncGenericFunction fund[N_INSTD][1] =
{""")
    fid.writelines(["""
    {&np_%s},""" % k[0] for k in inst_list])
    fid.write("""
};

static char typed[3] = {NPY_DOUBLE, NPY_DOUBLE, NPY_DOUBLE};
""")
    fid.close()


if __name__ == "__main__":
    gen_c()
