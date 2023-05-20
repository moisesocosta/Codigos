#include <iostream>
#include <cmath>
#include <vector>
#include <GL/glut.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const float GRAVITY = 0.001f;
const float FRICTION = 0.99f;

struct Ball {
    float x;
    float y;
    float radius;
    float xSpeed;
    float ySpeed;
};

std::vector<Ball> balls;

void drawCircle(float cx, float cy, float radius) {
    const int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    for (const auto& ball : balls) {
        glColor3f(1.0f, 0.0f, 0.0f);
        drawCircle(ball.x, ball.y, ball.radius);
    }

    glutSwapBuffers();
}

void update(int value) {
    for (auto& ball : balls) {
        ball.x += ball.xSpeed;
        ball.y += ball.ySpeed;

        ball.ySpeed -= GRAVITY;
        ball.xSpeed *= FRICTION;
        ball.ySpeed *= FRICTION;

        if (ball.x + ball.radius > 1.0f || ball.x - ball.radius < -1.0f)
            ball.xSpeed = -ball.xSpeed;

        if (ball.y + ball.radius > 1.0f || ball.y - ball.radius < -1.0f)
            ball.ySpeed = -ball.ySpeed;

        for (const auto& otherBall : balls) {
            if (&ball != &otherBall) {
                float dx = otherBall.x - ball.x;
                float dy = otherBall.y - ball.y;
                float distance = sqrtf(dx * dx + dy * dy);
                float minDistance = ball.radius + otherBall.radius;

                if (distance <= minDistance) {
                    float angle = atan2f(dy, dx);
                    float targetXSpeed = cosf(angle) * minDistance;
                    float targetYSpeed = sinf(angle) * minDistance;

                    ball.xSpeed = targetXSpeed;
                    ball.ySpeed = targetYSpeed;

                    // Ajustar a posição para evitar sobreposição
                    float overlap = minDistance - distance;
                    ball.x -= overlap * cosf(angle);
                    ball.y -= overlap * sinf(angle);
                }
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void handleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Ball newBall;
        newBall.x = static_cast<float>(x) / WINDOW_WIDTH * 2 - 1;
        newBall.y = -(static_cast<float>(y) / WINDOW_HEIGHT * 2 - 1);
        newBall.radius = 0.05f;
        newBall.xSpeed = 0.02f;
        newBall.ySpeed = 0.02f;

        balls.push_back(newBall);
    }
}

void initialize() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Side Pocket");
    glutDisplayFunc(drawScene);
    glutMouseFunc(handleMouseClick);
    glutTimerFunc(10, update, 0);
    initialize();
    glutMainLoop();
    return 0;
}
