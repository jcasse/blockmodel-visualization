#include <cstdlib>
#include <cmath>
#include<GL/glut.h>
#include "block.h"

using namespace std;

void renderScene()
{
  // Clear display window
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  //// Alpha Blending //////////////////////////////////////////////////////////
  //glEnable(GL_BLEND); //Enable alpha blending
  //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set the blend function
  //////////////////////////////////////////////////////////////////////////////

  // Save the previous camera settings.
  glPushMatrix();

  // Perform a rotation around the y axis (0,1,0)
  // by the amount of degrees defined in the variable angle
  //glRotatef(angle, rotAxis[0], rotAxis[1], rotAxis[2]);
  glRotatef(xrot, 1.0f, 0.0f, 0.0f);
  glRotatef(yrot, 0.0f, 1.0f, 0.0f);

  // Draw object
  draw_objects();

  // Discard the modeling transformations;
  // after this, the matrix will have only the camera settings
  glPopMatrix();

  // Swapping the buffers causes the rendering above to be displayed
  glutSwapBuffers();
}

void reshapeWindow(int width, int height)
{
  // Prevent a divide by zero, when window is too short
  if(height == 0) height = 1;

  // Reset the coordinate system before modifying
  // set the current matrix to be the projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
	
  // Set the viewport to be the entire window
  glViewport(0, 0, width, height);

  // Set the correct perspective
  // (fov yz angle, ratio, near, and far clipping planes)
  gluPerspective(fov_yz_angle, width / height, zNear, zFar);

  // Set the camera
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(cx, cy, cz, px, py, pz, 0.0, 1.0, 0.0);
}

void init()
{
  // Front objects are drawn in front of back objects
  glEnable(GL_DEPTH_TEST);

  // Set display-window color
  glClearColor(0.5, 0.7, 0.0, 0.0);
}

int main(int argc, char ** argv)
{
  // check command-line arguments
  if(argc != 2) {cerr << "usage: " << argv[0] << " dir" << endl; exit(1);}

  // get data
  outer_dim = get_block_model(blocking, string(argv[1]));

  // set camera back enough so that the entire matrix can be viewed
  cz = max(outer_dim) * distance_factor;

  // Initialize GLUT
  glutInit(&argc, argv);

  // Set display mode
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

  // Create window
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(700, 650);
  glutCreateWindow("Blocked Matrix");

  // Initialize
  init();

  // Send graphics to display window
  glutDisplayFunc(renderScene);
  glutIdleFunc(renderScene);

  // Maintain aspect ratio when window is resized
  glutReshapeFunc(reshapeWindow);

  // Handle keyboard events
  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(processSpecialKeys);
  
  glutMouseFunc(mouse);
  glutMotionFunc(mouseMotion);
  //glutPassiveMotionFunc(motionPassive);

  // Display everything and wait
  glutMainLoop();

  return 0;
}
