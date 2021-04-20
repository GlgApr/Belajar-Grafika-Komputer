#include<stdlib.h> 
#include<glut.h> 
float z_pos = -10.0f;  float rot = 0.0f;
float y_pos = 0.0f; float x_pos = 0.0f;
float x_rot = 0.0f; float y_rot = 0.0f;
float z_rot = 0.0f;
void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(160, (float)width / (float)height, 1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void putaran(int id)
{
	rot += 0;
	glutPostRedisplay();  // request redisplay
	glutTimerFunc(100, putaran, 0);  // request next timer event
}


void keyboardku(unsigned char key, int x, int y)
{
	if ((key == '<') || (key == ',')) z_pos -= 0.1f;
	if ((key == '>') || (key == '.')) z_pos += 0.1f;
	if ((key == 's') || (key == 'S')) y_pos -= 0.1f;
	if ((key == 'w') || (key == 'W')) y_pos += 0.1f;
	if ((key == 'a') || (key == 'A')) x_pos -= 0.1f;
	if ((key == 'd') || (key == 'D')) x_pos += 0.1f;
	if ((key == 'x') || (key == 'X')) //Rotasi sumbu x kanan
	{
		x_rot = 1.0f;
		y_rot = 0.0f;
		z_rot = 0.0f;
		rot += 10;
	}
}

void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(x_pos, y_pos, z_pos);
	glRotatef(rot, x_rot, y_rot, z_rot);

	// sisi kirir
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(3, -4, 0);
	glVertex3f(3, -6, 0);
	glVertex3f(3, -6, 3);
	glVertex3f(3, -4, 3);
	glEnd();

	// sisi kanan
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(6, -4, 0);
	glVertex3f(6, -6, 0);
	glVertex3f(6, -6, 3);
	glVertex3f(6, -4, 3);
	glEnd();

	// sisi depan

	glColor3f(0.3, 0.3, 0.3);//shape1
	glBegin(GL_POLYGON);
	glVertex3f(3, -4, 0);
	glVertex3f(3, -6, 0);
	glVertex3f(6, -6, 0);
	glVertex3f(6, -4, 0);
	glEnd();

	// sisi belakang

	glColor3f(0.3, 0.3, 0.3);//shape1
	glBegin(GL_POLYGON);
	glVertex3f(3, -4, 3);
	glVertex3f(3, -6, 3);
	glVertex3f(6, -6, 3);
	glVertex3f(6, -4, 3);
	glEnd();

	// sisi atas

	glColor3f(0.5, 0.5, 0.5);//shape1
	glBegin(GL_POLYGON);
	glVertex3f(3, -4, 0);
	glVertex3f(6, -4, 0);
	glVertex3f(6, -4, 3);
	glVertex3f(3, -4, 3);
	glEnd();

	// sisi bawah

	glColor3f(0.5, 0.5, 0.5);//shape1
	glBegin(GL_POLYGON);
	glVertex3f(3, -6, 0);
	glVertex3f(6, -6, 0);
	glVertex3f(6, -6, 3);
	glVertex3f(3, -6, 3);
	glEnd();

	// pegangan

	glColor3f(0.0, 1.0, 0.5);//shape1
	glBegin(GL_POLYGON);
	glVertex3f(3, -4, 0);
	glVertex3f(3, -3, 0);
	glVertex3f(3.5, -3, 0);
	glVertex3f(3.5, -4, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(5, -4, 0);
	glVertex3f(5, -3, 0);
	glVertex3f(4.5, -3, 0);
	glVertex3f(4.5, -4, 0);
	glEnd();

	// tombol
	glColor3f(0.5, 1.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(4.5, -4.5, 0);
	glVertex3f(4.5, -5, 0);
	glVertex3f(5, -5, 0);
	glVertex3f(5, -4.5, 0);
	glEnd();


	glFlush();
	glutSwapBuffers();
}

void init() {
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLdouble)500.0 / (GLdouble)500.0, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	return;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Galang Aprilian");
	glutDisplayFunc(mydisplay);
	glutTimerFunc(100, putaran, 0);
	glutKeyboardFunc(keyboardku);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}

