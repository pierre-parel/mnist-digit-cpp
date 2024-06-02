#include "activation.h"
#include <cmath>

// Sigmoid Activation
double activate(std::vector<double> inputs, int index) {
  return 1.0 / (1 + std::exp(-inputs[index]));
}

double derivative(std::vector<double> inputs, int index) {
  double a = activate(inputs, index);
  return a * (1 - a);
}
