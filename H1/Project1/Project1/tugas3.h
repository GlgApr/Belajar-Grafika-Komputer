#include <stdio.h>
#include <glut.h> //fix
void tugas3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0, 110);
	glVertex2d(-100, 80);
	glVertex2d(-120, 0);
	glVertex2d(-110, -80);
	glVertex2d(0, -110);
	glVertex2d(100, -80);
	glVertex2d(120, 0);
	glVertex2d(100, 80);
	glVertex2d(0, 110);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(-600, 0);
	glVertex2i(600, 0);
	glBegin(GL_LINES);
	glVertex2i(0, -600);
	glVertex2i(0, 600);
	glEnd();
	glFlush();

}