#include <cstdlib>
#include <iostream>
#include <vector>
#include <GL/glut.h>
#include <GL/glu.h>

GLint WINDOW_WIDTH = 500, WINDOW_HEIGHT = 500; // Tamanho da janela

void init();
void desenhar(); // Função para desenhar todos os pontos armazenados
void alterar_cor(GLubyte key, GLint x, GLint y);
void pontos_pressionados(GLint button, GLint action, GLint x, GLint y);// Corrigido para ter parâmetros distintos

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Inicializa o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o modo de exibição
    
    GLint screen_width = glutGet(GLUT_SCREEN_WIDTH);  // Largura do monitor
    GLint screen_height = glutGet(GLUT_SCREEN_HEIGHT); // Altura do monitor
    
    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_HEIGHT) / 2); 
    // Centraliza a janela

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); // Inicializa o tamanho da janela
    glutCreateWindow("Projeto"); // Cria a janela com o título
    
    init();
    glutDisplayFunc(desenhar); // Chama a função desenhar
    glutMainLoop(); // Inicia o loop principal
    
    return EXIT_SUCCESS;
}

void init()
{
    glClearColor(0, 0, 0, 1); // Cor de fundo
    glMatrixMode(GL_PROJECTION); // Tipo de projeção
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT); // Coordenadas da janela
}

void desenhar() // Desenha os pontos armazenados
{
    glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela para desenhar
    glutKeyboardFunc(alterar_cor); // Registra a função para eventos de teclado
    glutMouseFunc(pontos_pressionados); // Registra a função para eventos de mouse
    glFlush(); // Atualiza a janela
}

void alterar_cor(GLubyte key, GLint x, GLint y)
{
    if (key == 'r' || key == 'R') // Cor vermelha
    {
        glColor3f(1, 0, 0);
    }
    else if (key == 'g' || key == 'G') // Cor verde
    {
        glColor3f(0, 1, 0);
    }
    else if (key == 'b' || key == 'B') // Cor azul
    {
        glColor3f(0, 0, 1);
    }
    glutPostRedisplay(); // Redesenha a tela
}

void pontos_pressionados(GLint button, GLint action, GLint x, GLint y)
{
    glBegin(GL_POINTS);
        glVertex2f(x, y); // Inverte a coordenada y para a posição correta
    glEnd();
    glutPostRedisplay();
}
