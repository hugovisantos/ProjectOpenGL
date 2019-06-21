#pragma once
#include <windows.h>
#include <GLFW/\\glfw3.h>
#include <GL\glew.h>
#include <GL\glut.h>
#include <Math.h>
#define PI 3.14159265f

GLfloat ballRadius = 0.5f;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat ballMax, ballMin, ballYMax, ballYMin;
GLfloat xSpeed = 0.02f;
GLfloat ySpeed = 0.007f;
int refrashMillis = 30;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

void initGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0);

}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(ballX, ballY, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	int numSegments = 100;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) {
		angle = i * 2.0f * PI / numSegments;
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	}
	glEnd();

	glutSwapBuffers();

	ballX += xSpeed;
	ballY += ySpeed;

	if (ballX > ballMax) {
		ballX = ballMax;
		xSpeed = -xSpeed;
	}
	else if (ballX < ballMin) {
		ballX = ballMin;
		xSpeed = -xSpeed;
	}
	if (ballY > ballYMax) {
		ballY = ballYMax;
		ySpeed = -ySpeed;

	}
}

