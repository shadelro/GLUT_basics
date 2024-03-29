//
//  enemy.cpp
//  GLUT_basics
//
//  Created by Shadel,Brent on 9/15/13.
//  Copyright (c) 2013 Shadel,Brent. All rights reserved.
//

#include "Enemy.h"

Enemy::Enemy() {
  
}

Enemy::Enemy(GLfloat width, GLfloat height, GLfloat x, GLfloat y,
             GLfloat velocity, GLfloat directionX, GLfloat directionY) {
  SetWidth(width);
  SetHeight(height);
  SetX(x);
  SetY(y);
  SetVelocity(velocity);
  SetDirectionX(directionX);
  SetDirectionY(directionY);
}

void Enemy::Display() {
  glPushMatrix();
  glColor3f(1.0f, 0.0f, 0.0f);
  glTranslatef(m_x, m_y, 0);
  glBegin(GL_QUADS);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(m_width, 0.0f);
  glVertex2f(m_width, m_height);
  glVertex2f(0.0f, m_height);
  glEnd();
  glPopMatrix();

}

GLfloat Enemy::GetWidth() {
  return m_width;
}

GLfloat Enemy::GetHeight() {
  return m_height;
}

GLfloat Enemy::GetX() {
  return m_x;
}

GLfloat Enemy::GetY() {
  return m_y;
}

GLfloat Enemy::GetVelocity() {
  return m_velocity;
}

GLfloat Enemy::GetDirectionX() {
  return m_directionX;
}

GLfloat Enemy::GetDirectionY() {
  return m_directionY;
}

void Enemy::SetWidth(GLfloat width) {
  m_width = width;
}

void Enemy::SetHeight(GLfloat height) {
  m_height = height;
}

void Enemy::SetX(GLfloat x) {
  m_x = x;
}

void Enemy::SetY(GLfloat y) {
  m_y = y;
}

void Enemy::SetVelocity(GLfloat velocity) {
  m_velocity = velocity;
}

void Enemy::SetDirectionX(GLfloat directionX) {
  m_directionX = directionX;
}

void Enemy::SetDirectionY(GLfloat directionY) {
  m_directionY = directionY;
}