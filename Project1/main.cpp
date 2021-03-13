#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "shading/shading.h"

#include "world/Scene.h"

using namespace std;


//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

const int WIDTH = 800, HEIGHT = 600;

Scene scene = Scene(WIDTH, HEIGHT);

//--------------------------------------------------------------------------------
// Keyboard handling
//--------------------------------------------------------------------------------

void keyboard_handler(unsigned char key, int a, int b)
{
    if (key == 27)
        glutExit();
}


//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void render()
{
    // Define background

    // Swap buffers
    glutSwapBuffers();
}


//------------------------------------------------------------
// Initializes Glut and Glew
//------------------------------------------------------------

void init_glut_glew(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Lucas' neighbourhood");
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard_handler);

    glewInit();
}


int main(int argc, char** argv)
{
    init_glut_glew(argc, argv);
    
    // initiate shaders from main.
    init_shader(Lambert, "shaders/lambert/vertexshader.vert", "shaders/lambert/fragmentshader.frag");
    init_shader(Phong, "shaders/phong/vertexshader.vert", "shaders/phong/fragmentshader.frag");
    init_shader(Basic, "shaders/basic/vertexshader.vert", "shaders/basic/fragmentshader.frag");

    scene.init("data/environment/");

    // Hide console window
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);

    // Main loop
    glutMainLoop();

    return 0;
}
