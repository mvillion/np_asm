#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np

from enum import auto
from enum import Enum


class _m(Enum):
    m128 = auto()
    m128d = auto()
    m128i = auto()


def unpackhi_ps(x, y):
    return np.column_stack((
        x.reshape(-1, 2, 2)[:, 1, :].reshape(-1),
        y.reshape(-1, 2, 2)[:, 1, :].reshape(-1))).reshape(x.shape)


def unpacklo_ps(x, y):
    return np.column_stack((
        x.reshape(-1, 2, 2)[:, 0, :].reshape(-1),
        y.reshape(-1, 2, 2)[:, 0, :].reshape(-1))).reshape(x.shape)


def sign2float(x):
    x = x.astype(np.uint32)
    x *= 0xffff_ffff
    return x.view(np.float32)


# ______________________________________________________________________________
# float operations with 1 or 2 input(s)
inst_list = [
    # float
    (_m.m128, "add_ps", (_m.m128, _m.m128), np.add),  # SSE
    (_m.m128, "add_ss", (_m.m128, _m.m128), None),
    (_m.m128, "div_ps", (_m.m128, _m.m128), np.divide),
    (_m.m128, "div_ss", (_m.m128, _m.m128), None),
    (_m.m128, "max_ps", (_m.m128, _m.m128), np.maximum),
    (_m.m128, "max_ss", (_m.m128, _m.m128), None),
    (_m.m128, "min_ps", (_m.m128, _m.m128), np.minimum),
    (_m.m128, "min_ss", (_m.m128, _m.m128), None),
    (_m.m128, "mul_ps", (_m.m128, _m.m128), np.multiply),
    (_m.m128, "mul_ss", (_m.m128, _m.m128), None),
    (_m.m128, "rcp_ps", (_m.m128,), np.reciprocal),
    (_m.m128, "rcp_ss", (_m.m128,), None),
    (_m.m128, "rsqrt_ps", (_m.m128,), lambda x: 1/np.sqrt(x)),
    (_m.m128, "rsqrt_ss", (_m.m128,), None),
    (_m.m128, "sqrt_ps", (_m.m128,), np.sqrt),
    (_m.m128, "sqrt_ss", (_m.m128,), None),
    (_m.m128, "sub_ps", (_m.m128, _m.m128), np.subtract),
    (_m.m128, "sub_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpeq_ps", (_m.m128, _m.m128), lambda x, y: sign2float(np.equal(x, y))),
    (_m.m128, "cmpeq_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpge_ps", (_m.m128, _m.m128), lambda x, y: sign2float(np.greater_equal(x, y))),
    (_m.m128, "cmpge_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpgt_ps", (_m.m128, _m.m128), lambda x, y: sign2float(np.greater(x, y))),
    (_m.m128, "cmpgt_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmple_ps", (_m.m128, _m.m128), lambda x, y: sign2float(np.less_equal(x, y))),
    (_m.m128, "cmple_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmplt_ps", (_m.m128, _m.m128), lambda x, y: sign2float(np.less(x, y))),
    (_m.m128, "cmplt_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpord_ps", (_m.m128, _m.m128), None),
    (_m.m128, "cmpord_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpunord_ps", (_m.m128, _m.m128), None),
    (_m.m128, "cmpunord_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpneq_ps", (_m.m128, _m.m128), lambda x, y: np.not_equal(x, y).astype(np.float32)),
    (_m.m128, "cmpneq_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpnge_ps", (_m.m128, _m.m128), None),
    (_m.m128, "cmpnge_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpngt_ps", (_m.m128, _m.m128), None),
    (_m.m128, "cmpngt_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpnle_ps", (_m.m128, _m.m128), None),
    (_m.m128, "cmpnle_ss", (_m.m128, _m.m128), None),
    (_m.m128, "cmpnlt_ps", (_m.m128, _m.m128), None),
    (_m.m128, "cmpnlt_ss", (_m.m128, _m.m128), None),
    (_m.m128, "andnot_ps", (_m.m128, _m.m128), None),
    (_m.m128, "and_ps", (_m.m128, _m.m128), None),
    (_m.m128, "or_ps", (_m.m128, _m.m128), None),
    (_m.m128, "xor_ps", (_m.m128, _m.m128), None),
    (_m.m128, "movehl_ps", (_m.m128, _m.m128), None),
    (_m.m128, "movelh_ps", (_m.m128, _m.m128), None),
    (_m.m128, "move_ss", (_m.m128, _m.m128), None),
    (_m.m128, "unpackhi_ps", (_m.m128, _m.m128), unpackhi_ps),
    (_m.m128, "unpacklo_ps", (_m.m128, _m.m128), unpacklo_ps),
    (_m.m128, "addsub_ps", (_m.m128, _m.m128), None),  # SSE3
    (_m.m128, "hadd_ps", (_m.m128, _m.m128), None),
    (_m.m128, "hsub_ps", (_m.m128, _m.m128), None),
    (_m.m128, "movehdup_ps", (_m.m128,), None),
    (_m.m128, "moveldup_ps", (_m.m128,), None),
    (_m.m128i, "move_epi64", (_m.m128i,), None),  # SSE2
    (_m.m128i, "packs_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "packs_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "packus_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "unpackhi_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "unpackhi_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "unpackhi_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "unpackhi_epi64", (_m.m128i, _m.m128i), None),
    (_m.m128i, "unpacklo_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "unpacklo_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "unpacklo_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "unpacklo_epi64", (_m.m128i, _m.m128i), None),
    (_m.m128i, "add_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "add_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "add_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "add_epi64", (_m.m128i, _m.m128i), None),
    (_m.m128i, "adds_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "adds_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "adds_epu8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "adds_epu16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sub_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sub_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sub_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sub_epi64", (_m.m128i, _m.m128i), None),
    (_m.m128i, "subs_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "subs_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "subs_epu8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "subs_epu16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "madd_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "mulhi_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "mullo_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "mul_epu32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sll_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sll_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sll_epi64", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sra_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sra_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "srl_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "srl_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "srl_epi64", (_m.m128i, _m.m128i), None),
    (_m.m128i, "and_si128", (_m.m128i, _m.m128i), None),
    (_m.m128i, "andnot_si128", (_m.m128i, _m.m128i), None),
    (_m.m128i, "or_si128", (_m.m128i, _m.m128i), None),
    (_m.m128i, "xor_si128", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmpeq_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmpeq_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmpeq_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmplt_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmplt_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmplt_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmpgt_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmpgt_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmpgt_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "max_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "max_epu8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "min_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "min_epu8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "mulhi_epu16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "avg_epu8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "avg_epu16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sad_epu8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "hadd_epi16", (_m.m128i, _m.m128i), None),  # SSSE3
    (_m.m128i, "hadd_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "hadds_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "hsub_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "hsub_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "hsubs_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "maddubs_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "mulhrs_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "shuffle_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sign_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sign_epi16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "sign_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "abs_epi8", (_m.m128i,), None),
    (_m.m128i, "abs_epi16", (_m.m128i,), None),
    (_m.m128i, "abs_epi32", (_m.m128i,), None),
    (_m.m128i, "cmpeq_epi64", (_m.m128i, _m.m128i), None),  # SSE4.1
    (_m.m128i, "min_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "max_epi8", (_m.m128i, _m.m128i), None),
    (_m.m128i, "min_epu16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "max_epu16", (_m.m128i, _m.m128i), None),
    (_m.m128i, "min_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "max_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "min_epu32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "max_epu32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "mullo_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "mul_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "minpos_epu16", (_m.m128i,), None),
    (_m.m128i, "cvtepi8_epi32", (_m.m128i,), None),
    (_m.m128i, "cvtepi16_epi32", (_m.m128i,), None),
    (_m.m128i, "cvtepi8_epi64", (_m.m128i,), None),
    (_m.m128i, "cvtepi32_epi64", (_m.m128i,), None),
    (_m.m128i, "cvtepi16_epi64", (_m.m128i,), None),
    (_m.m128i, "cvtepi8_epi16", (_m.m128i,), None),
    (_m.m128i, "cvtepu8_epi32", (_m.m128i,), None),
    (_m.m128i, "cvtepu16_epi32", (_m.m128i,), None),
    (_m.m128i, "cvtepu8_epi64", (_m.m128i,), None),
    (_m.m128i, "cvtepu32_epi64", (_m.m128i,), None),
    (_m.m128i, "cvtepu16_epi64", (_m.m128i,), None),
    (_m.m128i, "cvtepu8_epi16", (_m.m128i,), None),
    (_m.m128i, "packus_epi32", (_m.m128i, _m.m128i), None),
    (_m.m128i, "cmpgt_epi64", (_m.m128i, _m.m128i), None),
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
    for arg_out, name, arg_in, _ in inst_list:
        in_list = ["__%s in%d" % (v.name, k+1) for k, v in enumerate(arg_in)]
        in_str = ", ".join(in_list)
        n_in = len(arg_in)
        in_str2 = ", ".join(["in%d" % (k+1) for k in range(n_in)])
        if n_in == 0:
            in_str = "void"
        fid.write("""
static __%s inline _np_mm_%s(%s)
{
    return _mm_%s(%s);
}
""" % (arg_out.name, name, in_str, name, in_str2))

    fid.write("""
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
// sse_fun is the list of instruction w/ names and number of parameters
static const sse_fun_t sse_fun[N_INSTI] =
{""")

    for v in inst_list:
        _, name, arg_in, _ = v
        n_in = len(arg_in)
        url = "https://www.intel.com/content/www/us/en/docs/intrinsics-guide"
        doc_str = """Function with %d arg
Intel documentation: %s/index.html#text=_mm_%s""" % (n_in, url, name)
        tup = (n_in, name, n_in, name, doc_str.replace("\n", "\\n"))
        fid.write('''
    {.n_in=%d, .name="_mm_%s", .sse%d=_np_mm_%s, .doc="%s"},''' % tup)
    fid.write("""
};
#pragma GCC diagnostic pop
""")

    fid.write("""

// create a function np_<op> for each instruction <op>""")

    # note: use _mm_store_si128 and _mm_load_si128
    # use _mm_storeu_si128 and _mm_loadu_si128 if alignment is an issue
    for k, v in enumerate(inst_list):
        _, name, arg_in, _ = v
        n_in = len(arg_in)
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
        name = v[1]
        fid.write("""    {"_mm_%s", np_mm_%s, METH_VARARGS, sse_fun[%d].doc},
""" % (name, name, k))

    fid.write("""    {NULL, NULL, 0, NULL} // sentinel
};
""")
    fid.close()


if __name__ == "__main__":
    gen_c()
