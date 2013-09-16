//
//  player.cpp
//  GLUT_basics
//
//  Created by Shadel,Brent on 9/15/13.
//  Copyright (c) 2013 Shadel,Brent. All rights reserved.
//

#include "Player.h"
#include "GLUT/glut.h"

Player::Player() {
  
}

Player::Player(GLfloat width, GLfloat height, GLfloat x, GLfloat y, GLfloat velocity) {
  SetWidth(width);
  SetHeight(height);
  SetX(x);
  SetY(y);
  SetVelocity(velocity);
}

void Player::Display() {
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef(m_x, m_y, 0);
  glBegin(GL_QUADS);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(m_width, 0.0f);
  glVertex2f(m_width, m_height);
  glVertex2f(0.0f, m_height);
  glEnd();
  glPopMatrix();

}

GLfloat Player::GetWidth() {
  return m_width;
}

GLfloat Player::GetHeight() {
  return m_height;
}

GLfloat Player::GetX() {
  return m_x;
}

GLfloat Player::GetY() {
  return m_y;
}

GLfloat Player::GetVelocity() {
  return m_velocity;
}

void Player::SetWidth(GLfloat width) {
  m_width = width;
}

void Player::SetHeight(GLfloat height) {
  m_height = height;
}

void Player::SetX(GLfloat x) {
  m_x = x;
}

void Player::SetY(GLfloat y) {
  m_y = y;
}

void Player::SetVelocity(GLfloat velocity) {
  m_velocity = velocity;
}
