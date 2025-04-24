#include <iostream>
#include "Matrix.h"

int main() {
    Matrix m1(2, 2);
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);
    std::cout << "Matrix m1:\n";
    m1.print(std::cout);

    Matrix m2 = m1;
    std::cout << "\nCopied matrix m2:\n";
    m2.print(std::cout);

    std::cout << "\nElement m1[1][0] = " << m1.get(1, 0) << "\n";

    std::cout << "Rows: " << m1.getR() << ", Cols: " << m1.getC() << "\n";

    m1.multBy(2);
    std::cout << "\nm1 after multiplying by 2:\n";
    m1.print(std::cout);

    m1.addTo(m2);
    std::cout << "\nm1 after adding m2:\n";
    m1.print(std::cout);

    m1.transpose();
    std::cout << "\nm1 after transpose:\n";
    m1.print(std::cout);

    Matrix detTest(3);
    detTest.set(0, 0, 6); detTest.set(0, 1, 1); detTest.set(0, 2, 1);
    detTest.set(1, 0, 4); detTest.set(1, 1, -2); detTest.set(1, 2, 5);
    detTest.set(2, 0, 2); detTest.set(2, 1, 8); detTest.set(2, 2, 7);
    std::cout << "\nMatrix detTest:\n";
    detTest.print(std::cout);
    std::cout << "Determinant: " << detTest.det() << "\n";

    Matrix minorM = detTest.minor(0, 0);
    std::cout << "\nMinor of detTest at (0,0):\n";
    minorM.print(std::cout);

    Matrix rev = reverse(detTest);
    std::cout << "\nInverse of detTest:\n";
    rev.print(std::cout);

    Matrix A(2, 2);
    A.set(0, 0, 2); A.set(0, 1, 1);
    A.set(1, 0, 5); A.set(1, 1, 7);

    Matrix B(2, 1);
    B.set(0, 0, 11);
    B.set(1, 0, 13);

    Matrix X = solve(A, B);
    std::cout << "\nSolving A * X = B\nSolution X:\n";
    X.print(std::cout);

    Matrix m3(2, 2);
    m3.set(0, 0, 1); m3.set(0, 1, 0);
    m3.set(1, 0, 0); m3.set(1, 1, 1);

    Matrix added = add(m2, m3);
    Matrix subtracted = subtr(m2, m3);
    Matrix multiplied = mult(m2, m3);
    Matrix transposed = transpose(m3);

    std::cout << "\nAdded (m2 + m3):\n";
    added.print(std::cout);

    std::cout << "\nSubtracted (m2 - m3):\n";
    subtracted.print(std::cout);

    std::cout << "\nMultiplied (m2 * m3):\n";
    multiplied.print(std::cout);

    std::cout << "\nTransposed m3:\n";
    transposed.print(std::cout);

    return 0;
}
