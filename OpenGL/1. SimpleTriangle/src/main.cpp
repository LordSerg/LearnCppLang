#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
//fragment shader
const char *fragmentShaderSrc = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
"}\0";
//vertex shader
const char *vertexShaderSrc = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//window size
int windowWidth{800};
int windowHeight{800};
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

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "First triangle", NULL, NULL);
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

    glViewport(0, 0, windowWidth<windowHeight?windowHeight:windowWidth, windowWidth<windowHeight?windowHeight:windowWidth);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    unsigned int vertexShader{glCreateShader(GL_VERTEX_SHADER)};
    glShaderSource(vertexShader,1,&vertexShaderSrc, NULL);
    glCompileShader(vertexShader);
    int success{};
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader,512,NULL, infoLog);
        std::cout<<"Compilation of vertex shader has failed:\n"<<infoLog<<std::endl;
    }

    unsigned int fragmentShader{glCreateShader(GL_FRAGMENT_SHADER)};
    glShaderSource(fragmentShader,1,&fragmentShaderSrc, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader,512,NULL, infoLog);
        std::cout<<"Compilation of fragment shader has failed:\n"<<infoLog<<std::endl;
    }

    //doing shader program (connect every shaser together)
    unsigned int shaderProgram{glCreateProgram()};
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shaderProgram,512,NULL, infoLog);
        std::cout<<"Linking of shader program has failed:\n"<<infoLog<<std::endl;
    }
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    //glUseProgram(shaderProgram);

    //float vertices[]{-0.5f, -0.5f, 0.0f, 
    //                  0.5f, -0.5f, 0.0f,
    //                  -0.5f, 0.5f, 0.0f,
    //                  0.5f, 0.5f, 0.0f};

    //for task1, task2
    float vertices[]{-0.5f, -0.5f, 0.0f, 
                      0.0f, -0.5f, 0.0f,
                      0.0f, 0.0f, 0.0f,
                      0.5f, 0.5f, 0.0f, 
                      0.0f, 0.5f, 0.0f,
                      0.0f, 0.0f, 0.0f};
                      
    unsigned int indeces[]{0,1,2,
                           1,2,3};
    
    //for task2
    unsigned int VAO1,VAO2,VBO1,VBO2;
    glGenVertexArrays(2, (GLuint*)({&VAO1, &VAO2;}));
    glGenBuffers(2, (GLuint*)({&VBO1, &VBO2;}));

    glBindVertexArray();//передать 1 значение и привязать по отдельности VBO1-VAO1 и VBO2-VAO2

    glBindBuffer(GL_ARRAY_BUFFER, );
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    /*//standart
    unsigned int VAO,VBO,EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indeces),indeces,GL_STATIC_DRAW);

    //binding vertex atributes
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    */
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//karkas regime on
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//karkas regime off

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.5f, 0.1f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //glUseProgram(shaderProgram);
        //glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        //glUseProgram(shaderProgram);
        //glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //glBindVertexArray(0);
        
        //task1
        /*Попробуйте нарисовать 2 треугольника рядом друг с другом с помощью функции 
        glDrawArrays(), добавив больше вершин к вашим данным.*/
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        
        //task2
        /*Теперь создайте те же 2 треугольника, используя два разных VAO и VBO для своих данных.*/

        //task3
        /*Создайте две шейдерные программы, где вторая программа использует другой фрагментный шейдер, 
        который выводит желтый цвет; нарисуйте оба треугольника снова, где один из них будет иметь желтый цвет.*/

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);

    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    if(width>height)
        glViewport((width-height)/2, 0, height, height);
    else
        glViewport(0, (height-width)/2, width, width);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window,true);
}