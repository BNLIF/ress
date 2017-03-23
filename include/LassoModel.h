#ifndef __LASSOMODEL_H
#define __LASSOMODEL_H

#include "Model.h"


class LassoModel: public Model {
public:
    LassoModel(double lambda=1., int max_iter=10000);
    ~LassoModel();

    double lambda; // regularization parameter
    int max_iter; // maximum iteration

};

#endif