#include <GL/glew.h>

#include <iostream>

#include "ErrorChecking.h"

void GLClearError() {
    while (glGetError() != GL_NO_ERROR) {

    }
}

void GLCheckError() {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] " << "(" << error << ")" << std::endl;
    }
}

bool GLLogCall(const char* function, const char* file, int line) {

    bool success = true;

    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] " << "(" << error << "): " << function << " in " << file << " at line:" << line << std::endl;
        success = false;
    }

    return success;
}