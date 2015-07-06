Cinder and Cairo provide the means for executing programs to draw pictures. They both use immediate mode graphics. To move an image elsewhere on the board you must erase it and redraw it in its new location.

This API offers a direct manipulation 2D graphics API on top of Cinder and Cairo that provides a GraphicalObject abstract base class from which developers can derive concrete graphical objects for applications. Along with this are Dataflow constraints included for the ability to connect aspects such as image locations so that one is constrained by another's data. This Dataflow constraint API allows for the getting and setting of constrained variables with automatic generation of dependencies. An example is connecting two images or objects so that as one moves, the other adjusts accordingly automatically. 

GraphicalObject objects supports the following operations:
Creation - A user or program must be able to create and add new application-specific graphical object instances to a window.
Deletion - A user or program must be able to remove and clean up application-specific graphical object instances from a window.
Selection - A user must be able to select an existing graphical object within its window. This could be a prerequisite for moving, resizing, etc. the object. Selection is best achieved by enabling graphical objects to receive mouse events.
Moving - A user or an application must be able to reposition an object within its window. For user interaction, this typically is achieved by the user dragging the object with the pointing device. A particular subclass or instance may override this capability to enforce immobile objects, but this behavior is expected in general.
Rendering - A graphical object should be able to draw itself within a window; this is achieved via a draw method or the like. Such a draw method will take advantage of Cinder/Cairo underlying immediate-mode graphics capabilities. The rendering method allows users to distinguish one graphical object from another within a window.
Bounding area - A graphical object should be bound by a rectangular area, its bounding box. In general, no part of the object's visual presentation will appear outside of its bounding box, and the object will not receive mouse events that occur outside of its bounding box.

Data Contraint supports the following operations:
Get - get contraints
Set - Set constraint
invalidate - Invalidates constraint
set Formula - Sets the formula to process. Must be integer arithmetic. Can be extended to use templating if necessary.

example: Constraint x; x.setFormula(someObj.x - y);
