#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <math.h>

using namespace std;

class Matrix {
    protected:
    double mat[4][4];   // this matrix is for MC

    public:
    Matrix();  // constructor
    void matrix_pre_multiply(Matrix* m);  // m*mat
    void transpose();  // mat'
    
    void translate(double, double, double);  // translate MC
    void rotate(double, double, double, double); // routate MC
    void multiply_vector(double*);  
    void normalize();  // this function is to normalize MC 
};

#endif
