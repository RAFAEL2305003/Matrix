#include "../include/matrix.h"
#include "../include/random.h"

// TODO: Add Stress Tests

int main (int argc, char *argv[]) {
    Random<double> r(-1, 1);

    std::size_t rows = 3;
    std::size_t cols = 3;

    Matrix<double> A(rows, cols);
    r.fillMatrix(A);

    Matrix<double> B(cols, rows);
    r.fillMatrix(B);

    Matrix<double> C(rows, cols);
    r.fillMatrix(C);

    // Commutativity
    assert(A + B == B + A);
    assert(A + C == C + A);
    assert(B + C == C + B);

    Matrix<double> Z(rows, cols); // Matrix with all elements equals to 0

    // Identity element
    assert(A == A + Z);
    assert(B == B + Z);
    assert(C == C + Z);

    // Scalar multiplication
    assert(A * 0 == Z);
    assert(A * 1 == Z);
    assert(B * 0 == Z);
    assert(B * 1 == Z);
    assert(C * 0 == Z);
    assert(C * 1 == Z);

    Matrix<double> I = identity<double>(rows);

    // Multiply Matrices
    // Identity Matrix
    assert(hadamard(A, I) == A);
    assert(hadamard(I, A) == A);
    assert(hadamard(B, I) == B);
    assert(hadamard(I, B) == B);
    assert(hadamard(C, I) == C);
    assert(hadamard(I, C) == C);
    // Associativity
    assert(hadamard(A, hadamard(B, C)) == hadamard(hadamard(A, B), C));
    // Distributivity
    assert(hadamard(A, (B + C)) == (hadamard(A, B) + hadamard(A, C)));

    // Transpose properties
    // Double transpose
    assert(A.transpose().transpose() == A);
    assert(B.transpose().transpose() == B);
    assert(C.transpose().transpose() == C);
    // Transpose of product
    assert(hadamard(A, B).transpose() == hadamard(A.transpose(), B.transpose()));
    assert(hadamard(A, C).transpose() == hadamard(A.transpose(), C.transpose()));
    assert(hadamard(B, C).transpose() == hadamard(B.transpose(), C.transpose()));
    // Transpose of sum
    assert((A + B).transpose() == A.transpose() + B.transpose());
    assert((A + C).transpose() == A.transpose() + C.transpose());
    assert((B + C).transpose() == B.transpose() + C.transpose());

    rows = 5;
    cols = 2;
    std::size_t rows_ = 2;
    std::size_t cols_ = 6;

    Matrix<double> X(rows, cols);
    Matrix<double> Y(rows_, cols_);

    // Dimensions Test
    auto [rows__, cols__] = hadamard(X, Y).shape();
    assert(rows__ == rows && cols__ == cols_);
    

    return 0;
}
