//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include "Graphics2D.h"

#include <iostream>

using namespace std;

//for now the coordinates system goes from (-aspectRatio, -1) to (aspectRatio, 1)
int main() {
    Graphics2D engine = Graphics2D(1920 / 2, 1080 / 2, "Application", false);
    engine.setLineColour(0, 0, 1, 1);
    engine.setFillColour(1, 0, 0, 1);
    engine.setClearColour(0.05, 0.1, 0.25, 1);
    engine.setLineWidth(4);
    engine.resizeText(0.08);
    engine.setRenderType(0);

    float coords[][2] = { {0, 0}, {-0.1, 0.1}, {-0.2, 0.8}, {0.2, 0.9}, {0.8, -0.2} };
    float count = 3;
    string text;
    double xPos, yPos;
    bool hasBegun = false;
    while (engine.shouldClose() == false) {
        if (engine.keyPress(GLFW_KEY_ESCAPE) == true) {
            engine.closeWindow();
        }
        if (engine.keyPress(GLFW_KEY_0) == true) {
            engine.setRenderType(0);
        }
        if (engine.keyPress(GLFW_KEY_1) == true) {
            engine.setRenderType(1);
        }
        if (engine.keyPress(GLFW_KEY_2) == true) {
            engine.setRenderType(2);
        }
        engine.getMousePos(&xPos, &yPos);
        if (xPos * xPos + yPos * yPos <= 0.9 * 0.9) {
            engine.setFillColour(0, 1, 0, 1);
            if (engine.mouseButtonPress(GLFW_MOUSE_BUTTON_1) == true) {
                hasBegun = true;
            }
        }
        else {
            engine.setFillColour(1, 0, 0, 1);
        }
        if (hasBegun == true) {
            count += 0.01;
            engine.setCircleVerticesCount((int)count);
            text = "THIS POLYGON HAS \n     ";
            text.append(to_string((int)count));
            text.append(" SIDES");
        }
        else {
            text = "CLICK ME TO BEGIN";
        }
        engine.circle(0, 0, 0.9);
        engine.renderString(-0.83, -0.1, (char*)text.c_str());

        engine.clear();
    }
}