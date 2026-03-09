#include "../include/matrix.h"
#include "../include/random.h"

int main (int argc, char *argv[]) {
    Random<double> r(-1, 1);

    std::size_t rows = 3;
    std::size_t cols = 3;

    Matrix<double> A(rows, cols);
    r.fillMatrix(A);

    Matrix<double> B(rows, cols);
    r.fillMatrix(B);

    Matrix<double> C(3, 3);
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

    return 0;
}
