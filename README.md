# OpenGL-2D-Interface-CPP  
This is a project which has the intention of providing a suitable interface for programmers to create shapes and text (with support for keyboard and mouse input) on a window with relative ease in C++ (however doesn't support textures or sound). This project was made using OpenGL, and heavily inspired by other graphics libraries such as LibGDX (Java) which achieve abstraction to a sufficient extent.  
  
The coordinate system for this engine is between (-aspectRatio, -1) and (aspectRatio, 1), where aspectRatio = resX / resY. All colour values are between 0 and 1 inclusive (when determining red, green, and blue components of a given colour). The only text characters currently supported are 0-9 and A-Z (capital letters only) as the text rendering system operates on a 14-segment display. Including "\n" in an input string for text rendering places subsequent letters on the next line.  
  
There are three different render types which this engine supports (0 = filled, 1 = line, 2 = filled with an outline). Fill colour, line colour, and text colour are all stored separatedly and used when needed.  
  
The main cpp file contains a basic framework which allows for a window to be created and constantly refreshed. From here you can use the following methods to render onto this window.  
  
This repository contains a sample program when executed produces a clickble circle on the window. When the circle is clicked numerous regular polygons are created and text appears inside of the polygons to state how many edges that polygon has. This program is here to demonstrate how this interface should be used.  
  
The engine contains the following public methods:  
-Graphics2D(unsigned int resX, unsigned int resY, const char* title, bool fullscreen) - Is the constructor for the engine. The parameters resX and resY refer to the size of the window in pixels (in the x and y direction respectively), title is the title of the window, and fullscreen determines whether the window will be windowed or fullscreen.  
  
-float** convertToDynamic(float coords[][2], int count) - Converts a static float array to a dynamic float array (where count is the size of the static array). This would be needed for other methods which take float** as a parameter.  
  
-double sin(double x, int iterations)  - Calculates sin(x) where iterations is the accuracy of the result.  
  
-double cos(double x, int iterations)  - Calculates cos(x) where iterations is the accuracy of the result.  
  
-bool shouldClose() - Determines whether the window should close (should be used as the condition for the render loop).  
  
-void closeWindow() - Closes the window.  
  
-void clear() - This method should be called at the end of every render cycle (i.e. end of render loop) in order to refresh the window, and ready it for the next render cycle.  
  
-void triangle(float x1, float y1, float x2, float y2, float x3, float y3) - Renders a triangle on screen given three coordinate values.  
  
-void rect(float x, float y, float width, float height) - Renders a rectangle on screen.  
  
-void line(float x1, float y1, float x2, float y2) - Renders a straight line on screen given two coordinate values.  
  
-void point(float x, float y) - Renders a single point on screen given a single coordinate. Uses the line colour.  
  
-void polygon(float** coords, int vertices) - Renders a polygon on screen given that the coords parameter is a two-dimensional float** array of coordinates (i.e. {{0, 0}, {0.2, 0.5}, {0.9, -0.4}} represents a polygon with three vertices) defined either clockwise or anticlockwise. The vertices parameter is an integer which represents how many vertices the given polygon has (i.e. length of the coords array).  
  
-void circle(float x, float y, float radius) - Renders a circle on screen.  
  
-void setRenderType(unsigned int value) - Changes the render type to the given value.  
  
-unsigned int getRenderType() - Returns the current render type in use.  
  
-void setLineColour(float r, float g, float b, float o)  
  
-void setFillColour(float r, float g, float b, float o)  
  
-void setTextColour(float r, float g, float b, float o)  
  
-void setClearColour(float r, float g, float b, float o)  
  
-void setLineWidth(float width) - Determines the thickness of straight lines in pixels.  
  
-float getAspectRatio()  
  
-int getCircleVerticesCount() - Returns the number of vertices used to approximate the shape of a circle.  
  
-void setCircleVerticesCount(int value) - Changes the number of vertices used to approximate the shape of a circle. A greater value would allow for more accurate circles to be rendered (when the circle method is called), however would be more computationally expensive to render.  
  
-bool keyPress(int key) - Determines whether a given key has been pressed given that the key parameter is of the form GLFW_KEY_X (where X is the name of the key in uppercase).  

-int getCurrentKey() - Returns an integer value representing the current key held down. This method returns -1 if no key is currently held down.
  
-bool mouseButtonPress(int button) - Determines whether a given mouse button has been pressed given that the button parameter is of the form GLFW_MOUSE_BUTTON_X (where X is the name of the button).  
  
-void getMousePos(double *xPos, double *yPos) - Takes two references as parameters, and writes the x and y position of the mouse relative to the window to the given references. This position is in the same coordinate system as the one used for rendering shapes, hence can be directly compared to a position within the window.  
  
-void resizeText(float size) - Changes the size of text which could be rendered next. The size parameter determines the width of the text using the same aforementioned coordinate system (the height of the texted is also scaled accordingy).  
  
-void renderString(float xPos, float yPos, string contents) - Renders a given string (consisting only of 0-9 and A-Z characters including spaces) on screen. The xPos and yPos parameters determine the bottom left coordinate of the text.
  
-~Graphics2D() - The deconstructor of the Graphics2D object.  
  
  
  
Last updated 15/05/21 - renderString now takes a string as a parameter instead of a char*, and a memory leak has been fixed regarding the circle method.
