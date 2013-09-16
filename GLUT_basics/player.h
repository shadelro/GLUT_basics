//
//  player.h
//  GLUT_basics
//
//  Created by Shadel,Brent on 9/15/13.
//  Copyright (c) 2013 Shadel,Brent. All rights reserved.
//

#ifndef __GLUT_basics__player__
#define __GLUT_basics__player__

#include "GLUT/glut.h"

class Player {
private:
  GLfloat m_width;
  GLfloat m_height;
  GLfloat m_x;
  GLfloat m_y;
  
  GLfloat m_velocity;
  
public:
  Player();
  Player(GLfloat width, GLfloat height, GLfloat x, GLfloat y, GLfloat velocity);

  GLfloat GetWidth();
  GLfloat GetHeight();
  GLfloat GetX();
  GLfloat GetY();
  GLfloat GetVelocity();
  
  void SetWidth(GLfloat width);
  void SetHeight(GLfloat height);
  void SetX(GLfloat x);
  void SetY(GLfloat y);
  void SetVelocity(GLfloat velocity);
};

#endif /* defined(__GLUT_basics__player__) */
