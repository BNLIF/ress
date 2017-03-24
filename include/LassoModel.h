#ifndef __LASSOMODEL_H
#define __LASSOMODEL_H

#include "Model.h"


class LassoModel: public Model {
public:
    LassoModel(double lambda=1., int max_iter=100000);
    ~LassoModel();

    double lambda; // regularization parameter
    int max_iter; // maximum iteration

    void Fit();

private:
    double _soft_thresholding(double x, double lambda_);
};

#endif