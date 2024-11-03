#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

GLint WINDOW_WIDTH  = 500, WINDOW_HEIGHT = 500;

void init();
void draw_test();
void mouse_test(GLint button, GLint action, GLint x, GLint y);
void mouse_test2(GLint x, GLint y);
void mouse_test3(GLint x, GLint y);
void keyboard_test(GLubyte key, GLint x, GLint y);
void keyboard_test2(GLint key, GLint x, GLint y);
void test_create_menu();
void menu_test(GLint item_number);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    GLint screen_width  = glutGet(GLUT_SCREEN_WIDTH),
          screen_height = glutGet(GLUT_SCREEN_HEIGHT);  
    
    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_HEIGHT) / 2);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("OpenGL manipulação de entradas (teclado/mouse)");
    
    init();
    glutDisplayFunc(draw_test);
    
    glutMouseFunc(mouse_test);
    glutPassiveMotionFunc(mouse_test2);
    glutMotionFunc(mouse_test3);
    
    glutKeyboardFunc(keyboard_test);
    glutSpecialFunc(keyboard_test2);
    
    test_create_menu();
    
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void draw_test()
{
    glClear(GL_COLOR_BUFFER_BIT);
    std::cout << "Desenho\n";
    glFlush();
}

void mouse_test(GLint button, GLint action, GLint x, GLint y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON: 
            std::cout << "Esquerda";
            break;
        case GLUT_MIDDLE_BUTTON:
            std::cout << "Meio";
            break;
        case GLUT_RIGHT_BUTTON:
            std::cout << "Direita";
            break;
        default: 
            break;
    }
    
    if(action == GLUT_DOWN)
        std::cout << " pressiona";
    else // GLUT_UP
        std::cout << " libera";
    
    std::cout << " em (x:" << x << ", y:" << y << ")\n";
}

void mouse_test2(GLint x, GLint y)
{
    std::cout << "Movendo mouse sem clicar para posição (x:" << x << ", y:" << y << ")\n"; 
}

void mouse_test3(GLint x, GLint y)
{
    std::cout << "Arrastando o mouse para posição (x:" << x << ", y:" << y << ")\n"; 
}

void keyboard_test(GLubyte key, GLint x, GLint y)
{
    GLint m = glutGetModifiers();
    
    if(m == GLUT_ACTIVE_SHIFT)
        std::cout << "Shift ou Caps ";
    else if(m == GLUT_ACTIVE_CTRL)
        std::cout << "Control ";
    else if(m == GLUT_ACTIVE_ALT)
        std::cout << "Alt "; 
    
    if(m == GLUT_ACTIVE_CTRL && key == 4)
        exit(EXIT_SUCCESS);

    std::cout << "Tecla: " << (GLint)key << " (x:" << x << ", y:" << y << ")\n"; 
    
    if (key == 27) // ESC = 27
        glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void keyboard_test2(GLint key, GLint x, GLint y)
{
    std::cout << "Tecla especial: " << key << " (x:" << x << ", y:" << y << ")\n"; 
    
    if(key == GLUT_KEY_F11)
        glutFullScreen();
}

void menu_test(GLint item_number)
{
    std::cout << "Item " << item_number << "\n";
    glutPostRedisplay();
}

void test_create_menu()
{
    GLint submenu_id = glutCreateMenu(menu_test);
    glutAddMenuEntry("Subitem 1", 4);
    glutAddMenuEntry("Subitem 2", 5);
    glutAddMenuEntry("Subitem 3", 6);  
    
    GLint menu_id = glutCreateMenu(menu_test);  
    glutAddMenuEntry("Item 1", 1);
    glutAddMenuEntry("Item 2", 2);
    glutAddSubMenu("Item 3", submenu_id);  
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
