#include "CShape.h"

Shape::Shape() {
    MC.mat[0][0] = 1.0;MC.mat[0][1] = 0.0;MC.mat[0][2] = 0.0;MC.mat[0][3] = 0.0;
    MC.mat[1][0] = 0.0;MC.mat[1][1] = 1.0;MC.mat[1][2] = 0.0;MC.mat[1][3] = 0.0;
    MC.mat[2][0] = 0.0;MC.mat[2][1] = 0.0;MC.mat[2][2] = 1.0;MC.mat[2][3] = 0.0;
    MC.mat[3][0] = 0.0;MC.mat[3][1] = 0.0;MC.mat[3][2] = 0.0;MC.mat[3][3] = 1.0;
    s = 1; 
}

void Shape::translate(double tx, double ty, double tz) {
    MC.translate(tx, ty, tz);
}

void Shape::rotate(double rx, double ry, double rz, double angle) {
    MC.rotate(rx, ry, rz, angle);
}

void Shape::rotate_mc(double rx, double ry, double rz, double angle) {

}

void Shape::transformNorm(GLfloat mcx, GLfloat mcy, GLfloat mcz, GLfloat &wcx, GLfloat &wcy, GLfloat &wcz)
{
        
        wcx = MC.mat[0][0]*mcx + MC.mat[0][1]*mcy + MC.mat[0][2]*mcz;// + MC.mat[0][3];
        wcy = MC.mat[1][0]*mcx + MC.mat[1][1]*mcy + MC.mat[1][2]*mcz;// + MC.mat[1][3];
        wcz = MC.mat[2][0]*mcx + MC.mat[2][1]*mcy + MC.mat[2][2]*mcz;// + MC.mat[2][3];

}

void Shape::getRef(double &x, double &y, double &z)
{
    x = MC.mat[0][3];
    y = MC.mat[1][3];
    z = MC.mat[2][3];
    
}

void Shape::rotate_origin(double rx, double ry, double rz, double angle) {
    Matrix* m = new Matrix();
    rotate(rx, ry, rz, angle);
    double v[4];
     v[0] = MC.mat[0][3];
     v[1] = MC.mat[1][3];
     v[2] = MC.mat[2][3];
     v[3] = MC.mat[3][3];
    m->multiply_vector(v);
    MC.mat[0][3] = v[0];
    MC.mat[1][3] = v[1];
    MC.mat[2][3] = v[2]; 
    MC.mat[3][3] = v[3];
    delete m;
}

void Shape::scale_change(double x) {
     s += x; 
} 

// CTM <- CTM * MC
void Shape::ctm_multiply() {
     GLfloat M[16];
     M[0] = MC.mat[0][0];
     M[1] = MC.mat[1][0];
     M[2] = MC.mat[2][0];
     M[3] = 0;
     M[4] = MC.mat[0][1];
     M[5] = MC.mat[1][1];
     M[6] = MC.mat[2][1];
     M[7] = 0;
     M[8] = MC.mat[0][2];
     M[9] = MC.mat[1][2];
     M[10] = MC.mat[2][2];
     M[11] = 0;
     M[12] = MC.mat[0][3];
     M[13] = MC.mat[1][3];
     M[14] = MC.mat[2][3];
     M[15] = 1;
     glMultMatrixf(M); 
} 

