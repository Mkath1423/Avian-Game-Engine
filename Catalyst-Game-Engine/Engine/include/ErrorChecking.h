#include <GL/glew.h>

#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));


#define GUARD_IN_RANGE(x, low, high, y) if(x < low || x >= high) return y; 

void GLClearError();
void GLCheckError();
bool GLLogCall(const char* function, const char* file, int line);
