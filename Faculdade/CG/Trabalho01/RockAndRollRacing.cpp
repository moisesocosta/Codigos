#include <GL/glut.h>
#include <cmath>

// Dimensões da janela
const int WIDTH = 800;
const int HEIGHT = 600;

// Posição e direção inicial do carro
float carPositionX = 0.0f;
float carPositionY = 0.0f;
float carAngle = 0.0f;

// Velocidade e direção do carro
float carSpeed = 0.0f;
float carDirection = 0.0f;

// Função para desenhar o carro
void drawCar() {
    glPushMatrix();
    glTranslatef(carPositionX, carPositionY, 0.0f);
    glRotatef(carAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f); // Cor do carro (vermelho)

    // Desenho do corpo do carro (retângulo)
    glBegin(GL_QUADS);
    glVertex2f(-20.0f, -10.0f);
    glVertex2f(-20.0f, 10.0f);
    glVertex2f(20.0f, 10.0f);
    glVertex2f(20.0f, -10.0f);
    glEnd();

    // Desenho das rodas dianteiras (círculos)
    glColor3f(0.0f, 0.0f, 0.0f); // Cor das rodas (preto)

    glPushMatrix();
    glTranslatef(-15.0f, -10.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Centro do círculo
    for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += 0.1f) {
        float x = 10.0f * std::cos(angle);
        float y = 10.0f * std::sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15.0f, 10.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Centro do círculo
    for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += 0.1f) {
        float x = 10.0f * std::cos(angle);
        float y = 10.0f * std::sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Desenho da roda traseira (círculo)
    glPushMatrix();
    glTranslatef(15.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Centro do círculo
    for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += 0.1f) {
        float x = 10.0f * std::cos(angle);
        float y = 10.0f * std::sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

// Função para desenhar o circuito
void drawTrack() {
    glColor3f(0.0f, 1.0f, 0.0f); // Cor do circuito (verde)

    const float radiusX = 200.0f;
    const float radiusY = 100.0f;
    const int numSegments = 100;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = radiusX * std::cos(theta);
        float y = radiusY * std::sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

// Função para atualizar a lógica do jogo
void update() {
    // Atualizar a posição do carro com base na velocidade e direção
    carPositionX += carSpeed * std::cos(carDirection);
    carPositionY += carSpeed * std::sin(carDirection);

    glutPostRedisplay(); // Redesenha a cena
}

// Função para manipular eventos de teclado
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Acelerar
            carSpeed += 0.1f;
            break;
        case 's': // Reverter
            carSpeed -= 0.1f;
            break;
        case 'a': // Virar à esquerda
            carAngle -= 5.0f;
            carDirection = carAngle * M_PI / 180.0f;
            break;
        case 'd': // Virar à direita
            carAngle += 5.0f;
            carDirection = carAngle * M_PI / 180.0f;
            break;
    }
}

// Função de desenho (callback)
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawTrack();
    drawCar();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Rock and Roll Racing");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WIDTH/2, WIDTH/2, -HEIGHT/2, HEIGHT/2, -1.0, 1.0);

    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
