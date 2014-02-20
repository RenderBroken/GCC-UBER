/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler-times "vpcmpud\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\n^k\]*%k\[0-9\]" 1 } } */

#include <immintrin.h>

volatile __m512i x;
volatile __mmask16 m;

void extern
avx512f_test (void)
{
  m = _mm512_cmplt_epu32_mask (x, x);
}
