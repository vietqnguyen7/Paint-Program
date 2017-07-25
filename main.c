/* Viet Nguyen*/

#include <stdio.h>
#include <GL/glut.h> 
#include <math.h>

#define CANVAS_WIDTH 640
#define CANVAS_HEIGHT 480

int clicks = 0;// Numbers of click initated since mode started.
int mode = 5; // 0 = rectangle, 1 = ellipse, 2 = line, 3 = bezier curve.
int filled = 2; //Checks if filled or not (for rectangle and ellipse
GLsizei rx1 = 0, ry1 = 0;//First coordinate for rectangle .
GLsizei rx2 = 0, ry2 = 0;//Second coordinate for rectangle.
GLsizei lx1 = 0, ly1 = 0;//First coordinate for line.
GLsizei lx2 = 0, ly2 = 0;//Second coordinate for line
GLsizei Cx, Cy, Mx, My;//Center coordinate and Major Axis coordinate for ellipse
GLsizei bx1, by1, bx2, by2, bx3, by3, bx4, by4;//Bezier curve coordinates for the 4 control points.

//~~~~~// ELLIPSE DRAWING //~~~~~~//
//Setting pixel for ellipse coloring.
void setPix(GLsizei x, GLsizei y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

//Creates a line between two points of an ellipse to give the illusion of a filled ellipse.
void fillPix(GLsizei x, GLsizei y, GLsizei x2, GLsizei y2)
{
	glBegin(GL_LINES);
	glVertex3f(x, y, 0);
	glVertex3f(x2, y2, 0);
	glEnd();
	glFlush();
}

//Plots all the points of the ellipse as well as filling them if filled is true.
void ellipsePlotPoints(GLsizei centerX, GLsizei centerY, GLsizei x, GLsizei y)
{
	setPix(centerX + x, centerY + y);
	setPix(centerX - x, centerY + y);
	setPix(centerX + x, centerY - y);
	setPix(centerX - x, centerY - y);
	if (filled == 0)
	{
		fillPix(centerX + x, centerY + y, centerX - x, centerY + y);
		fillPix(centerX + x, centerY - y, centerX - x, centerY - y);
	}
}

//~~~~~~~//RECTANGLE DRAWING //~~~~~~~~//
//menu for filled rectangle.
void recFilledMenu(int value)
{
	clicks = 0;
	filled = 0;
	mode = 0;
	printf("Mode is %d, and filled is %d\n", mode, filled);
	switch (value)
	{
	case 1:
		printf("Rectangle is red!\n");
		glColor3ub(255, 0, 0);
		break;
	case 2:
		printf("Rectangle is green!\n");
		glColor3ub(0, 255, 0);
		break;
	case 3:
		printf("Rectangle is blue!\n");
		glColor3ub(0, 0, 255);
		break;
	case 4:
		printf("Rectangle is yellow!\n");
		glColor3ub(255, 255, 0);
		break;
	case 5:
		printf("Rectangle is purple!\n");
		glColor3ub(128, 0, 128);
		break;
	case 6:
		printf("Rectangle is orange!\n");
		glColor3ub(255, 165, 0);
		break;
	case 7:
		printf("Rectangle is pink!\n");
		glColor3ub(255, 192, 203);
		break;
	case 8:
		printf("Rectangle is white!\n");
		glColor3ub(255, 255, 255);
		break;

	}
}
//menu for outlined rectangle.
void recOutlineMenu(int value)
{
	clicks = 0;
	filled = 1;
	mode = 0;
	printf("Mode is %d, and filled is %d\n", mode, filled);
	switch (value)
	{
	case 1:
		printf("Rectangle is red!\n");
		glColor3ub(255, 0, 0);
		break;
	case 2:
		printf("Rectangle is green!\n");
		glColor3ub(0, 255, 0);
		break;
	case 3:
		printf("Rectangle is blue!\n");
		glColor3ub(0, 0, 255);
		break;
	case 4:
		printf("Rectangle is yellow!\n");
		glColor3ub(255, 255, 0);
		break;
	case 5:
		printf("Rectangle is purple!\n");
		glColor3ub(128, 0, 128);
		break;
	case 6:
		printf("Rectangle is orange!\n");
		glColor3ub(255, 165, 0);
		break;
	case 7:
		printf("Rectangle is pink!\n");
		glColor3ub(255, 192, 203);
		break;
	case 8:
		printf("Rectangle is white!\n");
		glColor3ub(255, 255, 255);
		break;


	}
}
//empty rectangle menu
void recMenu(int value)
{
}
//Method to draw rectangle.
void draw_rectangle()
{
	clicks = 0;
	if (filled == 0)
	{
		glBegin(GL_POLYGON);
		glVertex3f(rx1, ry1, 0);
		glVertex3f(rx2, ry1, 0);
		glVertex3f(rx2, ry2, 0);
		glVertex3f(rx1, ry2, 0);
		glEnd();
		glFlush();
		rx1 = 0;
		rx2 = 0;
		ry1 = 0;
		ry2 = 0;
		printf("Drawn the rectangle!\n");

	}
	else if (filled == 1)
	{
		glBegin(GL_LINES);
		glVertex3f(rx1, ry1, 0);
		glVertex3f(rx2, ry1, 0);

		glVertex3f(rx2, ry2, 0);
		glVertex3f(rx1, ry2, 0);

		glVertex3f(rx1, ry1, 0);
		glVertex3f(rx1, ry2, 0);

		glVertex3f(rx2, ry1, 0);
		glVertex3f(rx2, ry2, 0);
		glEnd();
		glFlush();
		rx1 = 0;
		rx2 = 0;
		ry1 = 0;
		ry2 = 0;
		printf("Drawn the rectangle!\n");
	}
}

//menu for filled ellipse.
void ellFilledMenu(int value)
{
	clicks = 0;
	filled = 0;
	mode = 1;
	printf("Mode is %d, and filled is %d\n", mode, filled);
	printf("Click your midpoint!\n");
	switch (value)
	{
	case 1:
		printf("Ellipse is red!\n");
		glColor3ub(255, 0, 0);
		break;
	case 2:
		printf("Ellipse is green!\n");
		glColor3ub(0, 255, 0);
		break;
	case 3:
		printf("Ellipse is blue!\n");
		glColor3ub(0, 0, 255);
		break;
	case 4:
		printf("Ellipse is yellow!\n");
		glColor3ub(255, 255, 0);
		break;
	case 5:
		printf("Ellipse is purple!\n");
		glColor3ub(128, 0, 128);
		break;
	case 6:
		printf("Ellipse is orange!\n");
		glColor3ub(255, 165, 0);
		break;
	case 7:
		printf("Ellipse is pink!\n");
		glColor3ub(255, 192, 203);
		break;
	case 8:
		printf("Ellipse is white!\n");
		glColor3ub(255, 255, 255);
		break;
	}
}
//menu for outlined ellipse
void ellOutlineMenu(int value)
{
	clicks = 0;
	filled = 1;
	mode = 1;
	printf("Mode is %d, and filled is %d\n", mode, filled);
	switch (value)
	{
	case 1:
		printf("Ellipse is red!\n");
		glColor3ub(255, 0, 0);
		break;
	case 2:
		printf("Ellipse is green!\n");
		glColor3ub(0, 255, 0);
		break;
	case 3:
		printf("Ellipse is blue!\n");
		glColor3ub(0, 0, 255);
		break;
	case 4:
		printf("Ellipse is yellow!\n");
		glColor3ub(255, 255, 0);
		break;
	case 5:
		printf("Ellipse is purple!\n");
		glColor3ub(128, 0, 128);
		break;
	case 6:
		printf("Ellipse is orange!\n");
		glColor3ub(255, 165, 0);
		break;
	case 7:
		printf("Ellipse is pink!\n");
		glColor3ub(255, 192, 203);
		break;
	case 8:
		printf("Ellipse is white!\n");
		glColor3ub(255, 255, 255);
		break;
	}
}
//empty ellipse menu
void ellMenu(int value)
{
}
//Method for drawing ellipse
void draw_ellipse()
{
	clicks = 0;
	double distance = sqrt((Mx - Cx) * (Mx - Cx) + (My - Cy) * (My - Cy));
	GLsizei Rx = Cx - distance;
	GLsizei Ry = Cy - distance;
	GLsizei RxSq = Rx * Rx;
	GLsizei RySq = Ry * Ry;
	GLsizei x = 0;
	GLsizei y = Ry;
	GLsizei px = 0;
	GLsizei py = 2 * RxSq * y;
	ellipsePlotPoints(Cx, Cy, x, y);
	GLsizei p = RySq - (RxSq * Ry) + (0.25 * RxSq);
	while (px < py)
	{
		x++;
		px = px + 2 * RySq;
		if (p < 0)
		{
			p = p + RySq + px;
		}
		else
		{
			y--;
			py = py - 2 * RxSq;
			p = p + RySq + px - py;
		}
		ellipsePlotPoints(Cx, Cy, x, y);
	}
	p = RySq * (x + 0.5) * (x + 0.5) + RxSq * (y - 1) * (y - 1) - RxSq*RySq;
	while (y > 0)
	{
		y--;
		py = py - 2 * RxSq;
		if (p > 0)
		{
			p = p + RxSq - py;
		}
		else
		{
			x++;
			px = px + 2 * RySq;
			p = p + RxSq - py + px;
		}
		ellipsePlotPoints(Cx, Cy, x, y);
	}
}


//~~~~~~~//LINE DRAWING//~~~~~~~//
//menu for line drawing
void lineMenu(int value)
{
	clicks = 0;
	mode = 2;
	printf("Mode is %d\n", mode);
	switch (value)
	{
	case 1:
		printf("Line is red!\n");
		glColor3ub(255, 0, 0);
		break;
	case 2:
		printf("Line is green!\n");
		glColor3ub(0, 255, 0);
		break;
	case 3:
		printf("Line is blue!\n");
		glColor3ub(0, 0, 255);
		break;
	case 4:
		printf("Line is yellow!\n");
		glColor3ub(255, 255, 0);
		break;
	case 5:
		printf("Line is purple!\n");
		glColor3ub(128, 0, 128);
		break;
	case 6:
		printf("Line is orange!\n");
		glColor3ub(255, 165, 0);
		break;
	case 7:
		printf("Line is pink!\n");
		glColor3ub(255,192,203);
		break;
	case 8:
		printf("Line is white!\n");
		glColor3ub(255, 255, 255);
		break;
	}
}
//Method to draw line
void draw_line()
{
	clicks = 0;
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex3f(lx1, ly1, 0);
	glVertex3f(lx2, ly2, 0);
	glEnd();
	glFlush();
	lx1 = 0;
	lx2 = 0;
	ly1 = 0;
	ly2 = 0;
	printf("Drawn the line!\n");
}

//~~~~~~~//BEZIER DRAWING//~~~~~~~//
void bezMenu(int value)
{
	clicks = 0;
	mode = 3;
	printf(" Mode is %d\n", mode);
	switch (value)
	{
	case 1:
		printf("Bezier curve is red!\n");
		glColor3ub(255, 0, 0);
		break;
	case 2:
		printf("Bezier curve is green!\n");
		glColor3ub(0, 255, 0);
		break;
	case 3:
		printf("Bezier curve is blue!\n");
		glColor3ub(0, 0, 255);
		break;
	case 4:
		printf("Bezier curve is yellow!\n");
		glColor3ub(255, 255, 0);
		break;
	case 5:
		printf("Bezier curve is purple!\n");
		glColor3ub(128, 0, 128);
		break;
	case 6:
		printf("Bezier curve is orange!\n");
		glColor3ub(255, 165, 0);
		break;
	case 7:
		printf("Bezier curve is pink!\n");
		glColor3ub(255, 192, 203);
		break;
	case 8:
		printf("Bezier curve is white!\n");
		glColor3ub(255, 255, 255);
		break;
	}
}
//Method to draw bezier curve
void draw_bezier()
{
	int i;
	clicks = 0;
	GLfloat ctrlPoints[4][3] = {
		{ bx1,by1,0 },{ bx2,by2,0 },{ bx3,by3,0 },{ bx4,by4,0 } };
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 30; i++)
		glEvalCoord1f((GLfloat)i / 30.0);
	glEnd();
}

//empty main menu
void mainMenu(int value)
{
}


void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();
	if (mode == 0 && clicks == 2)
	{
		draw_rectangle();
	}
	else if (mode == 1 && clicks == 2)
	{
		draw_ellipse();
	}
	else if (mode == 2 && clicks == 2)
	{
		draw_line();
	}
	else if (mode == 3 && clicks == 4)
	{
		draw_bezier();
	}
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 640, 480, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void mouse(int btn, int state, int x, int y)
{
	//Rectangle Drawing
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && mode == 0)
	{
		clicks++;
		printf("Mode is %d and clicks at %d\n", mode, clicks);
		if (clicks == 1)
		{
			rx1 = x;
			ry1 = y;
		}
		else if (clicks == 2)
		{
			rx2 = x;
			ry2 = y;
		}
		printf("Right mouse button clicked at: (%d, %d)\n", x, y);
	}
	//Ellipse Drawing
	else if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && mode == 1)
	{
		clicks++;
		printf("Mode is %d and clicks at %d\n",mode,clicks);
		if (clicks == 1)
	{	
			Cx = x;
			Cy = y;
		}
		else if (clicks == 2)
		{
			Mx = x;
			My = y;
		}
	}
	//Line Drawing
	else if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && mode == 2)
	{
		clicks++;
		printf("Mode is %d and clicks at %d\n", mode, clicks);
		if (clicks == 1)
		{
			lx1 = x;
			ly1 = y;
		}
		else if (clicks == 2)
		{
			lx2 = x;
			ly2 = y;
		}
		printf("Right mouse button clicked at: (%d, %d)\n", x, y);
	}
	//Bezier Curve Drawing
	else if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && mode == 3)
	{
		clicks++;
		printf("Mode is %d and clicks at %d\n", mode, clicks);
		if (clicks == 1)
		{
			bx1 = x;
			by1 = y;
		}
		if (clicks == 2)
		{
			bx2 = x;
			by2 = y;
		}
		if (clicks == 3)
		{
			bx3 = x;
			by3 = y;
		}
		if (clicks == 4)
		{
			bx4 = x;
			by4 = y;
		}
		printf("Right mouse button clicked at: (%d, %d)\n", x, y);
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Viet's Paint");

	int recFilled = glutCreateMenu(recFilledMenu);
	glutAddMenuEntry("red", 1);
	glutAddMenuEntry("green", 2);
	glutAddMenuEntry("blue", 3);
	glutAddMenuEntry("yellow", 4);
	glutAddMenuEntry("purple", 5);
	glutAddMenuEntry("orange", 6);
	glutAddMenuEntry("pink", 7);
	glutAddMenuEntry("white", 8);
	int recOutline = glutCreateMenu(recOutlineMenu);
	glutAddMenuEntry("red", 1);
	glutAddMenuEntry("green", 2);
	glutAddMenuEntry("blue", 3);
	glutAddMenuEntry("yellow", 4);
	glutAddMenuEntry("purple", 5);
	glutAddMenuEntry("orange", 6);
	glutAddMenuEntry("pink", 7);
	glutAddMenuEntry("white", 8);

	int recSubMenu = glutCreateMenu(recMenu);
	glutAddSubMenu("filled", recFilled);
	glutAddSubMenu("outlined", recOutline);

	int ellFilled = glutCreateMenu(ellFilledMenu);
	glutAddMenuEntry("red", 1);
	glutAddMenuEntry("green", 2);
	glutAddMenuEntry("blue", 3);
	glutAddMenuEntry("yellow", 4);
	glutAddMenuEntry("purple", 5);
	glutAddMenuEntry("orange", 6);
	glutAddMenuEntry("pink", 7);
	glutAddMenuEntry("white", 8);
	int ellOutline = glutCreateMenu(ellOutlineMenu);
	glutAddMenuEntry("red", 1);
	glutAddMenuEntry("green", 2);
	glutAddMenuEntry("blue", 3);
	glutAddMenuEntry("yellow", 4);
	glutAddMenuEntry("purple", 5);
	glutAddMenuEntry("orange", 6);
	glutAddMenuEntry("pink", 7);
	glutAddMenuEntry("white", 8);

	int ellSubMenu = glutCreateMenu(ellMenu);
	glutAddSubMenu("filled", ellFilled);
	glutAddSubMenu("outlined", ellOutline);

	int lineSubMenu = glutCreateMenu(lineMenu);
	glutAddMenuEntry("red", 1);
	glutAddMenuEntry("green", 2);
	glutAddMenuEntry("blue", 3);
	glutAddMenuEntry("yellow", 4);
	glutAddMenuEntry("purple", 5);
	glutAddMenuEntry("orange", 6);
	glutAddMenuEntry("pink", 7);
	glutAddMenuEntry("white", 8);

	int bezSubMenu = glutCreateMenu(bezMenu);
	glutAddMenuEntry("red", 1);
	glutAddMenuEntry("green", 2);
	glutAddMenuEntry("blue", 3);
	glutAddMenuEntry("yellow", 4);
	glutAddMenuEntry("purple", 5);
	glutAddMenuEntry("orange", 6);
	glutAddMenuEntry("pink", 7);
	glutAddMenuEntry("white", 8);

	int mainmenu = glutCreateMenu(mainMenu);
	glutAddSubMenu("add rectangle", recSubMenu);
	glutAddSubMenu("add ellipse", ellSubMenu);
	glutAddSubMenu("add line", lineSubMenu);
	glutAddSubMenu("add bezier curve", bezSubMenu);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	glutDisplayFunc(display);
	glClear(GL_COLOR_BUFFER_BIT);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
}
