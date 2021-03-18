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

const int DELTA_TIME = 10;

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
    if (key == 'r') {
        EnvironmentManager & _env = *EnvironmentManager::get_instance();
        Environment::refresh_environment(_env);
    }
    else
        Camera::get_instance()->handle_keyboard(key, a, b);
}


//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void Render()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    environmentmanager->render();
    glutSwapBuffers();
}

void Render(int n)
{
    Render();
    glutTimerFunc(DELTA_TIME, Render, 0);
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
    glutTimerFunc(DELTA_TIME, Render, 0);

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

    // set the position of our light.
    Lighting::get_instance()->set_position(glm::vec3(3, 10, 2));

    // initiate the shaders
    shadingmanager->init("shaders");
    
    // initiate the geometries
    geometrymanager->init("models");
    
    // initiate the environment
    Environment::init(*environmentmanager, "data/entities/");
    
    // forgive me teacher, for I have sinned.
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    // Hide console window
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);
    
    // Main loop
    glutMainLoop();

    return 0;
}
