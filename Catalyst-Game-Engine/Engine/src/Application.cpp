#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <format>

#include "ErrorChecking.h"
#include "rendering/Buffers.h"
#include "rendering/Shading.h"
#include "Inputs.h"

#include "Window.h"

#define print(x) std::cout << x << "\n";

using Rendering::Buffers::VBO;
using Rendering::Buffers::EBO;
using Rendering::Shading::Shader;
using Context::Window;
using Context::CreationHint;

struct Vertex {
    float x, y, z, r, g, b, a;
    int texId;
    float u, v;
};

int main(void)
{
    Vertex a;


    print(sizeof(a))
    print(sizeof(Vertex))

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /* Create a windowed mode window and its OpenGL context */
    Window w = Window(750, 750, "WINDOW TEST");

    w.create();
    window = w.getId();

    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);


    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[8*(2+4)] = {
             0.0f,  0.0f,     // 0
             0.5f,  0.0f,     // 1
             0.5f,  0.5f,     // 2
             0.0f,  0.5f,     // 3
            -0.5f, -0.5f,     // 0
             0.0f, -0.5f,     // 1
             0.0f,  0.0f,     // 2
            -0.5f,  0.0f,     // 3
    };

    float colors[] = {
        1.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
    };
   
    unsigned int indices[6] = {
        0, 1, 2,
        2, 3, 0,
    };

    int vertexSize = (2 + 4) * sizeof(float);
    int numberOfVertecies = 8;


    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create buffer and copy data
    VBO positions_vbo = VBO(numberOfVertecies * 2 * sizeof(float));

    // define vertex layout
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    VBO colors_vbo = VBO(numberOfVertecies * 4 * sizeof(float));

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glEnableVertexAttribArray(1);

    // Create index buffer
    EBO ibo = EBO(indices, 6, 4, 2);

    glBindVertexArray(0);

    positions_vbo.bufferSubData(positions);
    colors_vbo.bufferSubData(colors);
	/*VAOLayout vaoLayout;

	ParseShader(filename, &vertexShader, &fragmentShader);*/

    Shader shader = Shader("resources/shaders/default.vert", "resources/shaders/default.frag");
    shader.use();


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
	{

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glBindVertexArray(vao);
        GLCall(glDrawElements(GL_TRIANGLES, 6*2, GL_UNSIGNED_INT, nullptr););

        glBindVertexArray(0);
        //print("x: " + std::to_string(w.getSize().x) + "y: " + std::to_string(w.getSize().y))

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

