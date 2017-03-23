#include "LassoModel.h"

#include <Eigen/Dense>
using namespace Eigen;

#include <iostream>
using namespace std;

int main()
{
    std::srand((unsigned int) time(0));

    int N_CELL = 8;
    int N_ZERO = 3;

    // initialize C vector: NCELL cells with NZERO zeros. (true charge in each cell)
    VectorXd C = 50 * (VectorXd::Random(N_CELL)+VectorXd::Constant(N_CELL, 1));
    VectorXd r = N_CELL / 2 * (VectorXd::Random(N_ZERO)+VectorXd::Constant(N_ZERO, 1));
    for (int i=0; i<N_ZERO; i++) {
        C( int(r(i)) ) = 0;
    }

    // initialize G matrix: N_CELL-N_ZERO rows and N_CELL columns. (geometry matrix)
    MatrixXd G = MatrixXd::Zero(N_CELL-N_ZERO, N_CELL);
    for (int i=0; i<N_CELL-N_ZERO; i++) {
        VectorXd t = VectorXd::Random(N_CELL);
        for (int j=0; j<N_CELL; j++) {
            G(i, j) = int(t(j)+1);
        }
    }

    // W vector is the measured charge on wires.
    VectorXd W = G * C;

    // cout << W << endl << endl;
    // cout << G << endl << endl;
    // cout << C << endl << endl;

    LassoModel m;
    m.SetData(G, W);
    m.Fit();

    cout << "geometry matrix:" << endl;
    cout << m.X() << endl << endl;

    cout << "fitted charge of each cell:" << endl;
    cout << m.beta().transpose() << endl << endl;

    cout << "measured charge on each wire:" << endl;
    cout << m.y().transpose() << endl << endl;

    cout << "predicted charge on each wire:" << endl;
    cout << m.Predict().transpose() << endl;

    return 0;
}