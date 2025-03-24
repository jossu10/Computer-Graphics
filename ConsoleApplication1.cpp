#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Point {
    float x, y;
};

std::vector<Point> controlPoints;
int selectedPoint = -1;

// Recursive de Casteljau algorithm
Point deCasteljau(std::vector<Point> points, float t) {
    if (points.size() == 1) return points[0];
    std::vector<Point> newPoints;
    for (size_t i = 0; i < points.size() - 1; i++) {
        newPoints.push_back({
            (1 - t) * points[i].x + t * points[i + 1].x,
            (1 - t) * points[i].y + t * points[i + 1].y
            });
    }
    return deCasteljau(newPoints, t);
}

void drawBezierCurve() {
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t <= 1; t += 0.01f) {
        Point p = deCasteljau(controlPoints, t);
        glVertex2f(p.x, p.y);
    }
    glEnd();
}

void drawControlPoints() {
    glPointSize(8.0f);
    glBegin(GL_POINTS);
    for (const auto& p : controlPoints) {
        glVertex2f(p.x, p.y);
    }
    glEnd();
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        xpos = (xpos / 400.0) - 1;
        ypos = 1 - (ypos / 400.0);

        if (action == GLFW_PRESS) {
            for (size_t i = 0; i < controlPoints.size(); i++) {
                if (std::hypot(controlPoints[i].x - xpos, controlPoints[i].y - ypos) < 0.05) {
                    selectedPoint = i;
                    break;
                }
            }
        }
        else if (action == GLFW_RELEASE) {
            selectedPoint = -1;
        }
    }
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    if (selectedPoint != -1) {
        controlPoints[selectedPoint].x = (xpos / 400.0) - 1;
        controlPoints[selectedPoint].y = 1 - (ypos / 400.0);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Bezier Curve", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glewInit();

    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    for (int i = 0; i < 4; i++) {
        controlPoints.push_back({ (rand() % 200 - 100) / 100.0f, (rand() % 200 - 100) / 100.0f });
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawBezierCurve();
        drawControlPoints();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}