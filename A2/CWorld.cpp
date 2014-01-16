#include <stdio.h>
#include "CWorld.h"

World::World() {
    int tx = -2, tz = -3;
    for (int i = 0; i < 36; i++){
        myCube[i].translate(tx*2,0,tz*2);
        tx++;
        if( tx > 3){
            tz++;
            tx = -2;
        }
        printf("%d, %d, %d\n",i, tx, tz);
    }
    border[0].translate(1,0,-8);
    border[1].translate(1,0,6);
    border[2].translate(-6,0,-1);
    border[3].translate(8,0,-1);
    goal.translate(8,0,-2);
}                                    

void World::draw_world(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz) {
    //myCube->draw(xeye, yeye, zeye, shade, lx, ly, lz);
    //myCube->WAxis();
    //myCube2->draw();
    //myPyramid->draw(xeye, yeye, zeye, shade, lx, ly, lz);
}
void World::draw_Cube(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz) {
     //myCube->scale_change(0.005);
     for (int i = 0; i < 36; i++){
        myCube[i].draw(xeye, yeye, zeye, shade, lx, ly, lz, sx,  sy, sz);
    }
    border[0].draw(xeye, yeye, zeye, shade, lx, ly, lz, 8,  0.25, 1);
    border[1].draw(xeye, yeye, zeye, shade, lx, ly, lz, 8,  0.25, 1);
    border[2].draw(xeye, yeye, zeye, shade, lx, ly, lz, 1,  0.25, 8);
    border[3].draw(xeye, yeye, zeye, shade, lx, ly, lz, 1,  0.25, 8);
    glColor3f(1.0,0.0,0.0);
    goal.draw(xeye, yeye, zeye, shade, lx, ly, lz, sx,  sy, sz);
    glColor3f(1.0,1.0,1.0);
    //myCube->WAxis();
}
