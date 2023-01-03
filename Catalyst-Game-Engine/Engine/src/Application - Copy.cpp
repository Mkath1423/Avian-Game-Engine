#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <format>

#include "ErrorChecking.h"
#include "rendering/Buffers.h"
#include "rendering/Shading.h"
#include "Inputs.h"

#include "Window.h"

#define print(x) std::cout << x << std::endl;

using Rendering::Buffers::VBO;
using Rendering::Buffers::EBO;
using Rendering::Shading::Shader;
using Context::Window;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    Window w = Window(750, 750, "WINDOW TEST");
    w.create();
    w.setWindowCallbacks();
    window = w.getId();

    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    Inputs::setCallbacks(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    float verticies[] = {
        -1.f, -1.f,   //1.0f, 1.0f, 1.0f, 1.0f,
         0.f, -1.f,   //1.0f, 1.0f, 1.0f, 1.0f,
         0.f,  0.f,   //1.0f, 1.0f, 1.0f, 1.0f,
        -1.f,  0.f,   //1.0f, 1.0f, 1.0f, 1.0f,

        0.f, 0.f,     //1.0f, 1.0f, 1.0f, 1.0f,
        0.f, 1.f,     //1.0f, 1.0f, 1.0f, 1.0f,
        1.f, 1.f,     //1.0f, 1.0f, 1.0f, 1.0f,
        1.f, 0.f,     //1.0f, 1.0f, 1.0f, 1.0f
    }; 

    
    unsigned int indexs[] = {
        0, 1, 2,
        2, 3, 0,

        4, 5, 6,
        6, 7, 4
    };

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao))

    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));
    GLCall(glEnableVertexAttribArray(0));

    unsigned int vbo;
    GLCall(glGenBuffers(1, &vbo));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo))
    GLCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), verticies, GL_STATIC_DRAW))


    //GLCall(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (2+4)* sizeof(float), 0));
    //GLCall(glEnableVertexAttribArray(1));

    //EBO ibo = EBO(indexs, 6, 4, 2);


    unsigned int ibo;
    GLCall(glGenBuffers(1, &ibo));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * 4 * sizeof(unsigned int), indexs, GL_STATIC_DRAW));

    //GLCall(glBindVertexArray(0))
    //GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    //GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));


	/*VAOLayout vaoLayout;

	ParseShader(filename, &vertexShader, &fragmentShader);*/

    Shader shader = Shader("resources/shaders/default.vert", "resources/shaders/default.frag");
    shader.use();
    
     GLCall(int uView = glGetUniformLocation(shader.getID(), "uView"));
     GLCall(int uProjection = glGetUniformLocation(shader.getID(), "uProjection"));

     ASSERT(uView != -1);
     ASSERT(uProjection != -1);

     float r = 0.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
	{

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        GLCall(glBindVertexArray(vao))
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));

        //GLCall(glUniformMatrix4(u_colorID, r, 0.8f, 0.3f, 1.0f));
        GLCall(glDrawElements(GL_TRIANGLES, 6 * 2, GL_UNSIGNED_INT, nullptr));
        r += 0.01f;

        if (r >= 1.0f) {
            r = 0;
        }

        //print("x: " + std::to_string(w.getSize().x) + "y: " + std::to_string(w.getSize().y))

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        Inputs::update(0.1f);
    }

    glfwTerminate();
    return 0;
}

