//#include <math.h>
//#include <stdio.h>
//#include <glut.h>
//
//void display()
//{
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(-1.0, 25.0, -1.0, 25.0);
//}
//void setPixel(GLint xCoordinate, GLint yCoordinate)
//{
//	glColor3f(1.0, 1.0, 0.0);
//	glBegin(GL_POINTS);
//	glVertex2f(xCoordinate, yCoordinate);
//	glEnd();
//	glFlush();
//}
//void lineBres(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
//{
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_LINES);
//	glLineWidth(5);
//	glVertex2i(0, 0);
//	glVertex2i(25, 0);
//	glVertex2i(0, 0);
//	glVertex2i(0, 25);
//	glEnd();
//	if (x0 == x1) {
//		y0 = y0 + 1;
//	}
//	else if (y0 == y1){
//		x0 = x0 + 1;
//	}
//	GLfloat m = (y1 - y0) / (x1 - x0);
//	if (m > 1)
//	{
//		GLint n = (y1 - y0) + 1;
//		GLfloat x, y;
//		x = x0;
//		y = y0;
//		setPixel(x, y);
//		for (int i = 2; i <= n; i++)
//		{
//						y++;
//						x = round(m*(y - y0) + x0);
//						setPixel(x, y);
//		}
//	}
//	else
//	{
//		GLint n = (x1 - x0) + 1;
//		GLfloat x, y;
//		x = x0;
//		y = y0;
//		setPixel(x, y);
//		for (int i = 2; i <= n; i++)
//		{
//					x++;
//					y = round(m*(x - x0) + y0);
//						setPixel(x, y);
//		}
//	}
//}
//void drawMyLine()
//{
//	glPointSize(7.0);
//	GLfloat x0 = 2;
//	GLfloat y0 = 5;
//	GLfloat xEnd = 20;
//	GLfloat yEnd = 19;
//	lineBres(x0, y0, xEnd, yEnd);
//}
//
//int main()
//{
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("1718125 - Brute Force Algorithm");
//	display();
//	glutDisplayFunc(drawMyLine);
//	glutMainLoop();
//	return 0;
//}


// T 3 DIMENSI

#include<stdlib.h>
#include<glut.h>
float x_pos = 0.0f;
float y_pos = 0.0f;
float z_pos = -10.0f;
float rot = 0.0f;
float stop = 10.0f;
bool* keyStates = new bool[256];
void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)width / (float)height, 1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void putar(int id)
{
	rot += stop;
	glutPostRedisplay();
	glutTimerFunc(100, putaran, 0);
}
void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(x_pos, y_pos, z_pos);
	glRotatef(rot, rot, 0, 0);

	//kotak 1
	// bawah
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	// depan      
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 0.0f, 1.0f);

	// atas     
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	//belakang
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	//kiri
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 1.0f);

	//kanan
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);

	//kotak 1 selesai

	//kotak 2
	//kiri
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(1.0f, -1.0f, 2.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, 2.0f);

	//bawah
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(1.0f, -1.0f, 2.0f);
	glVertex3f(2.0f, -1.0f, 2.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	//kanan
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(2.0f, -1.0f, 2.0f);
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(2.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	//atas
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0f, 0.0f, 2.0f);
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(2.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);

	//depan
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0f, -1.0f, 2.0f);
	glVertex3f(2.0f, -1.0f, 2.0f);
	glVertex3f(2.0f, 0.0f, 2.0f);
	glVertex3f(1.0f, 0.0f, 2.0f);

	//belakang
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);
	glVertex3f(2.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glEnd();


	glFlush();
	glutSwapBuffers();
}


void init()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLdouble)500.0 / (GLdouble)500.0, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	return;
}
int main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("1718125");
	glutDisplayFunc(tampil);
	glutTimerFunc(100, putar, 0);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}
