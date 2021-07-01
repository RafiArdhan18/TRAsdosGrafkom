#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);

int is_depth;
void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(0.7803921568627451, 0.9843137254901961, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    glTranslatef(100.0, -100.0, -100.0);

    glPushMatrix();//Bangunan Bola
    glColor3f (0.8901960784313725, 0.8901960784313725, 0.8901960784313725);
    //glRotatef((GLfloat) year, 0.0,0.0,1.0);
    glTranslatef (-150.0, 10.0, 259.0);
    glutWireSphere(105.0, 50.0, 50.0);
    glPopMatrix();

    glBegin(GL_QUADS);//Jalan halaman Rumah
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-500.0, -3.0, -200.0);
    glColor3f(0.0f, 0.4f, 0.4f);
    glVertex3f(-500.0, -3.0, 500.0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(200.0, -3.0, 500.0);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(200.0, -3.0, -200.0);
    glEnd();

    // BANGUNAN 1
    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(150.0, -3.0, 100.0);
    glVertex3f(100.0, -3.0, 100.0);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(150.0, 50.0, 100.0);
    glEnd();

    glBegin(GL_QUADS);//Kanan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(150.0, -3.0, -100.0);
    glVertex3f(100.0, -3.0, -100.0);
    glVertex3f(100.0, 50.0, -100.0);
    glVertex3f(150.0, 50.0, -100.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(150.0, 50.0, 100.0);
    glVertex3f(150.0, -3.0, 100.0);
    glVertex3f(150.0, -3.0, -100.0);
    glVertex3f(150.0, 50.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(150.0, 50.0, -100.0);
    glVertex3f(150.0, -3.0, -100.0);
    glVertex3f(150.0, -3.0, 100.0);
    glVertex3f(150.0, 50.0, 100.0);
    glEnd();

    glBegin(GL_QUADS);//Belakang
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(100.0, -3.0, 100.0);
    glVertex3f(100.0, -3.0, -100.0);
    glVertex3f(100.0, 50.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(100.0, -3.0, 100.0);
    glVertex3f(100.0, -3.0, -100.0);
    glVertex3f(100.0, 50.0, -100.0);
    glEnd();

    glBegin(GL_QUADS);//Atap
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(150.0, 50.0, 100.0);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(100.0, 50.0, -100.0);
    glVertex3f(150.0, 50.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis Atap
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(150.0, 50.0, 100.0);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(100.0, 50.0, -100.0);
    glVertex3f(150.0, 50.0, -100.0);
    glEnd();

    // LIFT 1
    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(170.0, -3.0, -10.0);
    glVertex3f(150.0, -3.0, -10.0);
    glVertex3f(150.0, 40.0, -10.0);
    glVertex3f(170.0, 40.0, -10.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(170.0, -3.0, -10.0);
    glVertex3f(150.0, -3.0, -10.0);
    glVertex3f(150.0, 40.0, -10.0);
    glVertex3f(170.0, 40.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);//Kanan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(170.0, -3.0, 30.0);
    glVertex3f(150.0, -3.0, 30.0);
    glVertex3f(150.0, 40.0, 30.0);
    glVertex3f(170.0, 40.0, 30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(170.0, -3.0, 30.0);
    glVertex3f(150.0, -3.0, 30.0);
    glVertex3f(150.0, 40.0, 30.0);
    glVertex3f(170.0, 40.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(170.0, -3.0, -10.0);
    glVertex3f(170.0, -3.0, 30.0);
    glVertex3f(170.0, 40.0, 30.0);
    glVertex3f(170.0, 40.0, -10.0);
    glEnd();

//JENDELA LIFT DEPAN
    glBegin(GL_QUADS);//Depan
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(170.05, 5.0, -5.0);
    glVertex3f(170.05, 5.0, 25.0);
    glVertex3f(170.05, 32.0, 25.0);
    glVertex3f(170.05, 32.0, -5.0);
    glEnd();

//GARIS JENDELA LIFT DEPAN
    glBegin(GL_LINE_LOOP);//Depan
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(170.05, 5.0, -5.0);
    glVertex3f(170.05, 5.0, 25.0);
    glVertex3f(170.05, 32.0, 25.0);
    glVertex3f(170.05, 32.0, -5.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//tengah
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(170.05, 18.5, -5.0);
    glVertex3f(170.05, 18.5, 25.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//tegak
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(170.05, 5.0, 10.0);
    glVertex3f(170.05, 32.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);//Atas
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(170.0, 40.0, -10.0);
    glVertex3f(170.0, 40.0, 30.0);
    glVertex3f(150.0, 40.0, 30.0);
    glVertex3f(150.0, 40.0, -10.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis atas
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(170.0, 40.0, -10.0);
    glVertex3f(170.0, 40.0, 30.0);
    glVertex3f(150.0, 40.0, 30.0);
    glVertex3f(150.0, 40.0, -10.0);
    glEnd();

    // Tangga 1
    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(170.0, -3.0, 50.0);
    glVertex3f(170.0, 30.0, 50.0);
    glVertex3f(150.0, 30.0, 50.0);
    glVertex3f(150.0, -3.0, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(170.0, -3.0, 50.0);
    glVertex3f(170.0, 30.0, 50.0);
    glVertex3f(150.0, 30.0, 50.0);
    glVertex3f(150.0, -3.0, 50.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(170.0, -3.0, 30.0);
    glVertex3f(170.0, 30.0, 30.0);
    glVertex3f(170.0, 30.0, 50.0);
    glVertex3f(170.0, -3.0, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(170.0, -3.0, 30.0);
    glVertex3f(170.0, 30.0, 30.0);
    glVertex3f(170.0, 30.0, 50.0);
    glVertex3f(170.0, -3.0, 50.0);
    glEnd();


// JENDELA TANGGA 1
    glBegin(GL_QUADS);//JENDELA DEPAN
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(170.0, 2.0, 32.0);
    glVertex3f(170.0, 25.0, 32.0);
    glVertex3f(170.0, 25.0, 48.0);
    glVertex3f(170.0, 2.0, 48.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS JENDELA DEPAN
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(170.0, 2.0, 32.0);
    glVertex3f(170.0, 25.0, 32.0);
    glVertex3f(170.0, 25.0, 48.0);
    glVertex3f(170.0, 2.0, 48.0);
    glEnd();

    glBegin(GL_QUADS);//Atap
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(170.0, 30.0, 30.0);
    glVertex3f(150.0, 30.0, 30.0);
    glVertex3f(150.0, 30.0, 50.0);
    glVertex3f(170.0, 30.0, 50.0);
    glEnd();


    // LIFT 2
    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, -3.0, 200.0);
    glVertex3f(120.0, -3.0, 200.0);
    glVertex3f(120.0, 50.0, 200.0);
    glVertex3f(100.0, 50.0, 200.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, -3.0, 200.0);
    glVertex3f(120.0, -3.0, 200.0);
    glVertex3f(120.0, 50.0, 200.0);
    glVertex3f(100.0, 50.0, 200.0);
    glEnd();

    glBegin(GL_QUADS);//Kanan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(120.0, -3.0, 240.0);
    glVertex3f(100.0, -3.0, 240.0);
    glVertex3f(100.0, 50.0, 240.0);
    glVertex3f(120.0, 50.0, 240.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(120.0, -3.0, 240.0);
    glVertex3f(100.0, -3.0, 240.0);
    glVertex3f(100.0, 50.0, 240.0);
    glVertex3f(120.0, 50.0, 240.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(120.0, -3.0, 200.0);
    glVertex3f(120.0, -3.0, 240.0);
    glVertex3f(120.0, 50.0, 240.0);
    glVertex3f(120.0, 50.0, 200.0);
    glEnd();

//JENDELA LIFT DEPAN 2
    glBegin(GL_QUADS);//JENDELA DEPAN
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(120.05, 5.0, 205.0);
    glVertex3f(120.05, 5.0, 235.0);
    glVertex3f(120.05, 42.0, 235.0);
    glVertex3f(120.05, 42.0, 205.0);
    glEnd();

// garis jendela lift depan 2
    glBegin(GL_LINE_LOOP);//JENDELA DEPAN
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(120.05, 5.0, 205.0);
    glVertex3f(120.05, 5.0, 235.0);
    glVertex3f(120.05, 42.0, 235.0);
    glVertex3f(120.05, 42.0, 205.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//JENDELA TGH
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(120.05, 23.5, 205.0);
    glVertex3f(120.05, 23.5, 235.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//JENDELA TGK
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(120.05, 5.0, 220.0);
    glVertex3f(120.05, 42.0, 220.0);
    glEnd();

    // JENDELA TANGGA 1
    glBegin(GL_QUADS);//JENDELA DEPAN
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(170.05, 2.0, 32.0);
    glVertex3f(170.05, 25.0, 32.0);
    glVertex3f(170.05, 25.0, 48.0);
    glVertex3f(170.05, 2.0, 48.0);
    glEnd();

    glBegin(GL_QUADS);//Atas
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(120.0, 50.0, 200.0);
    glVertex3f(120.0, 50.0, 240.0);
    glVertex3f(100.0, 50.0, 240.0);
    glVertex3f(100.0, 50.0, 200.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis atas
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(120.0, 50.0, 200.0);
    glVertex3f(120.0, 50.0, 240.0);
    glVertex3f(100.0, 50.0, 240.0);
    glVertex3f(100.0, 50.0, 200.0);
    glEnd();

    // Tangga 2
    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, -3.0, 260.0);
    glVertex3f(100.0, 30.0, 260.0);
    glVertex3f(120.0, 30.0, 260.0);
    glVertex3f(120.0, -3.0, 260.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, -3.0, 260.0);
    glVertex3f(100.0, 30.0, 260.0);
    glVertex3f(120.0, 30.0, 260.0);
    glVertex3f(120.0, -3.0, 260.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(120.0, -3.0, 240.0);
    glVertex3f(120.0, 30.0, 240.0);
    glVertex3f(120.0, 30.0, 260.0);
    glVertex3f(120.0, -3.0, 260.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(120.0, -3.0, 240.0);
    glVertex3f(120.0, 30.0, 240.0);
    glVertex3f(120.0, 30.0, 260.0);
    glVertex3f(120.0, -3.0, 260.0);
    glEnd();

// JENDELA TANGGA 2
    glBegin(GL_QUADS);//JENDELA DEPAN
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(120.05, 2.0, 242.0);
    glVertex3f(120.05, 25.0, 242.0);
    glVertex3f(120.05, 25.0, 258.0);
    glVertex3f(120.05, 2.0, 258.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS JENDELA DEPAN
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(120.05, 2.0, 242.0);
    glVertex3f(120.05, 25.0, 242.0);
    glVertex3f(120.05, 25.0, 258.0);
    glVertex3f(120.05, 2.0, 258.0);
    glEnd();

    glBegin(GL_QUADS);//Atas
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(120.0, 30.0, 240.0);
    glVertex3f(100.0, 30.0, 240.0);
    glVertex3f(100.0, 30.0, 260.0);
    glVertex3f(120.0, 30.0, 260.0);
    glVertex3f(120.0, 30.0, 260.0);
    glEnd();

    //BANGUNAN 2
    glBegin(GL_QUADS);//Kanan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, -3.0, 100.0);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(50.0, -3.0, 100.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //Garis Kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, -3.0, 100.0);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(50.0, -3.0, 100.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, -3.0, 100.0);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(100.0, 50.0, 400.0);
    glVertex3f(100.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //Garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, -3.0, 100.0);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(100.0, 50.0, 400.0);
    glVertex3f(100.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, -3.0, 400.0);
    glVertex3f(100.0, 50.0, 400.0);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(50.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //Garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, -3.0, 400.0);
    glVertex3f(100.0, 50.0, 400.0);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(50.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_QUADS);//Belakang
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(50.0, -3.0, 100.0);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(50.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //Garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, -3.0, 100.0);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(50.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_QUADS);//Atap
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(50.0, 50.0, 100.0);
    glVertex3f(100.0, 50.0, 100.0);
    glVertex3f(100.0, 50.0, 400.0);
    glVertex3f(50.0, 50.0, 400.0);
    glEnd();

    // BANGUNAN 5
    glBegin(GL_QUADS);//KANAN
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(50.0, -3.0, 400.0);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(50.0, 50.0, 370.0);
    glVertex3f(50.0, -3.0, 370.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis KANAN
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, -3.0, 400.0);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(50.0, 50.0, 370.0);
    glVertex3f(50.0, -3.0, 370.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(50.0, -3.0, 400.0);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-300.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, -3.0, 400.0);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-300.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, -3.0, 400.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-300.0, 50.0, 370.0);
    glVertex3f(-300.0, -3.0, 370.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis Kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, -3.0, 400.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-300.0, 50.0, 370.0);
    glVertex3f(-300.0, -3.0, 370.0);
    glEnd();

    glBegin(GL_QUADS);//Belakang
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, -3.0, 370.0);
    glVertex3f(-300.0, 50.0, 370.0);
    glVertex3f(50.0, 50.0, 370.0);
    glVertex3f(50.0, -3.0, 370.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, -3.0, 370.0);
    glVertex3f(-300.0, 50.0, 370.0);
    glVertex3f(50.0, 50.0, 370.0);
    glVertex3f(50.0, -3.0, 370.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(50.0, 50.0, 370.0);
    glVertex3f(-300.0, 50.0, 370.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis ATAP
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, 50.0, 400.0);
    glVertex3f(50.0, 50.0, 370.0);
    glVertex3f(-300.0, 50.0, 370.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glEnd();


     //Jendela bangunan 5 Atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(40.0, 37.0, 400.05);
    glVertex3f(40.0, 25.0, 400.05);
    glVertex3f(10.0, 25.0, 400.05);
    glVertex3f(10.0, 37.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(40.0, 37.0, 400.05);
    glVertex3f(40.0, 25.0, 400.05);
    glVertex3f(10.0, 25.0, 400.05);
    glVertex3f(10.0, 37.0, 400.05);
    glEnd();

    //Jendela bangunan 5 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(40.0, 15.0, 400.05);
    glVertex3f(40.0, 7.0, 400.05);
    glVertex3f(10.0, 7.0, 400.05);
    glVertex3f(10.0, 15.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(40.0, 15.0, 400.05);
    glVertex3f(40.0, 7.0, 400.05);
    glVertex3f(10.0, 7.0, 400.05);
    glVertex3f(10.0, 15.0, 400.05);
    glEnd();

    //Jendela bangunan 5 Atas Part 2
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-10.0, 37.0, 400.05);
    glVertex3f(-10.0, 25.0, 400.05);
    glVertex3f(-40.0, 25.0, 400.05);
    glVertex3f(-40.0, 37.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-10.0, 37.0, 400.05);
    glVertex3f(-10.0, 25.0, 400.05);
    glVertex3f(-40.0, 25.0, 400.05);
    glVertex3f(-40.0, 37.0, 400.05);
    glEnd();

    //Jendela bangunan 5 bawah Part 2
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-10.0, 15.0, 400.05);
    glVertex3f(-10.0, 7.0, 400.05);
    glVertex3f(-40.0, 7.0, 400.05);
    glVertex3f(-40.0, 15.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-10.0, 15.0, 400.05);
    glVertex3f(-10.0, 7.0, 400.05);
    glVertex3f(-40.0, 7.0, 400.05);
    glVertex3f(-40.0, 15.0, 400.05);
    glEnd();


    //Jendela bangunan 5 Atas Part 3
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-60.0, 37.0, 400.05);
    glVertex3f(-60.0, 25.0, 400.05);
    glVertex3f(-90.0, 25.0, 400.05);
    glVertex3f(-90.0, 37.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-60.0, 37.0, 400.05);
    glVertex3f(-60.0, 25.0, 400.05);
    glVertex3f(-90.0, 25.0, 400.05);
    glVertex3f(-90.0, 37.0, 400.05);
    glEnd();

    //Jendela bangunan 5 bawah Part 3
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-60.0, 15.0, 400.05);
    glVertex3f(-60.0, 7.0, 400.05);
    glVertex3f(-90.0, 7.0, 400.05);
    glVertex3f(-90.0, 15.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-60.0, 15.0, 400.05);
    glVertex3f(-60.0, 7.0, 400.05);
    glVertex3f(-90.0, 7.0, 400.05);
    glVertex3f(-90.0, 15.0, 400.05);
    glEnd();

    //Jendela bangunan 5 Atas Part 4
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-110.0, 37.0, 400.05);
    glVertex3f(-110.0, 25.0, 400.05);
    glVertex3f(-140.0, 25.0, 400.05);
    glVertex3f(-140.0, 37.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-110.0, 37.0, 400.05);
    glVertex3f(-110.0, 25.0, 400.05);
    glVertex3f(-140.0, 25.0, 400.05);
    glVertex3f(-140.0, 37.0, 400.05);
    glEnd();

    //Jendela bangunan 5 bawah Part 4
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-110.0, 15.0, 400.05);
    glVertex3f(-110.0, 7.0, 400.05);
    glVertex3f(-140.0, 7.0, 400.05);
    glVertex3f(-140.0, 15.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-110.0, 15.0, 400.05);
    glVertex3f(-110.0, 7.0, 400.05);
    glVertex3f(-140.0, 7.0, 400.05);
    glVertex3f(-140.0, 15.0, 400.05);
    glEnd();


    //Jendela bangunan 5 Atas Part 5
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-160.0, 37.0, 400.05);
    glVertex3f(-160.0, 25.0, 400.05);
    glVertex3f(-190.0, 25.0, 400.05);
    glVertex3f(-190.0, 37.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-160.0, 37.0, 400.05);
    glVertex3f(-160.0, 25.0, 400.05);
    glVertex3f(-190.0, 25.0, 400.05);
    glVertex3f(-190.0, 37.0, 400.05);
    glEnd();

    //Jendela bangunan 5 bawah Part 5
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-160.0, 15.0, 400.05);
    glVertex3f(-160.0, 7.0, 400.05);
    glVertex3f(-190.0, 7.0, 400.05);
    glVertex3f(-190.0, 15.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-160.0, 15.0, 400.05);
    glVertex3f(-160.0, 7.0, 400.05);
    glVertex3f(-190.0, 7.0, 400.05);
    glVertex3f(-190.0, 15.0, 400.05);
    glEnd();


     //Jendela bangunan 5 Atas Part 6
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-210.0, 37.0, 400.05);
    glVertex3f(-210.0, 25.0, 400.05);
    glVertex3f(-240.0, 25.0, 400.05);
    glVertex3f(-240.0, 37.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-210.0, 37.0, 400.05);
    glVertex3f(-210.0, 25.0, 400.05);
    glVertex3f(-240.0, 25.0, 400.05);
    glVertex3f(-240.0, 37.0, 400.05);
    glEnd();

    //Jendela bangunan 5 bawah Part 6
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-210.0, 15.0, 400.05);
    glVertex3f(-210.0, 7.0, 400.05);
    glVertex3f(-240.0, 7.0, 400.05);
    glVertex3f(-240.0, 15.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-210.0, 15.0, 400.05);
    glVertex3f(-210.0, 7.0, 400.05);
    glVertex3f(-240.0, 7.0, 400.05);
    glVertex3f(-240.0, 15.0, 400.05);
    glEnd();


     //Jendela bangunan 5 Atas Part 7
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-260.0, 37.0, 400.05);
    glVertex3f(-260.0, 25.0, 400.05);
    glVertex3f(-290.0, 25.0, 400.05);
    glVertex3f(-290.0, 37.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-260.0, 37.0, 400.05);
    glVertex3f(-260.0, 25.0, 400.05);
    glVertex3f(-290.0, 25.0, 400.05);
    glVertex3f(-290.0, 37.0, 400.05);
    glEnd();

    //Jendela bangunan 5 bawah Part 7
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-260.0, 15.0, 400.05);
    glVertex3f(-260.0, 7.0, 400.05);
    glVertex3f(-290.0, 7.0, 400.05);
    glVertex3f(-290.0, 15.0, 400.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-260.0, 15.0, 400.05);
    glVertex3f(-260.0, 7.0, 400.05);
    glVertex3f(-290.0, 7.0, 400.05);
    glVertex3f(-290.0, 15.0, 400.05);
    glEnd();


    // BANGUNAN 6
    glBegin(GL_QUADS);//KANAN
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, -3.0, -70.0);
    glVertex3f(-300.0, 50.0, -70.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(-300.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis KANAN
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, -3.0, -70.0);
    glVertex3f(-300.0, 50.0, -70.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(-300.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, -3.0, -100.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(100.0, 50.0, -100.0);
    glVertex3f(100.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis Depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, -3.0, -100.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(100.0, 50.0, -100.0);
    glVertex3f(100.0, -3.0, -100.0);
    glEnd();

    //Jendela bangunan 6 Atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(90.0, 37.0, -100.05);
    glVertex3f(90.0, 25.0, -100.05);
    glVertex3f(50.0, 25.0, -100.05);
    glVertex3f(50.0, 37.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(90.0, 37.0, -100.05);
    glVertex3f(90.0, 25.0, -100.05);
    glVertex3f(50.0, 25.0, -100.05);
    glVertex3f(50.0, 37.0, -100.05);
    glEnd();

    //Jendela bangunan 6 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(90.0, 15.0, -100.05);
    glVertex3f(90.0, 7.0, -100.05);
    glVertex3f(50.0, 7.0, -100.05);
    glVertex3f(50.0, 15.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(90.0, 15.0, -100.05);
    glVertex3f(90.0, 7.0, -100.05);
    glVertex3f(50.0, 7.0, -100.05);
    glVertex3f(50.0, 15.0, -100.05);
    glEnd();

    //Jendela bangunan 6 Atas Part 2
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(20.0, 37.0, -100.05);
    glVertex3f(20.0, 25.0, -100.05);
    glVertex3f(-20.0, 25.0, -100.05);
    glVertex3f(-20.0, 37.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(20.0, 37.0, -100.05);
    glVertex3f(20.0, 25.0, -100.05);
    glVertex3f(-20.0, 25.0, -100.05);
    glVertex3f(-20.0, 37.0, -100.05);
    glEnd();

    //Jendela bangunan 6 bawah Part 2
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(20.0, 15.0, -100.05);
    glVertex3f(20.0, 7.0, -100.05);
    glVertex3f(-20.0, 7.0, -100.05);
    glVertex3f(-20.0, 15.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(20.0, 15.0, -100.05);
    glVertex3f(20.0, 7.0, -100.05);
    glVertex3f(-20.0, 7.0, -100.05);
    glVertex3f(-20.0, 15.0, -100.05);
    glEnd();

    //Jendela bangunan 6 Atas Part 3
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-50.0, 37.0, -100.05);
    glVertex3f(-50.0, 25.0, -100.05);
    glVertex3f(-90.0, 25.0, -100.05);
    glVertex3f(-90.0, 37.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-50.0, 37.0, -100.05);
    glVertex3f(-50.0, 25.0, -100.05);
    glVertex3f(-90.0, 25.0, -100.05);
    glVertex3f(-90.0, 37.0, -100.05);
    glEnd();

    //Jendela bangunan 6 bawah Part 3
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-50.0, 15.0, -100.05);
    glVertex3f(-50.0, 7.0, -100.05);
    glVertex3f(-90.0, 7.0, -100.05);
    glVertex3f(-90.0, 15.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-50.0, 15.0, -100.05);
    glVertex3f(-50.0, 7.0, -100.05);
    glVertex3f(-90.0, 7.0, -100.05);
    glVertex3f(-90.0, 15.0, -100.05);
    glEnd();

    //Jendela bangunan 6 Atas Part 4
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-120.0, 37.0, -100.05);
    glVertex3f(-120.0, 25.0, -100.05);
    glVertex3f(-160.0, 25.0, -100.05);
    glVertex3f(-160.0, 37.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-120.0, 37.0, -100.05);
    glVertex3f(-120.0, 25.0, -100.05);
    glVertex3f(-160.0, 25.0, -100.05);
    glVertex3f(-160.0, 37.0, -100.05);
    glEnd();

    //Jendela bangunan 6 bawah Part 4
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-120.0, 15.0, -100.05);
    glVertex3f(-120.0, 7.0, -100.05);
    glVertex3f(-160.0, 7.0, -100.05);
    glVertex3f(-160.0, 15.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-120.0, 15.0, -100.05);
    glVertex3f(-120.0, 7.0, -100.05);
    glVertex3f(-160.0, 7.0, -100.05);
    glVertex3f(-160.0, 15.0, -100.05);
    glEnd();

    //Jendela bangunan 6 Atas Part 5
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-190.0, 37.0, -100.05);
    glVertex3f(-190.0, 25.0, -100.05);
    glVertex3f(-230.0, 25.0, -100.05);
    glVertex3f(-230.0, 37.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-190.0, 37.0, -100.05);
    glVertex3f(-190.0, 25.0, -100.05);
    glVertex3f(-230.0, 25.0, -100.05);
    glVertex3f(-230.0, 37.0, -100.05);
    glEnd();

    //Jendela bangunan 6 bawah Part 5
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-190.0, 15.0, -100.05);
    glVertex3f(-190.0, 7.0, -100.05);
    glVertex3f(-230.0, 7.0, -100.05);
    glVertex3f(-230.0, 15.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-190.0, 15.0, -100.05);
    glVertex3f(-190.0, 7.0, -100.05);
    glVertex3f(-230.0, 7.0, -100.05);
    glVertex3f(-230.0, 15.0, -100.05);
    glEnd();

    //Jendela bangunan 6 Atas Part 6
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-255.0, 37.0, -100.05);
    glVertex3f(-255.0, 25.0, -100.05);
    glVertex3f(-295.0, 25.0, -100.05);
    glVertex3f(-295.0, 37.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-255.0, 37.0, -100.05);
    glVertex3f(-255.0, 25.0, -100.05);
    glVertex3f(-295.0, 25.0, -100.05);
    glVertex3f(-295.0, 37.0, -100.05);
    glEnd();

    //Jendela bangunan 6 bawah Part 6
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-255.0, 15.0, -100.05);
    glVertex3f(-255.0, 7.0, -100.05);
    glVertex3f(-295.0, 7.0, -100.05);
    glVertex3f(-295.0, 15.0, -100.05);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(255 / 255.f, 247 / 255.f, 230 / 255.f);
    glVertex3f(-255.0, 15.0, -100.05);
    glVertex3f(-255.0, 7.0, -100.05);
    glVertex3f(-295.0, 7.0, -100.05);
    glVertex3f(-295.0, 15.0, -100.05);
    glEnd();

    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, -3.0, -70.0);
    glVertex3f(100.0, 50.0, -70.0);
    glVertex3f(100.0, 50.0, -100.0);
    glVertex3f(100.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, -3.0, -70.0);
    glVertex3f(100.0, 50.0, -70.0);
    glVertex3f(100.0, 50.0, -100.0);
    glVertex3f(100.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_QUADS);//Belakang
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, -3.0, -70.0);
    glVertex3f(100.0, 50.0, -70.0);
    glVertex3f(-300.0, 50.0, -70.0);
    glVertex3f(-300.0, -3.0, -70.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, -3.0, -70.0);
    glVertex3f(100.0, 50.0, -70.0);
    glVertex3f(-300.0, 50.0, -70.0);
    glVertex3f(-300.0, -3.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, 50.0, -100.0);
    glVertex3f(100.0, 50.0, -70.0);
    glVertex3f(-300.0, 50.0, -70.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glEnd();

    // BANGUNAN 7
    glBegin(GL_QUADS);//KANAN
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, -3.0, 400.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-350.0, 50.0, 400.0);
    glVertex3f(-350.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis KANAN
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, -3.0, 400.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-350.0, 50.0, 400.0);
    glVertex3f(-350.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, -3.0, 400.0);
    glVertex3f(-350.0, 50.0, 400.0);
    glVertex3f(-350.0, 50.0, -100.0);
    glVertex3f(-350.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, -3.0, 400.0);
    glVertex3f(-350.0, 50.0, 400.0);
    glVertex3f(-350.0, 50.0, -100.0);
    glVertex3f(-350.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_QUADS);//Kiri
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, -3.0, -100.0);
    glVertex3f(-350.0, 50.0, -100.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(-300.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis Kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, -3.0, -100.0);
    glVertex3f(-350.0, 50.0, -100.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(-300.0, -3.0, -100.0);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, -3.0, -100.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-300.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, -3.0, -100.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-300.0, -3.0, 400.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, 50.0, 400.0);
    glVertex3f(-300.0, 50.0, -100.0);
    glVertex3f(-350.0, 50.0, -100.0);
    glVertex3f(-350.0, 50.0, 400.0);
    glEnd();

    // BANGUNAN KECIL - DALAM BANGUNAN PART 1
    glBegin(GL_QUADS);//SAMPING KANAN PART 1
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, -3.0, 320.0);
    glVertex3f(-350.0, 50.0, 320.0);
    glVertex3f(-380.0, 50.0, 300.0);
    glVertex3f(-380.0, -3.0, 300.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING dpn PART 1
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-380.0, -3.0, 300.0);
    glVertex3f(-380.0, 50.0, 300.0);
    glVertex3f(-380.0, 50.0, 170.0);
    glVertex3f(-380.0, -3.0, 170.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING Kiri PART 1
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-380.0, -3.0, 170.0);
    glVertex3f(-380.0, 50.0, 170.0);
    glVertex3f(-350.0, 50.0, 150.0);
    glVertex3f(-350.0, -3.0, 150.0);
    glEnd();

    glBegin(GL_QUADS);//Samping belakang PART 1
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, -3.0, 320.0);
    glVertex3f(-350.0, 50.0, 320.0);
    glVertex3f(-350.0, 50.0, 150.0);
    glVertex3f(-350.0, -3.0, 150.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP PART 1
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, 50.0, 320.0);
    glVertex3f(-380.0, 50.0, 300.0);
    glVertex3f(-380.0, 50.0, 170.0);
    glVertex3f(-350.0, 50.0, 150.0);
    glEnd();

    // GARIS BANGUNAN KECIL - DALAM BANGUNAN PART 1
    glBegin(GL_LINE_LOOP);//SAMPING KANAN PART 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, -3.0, 320.0);
    glVertex3f(-350.0, 50.0, 320.0);
    glVertex3f(-380.0, 50.0, 300.0);
    glVertex3f(-380.0, -3.0, 300.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//SAMPING dpn PART 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-380.0, -3.0, 300.0);
    glVertex3f(-380.0, 50.0, 300.0);
    glVertex3f(-380.0, 50.0, 170.0);
    glVertex3f(-380.0, -3.0, 170.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//SAMPING Kiri PART 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-380.0, -3.0, 170.0);
    glVertex3f(-380.0, 50.0, 170.0);
    glVertex3f(-350.0, 50.0, 150.0);
    glVertex3f(-350.0, -3.0, 150.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Samping belakang PART 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, -3.0, 320.0);
    glVertex3f(-350.0, 50.0, 320.0);
    glVertex3f(-350.0, 50.0, 150.0);
    glVertex3f(-350.0, -3.0, 150.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//ATAP PART 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, 50.0, 320.0);
    glVertex3f(-380.0, 50.0, 300.0);
    glVertex3f(-380.0, 50.0, 170.0);
    glVertex3f(-350.0, 50.0, 150.0);
    glEnd();

    // BANGUNAN KECIL - DALAM BANGUNAN PART 2
    glBegin(GL_QUADS);//SAMPING KANAN PART 2
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, -3.0, 70.0);
    glVertex3f(-350.0, 50.0, 70.0);
    glVertex3f(-380.0, 50.0, 70.0);
    glVertex3f(-380.0, -3.0, 70.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING dpn PART 2
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-380.0, -3.0, 70.0);
    glVertex3f(-380.0, 50.0, 70.0);
    glVertex3f(-380.0, 50.0, 0.0);
    glVertex3f(-380.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING Kiri PART 2
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, -3.0, 0.0);
    glVertex3f(-350.0, 50.0, 0.0);
    glVertex3f(-380.0, 50.0, 0.0);
    glVertex3f(-380.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);//Samping belakang PART 2
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, -3.0, 70.0);
    glVertex3f(-350.0, 50.0, 70.0);
    glVertex3f(-350.0, 50.0, 0.0);
    glVertex3f(-350.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP PART 2
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-350.0, 50.0, 70.0);
    glVertex3f(-350.0, 50.0, 0.0);
    glVertex3f(-380.0, 50.0, 0.0);
    glVertex3f(-380.0, 50.0, 70.0);
    glEnd();

    //GARIS BANGUNAN KECIL - DALAM BANGUNAN PART 2
    glBegin(GL_LINE_LOOP);//SAMPING KANAN PART 2
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, -3.0, 70.0);
    glVertex3f(-350.0, 50.0, 70.0);
    glVertex3f(-380.0, 50.0, 70.0);
    glVertex3f(-380.0, -3.0, 70.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//SAMPING dpn PART 2
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-380.0, -3.0, 70.0);
    glVertex3f(-380.0, 50.0, 70.0);
    glVertex3f(-380.0, 50.0, 0.0);
    glVertex3f(-380.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//SAMPING Kiri PART 2
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, -3.0, 0.0);
    glVertex3f(-350.0, 50.0, 0.0);
    glVertex3f(-380.0, 50.0, 0.0);
    glVertex3f(-380.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Samping belakang PART 2
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, -3.0, 70.0);
    glVertex3f(-350.0, 50.0, 70.0);
    glVertex3f(-350.0, 50.0, 0.0);
    glVertex3f(-350.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//ATAP PART 2
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-350.0, 50.0, 70.0);
    glVertex3f(-350.0, 50.0, 0.0);
    glVertex3f(-380.0, 50.0, 0.0);
    glVertex3f(-380.0, 50.0, 70.0);
    glEnd();

    // Ruang Tengah 1
    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, -3.0, 30.0);
    glVertex3f(-300.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, -3.0, 30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KANAN
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, -3.0, 30.0);
    glVertex3f(-300.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, -3.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, -3.0, 0.0);
    glVertex3f(-300.0, 50.0, 0.0);
    glVertex3f(-150.0, 50.0, 0.0);
    glVertex3f(-150.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KIRI
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, -3.0, 0.0);
    glVertex3f(-300.0, 50.0, 0.0);
    glVertex3f(-150.0, 50.0, 0.0);
    glVertex3f(-150.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-300.0, 50.0, 30.0);
    glVertex3f(-300.0, 50.0, -3.0);
    glVertex3f(-150.0, 50.0, -3.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS ATAP
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-300.0, 50.0, 30.0);
    glVertex3f(-300.0, 50.0, -3.0);
    glVertex3f(-150.0, 50.0, -3.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glEnd();

    //Ruang Tengah 2
    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-150.0, -3.0, 30.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 120.0);
    glVertex3f(-150.0, -3.0, 120.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KIRI
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-150.0, -3.0, 30.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 120.0);
    glVertex3f(-150.0, -3.0, 120.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-120.0, -3.0, 120.0);
    glVertex3f(-120.0, 50.0, 120.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(-120.0, -3.0, 30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KANAN
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-120.0, -3.0, 120.0);
    glVertex3f(-120.0, 50.0, 120.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(-120.0, -3.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-120.0, 50.0, 120.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 120.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS ATAP
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-120.0, 50.0, 120.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 120.0);
    glEnd();

    // Ruang Tengah 3
    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-120.0, -3.0, 30.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(100.0, 50.0, 30.0);
    glVertex3f(100.0, -3.0, 30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KANAN
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-120.0, -3.0, 30.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(100.0, 50.0, 30.0);
    glVertex3f(100.0, -3.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(100.0, -3.0, 0.0);
    glVertex3f(100.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(-120.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KIRI
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0, -3.0, 0.0);
    glVertex3f(100.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(-120.0, -3.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(100.0, 50.0, 0.0);
    glVertex3f(100.0, 50.0, 30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS ATAP
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(100.0, 50.0, 0.0);
    glVertex3f(100.0, 50.0, 30.0);
    glEnd();

    // Ruang Tengah 4
    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-120.0, -3.0, 0.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, -70.0);
    glVertex3f(-120.0, -3.0, -70.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KANAN
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-120.0, -3.0, 0.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, -70.0);
    glVertex3f(-120.0, -3.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-150.0, -3.0, 0.0);
    glVertex3f(-150.0, 50.0, 0.0);
    glVertex3f(-150.0, 50.0, -70.0);
    glVertex3f(-150.0, -3.0, -70.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KIRI
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-150.0, -3.0, 0.0);
    glVertex3f(-150.0, 50.0, 0.0);
    glVertex3f(-150.0, 50.0, -70.0);
    glVertex3f(-150.0, -3.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-150.0, 50.0, -70.0);
    glVertex3f(-150.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, -70.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS ATAP
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-120.0, 50.0, 30.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(100.0, 50.0, 0.0);
    glVertex3f(100.0, 50.0, 30.0);
    glEnd();

    //Atap Tengah
    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS ATAP
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glEnd();

    // Ruang Tengah 5
    glBegin(GL_QUADS);//SAMPING KANAN 1
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(50.0, -3.0, 120.0);
    glVertex3f(50.0, 50.0, 120.0);
    glVertex3f(-120.0, 50.0, 120.0);
    glVertex3f(-120.0, -3.0, 120.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KANAN 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, -3.0, 120.0);
    glVertex3f(50.0, 50.0, 120.0);
    glVertex3f(-120.0, 50.0, 120.0);
    glVertex3f(-120.0, -3.0, 120.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING KANAN 2
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(-150.0, -3.0, 120.0);
    glVertex3f(-150.0, 50.0, 120.0);
    glVertex3f(-300.0, 50.0, 120.0);
    glVertex3f(-300.0, -3.0, 120.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KANAN 2
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-150.0, -3.0, 120.0);
    glVertex3f(-150.0, 50.0, 120.0);
    glVertex3f(-300.0, 50.0, 120.0);
    glVertex3f(-300.0, -3.0, 120.0);
    glEnd();

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(50.0, -3.0, 150.0);
    glVertex3f(50.0, 50.0, 150.0);
    glVertex3f(-300.0, 50.0, 150.0);
    glVertex3f(-300.0, -3.0, 150.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS KIRI
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, -3.0, 150.0);
    glVertex3f(50.0, 50.0, 150.0);
    glVertex3f(-300.0, 50.0, 150.0);
    glVertex3f(-300.0, -3.0, 150.0);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3f(79 / 255.f, 29 / 255.f, 25 / 255.f);
    glVertex3f(50.0, 50.0, 150.0);
    glVertex3f(50.0, 50.0, 120.0);
    glVertex3f(-300.0, 50.0, 120.0);
    glVertex3f(-300.0, 50.0, 150.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS ATAP
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 0.0);
    glVertex3f(-120.0, 50.0, 30.0);
    glEnd();

    //Pintu 1
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(150.05, 15.0, -90.0);
    glVertex3f(150.05, -3.0, -90.0);
    glVertex3f(150.05, -3.0, -60.0);
    glVertex3f(150.05, 15.0, -60.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
     glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 15.0, -90.0);
    glVertex3f(150.05, -3.0, -90.0);
    glVertex3f(150.05, -3.0, -60.0);
    glVertex3f(150.05, 15.0, -60.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 15.0, -75.0);
    glVertex3f(150.05, -3.0, -75.0);
    glEnd();

    //Pintu 2
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(150.05, 15.0, 60.0);
    glVertex3f(150.05, -3.0, 60.0);
    glVertex3f(150.05, -3.0, 90.0);
    glVertex3f(150.05, 15.0, 90.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 15.0, 60.0);
    glVertex3f(150.05, -3.0, 60.0);
    glVertex3f(150.05, -3.0, 90.0);
    glVertex3f(150.05, 15.0, 90.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 15.0, 75.0);
    glVertex3f(150.05, -3.0, 75.0);
    glEnd();

    //Pintu 3
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 15.0, 360.0);
    glVertex3f(100.05, -3.0, 360.0);
    glVertex3f(100.05, -3.0, 390.0);
    glVertex3f(100.05, 15.0, 390.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.05, 15.0, 360.0);
    glVertex3f(100.05, -3.0, 360.0);
    glVertex3f(100.05, -3.0, 390.0);
    glVertex3f(100.05, 15.0, 390.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.05, 15.0, 375.0);
    glVertex3f(100.05, -3.0, 375.0);
    glEnd();

    //Pintu 4
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-350.05, 15.0, 390.0);
    glVertex3f(-350.05, -3.0, 390.0);
    glVertex3f(-350.05, -3.0, 360.0);
    glVertex3f(-350.05, 15.0, 360.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-350.05, 15.0, 390.0);
    glVertex3f(-350.05, -3.0, 390.0);
    glVertex3f(-350.05, -3.0, 360.0);
    glVertex3f(-350.05, 15.0, 360.0);
    glEnd();

    //Pintu Besar
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-380.05, 20.0, 280.0);
    glVertex3f(-380.05, -3.0, 280.0);
    glVertex3f(-380.05, -3.0, 190.0);
    glVertex3f(-380.05, 20.0, 190.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-380.05, 20.0, 280.0);
    glVertex3f(-380.05, -3.0, 280.0);
    glVertex3f(-380.05, -3.0, 190.0);
    glVertex3f(-380.05, 20.0, 190.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-380.05, 20.0, 210.0);
    glVertex3f(-380.05, -3.0, 210.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-380.05, 20.0, 260.0);
    glVertex3f(-380.05, -3.0, 260.0);
    glEnd();

    //Jendela 1
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(150.05, 37.0, -90.0);
    glVertex3f(150.05, 25.0, -90.0);
    glVertex3f(150.05, 25.0, -60.0);
    glVertex3f(150.05, 37.0, -60.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 37.0, -90.0);
    glVertex3f(150.05, 25.0, -90.0);
    glVertex3f(150.05, 25.0, -60.0);
    glVertex3f(150.05, 37.0, -60.0);
    glEnd();

    //Jendela 2 Atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(150.05, 37.0, -50.0);
    glVertex3f(150.05, 25.0, -50.0);
    glVertex3f(150.05, 25.0, -20.0);
    glVertex3f(150.05, 37.0, -20.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(150.05, 37.0, -50.0);
    glVertex3f(150.05, 25.0, -50.0);
    glVertex3f(150.05, 25.0, -20.0);
    glVertex3f(150.05, 37.0, -20.0);
    glEnd();

    //Jendela 2 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(150.05, 15.0, -50.0);
    glVertex3f(150.05, 7.0, -50.0);
    glVertex3f(150.05, 7.0, -20.0);
    glVertex3f(150.05, 15.0, -20.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(150.05, 15.0, -50.0);
    glVertex3f(150.05, 7.0, -50.0);
    glVertex3f(150.05, 7.0, -20.0);
    glVertex3f(150.05, 15.0, -20.0);
    glEnd();

    //Jendela 3
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(150.05, 37.0, 60.0);
    glVertex3f(150.05, 25.0, 60.0);
    glVertex3f(150.05, 25.0, 90.0);
    glVertex3f(150.05, 37.0, 90.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(150.05, 37.0, 60.0);
    glVertex3f(150.05, 25.0, 60.0);
    glVertex3f(150.05, 25.0, 90.0);
    glVertex3f(150.05, 37.0, 90.0);
    glEnd();

    //Jendela 4 atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 37.0, 110.0);
    glVertex3f(100.05, 25.0, 110.0);
    glVertex3f(100.05, 25.0, 140.0);
    glVertex3f(100.05, 37.0, 140.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(100.05, 37.0, 110.0);
    glVertex3f(100.05, 25.0, 110.0);
    glVertex3f(100.05, 25.0, 140.0);
    glVertex3f(100.05, 37.0, 140.0);
    glEnd();

    //Jendela 4 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 15.0, 110.0);
    glVertex3f(100.05, 7.0, 110.0);
    glVertex3f(100.05, 7.0, 140.0);
    glVertex3f(100.05, 15.0, 140.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(100.05, 15.0, 110.0);
    glVertex3f(100.05, 7.0, 110.0);
    glVertex3f(100.05, 7.0, 140.0);
    glVertex3f(100.05, 15.0, 140.0);
    glEnd();

    //Jendela 5 atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 37.0, 150.0);
    glVertex3f(100.05, 25.0, 150.0);
    glVertex3f(100.05, 25.0, 180.0);
    glVertex3f(100.05, 37.0, 180.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(100.05, 37.0, 150.0);
    glVertex3f(100.05, 25.0, 150.0);
    glVertex3f(100.05, 25.0, 180.0);
    glVertex3f(100.05, 37.0, 180.0);
    glEnd();

    //Jendela 5 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 15.0, 150.0);
    glVertex3f(100.05, 7.0, 150.0);
    glVertex3f(100.05, 7.0, 180.0);
    glVertex3f(100.05, 15.0, 180.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(100.05, 15.0, 150.0);
    glVertex3f(100.05, 7.0, 150.0);
    glVertex3f(100.05, 7.0, 180.0);
    glVertex3f(100.05, 15.0, 180.0);
    glEnd();

    //Jendela 6 atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 37.0, 280.0);
    glVertex3f(100.05, 25.0, 280.0);
    glVertex3f(100.05, 25.0, 310.0);
    glVertex3f(100.05, 37.0, 310.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(100.05, 37.0, 280.0);
    glVertex3f(100.05, 25.0, 280.0);
    glVertex3f(100.05, 25.0, 310.0);
    glVertex3f(100.05, 37.0, 310.0);
    glEnd();

    //Jendela 6 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 15.0, 280.0);
    glVertex3f(100.05, 7.0, 280.0);
    glVertex3f(100.05, 7.0, 310.0);
    glVertex3f(100.05, 15.0, 310.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(100.05, 15.0, 280.0);
    glVertex3f(100.05, 7.0, 280.0);
    glVertex3f(100.05, 7.0, 310.0);
    glVertex3f(100.05, 15.0, 310.0);
    glEnd();

    //Jendela 7 atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 37.0, 320.0);
    glVertex3f(100.05, 25.0, 320.0);
    glVertex3f(100.05, 25.0, 350.0);
    glVertex3f(100.05, 37.0, 350.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(100.05, 37.0, 320.0);
    glVertex3f(100.05, 25.0, 320.0);
    glVertex3f(100.05, 25.0, 350.0);
    glVertex3f(100.05, 37.0, 350.0);
    glEnd();

    //Jendela 7 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 15.0, 320.0);
    glVertex3f(100.05, 7.0, 320.0);
    glVertex3f(100.05, 7.0, 350.0);
    glVertex3f(100.05, 15.0, 350.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(100.05, 15.0, 320.0);
    glVertex3f(100.05, 7.0, 320.0);
    glVertex3f(100.05, 7.0, 350.0);
    glVertex3f(100.05, 15.0, 350.0);
    glEnd();

    //Jendela 8
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(100.05, 37.0, 360.0);
    glVertex3f(100.05, 25.0, 360.0);
    glVertex3f(100.05, 25.0, 390.0);
    glVertex3f(100.05, 37.0, 390.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.05, 37.0, 360.0);
    glVertex3f(100.05, 25.0, 360.0);
    glVertex3f(100.05, 25.0, 390.0);
    glVertex3f(100.05, 37.0, 390.0);
    glEnd();

    //Jendela 9
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-350.05, 37.0, 360.0);
    glVertex3f(-350.05, 25.0, 360.0);
    glVertex3f(-350.05, 25.0, 390.0);
    glVertex3f(-350.05, 37.0, 390.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-350.05, 37.0, 360.0);
    glVertex3f(-350.05, 25.0, 360.0);
    glVertex3f(-350.05, 25.0, 390.0);
    glVertex3f(-350.05, 37.0, 390.0);
    glEnd();

    //Jendela 11 atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-350.05, 37.0, -60.0);
    glVertex3f(-350.05, 25.0, -60.0);
    glVertex3f(-350.05, 25.0, -90.0);
    glVertex3f(-350.05, 37.0, -90.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(-350.05, 37.0, -60.0);
    glVertex3f(-350.05, 25.0, -60.0);
    glVertex3f(-350.05, 25.0, -90.0);
    glVertex3f(-350.05, 37.0, -90.0);
    glEnd();

    //Jendela 11 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-350.05, 15.0, -60.0);
    glVertex3f(-350.05, 7.0, -60.0);
    glVertex3f(-350.05, 7.0, -90.0);
    glVertex3f(-350.05, 15.0, -90.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(-350.05, 15.0, -60.0);
    glVertex3f(-350.05, 7.0, -60.0);
    glVertex3f(-350.05, 7.0, -90.0);
    glVertex3f(-350.05, 15.0, -90.0);
    glEnd();

    //Jendela 12 atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-350.05, 37.0, -20.0);
    glVertex3f(-350.05, 37.0, -50.0);
    glVertex3f(-350.05, 25.0, -50.0);
    glVertex3f(-350.05, 25.0, -20.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(-350.05, 37.0, -20.0);
    glVertex3f(-350.05, 37.0, -50.0);
    glVertex3f(-350.05, 25.0, -50.0);
    glVertex3f(-350.05, 25.0, -20.0);
    glEnd();

    //Jendela 12 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-350.05, 15.0, -20.0);
    glVertex3f(-350.05, 15.0, -50.0);
    glVertex3f(-350.05, 7.0, -50.0);
    glVertex3f(-350.05, 7.0, -20.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(-350.05, 15.0, -20.0);
    glVertex3f(-350.05, 15.0, -50.0);
    glVertex3f(-350.05, 7.0, -50.0);
    glVertex3f(-350.05, 7.0, -20.0);
    glEnd();

    //Jendela 13 atas
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-350.05, 37.0, 110.0);
    glVertex3f(-350.05, 25.0, 110.0);
    glVertex3f(-350.05, 25.0, 80.0);
    glVertex3f(-350.05, 37.0, 80.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(-350.05, 37.0, 110.0);
    glVertex3f(-350.05, 25.0, 110.0);
    glVertex3f(-350.05, 25.0, 80.0);
    glVertex3f(-350.05, 37.0, 80.0);
    glEnd();

    //Jendela 13 bawah
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-350.05, 15.0, 110.0);
    glVertex3f(-350.05, 7.0, 110.0);
    glVertex3f(-350.05, 7.0, 80.0);
    glVertex3f(-350.05, 15.0, 80.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(145 / 255.f, 79 / 255.f, 74 / 255.f);
    glVertex3f(-350.05, 15.0, 110.0);
    glVertex3f(-350.05, 7.0, 110.0);
    glVertex3f(-350.05, 7.0, 80.0);
    glVertex3f(-350.05, 15.0, 80.0);
    glEnd();

    //JENDELA BESAR
    glBegin(GL_QUADS);
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-380.05, 37.0, 280.0);
    glVertex3f(-380.05, 25.0, 280.0);
    glVertex3f(-380.05, 25.0, 190.0);
    glVertex3f(-380.05, 37.0, 190.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-380.05, 37.0, 280.0);
    glVertex3f(-380.05, 25.0, 280.0);
    glVertex3f(-380.05, 25.0, 190.0);
    glVertex3f(-380.05, 37.0, 190.0);
    glEnd();

// ATRIBUT - ATRIBUT
//Lemari
    glBegin(GL_QUADS);//kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(80.0, 10.0, 1.0);
    glVertex3f(80.0, -3.0, 1.0);
    glVertex3f(80.0, -3.0, 4.0);
    glVertex3f(80.0, 10.0, 4.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(80.0, 10.0, 1.0);
    glVertex3f(80.0, -3.0, 1.0);
    glVertex3f(80.0, -3.0, 4.0);
    glVertex3f(80.0, 10.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(70.0, 10.0, 1.0);
    glVertex3f(70.0, -3.0, 1.0);
    glVertex3f(70.0, -3.0, 4.0);
    glVertex3f(70.0, 10.0, 4.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(70.0, 10.0, 1.0);
    glVertex3f(70.0, -3.0, 1.0);
    glVertex3f(70.0, -3.0, 4.0);
    glVertex3f(70.0, 10.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(80.0, 10.0, 4.0);
    glVertex3f(80.0, -3.0, 4.0);
    glVertex3f(70.0, -3.0, 4.0);
    glVertex3f(70.0, 10.0, 4.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(80.0, 10.0, 4.0);
    glVertex3f(80.0, -3.0, 4.0);
    glVertex3f(70.0, -3.0, 4.0);
    glVertex3f(70.0, 10.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);//Belakang
   glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(80.0, 10.0, 1.0);
    glVertex3f(80.0, -3.0, 1.0);
    glVertex3f(70.0, -3.0, 1.0);
    glVertex3f(70.0, 10.0, 1.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(80.0, 10.0, 1.0);
    glVertex3f(80.0, -3.0, 1.0);
    glVertex3f(70.0, -3.0, 1.0);
    glVertex3f(70.0, 10.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);//Atas
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(80.0, 10.0, 1.0);
    glVertex3f(80.0, 10.0, 4.0);
    glVertex3f(70.0, 10.0, 4.0);
    glVertex3f(70.0, 10.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);//Kaca
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(79.0, 9.0, 4.0);
    glVertex3f(79.0, -2.0, 4.0);
    glVertex3f(76.0, -2.0, 4.0);
    glVertex3f(76.0, 9.0, 4.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kaca
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(79.0, 9.0, 4.0);
    glVertex3f(79.0, -2.0, 4.0);
    glVertex3f(76.0, -2.0, 4.0);
    glVertex3f(76.0, 9.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);//Kaca
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(74.0, 9.0, 4.0);
    glVertex3f(74.0, -2.0, 4.0);
    glVertex3f(71.0, -2.0, 4.0);
    glVertex3f(71.0, 9.0, 4.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kaca
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(74.0, 9.0, 4.0);
    glVertex3f(74.0, -2.0, 4.0);
    glVertex3f(71.0, -2.0, 4.0);
    glVertex3f(71.0, 9.0, 4.0);
    glEnd();

    //Kursi 1
    glBegin(GL_QUADS);//Dudukan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(103.0, 0.0, -10.0);
    glVertex3f(103.0, 0.0, 0.0);
    glVertex3f(101.0, 0.0, 0.0);
    glVertex3f(101.0, 0.0, -10.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis dudukan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(103.0, 0.0, -10.0);
    glVertex3f(103.0, 0.0, 0.0);
    glVertex3f(101.0, 0.0, 0.0);
    glVertex3f(101.0, 0.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);//Senderan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(101.0, 0.0, -10.0);
    glVertex3f(101.0, 3.0, -10.0);
    glVertex3f(101.0, 3.0, 0.0);
    glVertex3f(101.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis senderan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(101.0, 0.0, -10.0);
    glVertex3f(101.0, 3.0, -10.0);
    glVertex3f(101.0, 3.0, 0.0);
    glVertex3f(101.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//kaki
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(103.0, -3.0, -10.0);
    glVertex3f(103.0, 0.0, -10.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//kaki
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(101.0, -3.0, -10.0);
    glVertex3f(101.0, 0.0, -10.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//kaki
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(101.0, -3.0, 0.0);
    glVertex3f(101.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//kaki
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(103.0, -3.0, 0.0);
    glVertex3f(103.0, 0.0, 0.0);
    glEnd();

    //Kursi 2
    glBegin(GL_QUADS);//Dudukan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(103.0, 0.0, -70.0);
    glVertex3f(103.0, 0.0, -60.0);
    glVertex3f(101.0, 0.0, -60.0);
    glVertex3f(101.0, 0.0, -70.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis dudukan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(103.0, 0.0, -70.0);
    glVertex3f(103.0, 0.0, -60.0);
    glVertex3f(101.0, 0.0, -60.0);
    glVertex3f(101.0, 0.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);//Senderan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(101.0, 0.0, -70.0);
    glVertex3f(101.0, 3.0, -70.0);
    glVertex3f(101.0, 3.0, -60.0);
    glVertex3f(101.0, 0.0, -60.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis senderan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(101.0, 0.0, -70.0);
    glVertex3f(101.0, 3.0, -70.0);
    glVertex3f(101.0, 3.0, -60.0);
    glVertex3f(101.0, 0.0, -60.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//kaki
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(103.0, -3.0, -60.0);
    glVertex3f(103.0, 0.0, -60.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//kaki
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(101.0, -3.0, -60.0);
    glVertex3f(101.0, 0.0, -60.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//kaki
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(101.0, -3.0, -70.0);
    glVertex3f(101.0, 0.0, -70.0);
    glEnd();

    glBegin(GL_LINE_STRIP);//kaki
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(103.0, -3.0, -70.0);
    glVertex3f(103.0, 0.0, -70.0);
    glEnd();

   //Vending Machine 1
    glBegin(GL_QUADS); //belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.5, -3.0, 92.0);
    glVertex3f(150.5, 7.0, 92.0);
    glVertex3f(150.5, 7.0, 97.0);
    glVertex3f(150.5, -3.0, 97.0);
    glEnd();

    glBegin(GL_LINE_LOOP); // garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(150.5, -3.0, 92.0);
    glVertex3f(150.5, 7.0, 92.0);
    glVertex3f(150.5, 7.0, 97.0);
    glVertex3f(150.5, -3.0, 97.0);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.5, -3.0, 92.0);
    glVertex3f(150.5, 7.0, 92.0);
    glVertex3f(155.0, 7.0, 92.0);
    glVertex3f(155.0, -3.0, 92.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(150.5, -3.0, 92.0);
    glVertex3f(150.5, 7.0, 92.0);
    glVertex3f(155.0, 7.0, 92.0);
    glVertex3f(155.0, -3.0, 92.0);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(155.0, -3.0, 92.0);
    glVertex3f(155.0, 7.0, 92.0);
    glVertex3f(155.0, 7.0, 97.0);
    glVertex3f(155.0, -3.0, 97.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(155.0, -3.0, 92.0);
    glVertex3f(155.0, 7.0, 92.0);
    glVertex3f(155.0, 7.0, 97.0);
    glVertex3f(155.0, -3.0, 97.0);
    glEnd();

    glBegin(GL_QUADS); //kaca depan
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(155.2, -1.0, 93.0);
    glVertex3f(155.2, 5.0, 93.0);
    glVertex3f(155.2, 5.0, 96.0);
    glVertex3f(155.2, -1.0, 96.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(155.0, -3.0, 97.0);
    glVertex3f(155.0, 7.0, 97.0);
    glVertex3f(150.5, 7.0, 97.0);
    glVertex3f(150.5, -3.0, 97.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(155.0, -3.0, 97.0);
    glVertex3f(155.0, 7.0, 97.0);
    glVertex3f(150.5, 7.0, 97.0);
    glVertex3f(150.5, -3.0, 97.0);
    glEnd();

    glBegin(GL_QUADS); //atap
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(155.0, 7.0, 97.0);
    glVertex3f(155.0, 7.0, 92.0);
    glVertex3f(150.5, 7.0, 97.0);
    glVertex3f(150.5, 7.0, 92.0);
    glEnd();

//Vending Machine 2
    glBegin(GL_QUADS); //belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(50.5, -3.0, 295.0);
    glVertex3f(50.5, 7.0, 295.0);
    glVertex3f(50.5, 7.0, 300.0);
    glVertex3f(50.5, -3.0, 300.0);
    glEnd();

    glBegin(GL_LINE_LOOP); // garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.5, -3.0, 295.0);
    glVertex3f(50.5, 7.0, 295.0);
    glVertex3f(50.5, 7.0, 300.0);
    glVertex3f(50.5, -3.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(50.5, -3.0, 295.0);
    glVertex3f(50.5, 7.0, 295.0);
    glVertex3f(55.0, 7.0, 295.0);
    glVertex3f(55.0, -3.0, 295.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.5, -3.0, 295.0);
    glVertex3f(50.5, 7.0, 295.0);
    glVertex3f(55.0, 7.0, 295.0);
    glVertex3f(55.0, -3.0, 295.0);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(55.0, -3.0, 295.0);
    glVertex3f(55.0, 7.0, 295.0);
    glVertex3f(55.0, 7.0, 300.0);
    glVertex3f(55.0, -3.0, 300.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(55.0, -3.0, 295.0);
    glVertex3f(55.0, 7.0, 295.0);
    glVertex3f(55.0, 7.0, 300.0);
    glVertex3f(55.0, -3.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //kaca depan
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(55.2, -1.0, 296.0);
    glVertex3f(55.2, 5.0, 296.0);
    glVertex3f(55.2, 5.0, 299.0);
    glVertex3f(55.2, -1.0, 299.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(55.0, -3.0, 300.0);
    glVertex3f(55.0, 7.0, 300.0);
    glVertex3f(50.5, 7.0, 300.0);
    glVertex3f(50.5, -3.0, 300.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(55.0, -3.0, 300.0);
    glVertex3f(55.0, 7.0, 300.0);
    glVertex3f(50.5, 7.0, 300.0);
    glVertex3f(50.5, -3.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //atap
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(55.0, 7.0, 300.0);
    glVertex3f(55.0, 7.0, 295.0);
    glVertex3f(50.5, 7.0, 300.0);
    glVertex3f(50.5, 7.0, 295.0);
    glEnd();

//Vending Machine 3
    glBegin(GL_QUADS); //belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(50.5, -3.0, 100.0);
    glVertex3f(50.5, 7.0, 100.0);
    glVertex3f(50.5, 7.0, 105.0);
    glVertex3f(50.5, -3.0, 105.0);
    glEnd();

    glBegin(GL_LINE_LOOP); // garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.5, -3.0, 100.0);
    glVertex3f(50.5, 7.0, 100.0);
    glVertex3f(50.5, 7.0, 105.0);
    glVertex3f(50.5, -3.0, 105.0);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(50.5, -3.0, 100.0);
    glVertex3f(50.5, 7.0, 100.0);
    glVertex3f(55.0, 7.0, 100.0);
    glVertex3f(55.0, -3.0, 100.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.5, -3.0, 100.0);
    glVertex3f(50.5, 7.0, 100.0);
    glVertex3f(55.0, 7.0, 100.0);
    glVertex3f(55.0, -3.0, 100.0);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(55.0, -3.0, 100.0);
    glVertex3f(55.0, 7.0, 100.0);
    glVertex3f(55.0, 7.0, 105.0);
    glVertex3f(55.0, -3.0, 105.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(55.0, -3.0, 100.0);
    glVertex3f(55.0, 7.0, 100.0);
    glVertex3f(55.0, 7.0, 105.0);
    glVertex3f(55.0, -3.0, 105.0);
    glEnd();

    glBegin(GL_QUADS); //kaca depan
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(55.2, -1.0, 101.0);
    glVertex3f(55.2, 5.0, 101.0);
    glVertex3f(55.2, 5.0, 104.0);
    glVertex3f(55.2, -1.0, 104.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(55.0, -3.0, 105.0);
    glVertex3f(55.0, 7.0, 105.0);
    glVertex3f(50.5, 7.0, 105.0);
    glVertex3f(50.5, -3.0, 105.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(55.0, -3.0, 105.0);
    glVertex3f(55.0, 7.0, 105.0);
    glVertex3f(50.5, 7.0, 105.0);
    glVertex3f(50.5, -3.0, 105.0);
    glEnd();

    glBegin(GL_QUADS); //atap
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(55.0, 7.0, 105.0);
    glVertex3f(55.0, 7.0, 100.0);
    glVertex3f(50.5, 7.0, 105.0);
    glVertex3f(50.5, 7.0, 100.0);
    glEnd();

//Vending Machine 4
    glBegin(GL_QUADS); //belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-147.5, -3.0, 100.0);
    glVertex3f(-147.5, 7.0, 100.0);
    glVertex3f(-147.5, 7.0, 105.0);
    glVertex3f(-147.5, -3.0, 105.0);
    glEnd();

    glBegin(GL_LINE_LOOP); // garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-147.5, -3.0, 100.0);
    glVertex3f(-147.5, 7.0, 100.0);
    glVertex3f(-147.5, 7.0, 105.0);
    glVertex3f(-147.5, -3.0, 105.0);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-147.5, -3.0, 100.0);
    glVertex3f(-147.5, 7.0, 100.0);
    glVertex3f(-142.0, 7.0, 100.0);
    glVertex3f(-142.0, -3.0, 100.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-147.5, -3.0, 100.0);
    glVertex3f(-147.5, 7.0, 100.0);
    glVertex3f(-142.0, 7.0, 100.0);
    glVertex3f(-142.0, -3.0, 100.0);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-142.0, -3.0, 100.0);
    glVertex3f(-142.0, 7.0, 100.0);
    glVertex3f(-142.0, 7.0, 105.0);
    glVertex3f(-142.0, -3.0, 105.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-142.0, -3.0, 100.0);
    glVertex3f(-142.0, 7.0, 100.0);
    glVertex3f(-142.0, 7.0, 105.0);
    glVertex3f(-142.0, -3.0, 105.0);
    glEnd();

    glBegin(GL_QUADS); //kaca depan
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-141.8, -1.0, 101.0);
    glVertex3f(-141.8, 5.0, 101.0);
    glVertex3f(-141.8, 5.0, 104.0);
    glVertex3f(-141.8, -1.0, 104.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-142.0, -3.0, 105.0);
    glVertex3f(-142.0, 7.0, 105.0);
    glVertex3f(-147.5, 7.0, 105.0);
    glVertex3f(-147.5, -3.0, 105.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-142.0, -3.0, 105.0);
    glVertex3f(-142.0, 7.0, 105.0);
    glVertex3f(-147.5, 7.0, 105.0);
    glVertex3f(-147.5, -3.0, 105.0);
    glEnd();

    glBegin(GL_QUADS); //atap
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-142.0, 7.0, 105.0);
    glVertex3f(-142.0, 7.0, 100.0);
    glVertex3f(-147.5, 7.0, 105.0);
    glVertex3f(-147.5, 7.0, 100.0);
    glEnd();

    //Lemari Mading
    glBegin(GL_QUADS);//kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.0, 15.0, -99.5);
    glVertex3f(100.0, 5.0, -99.5);
    glVertex3f(100.0, 5.0, -98.0);
    glVertex3f(100.0, 15.0, -98.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kiri
    glColor3f(54/255.f, 54/255.f, 54/255.f);
    glVertex3f(100.0, 15.0, -99.5);
    glVertex3f(100.0, 5.0, -99.5);
    glVertex3f(100.0, 5.0, -98.0);
    glVertex3f(100.0, 15.0, -98.0);
    glEnd();

    glBegin(GL_QUADS);//Kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(80.0, 15.0, -99.5);
    glVertex3f(80.0, 5.0, -99.5);
    glVertex3f(80.0, 5.0, -98.0);
    glVertex3f(80.0, 15.0, -98.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kanan
    glColor3f(54/255.f, 54/255.f, 54/255.f);
    glVertex3f(80.0, 15.0, -99.5);
    glVertex3f(80.0, 5.0, -99.5);
    glVertex3f(80.0, 5.0, -98.0);
    glVertex3f(80.0, 15.0, -98.0);
    glEnd();

    glBegin(GL_QUADS);//Belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.0, 15.0, -99.5);
    glVertex3f(100.0, 5.0, -99.5);
    glVertex3f(80.0, 5.0, -99.5);
    glVertex3f(80.0, 15.0, -99.5);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS belakang
    glColor3f(54/255.f, 54/255.f, 54/255.f);
    glVertex3f(100.0, 15.0, -99.5);
    glVertex3f(100.0, 5.0, -99.5);
    glVertex3f(80.0, 5.0, -99.5);
    glVertex3f(80.0, 15.0, -99.5);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.0, 15.0, -98.0);
    glVertex3f(100.0, 5.0, -98.0);
    glVertex3f(80.0, 5.0, -98.0);
    glVertex3f(80.0, 15.0, -98.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS depan
    glColor3f(54/255.f, 54/255.f, 54/255.f);
    glVertex3f(100.0, 15.0, -98.0);
    glVertex3f(100.0, 5.0, -98.0);
    glVertex3f(80.0, 5.0, -98.0);
    glVertex3f(80.0, 15.0, -98.0);
    glEnd();

    glBegin(GL_QUADS);//Atas
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.0, 15.0, -99.5);
    glVertex3f(100.0, 15.0, -98.0);
    glVertex3f(80.0, 15.0, -98.0);
    glVertex3f(80.0, 15.0, -99.5);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.0, 5.0, -99.5);
    glVertex3f(100.0, 5.0, -98.0);
    glVertex3f(80.0, 5.0, -98.0);
    glVertex3f(80.0, 5.0, -99.5);
    glEnd();

    glBegin(GL_QUADS);//Kaca
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(99.0, 14.0, -98.0);
    glVertex3f(99.0, 6.0, -98.0);
    glVertex3f(81.0, 6.0, -98.0);
    glVertex3f(81.0, 14.0, -98.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kaca
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(99.0, 14.0, -98.0);
    glVertex3f(99.0, 6.0, -98.0);
    glVertex3f(81.0, 6.0, -98.0);
    glVertex3f(81.0, 14.0, -98.0);
    glEnd();


    //Lemari Mading 2
    glBegin(GL_QUADS);//kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-149.5, 15.0, -60.0);
    glVertex3f(-149.5, 5.0, -60.0);
    glVertex3f(-148.0, 5.0, -60.0);
    glVertex3f(-148.0, 15.0, -60.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kiri
    glColor3f(54/255.f, 54/255.f, 54/255.f);
    glVertex3f(-149.5, 15.0, -60.0);
    glVertex3f(-149.5, 5.0, -60.0);
    glVertex3f(-148.0, 5.0, -60.0);
    glVertex3f(-148.0, 15.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);//Kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-149.5, 15.0, -30.0);
    glVertex3f(-149.5, 5.0, -30.0);
    glVertex3f(-148.0, 5.0, -30.0);
    glVertex3f(-148.0, 15.0, -30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kanan
    glColor3f(54/255.f, 54/255.f, 54/255.f);
    glVertex3f(-149.5, 15.0, -30.0);
    glVertex3f(-149.5, 5.0, -30.0);
    glVertex3f(-148.0, 5.0, -30.0);
    glVertex3f(-148.0, 15.0, -30.0);
    glEnd();

    glBegin(GL_QUADS);//Belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-149.5, 15.0, -60.0);
    glVertex3f(-149.5, 5.0, -60.0);
    glVertex3f(-149.5, 5.0, -30.0);
    glVertex3f(-149.5, 15.0, -30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS belakang
    glColor3f(54/255.f, 54/255.f, 54/255.f);
    glVertex3f(-149.5, 15.0, -60.0);
    glVertex3f(-149.5, 5.0, -60.0);
    glVertex3f(-149.5, 5.0, -30.0);
    glVertex3f(-149.5, 15.0, -30.0);
    glEnd();

    glBegin(GL_QUADS);//Depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-148.0, 15.0, -60.0);
    glVertex3f(-148.0, 5.0, -60.0);
    glVertex3f(-148.0, 5.0, -30.0);
    glVertex3f(-148.0, 15.0, -30.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS depan
    glColor3f(54/255.f, 54/255.f, 54/255.f);
    glVertex3f(-148.0, 15.0, -60.0);
    glVertex3f(-148.0, 5.0, -60.0);
    glVertex3f(-148.0, 5.0, -30.0);
    glVertex3f(-148.0, 15.0, -30.0);
    glEnd();

    glBegin(GL_QUADS);//Atas
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-149.5, 15.0, -60.0);
    glVertex3f(-148.0, 15.0, -30.0);
    glVertex3f(-148.0, 15.0, -30.0);
    glVertex3f(-149.5, 15.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-149.5, 5.0, -60.0);
    glVertex3f(-148.0, 5.0, -30.0);
    glVertex3f(-148.0, 5.0, -30.0);
    glVertex3f(-149.5, 5.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);//Kaca
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-148.0, 14.0, -59.0);
    glVertex3f(-148.0, 6.0, -59.0);
    glVertex3f(-148.0, 6.0, -31.0);
    glVertex3f(-148.0, 14.0, -31.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//GARIS kaca
    glColor3f(151 / 255.f, 189 / 255.f, 207 / 255.f);
    glVertex3f(-148.0, 14.0, -59.0);
    glVertex3f(-148.0, 6.0, -59.0);
    glVertex3f(-148.0, 6.0, -31.0);
    glVertex3f(-148.0, 14.0, -31.0);
    glEnd();

    //Tong Sampah 1
    glBegin(GL_QUADS); //belakang
    glColor3f(20 / 255.f, 135 / 255.f, 20 / 255.f);
    glVertex3f(-379.0, -3.0, 290.0);
    glVertex3f(-379.0, 5.0, 290.0);
    glVertex3f(-379.0, 5.0, 293.0);
    glVertex3f(-379.0, -3.0, 293.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-379.0, -3.0, 290.0);
    glVertex3f(-379.0, 5.0, 290.0);
    glVertex3f(-379.0, 5.0, 293.0);
    glVertex3f(-379.0, -3.0, 293.0);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(20 / 255.f, 135 / 255.f, 20 / 255.f);
    glVertex3f(-379.0, -3.0, 290.0);
    glVertex3f(-379.0, 5.0, 290.0);
    glVertex3f(-376.0, 5.0, 290.0);
    glVertex3f(-376.0, -3.0, 290.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-379.0, -3.0, 290.0);
    glVertex3f(-379.0, 5.0, 290.0);
    glVertex3f(-376.0, 5.0, 290.0);
    glVertex3f(-376.0, -3.0, 290.0);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(20 / 255.f, 135 / 255.f, 20 / 255.f);
    glVertex3f(-376.0, -3.0, 290.0);
    glVertex3f(-376.0, 5.0, 290.0);
    glVertex3f(-376.0, 5.0, 293.0);
    glVertex3f(-376.0, -3.0, 293.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-376.0, -3.0, 290.0);
    glVertex3f(-376.0, 5.0, 290.0);
    glVertex3f(-376.0, 5.0, 293.0);
    glVertex3f(-376.0, -3.0, 293.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(20 / 255.f, 135 / 255.f, 20 / 255.f);
    glVertex3f(-376.0, -3.0, 293.0);
    glVertex3f(-376.0, 5.0, 293.0);
    glVertex3f(-379.0, 5.0, 293.0);
    glVertex3f(-379.0, -3.0, 293.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-376.0, -3.0, 293.0);
    glVertex3f(-376.0, 5.0, 293.0);
    glVertex3f(-379.0, 5.0, 293.0);
    glVertex3f(-379.0, -3.0, 293.0);
    glEnd();

    glBegin(GL_QUADS); //tutupan
    glColor3f(20 / 255.f, 135 / 255.f, 20 / 255.f);
    glVertex3f(-379.0, 5.0, 290.0);
    glVertex3f(-379.0, 5.0, 293.0);
    glVertex3f(-376.5, 7.0, 293.0);
    glVertex3f(-376.5, 7.0, 290.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis tutupan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-379.0, 5.0, 290.0);
    glVertex3f(-379.0, 5.0, 293.0);
    glVertex3f(-376.5, 7.0, 293.0);
    glVertex3f(-376.5, 7.0, 290.0);
    glEnd();

    //Tong Sampah 2
    glBegin(GL_QUADS); //belakang
    glColor3f(3 / 255.f, 1 / 255.f, 48 / 255.f);
    glVertex3f(50.5, -3.0, 350.0);
    glVertex3f(50.5, 5.0, 350.0);
    glVertex3f(50.5, 5.0, 353.0);
    glVertex3f(50.5, -3.0, 353.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.5, -3.0, 350.0);
    glVertex3f(50.5, 5.0, 350.0);
    glVertex3f(50.5, 5.0, 353.0);
    glVertex3f(50.5, -3.0, 353.0);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(3 / 255.f, 1 / 255.f, 48 / 255.f);
    glVertex3f(50.5, -3.0, 350.0);
    glVertex3f(50.5, 5.0, 350.0);
    glVertex3f(53.0, 5.0, 350.0);
    glVertex3f(53.0, -3.0, 350.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.5, -3.0, 350.0);
    glVertex3f(50.5, 5.0, 350.0);
    glVertex3f(53.0, 5.0, 350.0);
    glVertex3f(53.0, -3.0, 350.0);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(3 / 255.f, 1 / 255.f, 48 / 255.f);
    glVertex3f(53.0, -3.0, 350.0);
    glVertex3f(53.0, 5.0, 350.0);
    glVertex3f(53.0, 5.0, 353.0);
    glVertex3f(53.0, -3.0, 353.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(53.0, -3.0, 350.0);
    glVertex3f(53.0, 5.0, 350.0);
    glVertex3f(53.0, 5.0, 353.0);
    glVertex3f(53.0, -3.0, 353.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(3 / 255.f, 1 / 255.f, 48 / 255.f);
    glVertex3f(53.0, -3.0, 353.0);
    glVertex3f(53.0, 5.0, 353.0);
    glVertex3f(50.5, 5.0, 353.0);
    glVertex3f(50.5, -3.0, 353.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(53.0, -3.0, 353.0);
    glVertex3f(53.0, 5.0, 353.0);
    glVertex3f(50.5, 5.0, 353.0);
    glVertex3f(50.5, -3.0, 353.0);
    glEnd();

    glBegin(GL_QUADS); //tutupan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.5, 5.0, 350.0);
    glVertex3f(50.5, 5.0, 353.0);
    glVertex3f(53.0, 7.0, 353.0);
    glVertex3f(53.0, 7.0, 350.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis tutupan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.5, 5.0, 350.0);
    glVertex3f(50.5, 5.0, 353.0);
    glVertex3f(53.0, 7.0, 353.0);
    glVertex3f(53.0, 7.0, 350.0);
    glEnd();

    //Tong Sampah 3
    glBegin(GL_QUADS); //belakang
    glColor3f(54 / 255.f, 54 / 255.f, 54 / 255.f);
    glVertex3f(100.5, -3.0, -50.0);
    glVertex3f(100.5, 5.0, -50.0);
    glVertex3f(100.5, 5.0, -47.0);
    glVertex3f(100.5, -3.0, -47.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.5, -3.0, -50.0);
    glVertex3f(100.5, 5.0, -50.0);
    glVertex3f(100.5, 5.0, -47.0);
    glVertex3f(100.5, -3.0, -47.0);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(54 / 255.f, 54 / 255.f, 54 / 255.f);
    glVertex3f(100.5, -3.0, -50.0);
    glVertex3f(100.5, 5.0, -50.0);
    glVertex3f(103.0, 5.0, -50.0);
    glVertex3f(103.0, -3.0, -50.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.5, -3.0, -50.0);
    glVertex3f(100.5, 5.0, -50.0);
    glVertex3f(103.0, 5.0, -50.0);
    glVertex3f(103.0, -3.0, -50.0);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(54 / 255.f, 54 / 255.f, 54 / 255.f);
    glVertex3f(103.0, -3.0, -50.0);
    glVertex3f(103.0, 5.0, -50.0);
    glVertex3f(103.0, 5.0, -47.0);
    glVertex3f(103.0, -3.0, -47.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(103.0, -3.0, -50.0);
    glVertex3f(103.0, 5.0, -50.0);
    glVertex3f(103.0, 5.0, -47.0);
    glVertex3f(103.0, -3.0, -47.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(54 / 255.f, 54 / 255.f, 54 / 255.f);
    glVertex3f(103.0, -3.0, -47.0);
    glVertex3f(103.0, 5.0, -47.0);
    glVertex3f(100.5, 5.0, -47.0);
    glVertex3f(100.5, -3.0, -47.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(103.0, -3.0, -47.0);
    glVertex3f(103.0, 5.0, -47.0);
    glVertex3f(100.5, 5.0, -47.0);
    glVertex3f(100.5, -3.0, -47.0);
    glEnd();

    glBegin(GL_QUADS); //tutupan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.5, 5.0, -50.0);
    glVertex3f(100.5, 5.0, -47.0);
    glVertex3f(103.0, 7.0, -47.0);
    glVertex3f(103.0, 7.0, -50.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //garis tutupan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.5, 5.0, -50.0);
    glVertex3f(100.5, 5.0, -47.0);
    glVertex3f(103.0, 7.0, -47.0);
    glVertex3f(103.0, 7.0, -50.0);
    glEnd();


//TULISAN FREIE UNIVERSIAT BERLIN

    // TULISAN FREIE
    //huruf F Depan
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 93.0);
    glVertex3f(150.05, 48.0, 97.0);
    glVertex3f(150.05, 41.5, 97.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 45.0, 97.0);
    glVertex3f(150.05, 45.0, 93.0);
    glEnd();

    //huruf R Depan
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 41.5, 87.0);
    glVertex3f(150.05, 45.0, 91.0);
    glVertex3f(150.05, 45.0, 87.0);
    glVertex3f(150.05, 48.0, 87.0);
    glVertex3f(150.05, 48.0, 91.0);
    glVertex3f(150.05, 41.5, 91.0);
    glEnd();

    //huruf E Depan
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 81.0);
    glVertex3f(150.05, 48.0, 85.0);
    glVertex3f(150.05, 41.5, 85.0);
    glVertex3f(150.05, 41.5, 81.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 45.0, 85.0);
    glVertex3f(150.05, 45.0, 81.0);
    glEnd();

    //huruf I Depan
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 79.0);
    glVertex3f(150.05, 41.5, 79.0);
    glEnd();

    //huruf E Depan
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 73.0);
    glVertex3f(150.05, 48.0, 77.0);
    glVertex3f(150.05, 41.5, 77.0);
    glVertex3f(150.05, 41.5, 73.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 45.0, 77.0);
    glVertex3f(150.05, 45.0, 73.0);
    glEnd();

    // TULISAN UNIVERSITAT
    //huruf U
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 69.0);
    glVertex3f(150.05, 41.5, 69.0);
    glVertex3f(150.05, 41.5, 65.0);
    glVertex3f(150.05, 48.0, 65.0);
    glEnd();

    //huruf N
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 41.5, 63.0);
    glVertex3f(150.05, 48.0, 63.0);
    glVertex3f(150.05, 41.5, 59.0);
    glVertex3f(150.05, 48.0, 59.0);
    glEnd();

    //huruf I
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 57.0);
    glVertex3f(150.05, 41.5, 57.0);
    glEnd();

    //huruf V
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 55.0);
    glVertex3f(150.05, 41.5, 53.0);
    glVertex3f(150.05, 48.0, 51.0);
    glEnd();

    //huruf E
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 45.0);
    glVertex3f(150.05, 48.0, 49.0);
    glVertex3f(150.05, 41.5, 49.0);
    glVertex3f(150.05, 41.5, 45.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 45.0, 49.0);
    glVertex3f(150.05, 45.0, 45.0);
    glEnd();

    //huruf R
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 41.5, 39.0);
    glVertex3f(150.05, 45.0, 43.0);
    glVertex3f(150.05, 45.0, 39.0);
    glVertex3f(150.05, 48.0, 39.0);
    glVertex3f(150.05, 48.0, 43.0);
    glVertex3f(150.05, 41.5, 43.0);
    glEnd();

    //huruf S
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 33.0);
    glVertex3f(150.05, 48.0, 37.0);
    glVertex3f(150.05, 45.0, 37.0);
    glVertex3f(150.05, 45.0, 33.0);
    glVertex3f(150.05, 41.5, 33.0);
    glVertex3f(150.05, 41.5, 37.0);
    glEnd();

    //huruf I
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 31.0);
    glVertex3f(150.05, 41.5, 31.0);
    glEnd();

    //huruf T
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 29.0);
    glVertex3f(150.05, 48.0, 25.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 27.0);
    glVertex3f(150.05, 41.5, 27.0);
    glEnd();

    //huruf A
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 41.5, 24.0);
    glVertex3f(150.05, 48.0, 22.0);
    glVertex3f(150.05, 41.5, 20.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 45.0, 23.0);
    glVertex3f(150.05, 45.0, 21.0);
    glEnd();

    //huruf T
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 18.0);
    glVertex3f(150.05, 48.0, 14.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 16.0);
    glVertex3f(150.05, 41.5, 16.0);
    glEnd();

    // TULISAN BERLIN
    //huruf B
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 10.0);
    glVertex3f(150.05, 48.0, 6.0);
    glVertex3f(150.05, 41.5, 6.0);
    glVertex3f(150.05, 41.5, 10.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 45.0, 10.0);
    glVertex3f(150.05, 45.0, 6.0);
    glEnd();

    //huruf E
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, 0.0);
    glVertex3f(150.05, 48.0, 4.0);
    glVertex3f(150.05, 41.5, 4.0);
    glVertex3f(150.05, 41.5, 0.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 45.0, 4.0);
    glVertex3f(150.05, 45.0, 0.0);
    glEnd();

    //huruf R
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 41.5, -6.0);
    glVertex3f(150.05, 45.0, -2.0);
    glVertex3f(150.05, 45.0, -6.0);
    glVertex3f(150.05, 48.0, -6.0);
    glVertex3f(150.05, 48.0, -2.0);
    glVertex3f(150.05, 41.5, -2.0);
    glEnd();

    //huruf L
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, -8.0);
    glVertex3f(150.05, 41.5, -8.0);
    glVertex3f(150.05, 41.5, -12.0);
    glEnd();

    //huruf I
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 48.0, -14.0);
    glVertex3f(150.05, 41.5, -14.0);
    glEnd();

    //huruf N
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(150.05, 41.5, -16.0);
    glVertex3f(150.05, 48.0, -16.0);
    glVertex3f(150.05, 41.5, -20.0);
    glVertex3f(150.05, 48.0, -20.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

/*
tombol pada keyboard:
"a": ke kiri
"d": ke kanan
"w": ke depan
"s": ke belakang
"z" : ke atas
"x" : ke bawah
"i" : rotasi ke bawah terhadap sumbu X
"k" : rotasi ke atas terhadap sumbu X
"j" : rotasi ke kiri terhadap sumbu Y
"l" : rotasi ke kanan terhadap sumbu Y
"m" : rotasi ke kiri terhadap sumbu Z
"n" : rotasi ke kanan terhadap sumbu Z
"Q" : Melihat interior
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 5.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -5.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0);
        break;
    case 'q':
    case 'Q':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}
void resize(int width, int height)
{
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, width / height, 1.0, 5000.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1600, 1000);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Freie Universitat Berlin");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
