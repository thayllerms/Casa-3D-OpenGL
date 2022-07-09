#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>


float posX=0.0,posY=0.0,posZ=0.0;
float transX=0.0,transY=0.0,transZ=0.0;
GLsizei rsize = 50;

void movimento(int key,int x,int y){
    //Movimento
    switch (key){
        //movimento para direita
        case GLUT_KEY_RIGHT:
          posY += 0.5;
        break;
        //movimento para esquerda.
        case GLUT_KEY_LEFT:
          posY -= 0.5;
        break;
        //identifica o movimento para cima
        case GLUT_KEY_UP:
          posX += 0.5;
        break;
        //identifica o movimento para baixo.
        case GLUT_KEY_DOWN:
          posX -= 0.5;
        break;

        case GLUT_KEY_F1:
          transZ += 0.5;
        break;

        case GLUT_KEY_F2:
          transZ -= 0.5;
        break;

        case GLUT_KEY_F3:
          transY += 0.5;
        break;

        case GLUT_KEY_F4:
          transY -= 0.5;
        break;

        case GLUT_KEY_F5:
          transX += 0.5;
        break;

        case GLUT_KEY_F6:
          transX -= 0.5;
        break;

        case GLUT_KEY_F7:
          transX = 0.0;
          transY = 0.0;
          transZ = 0.0;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}

void desenha () {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (posX==360)
    posX=0;

  if (posY==360)
      posY=0;

   // clear window 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        //movimentos de rotacao e translacao
        glRotatef(posX,1.0,0.0,0.0);
        glRotatef(posY,0.0,1.0,0.0);
        glTranslatef(transX, transY, transZ);

        //desenha a base da casa.
        glPushMatrix();
            glColor3f (0.5, 0.4, .3);
            glScalef(1.0, 1.0, 2.0);
            glutSolidCube(2);
            glutSolidCone(1.0,1.0,1.5,1.4);
        glPopMatrix();

        //janela da frente
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(0.15,-0.0,2.05);
          glVertex3f(0.65, -0.0,2.05);  
          glVertex3f(0.65, 0.5,2.05); 
          glVertex3f(0.15, 0.5,2.05);
        glEnd();

        //janela da frente
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(-0.1,-0.0,-2.05);
          glVertex3f(-0.6, -0.0,-2.05); 
          glVertex3f(-0.6, 0.5,-2.05);
          glVertex3f(-0.1, 0.5,-2.05);
        glEnd();

        //janela de trás
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(0.15,-0.0,-2.05);
          glVertex3f(0.65, -0.0,-2.05);  
          glVertex3f(0.65, 0.5,-2.05); 
          glVertex3f(0.15, 0.5,-2.05);
        glEnd();

        //janela de trás
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(-0.1,-0.0,2.05);
          glVertex3f(-0.6, -0.0,2.05); 
          glVertex3f(-0.6, 0.5,2.05); 
          glVertex3f(-0.1, 0.5,2.05);
        glEnd();

        //janela do lado esquerdo
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(-1.01,-0.2,-0.6);
          glVertex3f(-1.01, -0.2,-1.5); 
          glVertex3f(-1.01 , 0.5,-1.5);
          glVertex3f(-1.01, 0.5,-0.6);
        glEnd();

        //janela do lado direito
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(1.01,-0.2,0.4);
          glVertex3f(1.01, -0.2,1.3);  
          glVertex3f(1.01 , 0.5,1.3); 
          glVertex3f(1.01, 0.5,0.4);
        glEnd();

        //janela do lado direito
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(1.01,-0.2,-0.6);
          glVertex3f(1.01, -0.2,-1.5); 
          glVertex3f(1.01 , 0.5,-1.5);
          glVertex3f(1.01, 0.5,-0.6);
        glEnd();

        //porta
        glBegin(GL_QUADS);
          glColor3f (.3, 0.2, .1); //marrom
          glVertex3f(-1.01,-1.0,0.9);
          glVertex3f(-1.01, -1.0,-0.0); 
          glVertex3f(-1.01 , 0.4,-0.0);
          glVertex3f(-1.01, 0.4,0.9);
        glEnd();

        glBegin(GL_POLYGON); // Primitiva para desenhar um polígono
      	  glColor3f(0.7f, 0.1f, 0.0f); 
          glVertex3f( 0.0f, 2.0f,2.01);  // primeiro vértice do polígono
          glVertex3f( 1.0f, 1.0f,2.01); // segundo vértice do polígono
          glVertex3f( -1.0f, 1.0f,2.01); // terceiro vértice do polígono
        glEnd(); 
        
        glBegin(GL_POLYGON); // Primitiva para desenhar um polígono
      	  glColor3f(0.7f, 0.1f, 0.0f); 
          glVertex3f( 0.0f, 2.0f,-2.01);  //primeiro vértice do polígono
          glVertex3f( 1.0f, 1.0f,-2.01); // segundo vértice do polígono
          glVertex3f( -1.0f, 1.0f,-2.01); //terceiro vértice do polígono
        glEnd();

        //Telhado direito
        glBegin(GL_QUADS);
          glColor3f(0.7f, 0.1f, 0.0f); 
          glVertex3f(-0.0f,2.0f, 2.01f);
          glVertex3f( 1.0f, 1.0f, 2.01f);       
          glVertex3f( 1.0f, 1.0f, -2.01f);       
          glVertex3f(-0.0f,2.0f, -2.01f);       
        glEnd();

        //Telhado esquerdo
        glBegin(GL_QUADS);
          glColor3f(0.7f, 0.1f, 0.0f); 
          glVertex3f( 0.0f,2.0f, 2.01f);
          glVertex3f( -1.0f, 1.0f, 2.01f);       
          glVertex3f( -1.0f, 1.0f, -2.01f);       
          glVertex3f( 0.0f,2.0f, -2.01f);       
        glEnd();

        //Grama
        glBegin(GL_QUADS);
          glColor3f(0.3f, 1.0f, 0.0f); 
          glVertex3f( 5.0f, -1.01f, 2.8f);
          glVertex3f( -5.0f, -1.01f, 2.8f);       
          glVertex3f( -5.0f, -1.01f, -2.8f);       
          glVertex3f( 5.0f, -1.01f, -2.8f);       
        glEnd();

        //Caminho da entrada
        glBegin(GL_QUADS);
          glColor3f(1.0f, 0.0f, 0.0f); //Vermelho
          glVertex3f( -1.0f, -1.0f, 0.9f);
          glVertex3f( -5.0f, -1.0f, 0.9f);       
          glVertex3f( -5.0f, -1.0f, -0.0f);       
          glVertex3f( -1.0f, -1.0f, -0.0f);       
        glEnd();
        
    glPopMatrix();

    float t;
    glBegin(GL_POLYGON);
          glColor3f(1.0f, 1.0f, 0.0f);  
          for(int i = 0; i < 360; i++){
            t = i*3.142/180;
            glVertex3f(2+0.4*cos(t), (2.7+0.5*(sin(t))), 2.01f); 
          }
    glEnd();

    GLfloat luz_ambiente[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat luz_difusa[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat luz_epecular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat luz_posicao[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_epecular);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicao);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
       
    // flush drawing routines to the window 
    glFlush();
}

void inicializar(){

    // set up depth-buffering 
    glEnable(GL_DEPTH_TEST);

    // define the projection transformation
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //FovY, Aspect, zNear, ZFar
    gluPerspective(45,1,4,20);

    // define the viewing transformation 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
// Especifica a direção do vetor "Cima". Geralmente, Y.
    gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
} 

int main ( int argc, char * argv[] ) {

    // initialize GLUT, using any commandline parameters passed to the program 
    glutInit(&argc,argv);

    // setup the size, position, and display mode for new windows 
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
    // create and set up a window 
    glutCreateWindow("Casinha 3D");
    glutDisplayFunc(desenha);
    inicializar();
    glutSpecialFunc(movimento);
    glutMainLoop();
}
