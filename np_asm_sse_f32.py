#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# ______________________________________________________________________________
# float operation with 1 or 2 input(s)
instf_list = [
    ("add_ps", 2),
    ("add_ss", 2),
    ("div_ps", 2),
    ("div_ss", 2),
    ("max_ps", 2),
    ("max_ss", 2),
    ("min_ps", 2),
    ("min_ss", 2),
    ("mul_ps", 2),
    ("mul_ss", 2),
    ("rcp_ps", 1),
    ("rcp_ss", 1),
    ("rsqrt_ps", 1),
    ("rsqrt_ss", 1),
    ("sqrt_ps", 1),
    ("sqrt_ss", 1),
    ("sub_ps", 2),
    ("sub_ss", 2),
    ("cmpeq_ps", 2),
    ("cmpeq_ss", 2),
    ("cmpge_ps", 2),
    ("cmpge_ss", 2),
    ("cmpgt_ps", 2),
    ("cmpgt_ss", 2),
    ("cmple_ps", 2),
    ("cmple_ss", 2),
    ("cmplt_ps", 2),
    ("cmplt_ss", 2),
    ("cmpord_ps", 2),
    ("cmpord_ss", 2),
    ("cmpunord_ps", 2),
    ("cmpunord_ss", 2),
    ("cmpneq_ps", 2),
    ("cmpneq_ss", 2),
    ("cmpnge_ps", 2),
    ("cmpnge_ss", 2),
    ("cmpngt_ps", 2),
    ("cmpngt_ss", 2),
    ("cmpnle_ps", 2),
    ("cmpnle_ss", 2),
    ("cmpnlt_ps", 2),
    ("cmpnlt_ss", 2),
    ("andnot_ps", 2),
    ("and_ps", 2),
    ("or_ps", 2),
    ("xor_ps", 2),
    ("movehl_ps", 2),
    ("movelh_ps", 2),
    ("move_ss", 2),
    ("unpackhi_ps", 2),
    ("unpacklo_ps", 2),
]

n_instf = len(instf_list)

fid = open("np_asm_sse_f32_auto.c", "w")

fid.write(
    """// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// instf_str is the list of instruction names
#define N_INSTF %d

static const char *instf_str[N_INSTF] =
{
""" % n_instf)
fid.writelines([
    '''    "%s",
''' % k[0] for k in instf_list])
fid.write(
    """};
""")

fid.write(
    """
// n_in_f is the number of inputs for each instruction
static const char n_in_f[N_INSTF] =
{
""")
fid.writelines([
    """    %d,
""" % k[1] for k in instf_list])
fid.write(
    """};
""")

fid.write(
    """
// create a function np_<op> for each instruction <op>
""")

for inst_name, n_input in instf_list:
    fun_str = """static void np_%s(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
{
    npy_intp n = dimensions[0];
    float *in1 = (float *)args[0];
    float *in2 = (float *)args[1];
    float *out = (float *)args[2];
    int size_ratio = sizeof(__m128)/sizeof(float);
    npy_intp in1_step = steps[0]/size_ratio;
    npy_intp in2_step = steps[1]/size_ratio;
    npy_intp out_step = steps[2]/size_ratio;
    for (npy_intp i = 0; i < n/size_ratio; i++)
    {
        // BEGIN main ufunc computation
        _mm_storeu_ps(out, _mm_%s(""" % (inst_name, inst_name)
    if n_input == 1:
        fun_str += """
            _mm_loadu_ps(in1)));"""
    else:
        fun_str += """
            _mm_loadu_ps(in1), _mm_loadu_ps(in2)));"""
    fun_str += """
        // END main ufunc computation
        in1 += in1_step*size_ratio;
        in2 += in2_step*size_ratio;
        out += out_step*size_ratio;
    }
}

"""
    fid.write(fun_str)

fid.write(
    """
// funf is the list of all npy_<op> functions
PyUFuncGenericFunction funf[N_INSTF][1] =
{
""")
fid.writelines([
    """    {&np_%s},
""" % k[0] for k in instf_list])
fid.write(
    """};

static char typef[3] = {NPY_FLOAT, NPY_FLOAT, NPY_FLOAT};
""")
fid.close()
