//my include
#include "utfString.hpp"
#include "simulation.hpp"
//cpp include
#include <vector>
#include <string>

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <windows.h>

#pragma execution_character_set("utf-8")
#include <io.h>
#include <fcntl.h>

//simulation constants
const int MIN_BALLS{100};
const int MAX_BALLS{1000};
const int MIN_BALLS_PER_SEC{1};
const int MAX_BALLS_PER_SEC{20};

//OpenGL functions def
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//simulation function def
void startSimulation(GLFWwindow *window, simulation *SIM);
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    int NUM_OF_BALLS{};
    int NUM_OF_BALLS_PER_SECOND{};
    
    //input num of balls (100 - 1000)
    std::cout<<"Input number of balls (100 - 1000):\n";
    std::cin>>NUM_OF_BALLS;
    if(NUM_OF_BALLS<MIN_BALLS)NUM_OF_BALLS = MIN_BALLS;
    if(NUM_OF_BALLS>MAX_BALLS)NUM_OF_BALLS = MAX_BALLS;

    //input num of balls per second (1 - 20)
    std::cout<<"Input number of balls per second (1 - 20):\n";
    std::cin>>NUM_OF_BALLS_PER_SECOND;
    if(NUM_OF_BALLS_PER_SECOND<MIN_BALLS_PER_SEC)NUM_OF_BALLS_PER_SECOND = MIN_BALLS_PER_SEC;
    if(NUM_OF_BALLS_PER_SECOND>MAX_BALLS_PER_SEC)NUM_OF_BALLS_PER_SECOND = MAX_BALLS_PER_SEC;

    //clear all + thinking simulation
    std::cout<<"\n\nthinking...\n";

    for(int i=0;i<50;++i)
    {
        waitCursore(i);
        Sleep(50);
    }
    system("CLS");

    //


    //creating openGL window an loading GLFW
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

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Galton board simulation", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to open GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    //load GLAD (for fun, it is not, actually, nesessary)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //main cycle
    int input{1};
    simulation *sim{};
    startSimulation(window,sim);
    while(input!=3)
    {
        std::cout<<"GALTON BOARD SIMULATION"<<std::endl;
        std::cout<<""<<std::endl;
        std::cout<<"Current preset:"<<std::endl;
        std::cout<<"\tnumber of balls  = "<<NUM_OF_BALLS<<std::endl;
        std::cout<<"\tballs per second = "<<NUM_OF_BALLS_PER_SECOND<<std::endl;
        std::cout<<"MENU:"<<std::endl;
        std::cout<<"1 -> start new simulation;"<<std::endl;
        std::cout<<"2 -> change simulation preset;"<<std::endl;
        std::cout<<"3 -> exit;"<<std::endl;
        std::cout<<"input command: "<<std::endl;
        std::cin>>input;
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

void startSimulation(GLFWwindow *window, simulation *SIM)//, std::vector<ball>&balls,grid &g, std::vector<cell>&cells)
{
    bool isFinished{false};
    int i{};
    while(!glfwWindowShouldClose(window)&&!(isFinished))
    {
        processInput(window);

        glClearColor(0.5f, 0.1f, 0.5f, 1.0f);//set backColor
        glClear(GL_COLOR_BUFFER_BIT);

        SIM->moveBalls();
        SIM->checkCollision();
        SIM->draw();
        // for(auto b : balls)
        // {
        //     b->draw();
        //     b->move();
        // }
        // g->checkCollision(b);
        // for(auto b : balls)
        //     b->gravity();
        waitCursore((++i)/100);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    system("CLS");
}