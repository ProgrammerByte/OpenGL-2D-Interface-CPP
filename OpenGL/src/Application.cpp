//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include "Graphics2D.h"

#include <iostream>

using namespace std;

//for now the coordinates system goes from (-aspectRatio, -1) to (aspectRatio, 1)
int main() {
    //float cbt[][3];
    //cbt = { {0, 1, 2}, {3, 4, 5} };




    Graphics2D engine = Graphics2D(1920 / 2, 1080 / 2, "Application", false);
    //engine.setColour(0, 0, 1, 1);
    //engine.setLineColour(0, 0, 1, 1);
    engine.setFillColour(1, 0, 0, 1);
    engine.setClearColour(0.05, 0.1, 0.25, 1);
    engine.setLineWidth(4);
    engine.resizeText(0.08);
    engine.setRenderType(0);
    //float x = 0;

    float coords[][2] = { {0, 0}, {-0.1, 0.1}, {-0.2, 0.8}, {0.2, 0.9}, {0.8, -0.2} };
    //float** dynamicCoords = engine.convertToDynamic(coords, 5);
    float count = 3;
    //engine.setTextColour(0, 0, 1, 1);
    //string text = "A\nB\n";
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
        //if (engine.mouseButtonPress(GLFW_MOUSE_BUTTON_1)) {
         //   cout << "Button 1 pressed" << endl;
        //}
        //glfwGetMouseButton
        //glfwGetMousePos(&xPos, &yPos);
        //glfwMouse
        engine.getMousePos(&xPos, &yPos); //THIS IS WORKING BUT A SENSE OF SCALE SHOULD PROBABLY BE ADDED
        //cout << xPos << "      " << yPos << endl;
        if (xPos * xPos + yPos * yPos <= 0.9 * 0.9) {
            engine.setFillColour(0, 1, 0, 1);
            if (engine.mouseButtonPress(GLFW_MOUSE_BUTTON_1) == true) {
                hasBegun = true;
            }
        }
        else {
            engine.setFillColour(1, 0, 0, 1);
        }

       // engine.triangle(-1.5, -0.5, -1, 0.5, -0.5, -0.5);
       // x += 0.01;
        //engine.rect(-0.5, 0, 1.4, 0.8);
        //engine.line(0, 0, 0.5, 0.1);
        //engine.polygon(**coords, 5);
        //engine.polygon(dynamicCoords, 5);
        if (hasBegun == true) {
            count += 0.01;
            //engine.resizeText((float)count / 100);
            engine.setCircleVerticesCount((int)count);
            text = "THIS POLYGON HAS \n     ";
            text.append(to_string((int)count));
            text.append(" SIDES");
        }
        else {
            text = "CLICK ME TO BEGIN";
        }
        engine.circle(0, 0, 0.9);
        engine.renderString(-0.83, -0.1, (char*)text.c_str(), text.length());
        
        //engine.renderChar(-0.9, -0.9, (int)count);
        //engine.renderString(-0.98, 0, (char*)text.c_str(), text.length());
        
        engine.clear();
    }
}