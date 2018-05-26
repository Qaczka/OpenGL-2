#include "GL\freeglut.h"

//Rozmiar okna
int w_width = 800;
int w_height = 600;

void init();
void display();
void drawObject(float size, bool colors);
void timer(int value);

int main(int argc, char **argv)
{
	//Inicjalizacja biblioteki i okna
	glutInit(&argc, argv);
	glutInitWindowSize(w_width, w_height);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Lab 2");
	//Inicjalizacja œwiata
	init();
	//Wyœwietlenie œwiata na ekran
	glutDisplayFunc(display);
	//Funkcja timera
	glutTimerFunc(20, timer, 0);
	//Pêtla g³ówna
	glutMainLoop();
	return 0;
}

void init()
{
	//Kolor t³a
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Œwiat³o
	GLfloat light_ambient[4] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[4] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat light_position[4] = { -1.0, -1.0, 0.0, 1.0 };
	GLfloat material[4] = { 0.5, 0.5, 0.5, 1.0 };

	glEnable(GL_LIGHTING);

	glLightfv(GL_AMBIENT, GL_LIGHT0, light_ambient);
	glLightfv(GL_DIFFUSE, GL_LIGHT0, light_diffuse);
	glLightfv(GL_SPECULAR, GL_LIGHT0, light_specular);
	glLightfv(GL_POSITION, GL_LIGHT0, light_position);
	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glEnable(GL_COLOR_MATERIAL);

	glNormal3f(0.1, 0.1, 0.1);
	glEnable(GL_NORMALIZE);

	//Pocz¹tkowe pochylenie szeœcianu (w dó³)
	glRotatef(4, -1.0f, 0.0f, 0.0f);
}

void display()
{
	//Wprowadzenie g³êbi (nie wyœwietlanie obiektów z ty³u)
	glEnable(GL_DEPTH_TEST);
	//Czyszczenie bufora kolorów i bufora g³êbi
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Rysowanie szeœcianu do bufora
	drawObject(0.25, true);
	//Wyœwietlanie szeœcianu na ekran
	glutSwapBuffers();
}

void drawObject(float size, bool colors)
{
	//Obrót i przemieszczanie siê szeœcianu
	glRotatef(2.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.001, 0.0f);

	//Rysowanie szeœcianu
	if (colors)
		glColor3f(1.0f, 0.0f, 0.0f);

	//Przednia œcianka
	glBegin(GL_POLYGON);
	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(-size, -size, -size);
	glEnd();
	
	//Tylna œcianka
	glBegin(GL_POLYGON);
	glVertex3f(-size, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);
	glEnd();

	if (colors)
		glColor3f(0.0f, 1.0f, 0.0f);

	//Lewa œcianka
	glBegin(GL_POLYGON);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);
	glVertex3f(-size, -size, size);
	glVertex3f(-size, -size, -size);
	glEnd();

	//Prawa œcianka
	glBegin(GL_POLYGON);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, -size, -size);
	glEnd();

	if (colors)
		glColor3f(0.0f, 0.0f, 1.0f);

	//Górna œcianka
	glBegin(GL_POLYGON);
	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(-size, size, size);
	glEnd();

	//Dolna œcianka
	glBegin(GL_POLYGON);
	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);
	glEnd();
}

void timer(int value)
{
	//Wyœwietlenie sceny
	display();

	//Kolejne wywo³anie funkcji timera
	glutTimerFunc(20, timer, 0);
}