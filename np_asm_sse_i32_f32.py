#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# ______________________________________________________________________________
# float operations with 1 or 2 input(s)
inst_list = [
    ("comieq_ss", 2, None),  # SSE
    ("comilt_ss", 2, None),
    ("comile_ss", 2, None),
    ("comigt_ss", 2, None),
    ("comige_ss", 2, None),
    ("comineq_ss", 2, None),
    ("ucomieq_ss", 2, None),
    ("ucomilt_ss", 2, None),
    ("ucomile_ss", 2, None),
    ("ucomigt_ss", 2, None),
    ("ucomige_ss", 2, None),
    ("ucomineq_ss", 2, None),
]


def gen_c(file_name="np_asm_sse_i32_f32_auto.c"):
    n_inst = len(inst_list)
    suffix = "_i32_f32"
    n_inst_name = "N_INST%s" % suffix.upper()

    fid = open(file_name, "w")

    fid.write("""// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// inst%s_str is the list of instruction names
#define %s %d

static const char *inst%s_str[%s] =
{""" % (suffix, n_inst_name, n_inst, suffix, n_inst_name))
    fid.writelines(['''
    "_mm_%s", ''' % k[0] for k in inst_list])
    fid.write("""
};""")

    fid.write("""

// n_in%s is the number of inputs for each instruction
static const char n_in%s[%s] =
{""" % (suffix, suffix, n_inst_name))
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
    int32_t *out = (int32_t *)args[1];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_%s(_mm_load_ps(in1));
        // END main ufunc computation
        in1 += size_ratio;
        out += 1;
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
    int32_t *out = (int32_t *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    // steps[k] == sizeof(float)
    npy_intp i = n/size_ratio;
    while (i > 0)
    {
        i--;
        // BEGIN main ufunc computation
        *out = _mm_%s(_mm_load_ps(in1), _mm_load_ps(in2));
        // END main ufunc computation
        in1 += size_ratio;
        in2 += size_ratio;
        out += 1;
    }
}
""" % (inst_name, inst_name)
        fid.write(fun_str)

    fid.write("""
// fun%s is the list of all npy_<op> functions
PyUFuncGenericFunction fun%s[%s][1] =
{""" % (suffix, suffix, n_inst_name))
    fid.writelines(["""
    {&np_%s},""" % k[0] for k in inst_list])
    fid.write("""
};

static char type%s[3] = {NPY_INT32, NPY_FLOAT, NPY_FLOAT};
""" % suffix)
    fid.close()


if __name__ == "__main__":
    gen_c()
