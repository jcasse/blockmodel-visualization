#include "controls.h"
#include "data.h"
#include "text.h"

matrix blocking;
vector<float> outer_dim;
const float distance_factor = 3;

// Alpha Blending ////////////////////////////////////////////////////////////
//const float ALPHA = 0.6f; //The opacity of each face of the cube
//////////////////////////////////////////////////////////////////////////////

void drawFrontFace(float * o, float * d, float * rgb)
// Precondition: o is the origin (bottom-left), d is the dimensions (x,y,0)
// and rgb is color (red-gree-blue)
// Postcondition: cube is defined
{
  // Specify the color (RGB) of all further drawings
  glColor3f(rgb[0], rgb[1], rgb[2]);
  // Alpha Blending //////////////////////////////////////////////////////////
  //glColor4f(rgb[0], rgb[1], rgb[2], ALPHA);
  ////////////////////////////////////////////////////////////////////////////

  // Draw polygon
  glBegin(GL_POLYGON);
	  glVertex3f(o[0] + 0.0f, o[1] + 0.0f, o[2] + d[2]);  // bottom-left
	  glVertex3f(o[0] + d[0], o[1] + 0.0f, o[2] + d[2]);  // bottom-right
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] + d[2]);  // top-right
	  glVertex3f(o[0] + 0.0f, o[1] + d[1], o[2] + d[2]);  // top-left
  glEnd();
}

void drawBackFace(float * o, float * d, float * rgb)
// Precondition: o is the origin (bottom-left), d is the dimensions (x,y,0)
// and rgb is color (red-gree-blue)
// Postcondition: cube is defined
{
  // Specify the color (RGB) of all further drawings
  glColor3f(rgb[0], rgb[1], rgb[2]);
  // Alpha Blending //////////////////////////////////////////////////////////
  //glColor4f(rgb[0], rgb[1], rgb[2], ALPHA);
  ////////////////////////////////////////////////////////////////////////////

  // Draw polygon
  glBegin(GL_POLYGON);
	  glVertex3f(o[0] + 0.0f, o[1] + 0.0f, o[2] + d[2]);  // bottom-left
	  glVertex3f(o[0] - d[0], o[1] + 0.0f, o[2] + d[2]);  // bottom-right
	  glVertex3f(o[0] - d[0], o[1] + d[1], o[2] + d[2]);  // top-right
	  glVertex3f(o[0] + 0.0f, o[1] + d[1], o[2] + d[2]);  // top-left
  glEnd();
}

void drawTopFace(float * o, float * d, float * rgb)
// Precondition: o is the origin (bottom-left), d is the dimensions (x,y,0)
// and rgb is color (red-gree-blue)
// Postcondition: cube is defined
{
  // Specify the color (RGB) of all further drawings
  glColor3f(rgb[0], rgb[1], rgb[2]);
  // Alpha Blending //////////////////////////////////////////////////////////
  //glColor4f(rgb[0], rgb[1], rgb[2], ALPHA);
  ////////////////////////////////////////////////////////////////////////////

  // Draw polygon
  glBegin(GL_POLYGON);
	  glVertex3f(o[0] + 0.0f, o[1] + d[1], o[2] + 0.0f);  // bottom-left
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] + 0.0f);  // bottom-right
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] - d[2]);  // top-right
	  glVertex3f(o[0] + 0.0f, o[1] + d[1], o[2] - d[2]);  // top-left
  glEnd();
}

void drawBottomFace(float * o, float * d, float * rgb)
// Precondition: o is the origin (bottom-left), d is the dimensions (x,y,0)
// and rgb is color (red-gree-blue)
// Postcondition: cube is defined
{
  // Specify the color (RGB) of all further drawings
  glColor3f(rgb[0], rgb[1], rgb[2]);
  // Alpha Blending //////////////////////////////////////////////////////////
  //glColor4f(rgb[0], rgb[1], rgb[2], ALPHA);
  ////////////////////////////////////////////////////////////////////////////

  // Draw polygon
  glBegin(GL_POLYGON);
	  glVertex3f(o[0] + 0.0f, o[1] + d[1], o[2] + 0.0f);  // bottom-left
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] + 0.0f);  // bottom-right
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] + d[2]);  // top-right
	  glVertex3f(o[0] + 0.0f, o[1] + d[1], o[2] + d[2]);  // top-left
  glEnd();
}

void drawRightFace(float * o, float * d, float * rgb)
// Precondition: o is the origin (bottom-left), d is the dimensions (0,y,z)
// and rgb is color (red-gree-blue)
// Postcondition: cube is defined
{
  // Specify the color (RGB) of all further drawings
  glColor3f(rgb[0], rgb[1], rgb[2]);
  // Alpha Blending //////////////////////////////////////////////////////////
  //glColor4f(rgb[0], rgb[1], rgb[2], ALPHA);
  ////////////////////////////////////////////////////////////////////////////

  // Draw polygon
  glBegin(GL_POLYGON);
	  glVertex3f(o[0] + d[0], o[1] + 0.0f, o[2] + 0.0f);  // bottom-left
	  glVertex3f(o[0] + d[0], o[1] + 0.0f, o[2] - d[2]);  // bottom-right
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] - d[2]);  // top-right
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] + 0.0f);  // top-left
  glEnd();
}

void drawLeftFace(float * o, float * d, float * rgb)
// Precondition: o is the origin (bottom-left), d is the dimensions (0,y,z)
// and rgb is color (red-gree-blue)
// Postcondition: cube is defined
{
  // Specify the color (RGB) of all further drawings
  glColor3f(rgb[0], rgb[1], rgb[2]);
  // Alpha Blending //////////////////////////////////////////////////////////
  //glColor4f(rgb[0], rgb[1], rgb[2], ALPHA);
  ////////////////////////////////////////////////////////////////////////////

  // Draw polygon
  glBegin(GL_POLYGON);
	  glVertex3f(o[0] + d[0], o[1] + 0.0f, o[2] + 0.0f);  // bottom-left
	  glVertex3f(o[0] + d[0], o[1] + 0.0f, o[2] + d[2]);  // bottom-right
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] + d[2]);  // top-right
	  glVertex3f(o[0] + d[0], o[1] + d[1], o[2] + 0.0f);  // top-left
  glEnd();
}

void drawBlock(float * o, float * d, float * rgb)
// Precondition: o is center of block (x,y,z), d is dimensions (x,y,z),
// rgb is color (red,green,blue)
// Postcondition: Block with color, dimensions and center is defined
{
  float o_front[] = {o[0] - d[0] / 2, o[1] - d[1] / 2, o[2] + d[2] / 2};
  float d_front[] = {d[0], d[1], 0.0f};
  drawFrontFace(o_front, d_front, rgb);

  float o_back[] = {o[0] + d[0] / 2, o[1] - d[1] / 2, o[2] - d[2] / 2};
  float d_back[] = {d[0], d[1], 0.0f};
  drawBackFace(o_back, d_back, rgb);

  float o_top[] = {o[0] - d[0] / 2, o[1] + d[1] / 2, o[2] + d[2] / 2};
  float d_top[] = {d[0], 0.0f, d[2]};
  drawTopFace(o_top, d_top, rgb);

  float o_bottom[] = {o[0] - d[0] / 2, o[1] - d[1] / 2, o[2] - d[2] / 2};
  float d_bottom[] = {d[0], 0.0f, d[2]};
  drawBottomFace(o_bottom, d_bottom, rgb);

  float o_left[] = {o[0] - d[0] / 2, o[1] - d[1] / 2, o[2] - d[2] / 2};
  float d_left[] = {0.0f, d[1], d[2]};
  drawLeftFace(o_left, d_left, rgb);

  float o_right[] = {o[0] + d[0] / 2, o[1] - d[1] / 2, o[2] + d[2] / 2};
  float d_right[] = {0.0f, d[1], d[2]};
  drawRightFace(o_right, d_right, rgb);
}

void draw_objects()
{
  // blocking
  for(size_t x = 0; x != blocking.size(); ++x)
  {
    for(size_t y = 0; y != blocking[0].size(); ++y)
    {
      for(size_t z = 0; z != blocking[0][0].size(); ++z)
      {
        float rgb[3];
        rgb[0] = (1 - blocking[x][y][z].dns) * 0.6f + 0.05f;
        rgb[1] = (1 - blocking[x][y][z].dns) * 0.6f + 0.05f;
        rgb[2] = (1 - blocking[x][y][z].dns) * 0.6f + 0.05f;
        float * ctr = blocking[x][y][z].ctr;
        float * dim = blocking[x][y][z].dim;
        drawBlock(ctr, dim, rgb);
      }
    }
  }

  // reference axes
  glColor3f(0.0f, 0.0f, 0.0f);
  float axes_gap = max(outer_dim) / block_gap_factor;
  float o[3];
  size_t r = blocking.size() - 1;
  o[0] = blocking[r][0][0].ctr[0] - blocking[r][0][0].dim[0] / 2 - axes_gap;
  o[1] = blocking[r][0][0].ctr[1] - blocking[r][0][0].dim[1] / 2 - axes_gap;
  o[2] = blocking[r][0][0].ctr[2] + blocking[r][0][0].dim[2] / 2 + axes_gap;

  // x axis
  glBegin(GL_LINES);
    glVertex3f(o[0], o[1], o[2]);                 // origin of the line
    glVertex3f(o[0] + outer_dim[1], o[1], o[2]);  // ending point of the line
  glEnd();
  glRasterPos3f(o[0] + outer_dim[1] * 1.03f, o[1] * 1.03f, o[2] * 1.03f);
  glutBitmapCharacter(font_style, 88);

  // y axis
  glBegin(GL_LINES);
    glVertex3f(o[0], o[1], o[2]);                 // origin of the line
    glVertex3f(o[0], o[1] + outer_dim[0], o[2]);  // ending point of the line
  glEnd();
  glRasterPos3f(o[0] * 1.03f, o[1] + outer_dim[0] * 1.03f, o[2] * 1.03f);
  glutBitmapCharacter(font_style, 89);

  // z axis
  glBegin(GL_LINES);
    glVertex3f(o[0], o[1], o[2]);                 // origin of the line
    glVertex3f(o[0], o[1], o[2] - outer_dim[2]);  // ending point of the line
  glEnd();
  glRasterPos3f(o[0] * 1.03f, o[1] * 1.03f, o[2] - outer_dim[2] * 1.03f);
  glutBitmapCharacter(font_style, 90);
}
