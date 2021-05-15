//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include "Graphics2D.h"

#include <iostream>

using namespace std;

//for now the coordinates system goes from (-aspectRatio, -1) to (aspectRatio, 1)
int main() {
	Graphics2D engine = Graphics2D(540, 540, "Template", false);
	while (engine.shouldClose() == false) {
		engine.clear();
	}
}