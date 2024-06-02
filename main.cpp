#include "NeuralNetwork/nn.h"
#include "Utils/csv.h"
#include <eigen3/Eigen/Dense>
#include <iostream>

int main() {
  const int inputSize = 60000;
  const int hiddenSize = 5;
  const int outputSize = 10;

  std::vector<int> layer_sizes = {inputSize, hiddenSize, outputSize};
  NeuralNetwork nn(layer_sizes);

  VectorXd input(inputSize);

  std::vector<Image> images = csvToImage("./TrainingImages/mnist_train.csv", 2);

  for (auto &image : images) {
    image.printImage();
    std::cout << "\n\n";
  }
}
