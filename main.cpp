#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <math.h>
#include <stdlib.h>
#include <windows.h>

void display();
void reshape(int w,int h);

void init()
{
    glClearColor(1,1,1,1.0);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,500);

    glutCreateWindow("Mark Tharwat - 19200164");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //background
    int i;
    double radius1 = 20;

    double angle;
    glTranslatef(0,5,0);
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.9,0.9);
    for(i = 0; i <= 360; i++) {
    angle = i * 3.14 / 180;
    glVertex2f(radius1 * cos(angle), radius1 * sin(angle));
    }
    glEnd();

    glTranslatef(0,-5,0);
    //Middle face polygon
    glBegin(GL_POLYGON);
        glColor3f(0, 0, 0); glVertex2f(0, -12);
        glColor3f(0, 0, 0); glVertex2f(13, 9);
        glColor3f(0, 0, 0); glVertex2f(17, 24);
        glColor3f(1, 0, 0); glVertex2f(12, 18);
        glColor3f(1, 0, 0); glVertex2f(7, 17);
        glColor3f(1, 0, 0); glVertex2f(5, 10);
        glColor3f(1, 0, 0); glVertex2f(0, 7);
        glColor3f(1, 0, 0); glVertex2f(-5, 10);
        glColor3f(1, 0, 0); glVertex2f(-7, 17);
        glColor3f(1, 0, 0); glVertex2f(-12, 18);
        glColor3f(0, 0, 0); glVertex2f(-17, 24);
        glColor3f(0, 0, 0); glVertex2f(-13, 9);
    glEnd();

    //Right cheek triangle
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 0); glVertex2f(2, -11);
        glColor3f(0, 0, 0); glVertex2f(10, -7);
        glColor3f(1, 0, 0); glVertex2f(12, 6);
    glEnd();

    //Left cheek triangle
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 0); glVertex2f(-2, -11);
        glColor3f(0, 0, 0); glVertex2f(-10, -7);
        glColor3f(1, 0, 0); glVertex2f(-12, 6);
    glEnd();

    //Right eye polygon
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.9,0.9); glVertex2f(2, 4);
        glColor3f(0.9,0.9,0.9); glVertex2f(5, 8);
        glColor3f(0.9,0.9,0.9); glVertex2f(8, 8);
        glColor3f(0.9,0.9,0.9); glVertex2f(7, 6);
    glEnd();

    //Left eye polygon
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.9,0.9); glVertex2f(-2, 4);
        glColor3f(0.9,0.9,0.9); glVertex2f(-5, 8);
        glColor3f(0.9,0.9,0.9); glVertex2f(-8, 8);
        glColor3f(0.9,0.9,0.9); glVertex2f(-7, 6);
    glEnd();

    //Left eye brows
    glLineWidth(8.0);
    glBegin(GL_LINES);
        glColor3f(0.9,0.9,0.9); glVertex2f(-11, 16);
        glColor3f(0.9,0.9,0.9); glVertex2f(0,14);
        glColor3f(0.9,0.9,0.9); glVertex2f(0,14);
        glColor3f(0.9,0.9,0.9); glVertex2f(11, 16);
        glColor3f(0.9,0.9,0.9); glVertex2f(-10, 13);
        glColor3f(0.9,0.9,0.9); glVertex2f(0,11);
        glColor3f(0.9,0.9,0.9); glVertex2f(0,11);
        glColor3f(0.9,0.9,0.9); glVertex2f(10, 13);
    glEnd();

    //Middle crown main polygon
    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0); glVertex2f(0, 8.5);
        glColor3f(1, 0, 0); glVertex2f(4, 11);
        glColor3f(0, 0, 0); glVertex2f(8, 24);
        glColor3f(1, 0, 0); glVertex2f(3, 20);
        glColor3f(1, 0, 0); glVertex2f(0, 16);
        glColor3f(1, 0, 0); glVertex2f(-3, 20);
        glColor3f(0, 0, 0); glVertex2f(-8, 24);
        glColor3f(1, 0, 0); glVertex2f(-4, 11);
    glEnd();

    //Middle crown triangle
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0); glVertex2f(0, 18);
        glColor3f(0, 0, 0); glVertex2f(2, 20);
        glColor3f(0, 0, 0); glVertex2f(-2, 20);
    glEnd();


        glFlush();

    glFlush();


}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25,25,-25,25);
    glMatrixMode(GL_MODELVIEW);
}
