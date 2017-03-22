#include "Model.h"

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
    VectorXi ri = r.cast<int>();
    for (int i=0; i<N_ZERO; i++) {
        C( r(i) ) = 0;
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

    cout << C << endl << endl;
    cout << G << endl << endl;
    cout << W << endl << endl;

    Model a;

    return 0;
}