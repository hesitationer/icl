#ifndef ICLQT_H
#define ICLQT_H

/** \mainpage ICLQt Package for embedding image visualization Wigets into QWidgets
This package provides some Widget classes, which allow to visualize ICL images in 
Qt based applications. 
\section CF Core Features
- Hardware acceleration using OpenGL
- X11 fallback implementation
- "Self organizing" and "low cost" On Screen Display (OSD) for all visualization components
- PaintEngine interface for abstracting from the underlying draw engine (OpenGL / X11)
- Mouse interaction interface for design of custom interactive applications

\section commonClasses Common classes
- <b>ICLWidget</b> basic Widget component
- <b>ICLDrawWidget</b> generalized drawing widget providing a high performance drawing 
  state machine to annotate images in real time applications
- <b>PaintEngine</b> Paint Engine class interface
- <b>MouseInteractionReceiver</b> interface class for receiving mouse interaction events
- <b>QImageConverter</b> Class for converting QImages to ICL images and back with optimized
  conversion routines and memory handling.

*/

#endif
