#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np
import sys

from importlib import import_module
from np_asm_directory import np_asm

if __name__ == "__main__":
    rng = np.random.Generator(np.random.SFC64())
    if len(sys.argv) > 1:
        print("dummy exit")
        sys.exit()

    # test f32 w/ 128 bit instructions__________________________________________
    data1 = rng.random((12, 8), np.float32)
    data1[0] = 0
    data2 = rng.random((12, 8), np.float32)

    test_dict = {"sse": "_mm_", "avx": "_mm256_"}

    for key, prefix in test_dict.items():
        module_name = "np_asm_%s_f32" % key
        inst_list = getattr(import_module(module_name), "inst_list")

        for inst_name, n_input, ref_fun in inst_list:
            if ref_fun is None:
                continue

            inst = prefix+inst_name
            fun = getattr(np_asm, inst)
            if n_input == 1:
                out = fun(data1)
                out_ref = ref_fun(data1)
            else:
                out = fun(data1, data2)
                out_ref = ref_fun(data1, data2)

            print("%s: diff is %f" % (inst, (out-out_ref).std().mean()))

    # test f64 w/ 128 bit instructions__________________________________________
    data1 = rng.random((12, 8), np.float64)
    data2 = rng.random((12, 8), np.float64)

    from np_asm_sse_f64 import inst_list

    for inst_name, n_input, ref_fun in inst_list:
        if ref_fun is None:
            continue

        inst = "_mm_"+inst_name
        fun = getattr(np_asm, inst)
        if n_input == 1:
            out = fun(data1)
            out_ref = ref_fun(data1)
        else:
            out = fun(data1, data2)
            out_ref = ref_fun(data1, data2)

        print("%s: diff is %f" % (inst, (out-out_ref).std().mean()))

    data = np.arange(12*16, dtype=np.int8).reshape(12, 16)

    out = np_asm._mm_add_epi8(data, data)
    out_ref = data+data

    print("diff is %f" % (out-out_ref).std().mean())
