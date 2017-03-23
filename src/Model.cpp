#include "Model.h"

#include <Eigen/Dense>
using namespace Eigen;

#include <iostream>
using namespace std;

Model::Model()
{}

Model::~Model()
{}

void Model::SetData(Eigen::MatrixXd& X, Eigen::VectorXd& y)
{
    X_ = X;
    y_ = y;
    beta_ = VectorXd::Zero(X_.cols()); // initialize solution to zero.
}

void Model::Fit()
{
    // dummy. implementation in child classes.
}

VectorXd Model::Predict()
{
    return X_ * beta_;
}
