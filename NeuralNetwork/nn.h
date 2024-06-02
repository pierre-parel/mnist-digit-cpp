#pragma once

#include "layer.h"
#include <eigen3/Eigen/Dense>
#include <tuple>
#include <vector>

using namespace Eigen;

class NeuralNetwork {
private:
  std::vector<MatrixXd> weights;
  std::vector<VectorXd> biases;

public:
  std::vector<Layer> layers;
  std::vector<int> layerSizes;
  NeuralNetwork(std::vector<int> layerSizes);
  int classify(std::vector<double> inputs);
  std::vector<double> calculateOutputs(std::vector<double> inputs);
  int maxValueIndex(std::vector<double> values);
  // TODO: COST
};

class LayerLearnData {
public:
  std::vector<double> inputs;
  std::vector<double> weightedInputs;
  std::vector<double> activations;
  std::vector<double> nodeValues;

  LayerLearnData(Layer layer);
};

class NetworkLearnData {
public:
  std::vector<LayerLearnData> layerData;

  NetworkLearnData(std::vector<Layer> layers);
};
