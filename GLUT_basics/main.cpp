#include <stdlib.h>
#include <GLUT/glut.h>
#include "Player.h"
#include "Enemy.h"

int lastFrameTime = 0;

GLfloat defaultWindowWidth = 640;
GLfloat defaultWindowHeight = 480;

GLfloat playerWidth = 32.0f;
GLfloat playerHeight = 32.0f;
GLfloat playerVelocity = 4.0f;

GLfloat enemyWidth = 64.0f;
GLfloat enemyHeight = 64.0f;
GLfloat enemyVelocity = 32.0f;

Player player(playerWidth, playerHeight,
              (defaultWindowWidth / 2) - (playerWidth / 2),
              (defaultWindowHeight / 2) - (playerHeight / 2),
              playerVelocity);
Enemy enemy(enemyWidth, enemyHeight, 0.0f, 0.0f, enemyVelocity, 1.0f, 1.0f);

void display();
void keyPressed(unsigned char key, int x, int y);
void idle();
void reshape(int width, int height);

int main(int argc, char * argv[]) {
  glutInit(&argc, argv);
    
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(defaultWindowWidth, defaultWindowHeight);
  
  glutCreateWindow("GLUT Basics");

  glutDisplayFunc(display);
  glutKeyboardFunc(keyPressed);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  
  glutMainLoop();
  
  return EXIT_SUCCESS;
}

void display(void) {
  if (lastFrameTime == 0) {
    lastFrameTime = glutGet(GLUT_ELAPSED_TIME);
  }
  
  int now = glutGet(GLUT_ELAPSED_TIME);
  int elapsedMilliseconds = now - lastFrameTime;
  float elapsedTime = elapsedMilliseconds / 1000.0f;
  lastFrameTime = now;
  
  int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
  int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
  
  if (enemy.GetX() > windowWidth - enemy.GetWidth()) {
    enemy.SetDirectionX(-1);
  } else if (enemy.GetX() < 0) {
    enemy.SetDirectionX(1);
  }
  
  enemy.SetX(enemy.GetX() +
             enemy.GetVelocity() * elapsedTime * enemy.GetDirectionX());
  enemy.SetY(enemy.GetY() +
             enemy.GetVelocity() * elapsedTime * enemy.GetDirectionY());
  
  if (enemy.GetY() > windowHeight - enemy.GetHeight()) {
    enemy.SetDirectionY(-1);
  } else if (enemy.GetY() < 0) {
    enemy.SetDirectionY(1);
  }
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  enemy.Display();
  player.Display();
  
  glutSwapBuffers();
}

void idle(void) {
  glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y) {
  switch (key) {
    case 'w':
      if (player.GetY() < glutGet(GLUT_WINDOW_HEIGHT) - player.GetHeight()) {
        player.SetY(player.GetY() + player.GetVelocity());
      }
      break;
    case 'a':
      if (player.GetX() > 0) {
        player.SetX(player.GetX() - player.GetVelocity());
      }
      break;
    case 's':
      if (player.GetY() > 0) {
        player.SetY(player.GetY() - player.GetVelocity());
      }
      break;
    case 'd':
      if (player.GetX() < glutGet(GLUT_WINDOW_WIDTH) - player.GetWidth()) {
        player.SetX(player.GetX() + player.GetVelocity());
      }
      break;
      
    default:
      break;
  }
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, width, 0, height);
  glMatrixMode(GL_MODELVIEW);
}