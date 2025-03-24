#include <GL/glut.h>

float xPos = 0.0f, yPos = 0.0f;  // Square's position

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    glTranslatef(xPos, yPos, 0.0f);  // Apply translation

    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();

    glutSwapBuffers();
}

void keyboard(int key, int, int) {
    float step = 0.05f;  // Movement step size

    switch (key) {
    case GLUT_KEY_UP:    yPos += step; break;
    case GLUT_KEY_DOWN:  yPos -= step; break;
    case GLUT_KEY_LEFT:  xPos -= step; break;
    case GLUT_KEY_RIGHT: xPos += step; break;
    }

    glutPostRedisplay();  // Redraw the scene
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set up orthographic projection
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Moving Square");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);

    glutMainLoop();
    return 0;
}
