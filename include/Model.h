#ifndef __MODEL_H
#define __MODEL_H

#include <Eigen/Dense>

class Model {
public:
    Model();
    virtual ~Model();

    Eigen::VectorXd& y() { return y_; }
    Eigen::MatrixXd& X() { return X_; }
    Eigen::VectorXd& beta() { return beta_; }

    void SetData(Eigen::MatrixXd& X, Eigen::VectorXd& y);
    virtual void Fit() {};
    Eigen::VectorXd Predict();

protected:
    // Fit: y = X * beta
    Eigen::VectorXd y_;
    Eigen::MatrixXd X_;
    Eigen::VectorXd beta_;
};

#endif