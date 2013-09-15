#include <stdlib.h>
#include <GLUT/glut.h>

void display();
void idle();
void reshape(int width, int height);

int main(int argc, char * argv[])
{
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

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBegin(GL_QUADS);
    glVertex2f(-.75f, -.75f);
    glVertex2f(.75f, -.75f);
    glVertex2f(.75f, .75f);
    glVertex2f(-.75f, .75f);
    glEnd();
    
    glutSwapBuffers();
}

void idle(void)
{
    glutPostRedisplay();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}