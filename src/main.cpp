//test if glfw can be compiled.
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "./graphics/fcglsl.hpp"

#include <iostream>

void framebufferSizeCallback(GLFWwindow *, int, int);
void inputCallback(GLFWwindow *);

GLfloat coords[]
    {
        -0.5, -0.5, 0.0,
         0.5, -0.5, 0.0,
         0.5,  0.5, 0.0
    };

const GLchar *fssrc="#version 450 core\nout vec4 color;\nvoid main()\n{\n    color = vec4(1.0, 0.5, 0.2, 1.0);\n}",
             *vssrc="#version 450 core\nlayout (location=0) in vec3 pos;\nvoid main()\n{\n    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);\n}";

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





    //compile shader
    //GLuint fs, vs, program;
    
    /*
    fcgraphics::readGLSL("./shaders/fsMain.glsl", fsrc);
    fcgraphics::readGLSL("./shaders/vsMain.glsl", vsrc);

    fcgraphics::compileGLSL((const GLchar *const *)fsrc.c_str(), fs, GL_FRAGMENT_SHADER);
    fcgraphics::compileGLSL((const GLchar *const *)vsrc.c_str(), vs, GL_VERTEX_SHADER);
    */
    GLuint fs=glCreateShader(GL_FRAGMENT_SHADER), vs=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(fs, 1, (const GLchar *const *)fssrc, NULL);
    glShaderSource(vs, 1, (const GLchar *const *)vssrc, NULL);

    glCompileShader(fs);
    glCompileShader(vs);
    GLuint program = glCreateProgram();
    //attach shader
    glAttachShader(program, fs);
    glAttachShader(program, vs);
    //link program
    glLinkProgram(program);
    glUseProgram(program);

    glDeleteShader(fs);
    glDeleteShader(vs);


    GLuint vbo;
    glGenBuffers(1, &vbo);
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    //location is 0 so first arg is 0, vertex attribute is a vec3 so 2nd arg is 3, type is float, not normalized so false, the 
    //distance between vertexs and attributes are 3 sizes of floats, the offset is 0 because the vbo is declared before.
    

    while( !glfwWindowShouldClose(window) ) // basic render loop(actually i rendered nothing)
    {
        inputCallback(window);

        glEnableVertexAttribArray(0);        

        glDrawArrays(GL_TRIANGLES, 0, 3);

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