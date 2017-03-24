#include "LassoModel.h"

#include <Eigen/Dense>
using namespace Eigen;

#include <iostream>
using namespace std;

LassoModel::LassoModel(double lambda_, int max_iter_)
{
    lambda = lambda_;
    max_iter = max_iter_;
    // cout << "Model constructed" << endl;
}

LassoModel::~LassoModel()
{}



void LassoModel::Fit()
{
    // cooridate decsent
    for (int i=0; i<max_iter; i++) {
        for (int j=0; j<beta_.size(); j++) {
            VectorXd beta_tmp = beta_;
            beta_tmp(j) = 0.0;
            VectorXd r_j = (y_ - X_ * beta_tmp);
            double arg1 = X_.col(j).dot(r_j);
            // cout << arg1 << endl;
            double norm = X_.col(j).dot(X_.col(j));
            if ((norm-0.01)<0) {norm = 1;}
            beta_(j) = _soft_thresholding(arg1, lambda*y_.size()) / norm;
        }
    }

}

double LassoModel::_soft_thresholding(double x, double lambda_)
{
    if (x > 0 && lambda_ < fabs(x)) {
        return x - lambda_;
    }
    else if (x < 0 && lambda_ < fabs(x)) {
        return x + lambda_;
    }
    else {
        return 0;
    }
}