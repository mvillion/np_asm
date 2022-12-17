#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np

from np_asm_directory import np_asm

if __name__ == "__main__":
    rng = np.random.Generator(np.random.SFC64())
    data = rng.random((12, 8), np.float32)

    out = np_asm.add_ps(data, data)
    out_ref = data+data

    print("diff is %f" % (out-out_ref).std().mean())
