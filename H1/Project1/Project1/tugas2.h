#include <stdio.h>
#include <glut.h> //fix
void tugas2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 2);
	glVertex2d(0, 30);
	glColor3f(1, 0, 3);
	glVertex2d(30, 50);
	glVertex2d(60, 30);
	glVertex2d(30, 0);
	glBegin(GL_QUADS);
	glVertex2d(0, 30);
	glVertex2d(-30, 50);
	glVertex2d(-60, 30);
	glColor3f(2, 3, 1);
	glVertex2d(-30, 0);
	glBegin(GL_QUADS);
	glVertex2d(30, -50);
	glColor3f(1, 2, 3);
	glVertex2d(-30, -50);
	glVertex2d(-30, 0);
	glColor3f(3, 0, 2);
	glVertex2d(30, 0);
	glEnd();
	glFlush();

}