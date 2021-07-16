#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "camera.h"

#include "shadingmanager.h"
#include "geometrymanager.h"

#include "animation_manager.h"

#include "geometrybuilder.h"
#include "environmentbuilder.h"


#include "environmentmanager.h"

using namespace std;




//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

const int WIDTH = 800, HEIGHT = 600;

const int DELTA_TIME = 1000 / 60; // for 60 calls per second

// Instance for managing our shader programs
ShadingManager* shadingmanager = ShadingManager::get_instance();

// Instance for managing the geometries we have.
GeometryManager* geometrymanager = GeometryManager::get_instance();

// Instance for managing the environment (all our models are stored here)
EnvironmentManager* environmentmanager = EnvironmentManager::get_instance();

AnimationManager* animationmanager = AnimationManager::get_instance();

// The player's camera.
Camera* camera = Camera::get_instance();

//--------------------------------------------------------------------------------
// Keyboard handling
//--------------------------------------------------------------------------------

/**
* Handle the keyboard input within the simulation.
* 
* @ref http://mcfletch.github.io/pyopengl/documentation/manual/glutKeyboardFunc.html
* @param key the key input to be handled.
* @param x the mouse x-location in window relative coordinates when the key was pressed
* @param y the mouse y-location in window relative coordinates when the key was pressed
*/
void keyboard_handler(unsigned char key, int x, int y)
{
    if (key == 27)
        glutExit();
    else if (key == 'b') { // b = deBug
        // Print relevant information for model placement in the world.
        std::cout << "(" << camera->get_position().x << ", " << camera->get_position().y << ", " << camera->get_position().z << ")" << std::endl;
        std::cout << "(" << camera->get_target().x << ", " << camera->get_target().y << ", " << camera->get_target().z << ")" << std::endl;
        std::cout << "pitch: " << camera->get_pitch() << std::endl;
        std::cout << "yaw: " << camera->get_yaw() << std::endl;
    }
    else
    {
        Camera::get_instance()->handle_keyboard(key); // handle the user's (camera controlling) input
        animationmanager->toggle_executing_keyed_animation(key);
    }
        
}

/**
* Handle the mouse controls for the player.
* 
* @param xpos the X position of the mouse
* @param ypos the Y position of the mouse
*/
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
    
    // render the objects within the environment.
    environmentmanager->render();

    glutSwapBuffers();
}

void render(int n)
{
    animationmanager->execute_ticked_animations();
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
    glutCreateWindow("Lucas' Fantasy World");
    glutDisplayFunc(render);
    glutSetCursor(GLUT_CURSOR_NONE); // hide cursor
    glutKeyboardFunc(keyboard_handler); // handle keyboard actions
    glutPassiveMotionFunc(mouse_handler); // handle mouse actions
    glutTimerFunc(DELTA_TIME, render, 0);

    glewInit();
}


int main(int argc, char** argv)
{
    init_glut_glew(argc, argv);

    // set the projection for our camera.
    camera->set_projection(
        glm::perspective(
            glm::radians(45.0f),
            1.0f * WIDTH / HEIGHT, 0.1f,
            4000.0f
        )
    );

    // set mouse to middle of screen, such that we do not have a 'jump' when we start using the application.
    glutWarpPointer(WIDTH / 2, HEIGHT / 2);

    // set the position of our light.
    Lighting::get_instance()->set_position(glm::vec3(15, 28, 30));

    // initiate the shaders
    shadingmanager->init("shaders");
    
    // initiate environment and geometries
    builders::geometry::init();
    builders::environment::init();
    
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    // Hide console window
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);
    
    // Main loop
    glutMainLoop();

    return 0;
}
