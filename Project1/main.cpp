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

void keyboard_handler(unsigned char key, int a, int b)
{
    if (key == 27)
        glutExit();
    if (key == 'r') {
        EnvironmentManager& _env = *environmentmanager;
        GeometryManager& _geom = *geometrymanager;
        Environment::refresh_environment(_env, _geom);
    }
    else if (key == 'b') { // b = deBug
        std::cout << "(" << camera->get_position().x << ", " << camera->get_position().y << ", " << camera->get_position().z << ")" << std::endl;
        std::cout << "(" << camera->get_target().x << ", " << camera->get_target().y << ", " << camera->get_target().z << ")" << std::endl;
        std::cout << camera->get_yaw() << std::endl;
        std::cout << camera->get_pitch() << std::endl;
    }
    else
        Camera::get_instance()->handle_keyboard(key, a, b);
}


void enable_cam_handler(int x, int y, int z, int d) {
    // enable camera and then remove handler.
    camera->set_enabled(true);
    glutMouseFunc(0);
}

void mouse_handler(int xpos, int ypos)
{
    camera->handle_mouse(xpos, ypos, WIDTH / 2, HEIGHT / 2);
}


//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void render()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    environmentmanager->render();
    glutSwapBuffers();
}

void render(int n)
{
    render();
    glutTimerFunc(DELTA_TIME, render, 0);
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
    glutCreateWindow("Lucas' neighbourhood");
    glutDisplayFunc(render);
    glutSetCursor(GLUT_CURSOR_NONE); // hide cursor
    glutKeyboardFunc(keyboard_handler);
    glutPassiveMotionFunc(mouse_handler);
    glutMouseFunc(enable_cam_handler);
    glutTimerFunc(DELTA_TIME, render, 0);

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
    
    // initiate the environment
    Environment::init(*environmentmanager, *geometrymanager, "data/");
    
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
