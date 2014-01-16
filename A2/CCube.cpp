#include "CCube.h"

GLfloat P = 0.8, B = 0.3, Ka = 1.0, Kd = 1.0;
 // point light position coordinates

Cube::Cube()
{  
    vertex[0][0] = -1;vertex[0][1] = -1;vertex[0][2] = -1;
    vertex[1][0] = -1;vertex[1][1] = 1; vertex[1][2] = -1;
    vertex[2][0] = 1;vertex[2][1] = -1; vertex[2][2] = -1; 
    vertex[3][0] = 1;vertex[3][1] = 1;vertex[3][2] = -1;
    vertex[4][0] = -1;vertex[4][1] = -1;vertex[4][2] = 1;
    vertex[5][0] = -1;vertex[5][1] = 1; vertex[5][2] = 1; 
    vertex[6][0] = 1;vertex[6][1] = -1;vertex[6][2] = 1;
    vertex[7][0] = 1;vertex[7][1] = 1;vertex[7][2] = 1;
    
    face[0][0] = 0;face[0][1] = 1;face[0][2] = 3; face[0][3] = 2;
    face[1][0] = 3;face[1][1] = 7;face[1][2] = 6;face[1][3] = 2;
    face[2][0] = 7;face[2][1] = 5;face[2][2] = 4;face[2][3] = 6;
    face[3][0] = 4;face[3][1] = 5;face[3][2] = 1;face[3][3] = 0;
    face[4][0] = 5;face[4][1] = 7;face[4][2] = 3;face[4][3] = 1;
    face[5][0] = 6;face[5][1] = 4;face[5][2] = 0;face[5][3] = 2;
    
    faceIndex[0] =0; faceIndex[1]=1;faceIndex[2]=2;faceIndex[3]=3;faceIndex[4]=4;faceIndex[5]=5;
    cubeShade[0] =1; cubeShade[1] =1; cubeShade[2] =1; cubeShade[3] =1; cubeShade[4] =1; cubeShade[5] =1;
    
    cube_face_norm[0][0] = 0;  cube_face_norm[0][1] = 0;  cube_face_norm[0][2] = -1;
    cube_face_norm[1][0] = 1;  cube_face_norm[1][1] = 0;  cube_face_norm[1][2] = 0;
    cube_face_norm[2][0] = 0;  cube_face_norm[2][1] = 0;  cube_face_norm[2][2] = 1;
    cube_face_norm[3][0] = -1; cube_face_norm[3][1] = 0;  cube_face_norm[3][2] = 0;
    cube_face_norm[4][0] = 0;  cube_face_norm[4][1] = 1;  cube_face_norm[4][2] = 0; 
    cube_face_norm[5][0] = 0;  cube_face_norm[5][1] = -1; cube_face_norm[5][2] = 0;

    cube_face_norm_wc[0][0] = 0;  cube_face_norm_wc[0][1] = 0;  cube_face_norm_wc[0][2] = -1;
    cube_face_norm_wc[1][0] = 1;  cube_face_norm_wc[1][1] = 0;  cube_face_norm_wc[1][2] = 0;
    cube_face_norm_wc[2][0] = 0;  cube_face_norm_wc[2][1] = 0;  cube_face_norm_wc[2][2] = 1;
    cube_face_norm_wc[3][0] = -1; cube_face_norm_wc[3][1] = 0;  cube_face_norm_wc[3][2] = 0;
    cube_face_norm_wc[4][0] = 0;  cube_face_norm_wc[4][1] = 1;  cube_face_norm_wc[4][2] = 0; 
    cube_face_norm_wc[5][0] = 0;  cube_face_norm_wc[5][1] = -1; cube_face_norm_wc[5][2] = 0; 
    
    cubeWC[0][0] = -1; cubeWC[0][1] = -1; cubeWC[0][2] = -1;
    cubeWC[1][0] = -1; cubeWC[1][1] = 1;  cubeWC[1][2] = -1;
    cubeWC[2][0] = 1;  cubeWC[2][1] = -1; cubeWC[2][2] = -1; 
    cubeWC[3][0] = 1;  cubeWC[3][1] = 1;  cubeWC[3][2] = -1;
    cubeWC[4][0] = -1; cubeWC[4][1] = -1; cubeWC[4][2] = 1;
    cubeWC[5][0] = -1; cubeWC[5][1] = 1;  cubeWC[5][2] = 1; 
    cubeWC[6][0] = 1;  cubeWC[6][1] = -1; cubeWC[6][2] = 1;
    cubeWC[7][0] = 1;  cubeWC[7][1] = 1;  cubeWC[7][2] = 1;
    
    faceColor[0][0] = 1; faceColor[0][1] = 1; faceColor[0][2] = 1;
    faceColor[1][0] = 1; faceColor[1][1] = 0; faceColor[1][2] = 0;
    faceColor[2][0] = 0; faceColor[2][1] = 0; faceColor[2][2] =0;
    faceColor[3][0] = 1; faceColor[3][1] = 1; faceColor[3][2] = 0;
    faceColor[4][0] = 1; faceColor[4][1] = 0; faceColor[4][2] = 0;
    faceColor[5][0] = 0; faceColor[5][1] = 1; faceColor[5][2] = 0;
    
    cube_face_center[0][0] = 0.0;cube_face_center[0][1] = 0.0;cube_face_center[0][2] = -1.0;
    cube_face_center[1][0] = 1.0;cube_face_center[1][1] = 0.0;cube_face_center[1][2] = 0.0;
    cube_face_center[2][0] = 0.0;cube_face_center[2][1] = 0.0;cube_face_center[2][2] = 1.0;
    cube_face_center[3][0] = -1.0;cube_face_center[3][1] = 0.0;cube_face_center[3][2] = 0.0;
    cube_face_center[4][0] = 0.0;cube_face_center[4][1] = 1.0;cube_face_center[4][2] = 0.0;
    cube_face_center[5][0] = 0.0;cube_face_center[5][1] = -1.0;cube_face_center[5][2] = 0.0;
    
}

void Cube::getNormal()
{
    int i;
    for (i = 0; i < 6; i++)
        this->transformNorm(cube_face_center[i][0], cube_face_center[i][1],  cube_face_center[i][2], cube_face_norm[i][0], cube_face_norm[i][1], cube_face_norm[i][2]);   
}        

void Cube::draw_face(int i)
{
    
    glBegin(GL_LINE_LOOP);
    glVertex3fv(&vertex[face[i][0]][0]);
    glVertex3fv(&vertex[face[i][1]][0]);
    glVertex3fv(&vertex[face[i][2]][0]);
    glVertex3fv(&vertex[face[i][3]][0]);
    glEnd();
}

void Cube::draw(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz)
{
    GLfloat shx,shy,shz,nx,ny,nz,ns,norm;
    double back_face;
    double refx=0, refy=0, refz=0;
    this->getRef(refx, refy, refz);
    
    glPushMatrix();
    this->ctm_multiply();
    glScalef(sx, sy, sz);
    getNormal();
     
    for (int i = 0; i < 6; i++) {
        
        if(shade != 0){
        shx = lx - cube_face_center[faceIndex[i]][0];  // the light direction = light source - the center of a face.
        shy = ly - cube_face_center[faceIndex[i]][1];  
        shz = lz - cube_face_center[faceIndex[i]][2];

        nx = cube_face_norm[faceIndex[i]][0];    // use the updated normal, or calculated by the normal of the face     n = (P1-P0) x (P2 - P1)
        ny = cube_face_norm[faceIndex[i]][1];
        nz = cube_face_norm[faceIndex[i]][2];

        norm = sqrt(sx*sx+sy*sy+sz*sz);
        ns = (nx*shx + ny*shy+nz*shz)/norm;

        if (ns > 0 ){
           if (B*Ka + P*Kd*ns<=1)
              cubeShade[i] = B*Ka + P*Kd*ns; // shade of the face i
           else cubeShade[i] = 1;
        }
        else
            cubeShade[i] = B*Ka;
        }else{
              cubeShade[0] =1; cubeShade[1] =1; cubeShade[2] =1; cubeShade[3] =1; cubeShade[4] =1; cubeShade[5] =1; 
        }
            
       // back_face = (cube_face_norm[faceIndex[i]][0] * (refx-xeye)) + (cube_face_norm[faceIndex[i]][1] * (refy-yeye)) + (cube_face_norm[faceIndex[i]][2] * (refz-zeye));
        //if (back_face <= 0)
        //glColor3f(1.0,1.0,1.0);
        draw_face(faceIndex[i]);
    }
    
    /*
    //Draws the Red x-axis 
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(vertex[3][0]/1.5,0,0);
	glEnd();

	///* Draws the Green y-axis 
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(0,vertex[5][1]/1.5,0);
	glEnd();

	///* Draws the Blue z-axis 
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(0,0,vertex[7][2]/1.5);
	glEnd();*/
	
    //glColor3f(1.0, 1.0, 1.0); 
    glPopMatrix();
}

void Cube::WAxis(){
     /* Draws the Red x-axis */
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(1.0,0,0);
	glEnd();

	/* Draws the Green y-axis */
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(0,1,0);
	glEnd();

	/* Draws the Blue z-axis */
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(0,0,1);
	glEnd();
	
    glColor3f(1.0, 1.0, 1.0);    
}
    
