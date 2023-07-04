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

    data_type_dict = {"f32": np.float32, "f64": np.float64}
    inst_type_dict = {
        "sse_int": "_mm_", "sse_64": "_mm_",
        "avx_f32": "_mm256_", "avx_f64": "_mm256_"}

    for key, prefix in inst_type_dict.items():

        for data_type, dtype in data_type_dict.items():
            if data_type not in key:
                continue
            if data_type in ["int"]:
                data1 = rng.random((12, 8), dtype)
                # data1[0] = 0
                data2 = rng.random((12, 8), dtype)
            else:
                data1 = rng.random((12, 8), dtype)
                # data1[0] = 0
                data2 = rng.random((12, 8), dtype)

        module_name = "np_asm_%s" % key
        inst_list = getattr(import_module(module_name), "inst_list")

        for arg_out, name, arg_in, ref_fun in inst_list:
            print(name)
            n_in = len(arg_in)
            inst = prefix+name
            # if inst == "_mm_cmpge_ps":
            #     print("coucou")
            if ref_fun is None:
                continue
            fun = getattr(np_asm, inst)
            if n_in == 1:
                out = fun(data1)
                out_ref = ref_fun(data1)
            else:
                out = fun(data1, data2)
                out_ref = ref_fun(data1, data2)

            is_equal = np.array_equal(out, out_ref, equal_nan=True)
            if is_equal:
                print("%s: ok" % inst)
            else:
                print("%s: diff is %f" % (inst, (out-out_ref).std().mean()))

    # __________________________________________________________________________
    data = np.arange(12*16, dtype=np.int8).reshape(12, 16)

    out = np_asm._mm_add_epi8(data, data[:1, :])
    out_ref = data+data[:1, :]

    print("diff is %f" % (out-out_ref).std().mean())
