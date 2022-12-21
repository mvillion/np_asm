#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# ______________________________________________________________________________
# double operations with 1 or 2 input(s)
inst_list = [
    ("move_sd", 2),  # SSE2
    ("add_pd", 2),
    ("add_sd", 2),
    ("sub_pd", 2),
    ("sub_sd", 2),
    ("mul_pd", 2),
    ("mul_sd", 2),
    ("div_pd", 2),
    ("div_sd", 2),
    ("sqrt_pd", 1),
    ("sqrt_sd", 2),
    ("min_pd", 2),
    ("min_sd", 2),
    ("max_pd", 2),
    ("max_sd", 2),
    ("and_pd", 2),
    ("andnot_pd", 2),
    ("or_pd", 2),
    ("xor_pd", 2),
    ("cmpeq_pd", 2),
    ("cmplt_pd", 2),
    ("cmple_pd", 2),
    ("cmpgt_pd", 2),
    ("cmpge_pd", 2),
    ("cmpneq_pd", 2),
    ("cmpnlt_pd", 2),
    ("cmpnle_pd", 2),
    ("cmpngt_pd", 2),
    ("cmpnge_pd", 2),
    ("cmpord_pd", 2),
    ("cmpunord_pd", 2),
    ("cmpeq_sd", 2),
    ("cmplt_sd", 2),
    ("cmple_sd", 2),
    ("cmpgt_sd", 2),
    ("cmpge_sd", 2),
    ("cmpneq_sd", 2),
    ("cmpnlt_sd", 2),
    ("cmpnle_sd", 2),
    ("cmpngt_sd", 2),
    ("cmpnge_sd", 2),
    ("cmpord_sd", 2),
    ("cmpunord_sd", 2),
    ("unpackhi_pd", 2),
    ("unpacklo_pd", 2),
    ("addsub_pd", 2),  # SSE3
    ("hadd_pd", 2),
    ("hsub_pd", 2),
    ("movedup_pd", 1),
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
    for inst_name, n_input in inst_list:
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
