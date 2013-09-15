#include <stdlib.h>
#include <GLUT/glut.h>

GLfloat defaultWindowWidth = 640;
GLfloat defaultWindowHeight = 480;

int lastFrameTime = 0;

GLfloat playerWidth = 32.0f;
GLfloat playerHeight = 32.0f;

GLfloat playerX = (defaultWindowWidth / 2) - (playerWidth / 2);
GLfloat playerY = (defaultWindowHeight / 2) - (playerHeight / 2);

GLfloat playerVelocity = 4.0f;

GLfloat enemyWidth = 64.0f;
GLfloat enemyHeight = 64.0f;

GLfloat enemyX = 0.0f;
GLfloat enemyY = 0.0f;

GLfloat enemyDirectionX = 1.0f;
GLfloat enemyDirectionY = 1.0f;

GLfloat enemyVelocity = 64.0f;

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
  
  enemyX += enemyVelocity * elapsedTime * enemyDirectionX;
  enemyY += enemyVelocity * elapsedTime * enemyDirectionY;
  
  if (enemyX > windowWidth - enemyWidth) {
    enemyDirectionX = -1;
  } else if (enemyX < 0) {
    enemyDirectionX = 1;
  }
  
  if (enemyY > windowHeight - enemyHeight) {
    enemyDirectionY = -1;
  } else if (enemyY < 0) {
    enemyDirectionY = 1;
  }
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glPushMatrix();
  glColor3f(1.0f, 0.0f, 0.0f);
  glTranslatef(enemyX, enemyY, 0);
  glBegin(GL_QUADS);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(enemyWidth, 0.0f);
  glVertex2f(enemyWidth, enemyHeight);
  glVertex2f(0.0f, enemyHeight);
  glEnd();
  glPopMatrix();
  
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef(playerX, playerY, 0);
  glBegin(GL_QUADS);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(playerWidth, 0.0f);
  glVertex2f(playerWidth, playerHeight);
  glVertex2f(0.0f, playerHeight);
  glEnd();
  glPopMatrix();
  
  glutSwapBuffers();
}

void idle(void) {
  glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y) {
  int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
  int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
  
  switch (key) {
    case 'w':
      if (playerY < windowHeight - playerHeight) {
        playerY += playerVelocity;
      }
      break;
    case 'a':
      if (playerX > 0) {
        playerX -= playerVelocity;
      }
      break;
    case 's':
      if (playerY > 0) {
        playerY -= playerVelocity;
      }
      break;
    case 'd':
      if (playerX < windowWidth - playerWidth) {
        playerX += playerVelocity;
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