//
//  enemy.h
//  GLUT_basics
//
//  Created by Shadel,Brent on 9/15/13.
//  Copyright (c) 2013 Shadel,Brent. All rights reserved.
//

#ifndef __GLUT_basics__enemy__
#define __GLUT_basics__enemy__
#include "GLUT/glut.h"

class Enemy {
private:
  GLfloat m_width;
  GLfloat m_height;
  GLfloat m_x;
  GLfloat m_y;
  
  GLfloat m_velocity;
  GLfloat m_directionX;
  GLfloat m_directionY;

public:
  Enemy();
  Enemy(GLfloat width, GLfloat height, GLfloat x, GLfloat y, GLfloat velocity,
        GLfloat directionX, GLfloat directionY);
  
  GLfloat GetWidth();
  GLfloat GetHeight();
  GLfloat GetX();
  GLfloat GetY();
  GLfloat GetVelocity();
  GLfloat GetDirectionX();
  GLfloat GetDirectionY();
  
  void SetWidth(GLfloat width);
  void SetHeight(GLfloat height);
  void SetX(GLfloat x);
  void SetY(GLfloat y);
  void SetVelocity(GLfloat velocity);
  void SetDirectionX(GLfloat directionX);
  void SetDirectionY(GLfloat directionY);
};

#endif /* defined(__GLUT_basics__enemy__) */
