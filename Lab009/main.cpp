#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

class Point {
public:
	Point(double xcoord = 0.0, double ycoord = 0.0);
	
	virtual ~Point() = default;
	virtual void input(const char* prompt);
	virtual void output() ;
	virtual double area() ;
	void move(double deltax, double deltay);
private:
	double x, y;
};


Point::Point(double xcoord, double ycoord){
	x = xcoord;
	y = ycoord;
}

void Point::output()  {
	std::cout << "Coordinates: (" << x << "," << y << ")" << std::endl;
}

double Point::area()  {
	return 0;
}
void Point::move(double deltax, double datay){}

void Point::input(const char* prompt) {
	std::cout << prompt << std::endl;
	std::cout << "Enter x:";
	std::cin >> x;
	std::cout << "Enter y:";
	std::cin >> y;
}

class Circle : public Point {
public:
	Circle(double radius = 0, double area = 0);

	void input(const char* prompt);
	void output();
	double area();
	void move();

private:
	double radius, areaVar;
};

Circle::Circle( double radius, double area) {
	
	this->radius = radius;
	this->areaVar = area;
}

void Circle::move(){}
void Circle::input(const char* prompt) {
	Point::input(prompt);
	std::cout << "radius:";
	std::cin >> radius;
	areaVar = M_PI * pow(radius, 2);
}

double Circle::area() {
	areaVar = M_PI * pow(radius, 2);
	return areaVar;
}

void Circle::output() { 
	std::cout << "Circle's area:" << std::setprecision(4) << area() << " "; Point::output();
}

class Square : public Point {
public:
	Square(double width = 0, double height = 0, double area = 0);
	
	void input(const char* prompt);
	void output();
	double area();
	void move();

private:
	double width, height, areaVar;
};



Square::Square(double width , double height , double area ) {
	this->width = width;
	this->height = height;
	areaVar = area;
}

void Square::move(){}

void Square::input(const char* prompt) {
	Point::input(prompt);
	std::cout << "Enter height:";
	std::cin >> height;
	std::cout << "Enter width:";
	std::cin >> width;

	areaVar = height * width;
}

double Square::area() {
	areaVar = width * height;
	return areaVar;
}

void Square::output(){
	std::cout << "Square's area:" << std::setprecision(4) << area() << " "; Point::output();
}


int main() {
	std::vector<std::shared_ptr<Point>> vec;
	std::shared_ptr<Point> p1 = std::make_shared<Point>(1,1);
	std::shared_ptr<Point> p2 = std::make_shared<Point>();
	std::shared_ptr<Point> c1 = std::make_shared<Circle>(2);
	std::shared_ptr<Point> c2 = std::make_shared<Circle>();
	std::shared_ptr<Point> s1 = std::make_shared<Square>(3,3);
	std::shared_ptr<Point> s2 = std::make_shared<Square>();
	
	p2->input("Point");
	c2->input("Circle");
	s2->input("Square");

	vec.insert(vec.end(), {p1, p2,c1,c2,s1,s2 });
	std::cout << "\nOriginal:" << std::endl;
	for (auto x : vec) {
		x->output();
	}
	std::sort(vec.begin(), vec.end(), [](std::shared_ptr<Point> p1, std::shared_ptr<Point> p2) {
		return p1->area() < p2->area();
		});
	std::cout << "\nSorted:" << std::endl;
	for (auto x : vec) {
		x->output();
	}
	

	

	return 0;
}