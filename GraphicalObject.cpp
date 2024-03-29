#include <cinder/app/App.h>
#include "cinder/app/AppNative.h"
#include "cinder/cairo/Cairo.h"
#include "../vc2013/GraphicalObject.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	GraphicalObject default Destructor. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

GraphicalObject::~GraphicalObject(){
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets a type or label of type string for the object. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="str">	The string type/label. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setType(std::string str)
{
	type = str;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the type or label of type string for the object. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	The string type/label. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

std::string GraphicalObject::getType()
{
	return type;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets initial mouse location. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	The initial mouse location. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

cinder::Vec2f  GraphicalObject::getInitialMouseLocation(){
	return initialMouseLocation;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the object width of type double. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	The width. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

double GraphicalObject::getWidth(){
	return width;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the object height of type double. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	The height. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

double GraphicalObject::getHeight(){
	return height;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets center of object's bounding box of type Vec2f. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	The center of bounding box. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

cinder::Vec2f GraphicalObject::getCenterOfBoundingBox(){
	return centerOfBoundingBox;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets top left corner of bounding box of type Vec2f. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	The top left corner. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

cinder::Vec2f GraphicalObject::getTopLeftCorner(){
	return topLeftCorner;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the previous center of bounding box of type Vec2f. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	The previous center of bounding box. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

cinder::Vec2f GraphicalObject::getPrevCenterOfBoundingBox(){
	return prevCenterOfBoundingBox;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the previous top left corner of type Vec2f. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	The previous top left corner. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

cinder::Vec2f GraphicalObject::getPrevTopLeftCorner(){
	return prevTopLeftCorner;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets initial mouse location of type Vec2f. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="newInitialMouseLocation">	The new initial mouse location. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setInitialMouseLocation(cinder::Vec2f newMouseLocation){
	initialMouseLocation = newMouseLocation;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets center of bounding box. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="newCenterOfBOundingBox">	The new center of bounding box. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setCenterOfBoundingBox(cinder::Vec2f newCenterOfBOundingBox){
	centerOfBoundingBox = newCenterOfBOundingBox;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets top left corner. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="newTopLeftCorner">	The new top left corner. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setTopLeftCorner(cinder::Vec2f newTopLeftCorner){
	topLeftCorner = newTopLeftCorner;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets previous center of bounding box. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="prevCOB">	The previous center of bounding box. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setPrevCenterOfBoundingBox(cinder::Vec2f prevCOB){
	prevCenterOfBoundingBox = prevCOB;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets previous top left corner. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="prevTLC">	The previous top left corner. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setPrevTopLeftCorner(cinder::Vec2f prevTLC){
	prevTopLeftCorner = prevTLC;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets a width of type double. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="newWidth">	New width. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setWidth(double newWidth){
	width = newWidth;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets a height of type double. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="newHeight"> New height. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setHeight(double newHeight){
	height = newHeight;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Move graphical object. </summary>
///
/// <remarks>	This is a virtual object, and is meant to be overridden. The mouse event should 
/// 			include the event where the graphical object was first click on.
/// </remarks>
///
/// <param name="event"> Mouse event. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::moveGObject(cinder::app::MouseEvent event){
	cinder::Vec2f initialLocation = getInitialMouseLocation();
	if (initialLocation == cinder::Vec2f(.5, .5)){
		setInitialMouseLocation(event.getPos());
		return;
	}
	cinder::Vec2f difference = cinder::Vec2f(floor((double)event.getX() - initialLocation.x), floor((double)event.getY() - initialLocation.y));
	setCenterOfBoundingBox(cinder::Vec2f((getCenterOfBoundingBox().x + difference.x),(getCenterOfBoundingBox().y + difference.y)));
	setTopLeftCorner(cinder::Vec2f((getTopLeftCorner().x + difference.x),(getTopLeftCorner().y + difference.y)));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the bool value of if the object is selected. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool GraphicalObject::getIsSelected(){
	return isSelected;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets the bool isSelected if object is selected. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="selected">	true if selected. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicalObject::setisSelected(bool selected){
	isSelected = selected;
}