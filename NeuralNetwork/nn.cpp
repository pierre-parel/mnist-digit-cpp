#include "nn.h"
#include "layer.h"
#include <algorithm>
#include <iterator>

NeuralNetwork::NeuralNetwork(std::vector<int> layerSizes)
    : layerSizes(layerSizes) {

  for (int i = 0; i < layerSizes.size() - 1; i++) {
    layers.push_back(Layer(layerSizes[i], layerSizes[i + 1]));
  }
  // TODO: cost = MeanSquaredError
}

int NeuralNetwork::maxValueIndex(std::vector<double> values) {
  return std::distance(values.begin(),
                       std::max_element(values.begin(), values.end()));
}

int NeuralNetwork::classify(std::vector<double> inputs) {
  std::vector<double> outputs = calculateOutputs(inputs);
  int predictedClass = maxValueIndex(outputs);
  return predictedClass;
}

std::vector<double>
NeuralNetwork::calculateOutputs(std::vector<double> inputs) {
  for (auto &layer : layers) {
    layer.calculateOutputs(inputs);
  }
  return inputs;
}

NetworkLearnData::NetworkLearnData(std::vector<Layer> layers) {
  for (int i = 0; i < layers.size(); i++) {
    layerData.push_back(LayerLearnData(layers[i]));
  }
}
