#include <windows.h>
#include <glut.h>
#include <stdio.h>

int w = 400, h = 400, z = 0;
int x1 = 0, y1 = 0, sudut = 0, z1 = 0;

void kaca()
{
	//atas
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0, 43, z - 6); //untuk mengatur koordinat 3d
	glScalef(3, 0.2, 0); //untuk mengatur ukuran benda
	glutSolidCube(4.2f);
	glPopMatrix();

	//kanan
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(5.85, 35.4, z - 6); //untuk mengatur koordinat 3d
	glScalef(0.2, 3.5, 0); //untuk mengatur ukuran benda
	glutSolidCube(4.2f);
	glPopMatrix();

	//kiri
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-6.05, 35.4, z - 6); //untuk mengatur koordinat 3d
	glScalef(0.2, 3.5, 0); //untuk mengatur ukuran benda
	glutSolidCube(4.2f);
	glPopMatrix();

	//bawah
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0, 28.5, z - 6); //untuk mengatur koordinat 3d
	glScalef(3, 0.2, 0); //untuk mengatur ukuran benda
	glutSolidCube(4.2f);
	glPopMatrix();

	//kaca
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(-0.1, 35.8, z - 6); //untuk mengatur koordinat 3d
	glScalef(2.6, 3.32, 0); //untuk mengatur ukuran benda
	glutSolidCube(4.2f);
	glPopMatrix();
}

void tembok()
{
	//tembok
	glColor3f(0.6, 0.3, 0);
	glPushMatrix();
	glTranslatef(0.0, 16, z - 7); //untuk mengatur koordinat 3d
	glScalef(10, 13, 1.0); //untuk mengatur ukuran benda
	glutSolidCube(4.2f);
	glPopMatrix();
}
void tiang()
{
	//TIANG
	//Tiang Kiri Depan
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(-7.5, -1, z + 2.5);
	glScalef(0.15, 4.0, 0.25);
	glutSolidCube(4.5f);
	glPopMatrix();

	//Tiang Kiri Belakang
	glPushMatrix();
	glTranslatef(-7.5, -1, z - 2.5);
	glScalef(0.15, 4.0, 0.25);
	glutSolidCube(4.5f);
	glPopMatrix();

	//Tiang Kanan Depan
	glPushMatrix();
	glTranslatef(7.5, -1, z + 2.5);
	glScalef(0.15, 4.0, 0.25);
	glutSolidCube(4.5f);
	glPopMatrix();

	//Tiang Kanan Belakang
	glPushMatrix();
	glTranslatef(7.5, -1, z - 2.5);
	glScalef(0.15, 4.0, 0.25);
	glutSolidCube(4.5f);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0);
	//rak 1
	glPushMatrix();
	glTranslatef(0.0, 0.0, z);
	glScalef(3.0, 0.09, 1.5);
	glutSolidCube(6.0f);
	glPopMatrix();

	//rak2
	glPushMatrix();
	glTranslatef(0.0, -7.0, z);
	glScalef(3.0, 0.09, 1.5);
	glutSolidCube(6.0f);
	glPopMatrix();

	//rak3
	glPushMatrix();
	glTranslatef(0.0, 7.0, z);
	glScalef(3.0, 0.09, 1.5);
	glutSolidCube(6.0f);
	glPopMatrix();

}

void rakbuku()
{
	glRotatef(sudut, x1, y1, z1); //untuk rotate
	tembok();
	tiang();
	kaca();
}

void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(25, timer, 0);
}

void resize(void)
{
	glClearColor(1.0, 9.0, 1.0, 0.0); //blackground
	glShadeModel(GL_MODELVIEW);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 1.5, 10.0, 1000.0);

}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1, 1, 1, 1);
	glLoadIdentity();

	glTranslatef(0, 0, -100);// besar kecilnya rak

	//Loop++;
	//   glRotatef(Loop,0.9,4.0,0.6);//rak yang berotasi

	rakbuku();

	glFlush();
	glutSwapBuffers();

}

void tampil()
{
	display();
}

void myKeyboard(unsigned char key, int x, int y){
	if (key == 'a') z += 1;
	else if (key == 'd') z -= 1;
	else if (key == 'x') {
		x1 = 1;
		y1 = 0;
		z1 = 0;
		sudut += 5;
	}
	else if (key == 'y') {
		y1 = 1;
		x1 = 0;
		z1 = 0;
		sudut += -5;
	}
	else if (key == 't') {
		y1 = 1;
		x1 = 0;
		z1 = 0;
		sudut -= -5;
	}
	else if (key == 'z') {
		y1 = 0;
		x1 = 0;
		z1 = 1;
		sudut += -5;
	}
	else if (key == 'c') {
		y1 = 0;
		x1 = 0;
		z1 = 1;
		sudut -= -5;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1000, 700);
	glutCreateWindow("Galang Aprilian");
	glClearColor(0.5, 0.5, 0.0, 0.0);
	glutDisplayFunc(display);
	gluOrtho2D(-320., 320., -240.0, 240.0);
	glutIdleFunc(tampil);
	resize();
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(25, timer, 0);
	glutMainLoop();
	return(0);
}
