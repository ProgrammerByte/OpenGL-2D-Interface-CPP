#include "Graphics2D.h"
#include "maths.h"

#include <iostream>

using namespace std;

const int xRes = 1920;
const int yRes = 1080;

int currentMode = 0;

float xStretch = 10;
float yStretch = 0.1;
float xMove = 0;
float yMove = 0;

void reset() {
	xStretch = 10;
	yStretch = 0.1;
	xMove = 0;
	yMove = 0;
}

double calcVal(double input) {
	switch (currentMode) {
		case 0:
			return sin(input, 50);
		case 1:
			return cos(input, 50);
		case 2:
			return tan(input, 50);
		case 3:
			return sinh(input, 1000);
		case 4:
			return cosh(input, 1000);
		case 5:
			return tanh(input, 1000);
		case 6:
			return calcExp(input, 1000);
		case 7:
			if (input > 0) {
				return ln(input, 1000);
			}
			return -DBL_MAX;
		case 8:
			return arcSinh(input, 1000); //BROKEN
		case 9:
			return root(input, 2, 1000);
	}
	return 0;
}

void calcGraph(float xCoords[], float yCoords[]) {
	for (int i = 0; i < xRes; i++) {
		yCoords[i] = yStretch * calcVal(xStretch * ((double)xCoords[i] - xMove)) + yMove;
	}
}

bool input(Graphics2D &engine) {
	int key = engine.getCurrentKey();
	if (key != -1) {
		if (key >= '0' && key <= '9') {
			currentMode = key - '0';
			reset();
		}
		else {
			switch (key) {
				case 'W':
					yStretch += 0.01;
					break;
				case 'S':
					yStretch -= 0.01;
					break;
				case 'D':
					xStretch -= 0.1;
					break;
				case 'A':
					xStretch += 0.1;
					break;
				case GLFW_KEY_UP:
					yMove += 0.01;
					break;
				case GLFW_KEY_DOWN:
					yMove -= 0.01;
					break;
				case GLFW_KEY_LEFT:
					xMove -= 0.01;
					break;
				case GLFW_KEY_RIGHT:
					xMove += 0.01;
					break;
				case 'R':
					reset();
					break;
				case GLFW_KEY_ESCAPE:
					engine.closeWindow();
					break;
			}
		}
		//cout << "HELP" << endl;
		return true;
	}
	return false;
}



//for now the coordinates system goes from (-aspectRatio, -1) to (aspectRatio, 1)
const string labels[10] = { "SIN X", "COS X", "TAN X", "SINH X", "COSH X", "TANH X", "EXP X", "LN X", "ARCSINH X", "ROOT X" };
char* controlText = (char*)"NUMBER KEYS TO SELECT GRAPH \n\nW AND S STRETCH IN Y AXIS \nA AND D STRETCH IN X AXIS \n\nARROW KEYS TRANSLATE GRAPH \n\nR TO RESET TRANSFORMATIONS";
int controlTextLength = strlen(controlText);

int main() {
	float xCoords[xRes];
	float yCoords[xRes];

	Graphics2D engine = Graphics2D(xRes, yRes, "Graph", true);
	engine.setLineWidth(4);
	engine.resizeText(0.1);
	float aspectRatio = engine.getAspectRatio();
	double increment = (double)(2 * (double)aspectRatio) / xRes;

	for (int i = 0; i < xRes; i++) {
		xCoords[i] = (i * increment) - aspectRatio;
	}
	calcGraph(xCoords, yCoords);

	while (engine.shouldClose() == false) {
		if (engine.keyPress('C')) {
			engine.renderString(-aspectRatio + 0.01, 0.78, controlText, controlTextLength);
		}
		else {
			engine.renderString(-aspectRatio + 0.01, -0.99, (char*)labels[currentMode].c_str(), labels[currentMode].length());
			engine.renderString(-aspectRatio + 0.01, 0.78, (char*)"C FOR CONTROLS", 14);
			engine.setLineWidth(1);
			engine.setLineColour(0.2, 0.2, 0.2, 1);
			engine.line(0, -1, 0, 1);
			engine.line(-aspectRatio, 0, aspectRatio, 0);
			engine.setLineColour(1, 1, 1, 1);
			for (int i = 0; i < xRes - 1; i++) {
				engine.line(xCoords[i], yCoords[i], xCoords[i + 1], yCoords[i + 1]);
			}

			if (input(engine) == true) {
				calcGraph(xCoords, yCoords);
			}
			engine.setLineWidth(4);
		}

		engine.clear();
	}
}