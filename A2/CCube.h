#ifndef CUBE_H
#define CUBE_H

#include <GL/glut.h>
#include "CShape.h"

class Cube : public Shape {
    protected:
    GLfloat vertex[8][3];     
    GLint face[6][4];  
    
    GLfloat faceColor[6][3]; //color for each face
    GLint cube_faces[6][4];
    GLfloat cube_face_center[6][3];                        
    GLfloat cube_face_norm[6][3];//normal faces in MC   

    GLint faceIndex[6];

    GLfloat cubeWC[8][3] ;//cube vertices in WC
    GLfloat cube_face_norm_wc[6][3]; //cube normals in WC
                     
    GLfloat cubeFaceZ[6]; // Z value of faces
    GLfloat backFaceTest[6]; // N * (Ref - P0)  
    GLfloat cubeShade[6];  // light shading of each face
    
    void getNormal();
                                  
    public:
    Cube();
    void draw_face(int);
    void draw(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz);    
    void WAxis(); 
                                           
};

#endif
