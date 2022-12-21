#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# ______________________________________________________________________________
# float operations with 1 or 2 input(s)
inst_list = [
    ("move_epi64", 1),  # SSE2
    ("packs_epi16", 2),
    ("packs_epi32", 2),
    ("packus_epi16", 2),
    ("unpackhi_epi8", 2),
    ("unpackhi_epi16", 2),
    ("unpackhi_epi32", 2),
    ("unpackhi_epi64", 2),
    ("unpacklo_epi8", 2),
    ("unpacklo_epi16", 2),
    ("unpacklo_epi32", 2),
    ("unpacklo_epi64", 2),
    ("add_epi8", 2),
    ("add_epi16", 2),
    ("add_epi32", 2),
    ("add_epi64", 2),
    ("adds_epi8", 2),
    ("adds_epi16", 2),
    ("adds_epu8", 2),
    ("adds_epu16", 2),
    ("sub_epi8", 2),
    ("sub_epi16", 2),
    ("sub_epi32", 2),
    ("sub_epi64", 2),
    ("subs_epi8", 2),
    ("subs_epi16", 2),
    ("subs_epu8", 2),
    ("subs_epu16", 2),
    ("madd_epi16", 2),
    ("mulhi_epi16", 2),
    ("mullo_epi16", 2),
    ("mul_epu32", 2),
    ("sll_epi16", 2),
    ("sll_epi32", 2),
    ("sll_epi64", 2),
    ("sra_epi16", 2),
    ("sra_epi32", 2),
    ("srl_epi16", 2),
    ("srl_epi32", 2),
    ("srl_epi64", 2),
    ("and_si128", 2),
    ("andnot_si128", 2),
    ("or_si128", 2),
    ("xor_si128", 2),
    ("cmpeq_epi8", 2),
    ("cmpeq_epi16", 2),
    ("cmpeq_epi32", 2),
    ("cmplt_epi8", 2),
    ("cmplt_epi16", 2),
    ("cmplt_epi32", 2),
    ("cmpgt_epi8", 2),
    ("cmpgt_epi16", 2),
    ("cmpgt_epi32", 2),
    ("max_epi16", 2),
    ("max_epu8", 2),
    ("min_epi16", 2),
    ("min_epu8", 2),
    ("mulhi_epu16", 2),
    ("avg_epu8", 2),
    ("avg_epu16", 2),
    ("sad_epu8", 2),
    ("hadd_epi16", 2),  # SSSE3
    ("hadd_epi32", 2),
    ("hadds_epi16", 2),
    ("hsub_epi16", 2),
    ("hsub_epi32", 2),
    ("hsubs_epi16", 2),
    ("maddubs_epi16", 2),
    ("mulhrs_epi16", 2),
    ("shuffle_epi8", 2),
    ("sign_epi8", 2),
    ("sign_epi16", 2),
    ("sign_epi32", 2),
    ("abs_epi8", 1),
    ("abs_epi16", 1),
    ("abs_epi32", 1),
    ("cmpeq_epi64", 2),  # SSE4.1
    ("min_epi8", 2),
    ("max_epi8", 2),
    ("min_epu16", 2),
    ("max_epu16", 2),
    ("min_epi32", 2),
    ("max_epi32", 2),
    ("min_epu32", 2),
    ("max_epu32", 2),
    ("mullo_epi32", 2),
    ("mul_epi32", 2),
    ("minpos_epu16", 1),
    ("cvtepi8_epi32", 1),
    ("cvtepi16_epi32", 1),
    ("cvtepi8_epi64", 1),
    ("cvtepi32_epi64", 1),
    ("cvtepi16_epi64", 1),
    ("cvtepi8_epi16", 1),
    ("cvtepu8_epi32", 1),
    ("cvtepu16_epi32", 1),
    ("cvtepu8_epi64", 1),
    ("cvtepu32_epi64", 1),
    ("cvtepu16_epi64", 1),
    ("cvtepu8_epi16", 1),
    ("packus_epi32", 2),
    ("cmpgt_epi64", 2),
]

n_inst = len(inst_list)

fid = open("np_asm_sse_int_auto.c", "w")

fid.write(
    """// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
// insti_str is the list of instruction names
#define N_INSTI %d

static const char *insti_str[N_INSTI] =
{""" % n_inst)
fid.writelines([
    '''
    "_mm_%s", ''' % k[0] for k in inst_list])
fid.write(
    """
};""")

fid.write(
    """

// n_in_i is the number of inputs for each instruction
static const char n_in_i[N_INSTI] =
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

# note: use _mm_store_si128 and _mm_load_si128
# use _mm_storeu_si128 and _mm_loadu_si128 if alignment is an issue
for inst_name, n_input in inst_list:
    fun_str = """
static void np_%s(
    char **args, const npy_intp *dimensions, const npy_intp *steps, void *data)
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
        // BEGIN main ufunc computation
        _mm_store_si128(out, _mm_%s(""" % (inst_name, inst_name)
    if n_input == 1:
        fun_str += """_mm_load_si128(in1)));"""
    else:
        fun_str += """
            _mm_load_si128(in1), _mm_load_si128(in2)));"""
    fun_str += """
        // END main ufunc computation
        in1 += 1;
        in2 += 1;
        out += 1;
    }
}
"""
    fid.write(fun_str)

fid.write(
    """
// funf is the list of all npy_<op> functions
PyUFuncGenericFunction funi[N_INSTI][4] =
{""")
fid.writelines([
    """
    {&np_%s, &np_%s, &np_%s, &np_%s},""" % ((k[0],)*4) for k in inst_list])
fid.write(
    """
};

static char typei[3*4] =
{
    NPY_INT8, NPY_INT8, NPY_INT8,
    NPY_INT16, NPY_INT16, NPY_INT16,
    NPY_INT32, NPY_INT32, NPY_INT32,
    NPY_INT64, NPY_INT64, NPY_INT64,
};
""")
fid.close()
