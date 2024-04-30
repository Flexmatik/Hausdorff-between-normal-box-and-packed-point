#include <array>
#include <immintrin.h>

struct PackedPoint_cpp {
  std::array<double, 8> X;
  std::array<double, 8> Y;
};

struct
    NormalBox_cpp { // coordinates of the point in the first quarter
  double w;
  double h;
};
