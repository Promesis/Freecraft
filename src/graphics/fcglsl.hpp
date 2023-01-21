/**
 * @file readglsl.hpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-21
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#ifndef fcglsl_hpp
#define fcglsl_hpp

#include <iostream>
#include <fstream>
#include <string>
#include "glad/glad.h"
#include "glfw/glfw3.h"

namespace fcgraphics
{
    void readGLSL(const char * fileName, std::string &str);
    void compileGLSL(const char *glsl, GLuint &shader, GLenum type);
};


#endif