#include <array>
#include <immintrin.h>

struct PackedPoint_avx {
  __m512d x;
  __m512d y;
};

struct
    NormalBox_avx { // coordinates of the point in the first quarter
  double w;
  double h;
};
