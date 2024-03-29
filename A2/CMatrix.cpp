#include "CMatrix.h"

// construct an identity matrix as mat
Matrix::Matrix() {    
    for( int i = 0; i < 4; i++ ) {
        for( int j = 0; j < 4; j++ ) {
            if( i == j )
                this->mat[i][j] = 1;
            else
                this->mat[i][j] = 0;
        }
    }
}

// multiplication  mat <- m * mat
void Matrix::matrix_pre_multiply(Matrix* m) {
    Matrix* temp = new Matrix();    
    for( int i = 0; i < 4; i++ ) {
        for( int j = 0; j < 4; j++ ) {
            double sum = 0;
            for( int k = 0; k < 4; k++ ) {    
                sum += m->mat[i][k] * this->mat[k][j];
            } 
            temp->mat[i][j] = sum;
        }
    }
    for( int i = 0; i < 4; i++ ) {
        for( int j = 0; j < 4; j++ ) {
            this->mat[i][j] = temp->mat[i][j];
        }
    }
    delete temp;
}

// translate the origin of MC
void Matrix::translate(double tx, double ty, double tz) {
    this->mat[0][3] += tx;
    this->mat[1][3] += ty;
    this->mat[2][3] += tz;
    this->mat[3][3] = 1;
}

void Matrix::transpose() {
}
// normalize MC
void Matrix::normalize() {
}

// v  <- mat * v
void Matrix::multiply_vector(double* v) {

}

// MC <= rotation matrix * MC, i.e., rotate cordinate vectors and the origin 
void Matrix::rotate(double x, double y, double z, double angle) { 
     angle = angle * 3.1415926/180;
    float oneC = 1 - cos(angle);
    float COS = cos(angle);
    float SIN = sin(angle);

    Matrix* m = new Matrix();

    m->mat[0][0] = x * x * oneC + cos( angle );
    m->mat[0][1] = y * x * oneC + z * sin( angle );
    m->mat[0][2] = x * z * oneC - y * SIN;
    m->mat[0][3] = 0;
    m->mat[1][0] = x * y * oneC - z * SIN;
    m->mat[1][1] = y * y * oneC + COS;
    m->mat[1][2] = y * z * oneC + x * SIN;
    m->mat[1][3] = 0;
    m->mat[2][0] = x * z * oneC + y * SIN;
    m->mat[2][1] = y * z * oneC - x * SIN;
    m->mat[2][2] = z * z * oneC + COS;
    m->mat[2][3] = 0;
    m->mat[3][0] = 0;
    m->mat[3][1] = 0;
    m->mat[3][2] = 0;
    m->mat[3][3] = 1;
   
    this->matrix_pre_multiply(m);
    delete m;
}



