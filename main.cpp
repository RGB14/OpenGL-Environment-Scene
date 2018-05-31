///////////////////////////////////////
//  COMPUTER GRAPHICS PROJECT        //
//  -------------------------        //
//  Environment Scene:               //
//  Sudipto Majumder (ID: 143400005) //
//                                   //
//  Bicycle Object:                  //
//  Merina Kawsar (ID: 143400003)    //
///////////////////////////////////////

#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1416

float red=0.3, green=0.3, blue=0.6;
double Angle = 30.0;
int radius;
double modX=0;
double modY=0;

void keyboard(int key, int x, int y)
{
  switch (key)
  {
  case 27:
	  exit (0);
	  break;

  case GLUT_KEY_RIGHT:
    modX+=10;
    break;
  case GLUT_KEY_LEFT:
    modX-=10;
    break;
  case GLUT_KEY_DOWN:
    modY-=10;
    if(modY<=-100)
    {
        modY+=10;
    }
    break;

case GLUT_KEY_UP:
    modY+=10;
    if(modY<70 && modY>=0)
    {
        modY-=10;
    }
    break;
  }
  glutPostRedisplay();
}
void cyclewheel(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100;

	GLfloat twicePi = 2.0f * PI;
    glPointSize(100);
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {

			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20;

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void Road()
{
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
        glVertex2f(0,100);
        glVertex2f(0,190);
        glVertex2f(1280,190);
        glVertex2f(1280,100);
    glEnd();
}
void RoadDivider(int dist)
{
    glPushMatrix();
    glTranslated(-(Angle*5)+300+dist,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.9);
        glVertex2f(250,140);
        glVertex2f(230,150);
        glVertex2f(330,150);
        glVertex2f(350,140);

    glEnd();
    glPopMatrix();
}
void Grass(int repeat)
{
    glPushMatrix();
    glTranslated(-(Angle*5)+repeat, 0 , 0) ;
    glBegin(GL_QUADS);
    glColor3f(0.1,0.3,0.01);
        glVertex2f(10,0);
        glVertex2f(rand()%14,50);
        glVertex2f(20,35);
        glVertex2f(22,0);

     glColor3f(0.1,0.28,0.06);
        glVertex2f(35,0);
        glVertex2f(rand()%40,72);
        glVertex2f(58,47);
        glVertex2f(67,0);

        glColor3f(0.1,0.3,0.01);
        glVertex2f(85,0);
        glVertex2f(rand()%99,50);
        glVertex2f(150,35);
        glVertex2f(180,0);

        glColor3f(0.11,0.3,0.01);
        glVertex2f(200,0);
        glVertex2f(rand()%210,65);
        glVertex2f(220,35);
        glVertex2f(222,0);

     glColor3f(0.1,0.3,0.06);
        glVertex2f(250,0);
        glVertex2f(rand()%260,90);
        glVertex2f(265,80);
        glVertex2f(267,0);

        glColor3f(0.1,0.2,0.01);
        glVertex2f(280,0);
        glVertex2f(rand()%290,75);
        glVertex2f(300,50);
        glVertex2f(310,0);
     glEnd();
     glPopMatrix();
}
void drawBicycle(){
 glColor3f(1.0,1.0,1.0);
 cyclewheel(100.0,120.0,30);
 cyclewheel(220.0,120.0,30);
 glLineWidth(3);
    glBegin(GL_LINES);
  {
      glVertex2f(100.0,115);
      glVertex2f(160,115);

      glVertex2f(100.0,115);
      glVertex2f(120,160);

       glVertex2f(120,160);
       glVertex2f(185,160);

       glVertex2f(185,160);
       glVertex2f(160,115);

        glVertex2f(220,115);
       glVertex2f(155,200);

        glVertex2f(155,200);
        glVertex2f(140,200);

   glVertex2f(120,160);
      glVertex2f(120,175);

     glVertex2f(115,175);
      glVertex2f(125,175);

    }
glEnd();
}
void rotateWheel(){

    glBegin(GL_LINES);
    {
     //right wheel

     glVertex2f(220,115);
     glVertex2f(190,110);

      glVertex2f(220,115);
      glVertex2f(230,150);

      glVertex2f(220,115);
      glVertex2f(243,100);

          ////leftwheel

      glVertex2f(100.0,115);
      glVertex2f(80,143);

      glVertex2f(100.0,115);
      glVertex2f(72,110);

      glVertex2f(100.0,115);
      glVertex2f(115.0,93);

    }

    glEnd();
}
void Init(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0,0, (GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D( 0.0 , (GLdouble)w, 0.0, (GLdouble)h);
}
void update(int value)
{
    Angle += 1 ;
    if(Angle > 3600)
    {
        Angle -= 3600 ;
    }
    glutPostRedisplay() ;
    glutTimerFunc(20 , update , 0) ;
}
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100;

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {

			glVertex2f(

			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}
void BuildingSmall()
{
    glPushMatrix();
    glTranslated(modX,(modY),0);
    glBegin(GL_QUADS);
        glColor3f(0.6,0.4,0.3);
        glVertex2f(600,200);
        glVertex2f(600,350);
        glVertex2f(800,350);
        glVertex2f(800,200);

        glColor3f(1.0,1.0,1.0);
        glVertex2f(650,250);
        glVertex2f(650,300);
        glVertex2f(700,300);
        glVertex2f(700,250);

        glColor3f(0.3,0.2,0.1);
        glVertex2f(750,200);
        glVertex2f(750,320);
        glVertex2f(790,320);
        glVertex2f(790,200);


        glColor3f(0.1,0.1,0.1);
        glVertex2f(550,200);
        glVertex2f(550,210);
        glVertex2f(850,210);
        glVertex2f(850,200);
    glEnd();
    glPopMatrix();
}
void NorthStar()
{
    glPushMatrix();
    glTranslated(-(Angle/8) , -100, 0) ;
    glColor3f(1.0,1.0,1.0);
    drawFilledCircle(900,700,1);
    glPopMatrix();

}
void Moon()
{
    glPushMatrix();
    glTranslated(-(Angle/2), -100, 0);
    glColor3f(1.0,0.9,0.9);
    drawFilledCircle(1200,600, 25);
    glPopMatrix();
}
void Cloud(int x, int y)
{
    glPushMatrix();
    glTranslated(-(Angle)+x, -20+y , 0) ;
    glColor3f(0.15,0.15,0.15);
    drawFilledCircle(700,500.0,30);
    drawFilledCircle(750,520.0,40);
    drawFilledCircle(800,500.0,30);

    glColor3f(0.20,0.20,0.20);
    drawFilledCircle(1200,400.0,30);
    drawFilledCircle(1250,420.0,40);
    drawFilledCircle(1300,400.0,30);
    glPopMatrix();
}
void MidnightSky()
{
    glBegin(GL_QUADS);
    glColor4f(0.0,0.0,0.1,0.1);
        glVertex2f(0,200);
        glVertex2f(0,300);
        glVertex2f(1280,300);
        glVertex2f(1280,200);

    glColor4f(0.0,0.0,0.05,0.1);
        glVertex2f(0,300);
        glVertex2f(0,400);
        glVertex2f(1280,400);
        glVertex2f(1280,300);

    glColor4f(0.0,0.0,0.025,0.1);
        glVertex2f(0,400);
        glVertex2f(0,500);
        glVertex2f(1280,500);
        glVertex2f(1280,400);

    glEnd();

}
void LampLighting(int getValue)
{
    glPushMatrix();
    glTranslated(-(Angle*5)+getValue, 0 , 0) ;
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.25);
        glVertex2f(600,200);
        glVertex2f(805,300);
        glVertex2f(805.5,300);
        glVertex2f(1000,200);
        glEnd();
     glPopMatrix();
}
void LampPost(int diff)
{
    glPushMatrix();
    glTranslated(-(Angle*5)+diff, 0 , 0) ;
    glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
        glVertex2f(800,200);
        glVertex2f(800,300);
        glVertex2f(810,300);
        glVertex2f(810,200);
    glColor3f(0.2,0.2,0.2);
        glVertex2f(795,200);
        glVertex2f(795,210);
        glVertex2f(815,210);
        glVertex2f(815,200);
        glEnd();
    glColor3f(0.7,0.7,0.8);
        drawFilledCircle(805,300,8);

        glPopMatrix();

}
void dynamicStars()
{
    for(int drawStar=1;drawStar<10;drawStar++){
    drawFilledCircle(rand()%1280,rand()%1280,1);
    glColor3f(0.0,0.0,0.6);
    drawFilledCircle(rand()%1280,rand()%1280,2);
    glColor3f(0.6,0.0,0.0);
    drawFilledCircle(rand()%1280,rand()%1280,1.5);
    glColor3f(1.0,1.0,1.0);
    }

}
void Land()
{
    glBegin(GL_QUADS);
    glColor4f(0.9,0.12,0.12,0.8);
        glVertex2f(0,180);
    glColor4f(0.3,0.1,0.1,1.0);
        glVertex2f(0,0);
    glColor4f(0.3,0.1,0.1,0.8);
        glVertex2f(1280,0);
    glColor4f(0.9,0.01,0.01,0.8);
        glVertex2f(1280,180);

   glColor4f(0.2,0.5,0.3,0.8);
        glVertex2f(0,200);
        glVertex2f(0,190);
    glColor4f(0.1,0.2,0.3,0.8);
        glVertex2f(1280,190);
        glVertex2f(1280,200);

    glEnd();
}
void BicycleModifier()
{
    glPushMatrix();
    glTranslated((300+modX),(150+modY),1);
    glScaled(0.5,0.5,1);
    drawBicycle();
    glPopMatrix();

}
static void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

    NorthStar();
    MidnightSky();
    dynamicStars();
    Moon();
    for(int pos=0;pos<5000;pos+=1200)
    {
       Cloud(pos,0);
    }
    for(int x=0;x<15000;x+=500)
    {
        LampLighting(x);
    }

    for(int x=0;x<15000;x+=500)
    {
        LampPost(x);
    }

    Land();
    Road();
    for(int x=0;x<15000;x+=500)
    {
       RoadDivider(x);
    }
    //BuildingSmall();
    BicycleModifier();
    for(int x=0;x<15000;x+=250)
    {
        Grass(x);
    }
  glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1280,720);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );

    glutCreateWindow("2D Midnight Scene");

    Init(1280, 720);
   // glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboard);
    glutDisplayFunc(display);
    glutTimerFunc(100, update , 0) ;

    glutMainLoop();

    return 1;
}
