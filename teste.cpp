#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>

GLint WINDOW_WIDTH = 500, WINDOW_HEIGHT = 500; 
int operacao,desenho;
GLint xi, yi, xf, yf;

void init();
void desenhar();
void alterar_cor(GLubyte key, GLint x, GLint y);
void pontos(GLint x, GLint y); 
void linhas(GLint button, GLint state, GLint x, GLint y);
void retangulo(GLint button, GLint state, GLint x, GLint y);
void criar_menu();
void menu(GLint item_number);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    GLint screen_width = glutGet(GLUT_SCREEN_WIDTH);
    GLint screen_height = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_HEIGHT) / 2);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Projeto");
    
    init();
    glutDisplayFunc(desenhar);
    glutKeyboardFunc(alterar_cor);
    criar_menu();
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glFlush();
}

void desenhar()
{
    switch (operacao) {
        case 1:
            glutMotionFunc(pontos);
            break;
        case 2:
            glutMouseFunc(linhas);
            break;
        case 3:
            glutMouseFunc(retangulo);
            break;
        default:
            glClear(GL_COLOR_BUFFER_BIT);
            break;
    }
    glFlush();
}

void alterar_cor(GLubyte key, GLint x, GLint y)
{
    if (key == 'r' || key == 'R')
    {
        glColor3f(1, 0, 0);
    }
    else if (key == 'g' || key == 'G')
    {
        glColor3f(0, 1, 0);
    }
    else if (key == 'b' || key == 'B')
    {
        glColor3f(0, 0, 1);
    }
    glFlush();
}

void criar_menu()
{
    
    GLint submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Pontos", 1);
    glutAddMenuEntry("Linhas", 2);
    glutAddMenuEntry("Retangulo", 3);
    
    GLint menu_id = glutCreateMenu(menu);  
    glutAddSubMenu("Desenhar", submenu_id);
    glutAddMenuEntry("Limpar", 4);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu(GLint item_number)
{
    operacao = item_number;
    desenhar();
}

void pontos(GLint x, GLint y)
{
    glBegin(GL_POINTS);
        glVertex2f(x, WINDOW_HEIGHT - y); 
    glEnd();
    glFlush();
}

void linhas(GLint button, GLint state, GLint x, GLint y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (xi == 0 && yi == 0) {
            xi = x;
            yi = WINDOW_HEIGHT - y;  
        }
        else {
            xf = x;
            yf = WINDOW_HEIGHT - y;

            glBegin(GL_LINES);
                glVertex2f(xi, yi);
                glVertex2f(xf, yf);
            glEnd();
            glFlush();
            xi = 0;
            yi = 0;
            xf = 0;
            yf = 0;
        }
    }
}

void retangulo(GLint button, GLint state, GLint x, GLint y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (xi == 0 && yi == 0) {
            xi = x;
            yi = WINDOW_HEIGHT - y;  
        }
        else {
            xf = x;
            yf = WINDOW_HEIGHT - y;  
            
            glBegin(GL_LINE_LOOP);
                glVertex2f(xi, yi);
                glVertex2f(xi, yf);
                glVertex2f(xf, yf);
                glVertex2f(xf, yi);
            glEnd();
            glFlush();
            xi = 0;
            yi = 0;
            xf = 0;
            yf = 0;
        }
    }
}