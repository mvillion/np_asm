#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# ______________________________________________________________________________
# double operations with 1 or 2 input(s)
inst_list = [
    ("move_sd", 2),  # SSE2
    ("unpackhi_pd", 2),
    ("unpacklo_pd", 2),
    ("addsub_pd", 2),  # SSE3
    ("hadd_pd", 2),
    ("hsub_pd", 2),
    ("movedup_pd", 1),
]

n_inst = len(inst_list)

fid = open("np_asm_sse_f64_auto.c", "w")

fid.write(
    """// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instd_str is the list of instruction names
#define N_INSTD %d

static const char *instd_str[N_INSTD] =
{""" % n_inst)
fid.writelines([
    '''
    "_mm_%s", ''' % k[0] for k in inst_list])
fid.write(
    """
};""")

fid.write(
    """

// n_in_d is the number of inputs for each instruction
static const char n_in_d[N_INSTD] =
{""")
fid.writelines([
    """
    %d,""" % k[1] for k in inst_list])
fid.write(
    """
};""")

fid.write(
    """

// create a function np_<op> for each instruction <op>""")

# note: use _mm_store_pd and _mm_load_pd
# use _mm_storeu_pd and _mm_loadu_pd if alignment is an issue
for inst_name, n_input in inst_list:
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
        _mm_store_pd(out, _mm_%s(""" % (inst_name, inst_name)
    if n_input == 1:
        fun_str += """_mm_load_pd(in1)));"""
    else:
        fun_str += """
            _mm_load_pd(in1), _mm_load_pd(in2)));"""
    fun_str += """
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += size_ratio;
    }
}
"""
    fid.write(fun_str)

fid.write(
    """
// fund is the list of all npy_<op> functions
PyUFuncGenericFunction fund[N_INSTD][1] =
{""")
fid.writelines([
    """
    {&np_%s},""" % k[0] for k in inst_list])
fid.write(
    """
};

static char typed[3] = {NPY_DOUBLE, NPY_DOUBLE, NPY_DOUBLE};
""")
fid.close()
