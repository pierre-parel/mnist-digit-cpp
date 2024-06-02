#pragma once
#include "Activation/activation.h"
#include <vector>

class Layer {
private:
public:
  int numNodesIn, numNodesOut;
  std::vector<double> weights, biases;

  std::vector<double> costGradientWeights;
  std::vector<double> costGradientBiases;

  std::vector<double> weightVelocities;
  std::vector<double> biasVelocities;

  Layer(int numNodesIn, int numNodesOut)
      : numNodesIn(numNodesIn), numNodesOut(numNodesOut) {}
  std::vector<double> calculateOutputs(std::vector<double> inputs);

  double getWeight(int nodeIn, int nodeOut);
};
