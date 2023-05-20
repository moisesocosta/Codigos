#include <GL/glut.h>
#include <cmath>

// Dimensões da janela
int width = 800;
int height = 600;

// Parâmetros do carro
float carX = 400.0f;
float carY = 300.0f;
float carAngle = 0.0f;
float carSpeed = 0.0f;
float carMaxSpeed = 5.0f;
float carAcceleration = 0.05f;
float carDeceleration = 0.1f;
float carSteeringAngle = 0.0f;
float carMaxSteeringAngle = 45.0f;
float carSteeringSpeed = 2.0f;

// Função para desenhar o carro
void drawCar() {
    glPushMatrix();
    glTranslatef(carX, carY, 0.0f);
    glRotatef(carAngle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); // Cor verde
    glVertex2f(-20, 10);
    glVertex2f(-20, -10);
    glVertex2f(20, -10);
    glVertex2f(20, 10);
    glEnd();

    glPopMatrix();
}

// Função para desenhar o circuito
void drawCircuit() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f); // Cor branca

    float radius = 200.0f;
    float centerX = width / 2.0f;
    float centerY = height / 2.0f;
    int numSegments = 100;
    float angleStep = 2.0f * M_PI / numSegments;

    for (int i = 0; i < numSegments; ++i) {
        float angle = i * angleStep;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

// Função para atualizar o movimento do carro
void updateCarMovement() {
    // Atualizar a posição do carro com base na velocidade e ângulo
    carX += carSpeed * sin(carAngle * M_PI / 180.0f);
    carY -= carSpeed * cos(carAngle * M_PI / 180.0f);

    // Atualizar o ângulo do carro com base no ângulo de direção
    carAngle += carSteeringAngle;

    // Limitar a velocidade máxima do carro
    if (carSpeed > carMaxSpeed) {
        carSpeed = carMaxSpeed;
    }

    // Desacelerar o carro quando não há aceleração ou ré
    if (carSpeed > 0.0f && carAcceleration == 0.0f) {
        carSpeed -= carDeceleration;
        if (carSpeed < 0.0f) {
            carSpeed = 0.0f;
        }
    } else if (carSpeed < 0.0f && carAcceleration == 0.0f) {
        carSpeed += carDeceleration;
        if (carSpeed > 0.0f) {
            carSpeed = 0.0f;
        }
    }

    // Limitar o ângulo de direção máximo
    if (carSteeringAngle > carMaxSteeringAngle) {
        carSteeringAngle = carMaxSteeringAngle;
    } else if (carSteeringAngle < -carMaxSteeringAngle) {
        carSteeringAngle = -carMaxSteeringAngle;
    }
}

// Função para lidar com eventos de teclado
void keyboardEvent(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Acelerar para frente quando a tecla 'w' for pressionada
            carAcceleration = 0.05f;
            break;
        case 's': // Acelerar para trás quando a tecla 's' for pressionada
            carAcceleration = -0.05f;
            break;
        case 'a': // Virar para a esquerda quando a tecla 'a' for pressionada
            carSteeringAngle = carSteeringSpeed;
            break;
        case 'd': // Virar para a direita quando a tecla 'd' for pressionada
            carSteeringAngle = -carSteeringSpeed;
            break;
    }
}

// Função para lidar com eventos de teclado soltos
void keyboardUpEvent(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Parar de acelerar para frente quando a tecla 'w' for liberada
        case 's': // Parar de acelerar para trás quando a tecla 's' for liberada
            carAcceleration = 0.0f;
            break;
        case 'a': // Parar de virar para a esquerda quando a tecla 'a' for liberada
        case 'd': // Parar de virar para a direita quando a tecla 'd' for liberada
            carSteeringAngle = 0.0f;
            break;
    }
}

// Função de renderização
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desenhar o circuito
    drawCircuit();

    // Atualizar o movimento do carro
    updateCarMovement();

    // Desenhar o carro
    drawCar();

    glFlush();
}

// Função de atualização da cena
void updateScene(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, updateScene, 0);
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Rock and Roll Racing");

    glutDisplayFunc(renderScene);
    glutKeyboardFunc(keyboardEvent);
    glutKeyboardUpFunc(keyboardUpEvent);

    glutTimerFunc(16, updateScene, 0);

    glutMainLoop();

    return 0;
}
