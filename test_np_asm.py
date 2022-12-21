#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np

from np_asm_directory import np_asm

if __name__ == "__main__":
    # rng = np.random.Generator(np.random.SFC64())
    # data = rng.random((12, 8), np.float32)
    data = np.arange(12*16, dtype=np.int8).reshape(12, 16)

    out = np_asm._mm_add_epi8(data, data)
    out_ref = data+data

    print("diff is %f" % (out-out_ref).std().mean())
