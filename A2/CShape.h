#ifndef CSHAPE_H
#define CSHAPE_H

#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "CMatrix.h"

using namespace std;

// the common class that will be inherited model object class
class Shape {
    private:
    //the Model coordinate system in (X, Y, Z, 0)        
    Matrix MC;
    // scale factor   
    double s;
    
    public:
    // constructor
    Shape();
    // function to do the CTM * MC  
    void ctm_multiply();
    // to change the scale factor
    void scale_change(double x); 
    // to translate the MC origin  
    void translate(double tx, double ty, double tz);
    // to rotate the MC with respect to a local axis. 
    void rotate_mc(double rx, double ry, double rz, double angle); 
    // to rotate the MC including both vectors and origin
    void rotate(double rx, double ry, double rz, double angle); 
    // to rotate the origin of MC and keep the vector changed
    void rotate_origin(double rx, double ry, double rz, double angle);                                    
    // draw function must be overwritten
    virtual void draw(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz) = 0;  
    
    void getRef(double &x, double &y, double &z);
    void transformNorm(GLfloat MCx, GLfloat MCy, GLfloat MCz, GLfloat &WCx, GLfloat &WCy, GLfloat &WCz);
};

#endif
