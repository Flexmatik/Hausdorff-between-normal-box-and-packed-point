#include "structures_cpp.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>

inline double SquaredDistance(double x0, double y0, double x1, double y1) {
  double squared = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
  return squared;
}

inline std::array<double, 8> Hausdorff_CPP(NormalBox_cpp box,
                                           PackedPoint_cpp pack) {
  std::array<double, 8> X;
  std::array<double, 8> Y;
  for (int i = 0; i < 8; i++) {
    X[i] = std::abs(pack.X[i]);
    Y[i] = std::abs(pack.Y[i]);
  }
  std::array<double, 8> result;
  for (int i = 0; i < 8; i++) {
    if (X[i] <= box.w && Y[i] <= box.h) {

      double a1 = SquaredDistance(X[i], Y[i], -box.w, box.h);
      double a2 = SquaredDistance(X[i], Y[i], -box.w, -box.h);
      double a3 = SquaredDistance(X[i], Y[i], box.w, -box.h);

      result[i] = (std::max(std::max(a1, a2), a3));
    } else if (X[i] <= box.w && Y[i] > box.h) {

      result[i] = (SquaredDistance(X[i], Y[i], -box.w, box.h));
    } else if (X[i] > box.w && Y[i] <= box.h) {

      result[i] = (SquaredDistance(X[i], Y[i], box.w, -box.h));
    } else {

      double a1 = SquaredDistance(X[i], Y[i], -box.w, box.h);
      double a2 = SquaredDistance(X[i], Y[i], box.w, -box.h);

      result[i] = (std::max(a1, a2));
    }
  }
  return result;
}
