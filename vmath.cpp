#include "vmath.h"
#include <arduino.h>

//  public domain function b.y Darel Rex Finley, 2006
//  http://alienryderflex.com/intersect/
//  Determines the intersection point of the line segment defined b.y points A and B
//  with the line segment defined b.y points C and D.
//
//  Returns YES if the intersection point was found, and stores that point in X,Y.
//  Returns NO if there is no determinable intersection point, in which case X,Y will
//  be unmodified.
bool lineSegmentIntersection(vec2 a, vec2 b, vec2 c, vec2 d, vec2 &out)
{
	float distAB, theCos, theSin, newX, ABpos;

	//  Fail if either line segment is zero-length.
	if (a.x==b.x && a.y==b.y || c.x==d.x && c.y==d.y) return false;

	//  Fail if the segments share an end-point.
	if (a.x==c.x && a.y==c.y || b.x==c.x && b.y==c.y
	||  a.x==d.x && a.y==d.y || b.x==d.x && b.y==d.y) {
		return false; 
	}

	//  (1) Translate the system so that point A is on the origin.
	b.x-=a.x; b.y-=a.y;
	c.x-=a.x; c.y-=a.y;
	d.x-=a.x; d.y-=a.y;

	//  Discover the length of segment A-B.
	distAB=sqrt(b.x*b.x+b.y*b.y);

	//  (2) Rotate the system so that point B is on the positive X a.xis.
	theCos=b.x/distAB;
	theSin=b.y/distAB;
	newX=c.x*theCos+c.y*theSin;
	c.y  =c.y*theCos-c.x*theSin; c.x=newX;
	newX=d.x*theCos+d.y*theSin;
	d.y  =d.y*theCos-d.x*theSin; d.x=newX;

	//  Fail if segment C-D doesn't cross line A-B.
	if (c.y<0. && d.y<0. || c.y>=0. && d.y>=0.) return false;

	//  (3) Discover the position of the intersection point along line A-B.
	ABpos=d.x+(c.x-d.x)*d.y/(d.y-c.y);

	//  Fail if segment C-D crosses line A-B outside of segment A-B.
	if (ABpos<0. || ABpos>distAB) return false;

	//  (4) Apply the discovered position to line A-B in the original coordinate system.
	out.x=a.x+ABpos*theCos;
	out.y=a.y+ABpos*theSin;

	//  Success.
	return true;
}

//  public domain function b.y Darel Rex Finley, 2006
//  http://alienryderflex.com/intersect/
//  Determines the intersection point of the line defined b.y points A and B with the
//  line defined b.y points C and D.
//
//  Returns YES if the intersection point was found, and stores that point in X,Y.
//  Returns NO if there is no determinable intersection point, in which case X,Y will
//  be unmodified.
bool lineIntersection(vec2 a, vec2 b, vec2 c, vec2 d, vec2 &out) 
{
	float  distAB, theCos, theSin, newX, ABpos ;

	//  Fail if either line is undefined.
	if (a.x == b.x && a.y == b.y || c.x == d.x && c.y == d.y) return false;

	//  (1) Translate the system so that point A is on the origin.
	b.x -= a.x; b.y -= a.y;
	c.x -= a.x; c.y -= a.y;
	d.x -= a.x; d.y -= a.y;

	//  Discover the length of segment A-B.
	distAB = sqrt(b.x*b.x+b.y*b.y);

	//  (2) Rotate the system so that point B is on the positive X a.xis.
	theCos = b.x/distAB;
	theSin = b.y/distAB;
	newX = c.x*theCos+c.y*theSin;
	c.y = c.y*theCos-c.x*theSin; c.x=newX;
	newX = d.x*theCos+d.y*theSin;
	d.y = d.y*theCos-d.x*theSin; d.x=newX;

	//  Fail if the lines are parallel.
	if (c.y == d.y) return false;

	//  (3) Discover the position of the intersection point along line A-B.
	ABpos = d.x+(c.x-d.x)*d.y/(d.y-c.y);

	//  (4) Apply the discovered position to line A-B in the original coordinate system.
	out.x = a.x+ABpos*theCos;
	out.y = a.y+ABpos*theSin;

	//  Success.
	return true;
}