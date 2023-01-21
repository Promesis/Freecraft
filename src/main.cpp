//test if glfw can be compiled.
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "graphics/fcglsl.hpp"

#include <iostream>

void framebufferSizeCallback(GLFWwindow *, int, int);
void inputCallback(GLFWwindow *);

GLfloat coords[]
    {
        -0.5, -0.5, 0.0,
         0.5, -0.5, 0.0,
         0.5,  0.5, 0.0
    };

int main(int argc, char **argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow *window = glfwCreateWindow(800,600,"test",NULL,NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glViewport(0, 0, 800, 600);

    GLuint fs, vs, program;
    std::string fsrc, vsrc;
    fcgraphics::readGLSL("./shaders/fsMain.glsl", fsrc);
    fcgraphics::readGLSL("./shaders/vsMain.glsl", vsrc);

    fcgraphics::compileGLSL(fsrc.c_str(), fs, GL_FRAGMENT_SHADER);
    fcgraphics::compileGLSL(vsrc.c_str(), vs, GL_VERTEX_SHADER);

    program = glCreateProgram();

    glAttachShader(program, fs);
    glAttachShader(program, vs);

    glLinkProgram(program);
    glUseProgram(program);

    glDeleteShader(fs);
    glDeleteShader(vs);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while( !glfwWindowShouldClose(window) ) // basic render loop(actually i rendered nothing)
    {
        inputCallback(window);

        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);



        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void inputCallback(GLFWwindow *window)
{
    if( glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS )
    {
        glfwSetWindowShouldClose(window, true);
    }
}