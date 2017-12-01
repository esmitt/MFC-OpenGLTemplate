OpenGL in MFC Single-View App
===================
A simple template to start to working using MFC in Single-View mode with OpenGL code.
The template only use `gl.h` and `glu.h` (for `gluPerspective`), focus on OpenGL's legacy code. It also works with modern (shader-based) OpenGL, just need to use glew or something similar.
Some tips:

 - Code is using Visual Studio 2017
 - The **OnEraseBkgnd** function should be added into the View class
 - The **OnCreate** function contains all the initialization
 - The **OnSize** function is to handle the window resizing 
 - The **OnDraw** function contains the drawing. The parameter `CDC* pDC` **have to be** uncommented.

As I mentioned, this is a single template..no more :-)