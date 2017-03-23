#include "LassoModel.h"

LassoModel::LassoModel(double lambda_, int max_iter_)
{
    lambda = lambda_;
    max_iter = max_iter_;
    // cout << "Model constructed" << endl;
}

LassoModel::~LassoModel()
{}