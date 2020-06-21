# OpenGL-2D-Interface-CPP  
This is a project which has the intention of providing a suitable interface for programmers to create shapes and text (with support for keyboard and mouse input) on a window with relative ease in C++ (however doesn't support textures or sound). This project was made using OpenGL, and heavily inspired by other graphics libraries such as LibGDX (Java) which achieve abstraction to a sufficient extent.  
  
The coordinate system for this engine is between (-aspectRatio, -1) and (aspectRatio, 1), where aspectRatio = resX / resY.  
  
There are three different render types which this engine supports (0 = filled, 1 = line, 2 = filled with an outline). Fill colour, line colour, and text colour are all stored separatedly and used when needed.  
  
The main method contains a sample program when executed produces a clickble circle on the window. When the circle is clicked numerous regular polygons are created and text appears inside of the polygons to state how many edges that polygon has.  
  
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
-void line(float x1, float y1, float x2, float y2) - Renders a straight line on screen given two coordinate values (fill colour is used by default if render type is equal to 0).    
-void polygon(float** coords, int vertices) - Renders a polygon on screen given that the coords parameter is a two-dimensional float** array of coordinates (i.e. {{0, 0}, {0.2, 0.5}, {0.9, -0.4}} represents a polygon with three vertices) defined either clockwise or anticlockwise. The vertices parameter is an integer which represents how many vertices the given polygon has (i.e. length of the coords array).  
-void circle(float x, float y, float radius) - Renders a circle on screen.  
-void setRenderType(unsigned int value) - Changes the render type to the given value.  
-unsigned int getRenderType() - Returns the current render type in use.  
-void setLineColour(float r, float g, float b, float o)  
-void setFillColour(float r, float g, float b, float o)  
-void setTextColour(float r, float g, float b, float o)  
-void setClearColour(float r, float g, float b, float o)  
