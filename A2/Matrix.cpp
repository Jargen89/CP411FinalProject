

typedef float Matrix4x4 [4][4];
Matrix4x4 matRot;

void matrix4x4SetIdentity (Matrix4x4 matIdent4x4)
{
  GLint row, col;

  for (row = 0; row < 4; row++)
     for (col = 0; col < 4 ; col++)
        matIdent4x4 [row][col] = (row == col);
}
  
void matrix4x4PreMultiply (Matrix4x4 m1, Matrix4x4 m2)
{
  GLint row, col;
  Matrix4x4 matTemp;
  for (row = 0; row < 4; row++)
     for (col = 0; col < 4 ; col++)
        matTemp [row][col] = m1 [row][0] * m2 [0][col] + m1 [row][1] *
                           m2 [1][col] + m1 [row][2] * m2 [2][col] +
                           m1 [row][3] * m2 [3][col];
  for (row = 0; row < 4; row++)
     for (col = 0; col < 4; col++)
        m2 [row][col] = matTemp [row][col];
}

void rotate3D (GLfloat angle, GLfloat rx, GLfloat ry, GLfloat rz)
{
  GLfloat radianAngle = angle * 3.1415926/180;     
  GLfloat axisVectLength = sqrt (rx * rx + ry*ry + rz*rz);
  GLfloat cosA = cos (radianAngle);
  GLfloat oneC = 1 - cosA;
  GLfloat sinA = sin (radianAngle);
  GLfloat ux = (rx) / axisVectLength;
  GLfloat uy = (ry) / axisVectLength;
  GLfloat uz = (rz) / axisVectLength;

  matRot [0][0] = ux*ux*oneC + cosA;
  matRot [0][1] = ux*uy*oneC - uz*sinA;
  matRot [0][2] = ux*uz*oneC + uy*sinA;
  matRot [0][3] = 1;

  matRot [1][0] = uy*ux*oneC + uz*sinA;
  matRot [1][1] = uy*uy*oneC + cosA;
  matRot [1][2] = uy*uz*oneC - ux*sinA;
  matRot [1][3] = 0;
  
  matRot [2][0] = uz*ux*oneC - uy*sinA;
  matRot [2][1] = uz*uy*oneC + ux*sinA;
  matRot [2][2] = uz*uz*oneC + cosA;
  matRot [2][3] = 0;
  
  matRot [3][0] = 0;
  matRot [3][1] = 0;
  matRot [3][2] = 0;
  matRot [3][3] = 1;      
}
