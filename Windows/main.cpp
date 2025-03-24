#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawWindow() {
    // white windows
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();

    // blue squares 
    glColor3f(0.4f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.4f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.4f);
    glVertex2f(-0.4f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.0f, -0.4f);
    glEnd();

    // Horizontal Bar 
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.02f);
    glVertex2f(0.5f, 0.02f);
    glVertex2f(0.5f, -0.02f);
    glVertex2f(-0.5f, -0.02f);
    glEnd();

    // Vertical Bar 
    glBegin(GL_QUADS);
    glVertex2f(-0.02f, 0.5f);
    glVertex2f(0.02f, 0.5f);
    glVertex2f(0.02f, -0.5f);
    glVertex2f(-0.02f, -0.5f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawWindow();
    glFlush();
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "Windows", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);
    glewInit();
    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}