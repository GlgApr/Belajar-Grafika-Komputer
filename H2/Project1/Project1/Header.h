#include<stdio.h>
#include<glut.h>
void bangun1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(1, 1.0, 1);
	glVertex2d(0, 250);
	glColor3f(0, 1.0, 0);
	glVertex2d(0, -250);
	glColor3f(0.0, 1.0, 0.5);
	glVertex2d(-250, 0);
	glColor3f(0.5, 1.0, 1.0);
	glVertex2d(250, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 1.0);
	glVertex2d(-35, 20);
	glVertex2d(-30, 10);
	glVertex2d(-25, 20);
	glVertex2d(-30, 30);
	glEnd();
	glFlush();
}
void bangun2()
{
	glBegin(GL_QUADS);
	glVertex2d(25, 20);
	glVertex2d(30, 10);
	glVertex2d(35, 20);
	glVertex2d(30, 30);
	glEnd();
}
void bangun3()
{
	glBegin(GL_QUADS);
	glVertex2d(25, -40);
	glVertex2d(30, -50);
	glVertex2d(35, -40);
	glVertex2d(30, -30);
	glEnd();
}
void bangun4()
{
	glBegin(GL_QUADS);
	glVertex2d(-65, -30);
	glVertex2d(-60, -40);
	glVertex2d(-55, -30);
	glVertex2d(-60, -20);
	glEnd();
}
void transformasi()
{
	glColor3f(1.0, 0.0, 1.0);
	bangun2();
	glEnd();
	glColor3f(1.0, 1.0, 0.5);
	glTranslated(15.0, 0.9, 0.0);
	bangun2();
	glEnd();

	glColor3f(0.5, 1.0, 0);
	glRotatef(15, 0, 0, 1);
	bangun3();
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glRotatef(12, 0, 0, 1);
	glScalef(2.0, -0.12, 0);
	bangun4();
	glEnd();
	glFlush();
}
