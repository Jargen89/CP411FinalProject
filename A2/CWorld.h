#include "CCube.h"
#include "CSphere.h"

class World {
    protected:
    Cube myCube[36];   // tiles
    Cube border[4];
    Cube goal;
    //std::vector<Cube*> vehicles;
    // in general an list of object data structure can be use for more objects
                                       
    public:
    // constructor           
    World(); 
    // draw all objects in the world 
    void draw_world(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz);    
    void draw_Cube(GLfloat xeye, GLfloat yeye, GLfloat zeye, GLint shade, GLfloat lx, GLfloat ly, GLfloat lz,GLfloat sx, GLfloat sy, GLfloat sz);
};
