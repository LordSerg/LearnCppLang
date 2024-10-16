
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//#include "map.h"
#include "map.h"
void ShowMap();

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
int main()
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int windowWidth{800};
    int windowHeight{800};

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Path find", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to open GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /*make a map*/
    map::generate(50,50);
    ShowMap();
    //doShit();
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.5f, 0.1f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        

        
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window,true);
}

void ShowMap()
{
    /*
    int emb=2;
    int pnt=10;
    for(int i=0;i<map::getW();++i)
    {
        for(int j=0;j<map::getH();++j)
        {
            std::cout<<(map::map_itself[j*map::getW()+i]->x)<<","<<map::map_itself[j*map::getW()+i]->y<<" ";
        }
        std::cout<<"\n";
    }
    */

}