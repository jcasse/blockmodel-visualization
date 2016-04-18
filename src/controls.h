#include <iostream>

static float red = 1.0, green = 1.0, blue = 1.0;
static float rotAxis[] = {0.0, 1.0, 0.0};
static float cx = 0.0, cy = 0.0, cz = 5.0;
static float px = 0.0, py = 0.0, pz = 0.0;
static float fov_yz_angle = 45.0f;
static float angle = 0.0;
static float zoomFactor = 1.0f;
static float zNear = 1.0f;
static float zFar = 10000.0f;
static int window_w, window_h;

bool mouseDown = false;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

using namespace std;

void setProjectionMatrix(int width, int height)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fov_yz_angle * zoomFactor, width / height, zNear, zFar);
} 

void processNormalKeys(unsigned char key, int, int)
{
  // parameters int x and int y not used
  if(key == 27) exit(0);
}

void processSpecialKeys(int key, int, int)
{
  // parameters int x and int y not used
  switch(key)
  {
	  case GLUT_KEY_F1: red = 1.0; green = 0.0; blue = 0.0; break;
	  case GLUT_KEY_F2: red = 0.0; green = 1.0; blue = 0.0; break;
	  case GLUT_KEY_F3: red = 0.0; green = 0.0; blue = 1.0; break;
	  case GLUT_KEY_LEFT:
      rotAxis[0] = 0.0;
      rotAxis[1] = 1.0;
      rotAxis[2] = 0.0;
      angle -= 3.0; break;
	  case GLUT_KEY_RIGHT:
      rotAxis[0] = 0.0;
      rotAxis[1] = 1.0;
      rotAxis[2] = 0.0;
      angle += 3.0; break;
	  case GLUT_KEY_UP:
      zoomFactor = 1.1f;
      setProjectionMatrix(window_w, window_h); break;
    case GLUT_KEY_DOWN:
      zoomFactor = 0.9f;
      setProjectionMatrix(window_w, window_h); break;
    case GLUT_KEY_HOME:
      zoomFactor = 1.0f;
      setProjectionMatrix(window_w, window_h); break;
  }
}

void mouse(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    mouseDown = true;

    xdiff = x - yrot;
    ydiff = -y + xrot;
  }
  else mouseDown = false;
}

void mouseMotion(int x, int y)
{
  if(mouseDown)
  {
    yrot = x - xdiff;
    xrot = y + ydiff;
  }
}
