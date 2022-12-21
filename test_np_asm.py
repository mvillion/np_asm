#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np
import sys

from np_asm_directory import np_asm

if __name__ == "__main__":
    rng = np.random.Generator(np.random.SFC64())
    data1 = rng.random((12, 8), np.float32)
    data2 = rng.random((12, 8), np.float32)

    if len(sys.argv) > 1:
        print("dummy exit")
        sys.exit()

    # test f32__________________________________________________________________
    from np_asm_sse_f32 import inst_list

    for inst_name, n_input, ref_fun in inst_list:
        if ref_fun is None:
            continue

        fun = getattr(np_asm, "_mm_"+inst_name)
        if n_input == 1:
            out = fun(data1)
            out_ref = ref_fun(data1)
        else:
            out = fun(data1, data2)
            out_ref = ref_fun(data1, data2)

        print("%s: diff is %f" % (inst_name, (out-out_ref).std().mean()))

    data = np.arange(12*16, dtype=np.int8).reshape(12, 16)

    out = np_asm._mm_add_epi8(data, data)
    out_ref = data+data

    print("diff is %f" % (out-out_ref).std().mean())
