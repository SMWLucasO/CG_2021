#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "camera.h"
#include "shadingmanager.h"
#include "geometrymanager.h"

#include "environmentmanager.h"
#include "environment.h"

using namespace std;


//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

const int WIDTH = 800, HEIGHT = 600;

ShadingManager* shadingmanager = ShadingManager::get_instance();
GeometryManager* geometrymanager = GeometryManager::get_instance();
EnvironmentManager* environmentmanager = EnvironmentManager::get_instance();

Camera* camera = Camera::get_instance();

//--------------------------------------------------------------------------------
// Keyboard handling
//--------------------------------------------------------------------------------

void keyboardHandler(unsigned char key, int a, int b)
{
    if (key == 27)
        glutExit();
}


//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void Render()
{
    // Define background
    static const GLfloat blue[] = { 0.0, 0.0, 0.4, 1.0 };
    glClearBufferfv(GL_COLOR, 0, blue);

    // Swap buffers
    glutSwapBuffers();
}


//------------------------------------------------------------
// void InitGlutGlew(int argc, char **argv)
// Initializes Glut and Glew
//------------------------------------------------------------

void init_glut_glew(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Hello OpenGL");
    glutDisplayFunc(Render);
    glutKeyboardFunc(keyboardHandler);

    glewInit();
}


int main(int argc, char** argv)
{
    init_glut_glew(argc, argv);

    // set the projection.
    camera->set_projection(
        glm::perspective(
            glm::radians(45.0f),
            1.0f * WIDTH / HEIGHT, 0.1f,
            20.0f
        )
    );

    // initiate the shaders
    shadingmanager->init("shaders");

    // initiate the geometries
    geometrymanager->init("<FOLDER_NAME_HERE_TODO>");

    // initiate the environment
    Environment::init(*environmentmanager);

    // Hide console window
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    // Main loop
    glutMainLoop();

    return 0;
}
