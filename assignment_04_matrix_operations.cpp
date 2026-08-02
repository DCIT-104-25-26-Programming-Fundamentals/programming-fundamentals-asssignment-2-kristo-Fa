// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================



#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void readMatrix(int matrix[1], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[1], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[1], int result[1], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int A[1], int B[1], int result[1], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[1], int B[1], int result[1], int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[1], B[1], res[1];
    int r1, c1, r2, c2;

    cout << "--- PART A: Transpose ---" << endl;
    cout << "Enter number of rows: ";
    cin >> r1;
    cout << "Enter number of columns: ";
    cin >> c1;
    readMatrix(A, r1, c1);
    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(A, r1, c1);
    transposeMatrix(A, res, r1, c1);
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(res, c1, r1);

    cout << "\n--- PART B: Addition ---" << endl;
    cout << "Enter rows and columns for both matrices: ";
    cin >> r1 >> c1;
    cout << "Matrix 1:" << endl;
    readMatrix(A, r1, c1);
    cout << "Matrix 2:" << endl;
    readMatrix(B, r1, c1);
    addMatrices(A, B, res, r1, c1);
    cout << "\nSum of Matrices:" << endl;
    displayMatrix(res, r1, c1);

    cout << "\n--- PART C: Multiplication ---" << endl;
    cout << "Enter rows for Matrix A: ";
    cin >> r1;
    cout << "Enter columns for Matrix A (and rows for B): ";
    cin >> c1;
    cout << "Enter columns for Matrix B: ";
    cin >> c2;
    cout << "Matrix A:" << endl;
    readMatrix(A, r1, c1);
    cout << "Matrix B:" << endl;
    readMatrix(B, c1, c2);
    multiplyMatrices(A, B, res, r1, c1, c2);
    cout << "\nProduct of Matrices (A x B):" << endl;
    displayMatrix(res, r1, c2);

    return 0;
}
