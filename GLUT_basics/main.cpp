#include <stdlib.h>
#include <GLUT/glut.h>

int lastFrameTime = 0;

GLfloat boxX = 0.0f;
GLfloat boxY = 0.0f;

GLfloat velocity = 128.0f;

int directionX = 1;
int directionY = 1;

GLfloat boxWidth = 64.0f;
GLfloat boxHeight = 64.0f;

void display();
void idle();
void reshape(int width, int height);

int main(int argc, char * argv[]) {
  glutInit(&argc, argv);
  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  
  glutCreateWindow("GLUT Basics");

  glutDisplayFunc(display);
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
  
  boxX += velocity * elapsedTime * directionX;
  boxY += velocity * elapsedTime * directionY;
  
  if (boxX > windowWidth - boxWidth) {
    directionX = -1;
  } else if (boxX < 0) {
    directionX = 1;
  }

  if (boxY > windowHeight - boxHeight) {
    directionY = -1;
  } else if (boxY < 0) {
    directionY = 1;
  }
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glPushMatrix();
  glTranslatef(boxX, boxY, 0);
  
  glBegin(GL_QUADS);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(boxWidth, 0.0f);
  glVertex2f(boxWidth, boxHeight);
  glVertex2f(0.0f, boxHeight);
  glEnd();
  glPopMatrix();
  
  glutSwapBuffers();
}

void idle(void) {
  glutPostRedisplay();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, width, 0, height);
  glMatrixMode(GL_MODELVIEW);
}