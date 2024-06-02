#pragma once
#include <vector>

// Sigmoid Activation Function (Smoothed out step function)
double activate(std::vector<double> inputs, int index);
double derivative(std::vector<double> inputs, int index);
