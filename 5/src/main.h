///////////////////////////////////////////////////////////////////////////////
// Definition of important global variables and functions
///////////////////////////////////////////////////////////////////////////////


// include guard
#ifndef MAIN_H
#define MAIN_H


///////////////////////////////////////////////////////////////////////////////
// types definition

// RGBA color type structure, 32-bit
struct S_RGBA
{
	unsigned char blue, green, red, alpha;

	S_RGBA() : blue(0), green(0), red(0), alpha(255)
	{}

	S_RGBA(unsigned char r, unsigned char g, unsigned char b)
		: blue(b), green(g), red(r), alpha(255)
	{}
};


// material structure
struct S_Material
{
	double red, green, blue;

	S_Material() : red(0.0), green(0.0), blue(0.0)
	{}

	S_Material(double r, double g, double b) : red(r), green(g), blue(b)
	{}
};


///////////////////////////////////////////////////////////////////////////////
// global variables

extern S_RGBA *frame_buffer;        // frame buffer (RGB values) memory pointer
extern int frame_w, frame_h;        // frame buffer size


////////////////////////////////////////////////////////////
// color and material constants used in application

const S_RGBA COLOR_BLACK(0, 0, 0);
const S_RGBA COLOR_BLUE(0, 0, 255);

const S_Material MAT_RED(1.0, 0.0, 0.0);
const S_Material MAT_RED2(0.6, 0.4, 0.4);


///////////////////////////////////////////////////////////////////////////////
// useful macros

// direct frame buffer pixel value macro
#define PIXEL(x, y)         (*(frame_buffer + (y) * frame_w + (x)))


///////////////////////////////////////////////////////////////////////////////
// functions specific for this lab

// function clears frame buffer
void ClearBuffers();

// rasterize line with given coordinates and color to frame buffer
// x1,y1,x2,y2 - line endpoints
// color - drawing color
void DrawLine(int x1, int y1, int x2, int y2, const S_RGBA &color);

// draw scene to position given by scene and object
// rotation using perspective projection
// - implementation is in student.cpp
void DrawScene();


///////////////////////////////////////////////////////////////////////////////
// variables specific for this lab
// - variables are changed in main.cpp in accordance with mouse controlling
// - student.cpp uses this values for proper drawing (object rotation, etc.)

// camera position within scene (0, 0, -CAMERA_DIST)
const int CAMERA_DIST = 1000;

// object rotation
extern int obj_rot_x;
extern int obj_rot_y;

// object translation
extern int obj_move_x;
extern int obj_move_y;

// whole scene rotation
extern int scene_rot_x;
extern int scene_rot_y;

// whole scene translation
extern int scene_move_z;


#endif // MAIN_H
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
