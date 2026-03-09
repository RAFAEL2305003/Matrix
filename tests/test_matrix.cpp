#include "../include/matrix.h"
#include "../include/random.h"

int main (int argc, char *argv[]) {
    Random<double> r(-1, 1);

    Matrix<double> A(3, 3);
    r.fillMatrix(A);

    Matrix<double> B(3, 3);
    r.fillMatrix(B);

    // commutativity test
    assert(A + B == B + A);
    return 0;
}
