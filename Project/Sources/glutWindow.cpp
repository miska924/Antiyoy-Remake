#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

#include "globals.h"
#include "glutWindow.h"
#include "interact.h"
#include "field.h"
#include "buttons.h"
#include "info.h"

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    drawField();
    drawInfo();
    drawButtons();
    
    glFlush();
    glutSwapBuffers();
}

void Timer(int value) {
    Draw();
    glutTimerFunc(50, Timer, 1);
}

void Initialize() {
    glClearColor(0.3, 0.5, 0.6, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, SZ, 0.0, SZ, -1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);

    // glfwWindowHint(GLFW_SAMPLES, 4);
    // glEnable(GL_MULTISAMPLE);  
}

void GlutWindow(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(WSZ, WSZ);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("PRIVIT");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(Draw);

    glutMotionFunc(MousePressedMove);
    glutPassiveMotionFunc(MouseMove);
    glutMouseFunc(MousePressed);

    glutTimerFunc(50, Timer, 0);
    Initialize();
    glutMainLoop();
}