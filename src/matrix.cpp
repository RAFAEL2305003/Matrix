#include "../include/matrix.h"
#include "../include/random.h"

/**
 * Usage example
 */
int main()
{
    Random<double> r(-1, 1);
    std::vector<int> inputs = {0, 0, 0, 1, 1, 0, 1, 1};
    Matrix<int> X(4, 2, inputs);
    X.print();

    std::vector<int> outputs = {0, 1, 1, 0};
    Matrix<int> Y(4, 1, outputs);
    Y.print();

    Matrix<double> W(2, 2);
    r.fillMatrixWithRand(W);
    W.print();

    return 0;
}