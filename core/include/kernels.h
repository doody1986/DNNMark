// The MIT License (MIT)
// 
// Copyright (c) 2016 Northeastern University
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in 
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef CORE_INCLUDE_KERNELS_H_
#define CORE_INCLUDE_KERNELS_H_

#include <cuda_runtime.h>

#include "common.h"

namespace dnnmark {

void BCMProductForward(Complex *fft_w, Complex *fft_x, Complex *y,
                int n, int p, int q, int k);
void BCMProductBackwardWeight(Complex *fft_dy, Complex *fft_x, Complex *dw,
                int n, int p, int q, int k);
void BCMProductBackwardData(Complex *fft_dy, Complex *fft_w, Complex *dx,
                int n, int p, int q, int k);

void BCMSumForward(Real *x, Real *y,
            int n, int p, int q, int k);
void BCMSumForward(Complex *x, Complex *y,
            int n, int p, int q, int k);
void BCMSumBackwardWeight(Real *x, Real *y,
            int n, int p, int q, int k);
void BCMSumBackwardWeight(Complex *x, Complex *y,
            int n, int p, int q, int k);
void BCMSumBackwardData(Real *x, Real *y,
            int n, int p, int q, int k);
void BCMSumBackwardData(Complex *x, Complex *y,
            int n, int p, int q, int k);

void BCMProductForwardO1(Complex *fft_w, Complex *fft_x, Complex *y,
                int n, int p, int q, int k, int tb_size);
void BCMProductBackwardWeightO1(Complex *fft_dy, Complex *fft_x, Complex *dw,
                int n, int p, int q, int k, int tb_size);
void BCMProductBackwardDataO1(Complex *fft_dy, Complex *fft_w, Complex *dx,
                int n, int p, int q, int k, int tb_size);

void BCMProductForwardO2(Complex *fft_w, Complex *fft_x, Complex *y,
                int n, int p, int q, int k);
void BCMProductBackwardWeightO2(Complex *fft_dy, Complex *fft_x, Complex *dw,
                int n, int p, int q, int k);
void BCMProductBackwardDataO2(Complex *fft_dy, Complex *fft_w, Complex *dx,
                int n, int p, int q, int k);

void BCMSumBackwardWeightO2(Complex *x, Complex *y, int n, int p, int q, int k);
void BCMSumBackwardDataO2(Complex *x, Complex *y, int n, int p, int q, int k);

// For backward weights
void NPK2PNK(Complex *x, Complex *y, int n, int p, int k, int tb_size = 256);
void NQK2QNK(Complex *x, Complex *y, int n, int q, int k, int tb_size = 256);
// For backward data of O1
// For forward of O2
void PQK2QPK(Complex *x, Complex *y, int p, int q, int k, int tb_size = 256);

// Fused Kernels
void BCMForward(Complex *fft_w, Complex *fft_x, Complex *y,
                int n, int p, int q, int k);
void BCMBackwardWeight(Complex *fft_dy, Complex *fft_x, Complex *dw,
                int n, int p, int q, int k);
void BCMBackwardData(Complex *fft_dy, Complex *fft_w, Complex *dx,
                int n, int p, int q, int k);
}

#endif // CORE_INCLUDE_KERNELS_H_