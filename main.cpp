#include <iostream>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow *window,int width,int height);
void processInput(GLFWwindow *window);

int main()
{
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
        glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

        int width = 800;
        int height = 600;
        const char *title = "Hello world OpenGL";
        GLFWwindow *window = glfwCreateWindow(width,height,title,NULL,NULL);

        glfwMakeContextCurrent(window);

        if(NULL == window) {
                cerr << "Failed to create GLFW window" << endl;
                glfwTerminate();
                exit(EXIT_FAILURE);
        }

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                cerr << "Failed to initialize GLAD" << endl;
                exit(EXIT_FAILURE);
        }

        glViewport(0,0,width,height);

        glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

        // render loop
        while(!glfwWindowShouldClose(window)) {

                processInput(window);

                glClearColor(0.2f,0.3f,0.3f,1.0f);
                glClear(GL_COLOR_BUFFER_BIT);

                // render
                float vertices[] = {
                        -0.5f, -0.5f, 0.0f,
                         0.5f, -0.5f, 0.0f,
                         0.0f,  0.5f, 0.0f
                };

                unsigned int VBO;
                glGenBuffers(1, &VBO);
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,GL_STATIC_DRAW);

                glfwSwapBuffers(window);
                glfwPollEvents();
        }

        glfwTerminate();

        cout << "Reached end!" << endl;
        return 0;
}

void framebuffer_size_callback(GLFWwindow *window,int width,int height) {
        glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window) {

        // Quit on escape
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(window,true);
        }
}
