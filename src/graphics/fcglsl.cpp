/**
 * @file fcglsl.cpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-21
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#include "fcglsl.hpp"

void fcgraphics::readGLSL(const char *filename, std::string &str)
{
    std::ifstream fin;
    fin.open(filename);
    std::string s;
    while(std::getline(fin,s))
        str += s+'\n';
}

void fcgraphics::compileGLSL(const GLchar *GLSL, GLuint &shader, GLenum type)
{
    shader = glCreateShader(type);
    glShaderSource(shader, 1, GLSL, NULL);
    glCompileShader(shader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if( !success )
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "OpenGL shader failed" << std::endl  
                  << infoLog << std::endl;
        return;
    }
    
}