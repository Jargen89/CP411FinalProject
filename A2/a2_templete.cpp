/* CP411 Assignment 2. templete, opp version
  Hongbing Fan, 16/10/09 17:00
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "CWorld.h"

GLint winWidth = 1280, winHeight = 720;  
GLfloat xeye = 14.0, yeye = 30.0, zeye = 14.0;  //  Viewing-coordinate origin.
GLfloat xref = 1.0, yref = 0.0, zref = -1.0;  //  Look-at point.   
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;        //  View up vector.
GLfloat scale = 1;
/*  Set coordinate limits for the clipping window:  */
GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;

typedef struct {
   double x,y,z;
} Point;

GLfloat lx = 1.5,ly = 1.5,lz = 1.5;
// point light position coordinates
GLfloat lightx = 1.5,lighty = 1.5,lightz = 1.5;

/*  Set positions for near and far clipping planes:  */
GLfloat vangle = 40.0, dnear = 1.0, dfar = 10.0;
GLfloat theta = 0.0, rx = 1.0, ry = 0.0, rz = 0.0, s=0.8;

GLfloat red = 1.0,  green = 1.0,  blue = 1.0;  //color   
GLint moving =0, xBegin = 0, coordinate = 1, type = 4, selected = 1, shading = 0, light = 0; 

GLint xMouse;

//deaclar a world containing all objects to draw.
World myWorld;
/*
void transformLight(Point *source){
     if(light = 1){
          
     }
     else if(light = 2){
          
     }
     else if(light = 3){
          
     }
     else if(light = 4){
          theta = (xBegin - xMouse < 0)? 1 : -1; 
          source->x += theta*-0.01;
     }
     else if(light = 5){
          theta = (xBegin - xMouse < 0)? 1 : -1; 
          source->y += theta*-0.01;
     }
     else if(light = 6){
          theta = (xBegin - xMouse < 0)? 1 : -1; 
          source->z += theta*-0.01;
     }//glutPostRedisplay ( );
}*/
           
void display(void)
{
    //glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(vangle, 1.0, 1, 100);
      
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(xeye, yeye, zeye, xref, yref, zref, Vx, Vy, Vz);    
    glColor3f(red ,green ,blue);
    // draw all objects in the world  
    if (selected == 1){
       glColor3f(1.0,1.0,1.0);
       myWorld.draw_Cube(xeye, xeye, xeye, shading, lx, ly, lz,1, 0.25, 1);
    }
    //myWorld.draw_world();  
      
    if(light != 0){
             //glColor3f(1.0, 1.0, 1.0);
             //transformLight(&lSource);
             //glTranslatef(lSource.x,lSource.y,lSource.z);
            // glutSolidSphere( 0.1, 25, 25);
            // glTranslatef(-1*lSource.x,-1*lSource.y,-1*lSource.z);
            //myWorld.draw_Sphere(xeye, yeye, zeye, shading, lx, ly, lz, scale,  scale,  scale);
    }
    
    glFlush();
    glutSwapBuffers();
    //glDisable(GL_DEPTH_TEST);
}



void Normalise(Point *p)
{
   double length;

   length = sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
   if (length != 0) {
      p->x /= length;
      p->y /= length;
      p->z /= length;
   } else {
      p->x = 0;
      p->y = 0;
      p->z = 0;
   }
}

Point CalcNormal(Point p,Point p1,Point p2)
{
   Point n,pa,pb;

   pa.x = p1.x - p.x;
   pa.y = p1.y - p.y;
   pa.z = p1.z - p.z;
   pb.x = p2.x - p.x;
   pb.y = p2.y - p.y;
   pb.z = p2.z - p.z;
   Normalise(&pa);
   Normalise(&pb);
 
   n.x = pa.y * pb.z - pa.z * pb.y;
   n.y = pa.z * pb.x - pa.x * pb.z;
   n.z = pa.x * pb.y - pa.y * pb.x;
   Normalise(&n);

   return(n);
}

void winReshapeFcn (GLint newWidth, GLint newHeight)
{   /*  Reset viewport and projection parameters  */
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    winWidth = newWidth;
    winHeight = newHeight;
} 

void mouseAction(int button, int state, int x, int y)
    {       
     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {    
        moving = 1;
        xBegin = x;
      }
      if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {      
        moving = 0;                
      }
    }           
      
void mouseMotion (GLint x, GLint y)
{      
   GLfloat x0, y0, z0, rx, ry, rz, theta;
   xMouse = x;
   if (moving){
     if (coordinate == 1 && type == 1 && light == 0)
     {                                                              
          theta = (xBegin - x > 0)? 1 : -1; 
          GLfloat x0, y0, z0;
          if (selected == 1){          
                    rx =  myWorld.myCube->MC.mat[0][0];
                    ry =  myWorld.myCube->MC.mat[1][0];
                    rz =  myWorld.myCube->MC.mat[2][0]; 
          
          
                    x0 = myWorld.myCube->MC.mat[0][3];
                    y0 = myWorld.myCube->MC.mat[1][3];
                    z0 = myWorld.myCube->MC.mat[2][3];
                    myWorld.myCube->rotate(rx, ry, rz, theta*0.5);  
          
                    myWorld.myCube->MC.mat[0][3] = x0;
                    myWorld.myCube->MC.mat[1][3] = y0;
                    myWorld.myCube->MC.mat[2][3] = z0;
          }
          //glutPostRedisplay ( ); 
     }
    
     else if (coordinate == 1 && type == 2 && light == 0)
     {                                                                       
          theta = (xBegin - x > 0)? 1 : -1; 
          GLfloat x0, y0, z0;
          if (selected == 1){          
                    rx =  myWorld.myCube->MC.mat[0][1];
                    ry =  myWorld.myCube->MC.mat[1][1];
                    rz =  myWorld.myCube->MC.mat[2][1]; 
          
          
                    x0 = myWorld.myCube->MC.mat[0][3];
                    y0 = myWorld.myCube->MC.mat[1][3];
                    z0 = myWorld.myCube->MC.mat[2][3];
                    myWorld.myCube->rotate(rx, ry, rz, theta*0.5);  
          
                    myWorld.myCube->MC.mat[0][3] = x0;
                    myWorld.myCube->MC.mat[1][3] = y0;
                    myWorld.myCube->MC.mat[2][3] = z0;
          }
     }
      else if (coordinate == 1 && type == 3 && light == 0)
     {                                                                       
          theta = (xBegin - x > 0)? 1 : -1; 
          GLfloat x0, y0, z0;
          if (selected == 1){          
                    rx =  myWorld.myCube->MC.mat[0][2];
                    ry =  myWorld.myCube->MC.mat[1][2];
                    rz =  myWorld.myCube->MC.mat[2][2]; 
          
          
                    x0 = myWorld.myCube->MC.mat[0][3];
                    y0 = myWorld.myCube->MC.mat[1][3];
                    z0 = myWorld.myCube->MC.mat[2][3];
                    myWorld.myCube->rotate(rx, ry, rz, theta*0.5);  
          
                    myWorld.myCube->MC.mat[0][3] = x0;
                    myWorld.myCube->MC.mat[1][3] = y0;
                    myWorld.myCube->MC.mat[2][3] = z0;
          }
     }
     
     else if (coordinate == 2 && type == 1 && light == 0)
     {                                                              
          theta = (xBegin - x > 0)? 1 : -1; 
          //rotate x axis
          rx = 1;
          ry = 0;
          rz = 0;
          
          if(selected == 1){
          myWorld.myCube->rotate_origin(rx, ry, rz, theta*0.5);                              
          }
          //glutPostRedisplay ( );
     }
     
     else if (coordinate == 2 && type == 2 && light == 0)
     {                                                              
          theta = (xBegin - x > 0)? 1 : -1; 
          //rotate y axis
          rx = 0;
          ry = 1;
          rz = 0;         
          if (selected == 1){
          myWorld.myCube->rotate_origin(rx, ry, rz, theta*0.5);  
          }
          //glutPostRedisplay ( ); 
     }
     
     else if (coordinate == 2 && type == 3 && light == 0)
     {                                                              
          theta = (xBegin - x > 0)? 1 : -1; 
          //rotate z axis
          rx = 0;
          ry = 0;
          rz = 1;
          if (selected == 1){
          myWorld.myCube->rotate_origin(rx, ry, rz, theta*0.5);  
          }
          //glutPostRedisplay ( );
     }
     
     else if (coordinate == 1 && type == 4 && light == 0)
     {                                  
          theta = (xBegin - x < 0)? 1 : -1;   
          if(selected == 1){
           myWorld.myCube->scale_change(theta*0.02); 
           }
          //glutPostRedisplay ( );
     }
     
     else if (coordinate == 2 && type == 4 && light == 0)
     {                                  
          theta = (xBegin - x < 0)? 1 : -1;   
          if(selected == 1){
           myWorld.myCube->translate(theta*0.02, 0, 0); 
          }
          //glutPostRedisplay ( );
     } 
     else if (coordinate == 2 && type == 5 && light == 0)
     {                                  
          theta = (xBegin - x < 0)? 1 : -1;   
          if(selected == 1){
           myWorld.myCube->translate(0,theta*0.02,0); 
          }
          //glutPostRedisplay ( );
     } 
     else if (coordinate == 2 && type == 6 && light == 0)
     {                                  
          theta = (xBegin - x < 0)? 1 : -1;   
          if(selected == 1){
           myWorld.myCube->translate(0,0,theta*0.02); 
          }
          //glutPostRedisplay ( );
     } 
     else if (coordinate == 3 && type == 1 && light == 0){//rotate vc x-axis
              
     }
     else if (coordinate == 3 && type == 2 && light == 0){//rotate vc y-axis
              
     }
     else if (coordinate == 3 && type == 3 && light == 0){//rotate vc z-axis
              
     }
     else if (coordinate == 3 && type == 4 && light == 0){//translate vc x-axis
          theta = (xBegin - x < 0)? 1 : -1; 
          xeye += theta*-0.01;  
          //xref += theta*-0.01;
          //glutPostRedisplay ( );     
     }
     else if (coordinate == 3 && type == 5 && light == 0){//translate vc y-axis
          theta = (xBegin - x < 0)? 1 : -1; 
          yeye += theta*-0.01;      
          //glutPostRedisplay ( );              
     }
     else if (coordinate == 3 && type == 6 && light == 0){//translate vc z-axis
          theta = (xBegin - x < 0)? 1 : -1; 
          zeye += theta*-0.01;       
          //glutPostRedisplay ( );
     }
     else if (coordinate == 3 && type == 7 && light == 0){//translate vc z-axis
          theta = (xBegin - x < 0)? 1 : -1; 
          dnear += theta*-0.01;       
          //glutPostRedisplay ( );
     }
     else if (coordinate == 3 && type == 8 && light == 0){//translate vc z-axis
          theta = (xBegin - x < 0)? 1 : -1; 
          dfar += theta*-0.01;       
          //glutPostRedisplay ( );
     }
     else if(light == 1){
          theta = (xBegin - x > 0)? 1 : -1; 
          //rotate x axis
          rx = 1;
          ry = 0;
          rz = 0;
          
          //myWorld.mySphere->rotate(rx, ry, rz, theta*0.5);  
          
          //lx = myWorld.mySphere->MC.mat[0][0] + myWorld.mySphere->MC.mat[0][1] + myWorld.mySphere->MC.mat[0][2] + myWorld.mySphere->MC.mat[0][3]:
          //ly = myWorld.mySphere->MC.mat[1][0] + myWorld.mySphere->MC.mat[1][1] + myWorld.mySphere->MC.mat[1][2] + myWorld.mySphere->MC.mat[1][3]:
          //lz = myWorld.mySphere->MC.mat[2][0] + myWorld.mySphere->MC.mat[2][1] + myWorld.mySphere->MC.mat[2][2] + myWorld.mySphere->MC.mat[2][3]:                             
     }
     else if(light == 2){
          theta = (xBegin - x > 0)? 1 : -1; 
          //rotate x axis
          rx = 0;
          ry = 1;
          rz = 0;
          
          //myWorld.mySphere->rotate(rx, ry, rz, theta*0.5);       
          
                                    
     }
     else if(light == 3){
          theta = (xBegin - x > 0)? 1 : -1; 
          //rotate x axis
          rx = 0;
          ry = 0;
          rz = 1;
          
          //myWorld.mySphere->rotate(rx, ry, rz, theta*0.5);                                 
     }
     else if(light == 4){
          theta = (xBegin - x < 0)? 1 : -1; 
           //myWorld.mySphere->translate(theta*0.02, 0, 0);
                                
     }
     else if(light == 5){
          theta = (xBegin - x < 0)? 1 : -1; 
           //myWorld.mySphere->translate( 0, theta*0.02, 0);
                                
     }
     else if(light == 6){
          theta = (xBegin - x < 0)? 1 : -1; 
           //myWorld.mySphere->translate(0,0,theta*0.02);
                                
     }
     
  } 
  //update the light source for the shading on each object.
  //lx = myWorld.mySphere->MC.mat[0][0] + myWorld.mySphere->MC.mat[0][1] + myWorld.mySphere->MC.mat[0][2];
  //ly = myWorld.mySphere->MC.mat[1][0] + myWorld.mySphere->MC.mat[1][1] + myWorld.mySphere->MC.mat[1][2];
  //lz = myWorld.mySphere->MC.mat[2][0] + myWorld.mySphere->MC.mat[2][1] + myWorld.mySphere->MC.mat[2][2];                             

     glutPostRedisplay ( );
}

void animate()
{
      return;
     glutPostRedisplay();
}

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 1.0);  // Set display-window color to black
    
    glMatrixMode(GL_PROJECTION);
    gluPerspective(vangle, 1.0, dnear, dfar);
    
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(xeye, yeye, zeye, xref, yref, zref, Vx, Vy, Vz);    
}

void MCTransMenu (GLint transOption)
   {
       switch (transOption) {
           case 1:
               {coordinate = 1; type = 1;}
               break;
           case 2:
               {coordinate = 1; type = 2;} break;
           case 3:
               {coordinate = 1; type = 3;}  break; 
           case 4:
               {coordinate = 1; type = 4;}  break;                                  
       }
       glutPostRedisplay ( );
   }


void WCTransMenu (GLint transOption)
{
       switch (transOption) {
       case 1:
       {coordinate = 2; type = 1;}  break;    
       case 2:
       {coordinate = 2; type = 2;}  break;    
       case 3:
       {coordinate = 2; type = 3;}  break;
       case 4:
       {coordinate = 2; type = 4;}  break;  
       case 5:
       {coordinate = 2; type = 5;}  break;
       case 6:
       {coordinate = 2; type = 6;}  break;                                
       }
   glutPostRedisplay ( );
}

void reset(){
     winWidth = 600, winHeight = 600;  
          xeye = 3.0, yeye = 3.0, zeye = 7.0;  //  Viewing-coordinate origin.
          xref = 0.0, yref = 0.0, zref = 0.0;  //  Look-at point.   
          Vx = 0.0, Vy = 1.0, Vz = 0.0;        //  View up vector.
          xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;
          vangle = 40.0, dnear = 1.0, dfar = 10.0;
          theta = 0.0, rx = 1.0, ry = 0.0, rz = 0.0, s=0.8;
         red = 1.0,  green = 1.0,  blue = 1.0;  //color   
         moving =0, xBegin = 0, coordinate = 1, type = 4,selected = 1, shading = 0, light = 0;
         glutIdleFunc(NULL);
}

void mainMenu(GLint option){
     
     switch(option){
     case 1:{
          reset();
          if (selected == 1){
             //myWorld.myCube = new Cube();
          }
         }break;
     case 2:{ exit(0);}break;
     }
     glutPostRedisplay ( );     
}

void VCTransMenu (GLint transOption)
{
   switch (transOption) {
       case 1:
       {coordinate = 3; type = 1;}  break;    
       case 2:
       {coordinate = 3; type = 2;}  break;    
       case 3:
       {coordinate = 3; type = 3;}  break;
       case 4:
       {coordinate = 3; type = 4;}  break;  
       case 5:
       {coordinate = 3; type = 5;}  break;
       case 6:
       {coordinate = 3; type = 6;}  break;  
       case 7:
       {coordinate = 3; type = 7;}  break;  
       case 8:
       {coordinate = 3; type = 8;}  break;
       case 9:
       {coordinate = 3; type = 9;}  break;                               
       }
       glutPostRedisplay ( );
}

void colorSubMenu (GLint colorOption)
{
   switch (colorOption) {
    case 1: {red = 1.0;green = 0.0;blue = 0.0;} break;                                                                                                     
    case 2: {red = 0.0;green = 1.0;blue = 0.0;} break;
    case 3: {red = 0.0;green = 0.0;blue = 1.0;}
   }
   glColor3f(red,green,blue);
   glutPostRedisplay ( );
}

void ObjSubMenu (GLint objectOption)
{
  switch (objectOption) {
  case 1: {
  selected = 1;} break;                                                                                                     
  case 2: {
  selected = 2;} break;
  case 3: {
  selected = 3;}
   }
   
  glutPostRedisplay ( ); 
   
}

void AnimateMenu(GLint animateOption)
   {
        switch (animateOption)
        {
             case 1:
             {glutIdleFunc(animate);selected = 1; } break;    // run the cube animation         
             case 2:
             {glutIdleFunc(animate);selected = 4;}   break;             //run the solar system
             case 3:
             {glutIdleFunc(NULL); }        //stop animation  
        }     
        glutPostRedisplay ( );
   }  

void LightMenu(GLint lightOption)
{
      switch (lightOption)
        {
             case 1:
             {light = 1;shading = 1;}  break;    
             case 2:
             {light = 2;shading = 1;}  break;    
             case 3:
             {light = 3;shading = 1;}  break;
             case 4:
             {light = 4;shading = 1;}  break;  
             case 5:
             {light = 5;shading = 1;}  break;
             case 6:
             {light = 6;shading = 1;}  break;  
             case 7:
             {light = 7;shading = 1;}  break;  
             case 8:
             {light = 8;shading = 1;}  break;  
             case 0:
             {light = 0;shading = 0;}
        }     
        glutPostRedisplay ( );
}
void ShadeMenu(GLint shadeOption)
{
      switch (shadeOption)
        {
             case 1:
             {shading = 1;}  break;    
             case 0:
             {shading = 0;}
        }     
        glutPostRedisplay ( );
}

void menu()
{
    GLint WCTrans_Menu, VCTrans_Menu, MCTrans_Menu, subMenuColor, Object_Menu, Style_Menu, Animate_Menu, Shade_Menu, Light_Menu;
    MCTrans_Menu = glutCreateMenu (MCTransMenu);
    glutAddMenuEntry (" Rotate x ", 1);
    glutAddMenuEntry (" Rotate y ", 2);
    glutAddMenuEntry (" Rotate z", 3);
    glutAddMenuEntry (" Scale", 4);
    
    Animate_Menu = glutCreateMenu (AnimateMenu);
    glutAddMenuEntry ("Animate Z-Axis", 1);
    glutAddMenuEntry ("Solar System", 2);
    glutAddMenuEntry ("Stop Animation", 3);
    
    Shade_Menu = glutCreateMenu (ShadeMenu);
    glutAddMenuEntry ("Shade On", 1);
    glutAddMenuEntry ("Shade Off", 0);
    
    Light_Menu = glutCreateMenu (LightMenu);
    glutAddMenuEntry ("Rotate Light x", 1);
    glutAddMenuEntry ("Rotate Light y", 2);
    glutAddMenuEntry ("Rotate Light z", 3);
    glutAddMenuEntry ("Translate Light x", 4);
    glutAddMenuEntry ("Translate Light y", 5);
    glutAddMenuEntry ("Translate Light z", 6);
    glutAddMenuEntry ("Ambient Light", 7);
    glutAddMenuEntry ("Pont Light", 8);
    glutAddMenuEntry ("Cancel Light Transformations", 0);
    
    
    WCTrans_Menu = glutCreateMenu (WCTransMenu);
    glutAddMenuEntry (" Rotate x ", 1);
    glutAddMenuEntry (" Rotate y ", 2);
    glutAddMenuEntry (" Rotate z", 3);
    glutAddMenuEntry (" Translate x ", 4);
    glutAddMenuEntry (" Translate y ", 5);
    glutAddMenuEntry (" Translate z", 6);
                  
    VCTrans_Menu = glutCreateMenu (VCTransMenu);
    glutAddMenuEntry (" Rotate x ", 1);
    glutAddMenuEntry (" Rotate y ", 2);
    glutAddMenuEntry (" Rotate z", 3);
    glutAddMenuEntry (" Translate x ", 4);
    glutAddMenuEntry (" Translate y ", 5);
    glutAddMenuEntry (" Translate z", 6);   
    glutAddMenuEntry (" Clipping Near ", 7);
    glutAddMenuEntry (" Clipping Far ", 8);
    glutAddMenuEntry (" Angle ", 9);
    
    subMenuColor = glutCreateMenu (colorSubMenu);
    glutAddMenuEntry ("Red", 1);
    glutAddMenuEntry ("Green", 2);
    glutAddMenuEntry ("Blue", 3);  
       
    Object_Menu = glutCreateMenu (ObjSubMenu);
    glutAddMenuEntry (" Cube ", 1);
    glutAddMenuEntry (" Prymid ", 2);
    glutAddMenuEntry (" House ", 3);  
      
    glutCreateMenu (mainMenu);      // Create main pop-up menu.
    glutAddMenuEntry (" Reset ", 1);
    glutAddSubMenu (" Object Selection ", Object_Menu);
    glutAddSubMenu (" Shading", Shade_Menu);
    glutAddSubMenu (" Light Transformations", Light_Menu);
    glutAddSubMenu (" Animation", Animate_Menu);
    glutAddSubMenu (" Model Transformations ", MCTrans_Menu);
    glutAddSubMenu (" WC Transformations ", WCTrans_Menu);
    glutAddSubMenu (" View Transformations ", VCTrans_Menu);
    glutAddSubMenu (" Colors ", subMenuColor);
    glutAddMenuEntry (" Quit", 2);
}

int main (int argc, char** argv)
{               
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("A3 by Jason Vieira");             
    init();  
    menu();  

    glutDisplayFunc(display);        
    glutMotionFunc(mouseMotion);
    glutMouseFunc(mouseAction);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
   
