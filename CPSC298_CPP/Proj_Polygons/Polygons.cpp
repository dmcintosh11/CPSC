// CPSC 298-6 "Programming in C++"
// dmcintosh@champman.edu
// In-class Programming Project: Polygons
// File: Polygons.cpp

#include <iostream>
#include <string>

// //////////////////////////////////////////////////////////////////////////////////////////////
// Base Class Polygon - an Abstract Base Class, can't be instantiated
// //////////////////////////////////////////////////////////////////////////////////////////////
class Polygon {

public:
	Polygon(double dWidth, double dHeight);
	virtual ~Polygon();
	virtual double area() = 0; // Pure virtual member function - no implementation in base class
	virtual void displayProperties();

protected:
	double m_dWidth;
	double m_dHeight;
	std::string m_strType;
};

Polygon::Polygon(double dWidth, double dHeight) : m_dWidth(dWidth), m_dHeight(dHeight), m_strType("Polygon")
{

}

Polygon::~Polygon()
{
	std::cout << "Polygon Destructor called" << std::endl;
}

void Polygon::displayProperties()
{
	std::cout << "Polygon Type: " << this->m_strType << ", Width: " << this->m_dWidth << ", Height: " << this->m_dHeight << std::endl;
	return;
}

// //////////////////////////////////////////////////////////////////////////////////////////////
// Derived Class Rectangle ("Concrete" class, can be instantiated)
// //////////////////////////////////////////////////////////////////////////////////////////////
class Rectangle : public Polygon
{
public:
	Rectangle(double dWidth, double dHeight);
	~Rectangle();
	double area();
};

Rectangle::Rectangle(double dWidth, double dHeight) : Polygon(dWidth, dHeight)
{
	this->m_strType = "Rectangle";
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle Destructor called" << std::endl;
}

double Rectangle::area()
{
	return (this->m_dHeight * this->m_dWidth);
}

// //////////////////////////////////////////////////////////////////////////////////////////////
// Derived Class Triangle ("Concrete" class, can be instantiated)
// //////////////////////////////////////////////////////////////////////////////////////////////

/* TODO: Define the Triangle class */
class Triangle : public Polygon{
public:
	Triangle(double width, double height);
	~Triangle();
	double area();
};

/* TODO: Define the Triangle constructor; make sure to set m_strType to "Triangle" */
Triangle::Triangle(double dWidth, double dHeight) : Polygon(dWidth, dHeight) {
	this->m_strType = "Triangle";
}

/* TODO: Define the Triangle destructor; have it print out "Triangle Destructor called" */
Triangle::~Triangle() {

	std::cout << "Triangle Destructor called" << std::endl;
}

/* TODO: Define the Triangle area member function; Area of a triangle = 0.5 * m_dWdith * m_dHeight */
double Triangle::area() {
	return 0.5 * m_dWidth * m_dHeight;
}


int main()
{
	Polygon* p_polygonRectangle = new Rectangle(2.0, 4.0);
	/* TODO: Declare a pointer to a Polygon variable (e.g. p_polygonTriangle)
	 *       and assign it to a Triangle object allocated using the new operator;
	 *       the width of the triangle should be 3.0 and the height 6.0.
	 */

	Polygon* p_polygonTriangle = new Triangle(3.0, 6.0);
	Polygon* p_polygon[2]; // You can create pointers to Polygon, but not a Polygon object

	p_polygon[0] = p_polygonRectangle;
	/* TODO: Assign the triangle object pointer to array element 1 of p_polygon. */
	p_polygon[1] = p_polygonTriangle;
	/* TODO: change "i < 1" to "i < 2" so that the loop iterates over both the Rectangle
	 *       and the Triangle.
	 */

	for (int i = 0; i < 2; i++)
	{
		// Polymorphic invocation
		p_polygon[i]->displayProperties(); // take advantage of reuse; use base class function
		double dArea = p_polygon[i]->area();
		std::cout << "Area: " << dArea << std::endl;
	}

	delete p_polygonRectangle;
	/* TODO: Delete the allocated Triangle object via the pointer to the Triangle object
	 *       that you declared.
	 */

	delete p_polygonTriangle;

	return 0;
}
