#ifndef _GraphicalObjectApp_
#define _GraphicalObjectApp_

#include <cinder/app/App.h>
#include <iostream>
#include "cinder/app/AppNative.h"
#include "cinder/cairo/Cairo.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A graphical object class allowing for a cairo graphical object to be created, 
/// 			dragged, etc. 
/// </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class GraphicalObject {
	/// <summary>	true if this object is selected. </summary>
	bool isSelected;

	/// <summary>	The object width. </summary>
	double width;

	/// <summary>	The object height. </summary>
	double height;

	/// <summary>	The object label/type. </summary>
	std::string type;

	/// <summary>	The object color. ColorA range expects: cinder color model, and floats 0.0 - 1.0 for each channel (RGB) </summary>
	cinder::ColorA color;

	/// <summary>	The initial mouse location. Format Vec2f expects x,y floats</summary>
	cinder::Vec2f initialMouseLocation;

	/// <summary>	The top left corner of bounding box. Format Vec2f expects x,y floats</summary>
	cinder::Vec2f topLeftCorner;

	/// <summary>	The center of bounding box. Format Vec2f expects x,y floats</summary>
	cinder::Vec2f centerOfBoundingBox;

	/// <summary>	The previous center of bounding box. Format Vec2f expects x,y floats</summary>
	cinder::Vec2f prevCenterOfBoundingBox;

	/// <summary>	The previous top left corner of bounding box. </summary>
	cinder::Vec2f prevTopLeftCorner;
public:
	virtual ~GraphicalObject();
	bool getIsSelected();
	double getWidth();
	double getHeight();
	std::string getType();
	cinder::Vec2f getInitialMouseLocation();
	cinder::Vec2f getCenterOfBoundingBox();
	cinder::Vec2f getTopLeftCorner();
	cinder::Vec2f getPrevCenterOfBoundingBox();
	cinder::Vec2f getPrevTopLeftCorner();
	void setType(std::string str);
	void setInitialMouseLocation(cinder::Vec2f newMouseLocation);
	void setTopLeftCorner(cinder::Vec2f newTopLeftCorner);
	void setCenterOfBoundingBox(cinder::Vec2f newCenterOfBOundingBox);
	void setPrevTopLeftCorner(cinder::Vec2f prevTopLeftCorner);
	void setPrevCenterOfBoundingBox(cinder::Vec2f prevCenterOfBOundingBox);
	void setisSelected(bool selected);
	void setWidth(double newWidth);
	void setHeight(double newHeight);
	virtual void draw(cinder::cairo::Context &ctx) = 0;
	virtual void moveGObject(cinder::app::MouseEvent event);
};

#endif /*_GraphicalObjectApp_*/