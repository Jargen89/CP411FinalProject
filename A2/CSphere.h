#ifndef Sphere_H
#define Sphere_H

#include <GL/glut.h>
#include "CShape.h"

class Sphere : public Shape {
    protected:
    GLfloat vertex[1][3];     
    
    public:
    Sphere();
    void draw(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz);                                           
};

#endif
