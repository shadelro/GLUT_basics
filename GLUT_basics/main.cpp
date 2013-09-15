#include <stdlib.h>
#include <GLUT/glut.h>

GLfloat defaultWindowWidth = 640;
GLfloat defaultWindowHeight = 480;

GLfloat boxWidth = 32.0f;
GLfloat boxHeight = 32.0f;

GLfloat boxX = (defaultWindowWidth / 2) - (boxWidth / 2);
GLfloat boxY = 0.0f;

GLfloat velocity = 4.0f;

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

void keyPressed(unsigned char key, int x, int y) {
  int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
  int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
  
  switch (key) {
    case 'w':
      if (boxY < windowHeight - boxHeight) {
        boxY += velocity;
      }
      break;
    case 'a':
      if (boxX > 0) {
        boxX -= velocity;
      }
      break;
    case 's':
      if (boxY > 0) {
        boxY -= velocity;
      }
      break;
    case 'd':
      if (boxX < windowWidth - boxWidth) {
        boxX += velocity;
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