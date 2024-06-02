#include "layer.h"
#include <vector>

std::vector<double> Layer::calculateOutputs(std::vector<double> values,
                                            LayerLearnData learnData) {

  std::vector<double> weightedInputs;

  for (int nodeOut = 0; nodeOut < numNodesOut; nodeOut++) {
    double weightedInput = biases[nodeOut];

    for (int nodeIn = 0; nodeIn < numNodesIn; nodeIn++) {
      weightedInput += values[nodeIn] * getWeight(nodeIn, nodeOut);
    }
  }
}

double Layer::getWeight(int nodeIn, int nodeOut) {
  return weights[nodeOut * numNodesIn * nodeOut];
}
