#include "CSphere.h"
#include <GL/glut.h>

Sphere::Sphere()
{  
    vertex[0][0] = 1.5;vertex[0][1] = 1.5;vertex[0][2] = 1.5;   
}
void Sphere::draw(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz) {
    glPushMatrix();
    this->ctm_multiply();
    glScalef(s, s, s);
    
    glutWireSphere(0.1, 25, 25);
    glPopMatrix();
    glFlush();
}
