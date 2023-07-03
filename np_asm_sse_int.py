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


def gen_c(file_name="np_asm_sse_int_auto.c"):
    n_inst = len(inst_list)

    fid = open(file_name, "w")

    fid.write("""// FILE AUTO-GENERATED FROM PYTHON CODE - DO NOT EDIT!
#define N_INSTI %d
""" % n_inst)
    fid.write("""
// _np are not really used as they are meant to be inlined
// They do exist to create symbols
""")

    # note: use _mm_store_si128 and _mm_load_si128
    # use _mm_storeu_si128 and _mm_loadu_si128 if alignment is an issue
    for name, n_in in inst_list:
        if n_in == 0:
            fid.write("""
static __m128i inline _np_mm_%s(void)
{
    return _mm_%s();
}
""" % (name, name))
        if n_in == 1:
            fid.write("""
static __m128i inline _np_mm_%s(__m128i in1)
{
    return _mm_%s(in1);
}
""" % (name, name))
        else:  # if n_in == 2:
            fid.write("""
static __m128i inline _np_mm_%s(__m128i in1, __m128i in2)
{
    return _mm_%s(in1, in2);
}
""" % (name, name))

    fid.write("""
// sse_fun is the list of instruction w/ names and number of parameters
static const sse_fun_t sse_fun[N_INSTI] =
{""")

    for k in inst_list:
        url = "https://www.intel.com/content/www/us/en/docs/intrinsics-guide"
        doc_str = """Function with %d arg
Intel documentation: %s/index.html#text=_mm_%s""" % (k[1], url, k[0])
        tup = (k[1], k[0], k[1], k[0], doc_str.replace("\n", "\\n"))
        fid.write('''
    {.n_in=%d, .name="_mm_%s", .sse%d=_np_mm_%s, .doc="%s"},''' % tup)
    fid.write("""
};""")

    fid.write("""

// create a function np_<op> for each instruction <op>""")

    # note: use _mm_store_si128 and _mm_load_si128
    # use _mm_storeu_si128 and _mm_loadu_si128 if alignment is an issue
    for k, v in enumerate(inst_list):
        name, n_in = v
        np_fun = ["like", "m128i", "m128i_m128i"][n_in]
        fid.write("""
static PyObject *np_mm_%s(PyObject* self, PyObject* arg)
{
    return np_sse_%s(self, arg, sse_fun[%d].sse%d);
}
""" % (name, np_fun, k, n_in))

    fid.write("""
static PyMethodDef np_sse_methods[] =
{
""")
    for k, v in enumerate(inst_list):
        fid.write("""    {"_mm_%s", np_mm_%s, METH_VARARGS, sse_fun[%d].doc},
""" % (v[0], v[0], k))

    fid.write("""    {NULL, NULL, 0, NULL} // sentinel
};
""")
    fid.close()


if __name__ == "__main__":
    gen_c()
