#include <stdio.h>
#include <glut.h> //fix
void segiempat()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2d(100, 100);
	//glVertex2d(-100, -100);
	glColor3f(1, 0, 0);
	glVertex2d(-100, 100);
	//glVertex2d(-100, 100);
	glColor3f(1, 0, 2);
	glVertex2d(-100, -100);
	//glVertex2d(60, 100);
	glColor3f(1, 0, 4);
	glVertex2d(100, -100);
	//glVertex2d(100, -60);
	glEnd();
	glFlush();

}