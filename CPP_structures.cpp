// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Triangle
{
	float sideA;
	float sideB;
	float sideC;
	short n;

	void init(int n, float a, float b, float c);
	void print();
	float getPerimeter();
	float getArea();
	float getArea(float a, float b, float c);
	float getBigger(Triangle triangle);
	bool equals(Triangle triangle);
	bool isTriangle();
	bool isTriangle(float a, float b, float c);
};

void Triangle::init(int number, float a, float b, float c)
{
	n = number;
	sideA = a;
	sideB = b;
	sideC = c;
}

void Triangle::print()
{
	cout << endl << "Triangle " << n << " {" << sideA << ", " << sideB << ", " << sideC << "}" << endl << "perimeter: " << getPerimeter() << endl << "area: " << getArea();
}

float Triangle::getPerimeter()
{
	if (isTriangle(sideA, sideB, sideC))
	{
		return sideA + sideB + sideC;
	}
	else
	{
		return -1;
	}
}

float Triangle::getArea()
{
	return getArea(sideA, sideB, sideC);
}

inline float Triangle::getArea(float a, float b, float c)
{
	if (isTriangle(a, b, c))
	{
		float p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	else
	{
		return -1;
	}
}

float Triangle::getBigger(Triangle triangle)
{
	return getArea() - triangle.getArea();
}

bool Triangle::equals(Triangle triangle)
{
	return (getBigger(triangle) != 0 ? false : true);
}

bool Triangle::isTriangle()
{
	return isTriangle(sideA, sideB, sideC);
}

bool Triangle::isTriangle(float a, float b, float c)
{
	return ((a + b > c) && (a + c > b) && (b + c > a)) ? true : false;
}


struct Point2D
{
	int x;
	int y;
	double zeroDistance;

	Point2D(int x, int y)
	{
		this->x = x;
		this->y = y;
		zeroDistance = getZeroDistance();
	}

	Point2D()
	{
		this->x = 0;
		this->y = 0;
		this->zeroDistance = 0;
	}

	void input()
	{
		cout << "\nInput X: ";
		cin >> x;
		cout << "\nInput Y: ";
		cin >> y;
	}

	void input(const int a, const int b)
	{
		x = a;
		y = b;
		zeroDistance = getZeroDistance();
	}

	void showInfo(const int n)
	{
		std::cout << "\nPoint" << n << " (" << x << ", " << y << ")\n";
	}

	void showInfo()
	{
		std::cout << "\nPoint (" << x << ", " << y << ")\n";
	}

	double getZeroDistance()
	{
		return getDistance();
		// return getDistance(0, 0);
	}

	double getDistance(int x2 = 0, int y2 = 0)
	{
		return sqrt(pow((x - x2), 2) + pow((y - y2), 2));
	}

	double getDistance(Point2D point)
	{
		return getDistance(point.x, point.y);
		// return sqrt(pow((x - point.x), 2) + pow((y - point.y), 2));
	}
};

struct Circle
{
	Point2D center;
	int radius;

	Circle(int x, int y, int r);
	void showInfo();
	double getPerimeter();
	double getSquare();
	bool contains(Point2D point);
	bool contains(int x, int y);
};

Circle::Circle(int x, int y, int r)
{
	center.x = x;
	center.y = y;
	radius = r;
}

void Circle::showInfo()
{
	cout << "\nCircle: ";
	cout << endl << "center: " << "(" << center.x << ", " << center.y << ")";
	cout << endl << "radius = " << radius;
	cout << endl << "perimeter = " << getPerimeter() << endl;
}

double Circle::getPerimeter()
{
	return 2 * 3.1415 * radius;
}

double Circle::getSquare()
{
	return 3.1415 * radius * radius;
}

bool Circle::contains(Point2D point)
{
	double distance = center.getDistance(point);
	if (distance <= radius)
		return true;
	else
		return false;
}


bool Circle::contains(int x, int y)
{
	double distance = center.getDistance(x, y);
	if (distance <= radius)
		return true;
	else
		return false;
}

struct Point3D
{
	int x;
	int y;
	int z;

	Point3D()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Point3D(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
	}

	void input()
	{
		cout << "\nInput X: ";
		cin >> x;
		cout << "\nInput Y: ";
		cin >> y;
		cout << "\nInput Z: ";
		cin >> z;
	}

	void set(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
	}

	void showInfo()
	{
		std::cout << "\n Point(" << x << ", " << y << ", " << z << ")\n";
	}

	double calculateDistance(int x1 = 0, int y1 = 0, int z1 = 0)
	{
		return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1));
	}

	double getZeroDistance()
	{
		return calculateDistance();
	}

	double calculateDistance(const Point3D* point)
	{
		return calculateDistance(point->x, point->y, point->z);
	}
};


void inputPointXY(Point2D& point1)
{
	cout << "Input x:" << endl;
	cin >> point1.x;
	cout << "Input y:" << endl;
	cin >> point1.y;
}

int main()
{
	// point2D
	Point2D p11, p12, p13;
	p11.input(0, 4);
	p12.input(3, 0);
	p13.input(3, 5);

	p11.showInfo();
	cout << "Distance to (0, 0): " << p11.getZeroDistance() << endl;

	p12.showInfo();
	cout << "Distance to (0, 0): " << p12.getZeroDistance() << endl;

	p13.showInfo();
	cout << "Distance to (0, 0): " << p13.getZeroDistance() << endl;

	cout << "Distance from p11 to p12: " << p11.getDistance(p12) << endl;

	p11.input();
	cout << "Distance to (0, 0): " << p11.getZeroDistance() << endl;


	cout << "Distance from p11 to (3,6): " << p11.getDistance(3, 6) << endl;


	// point3D
	Point3D* p1 = new Point3D;
	p1->input();
	p1->showInfo();
	cout << "Distance to (0, 0, 0): " << p1->getZeroDistance() << endl;


	Point3D* p2 = new Point3D;
	const int x = 1, y = 4, z = 8; // x - first test coordinate
	p2->input();
	p2->showInfo();
	cout << "Zero distance: " << p2->getZeroDistance();

	cout << endl << "p1 <-> p2 distance: " << p1->calculateDistance(p2->x, p2->y, p2->z);
	cout << endl << "p1 <-> p2 distance: " << p1->calculateDistance(p2);


	// Array of point2D
	const int N = 10;
	Point2D points[N];
	for (int i = 0; i < N; i++)
	{
		points[i].input(2 + rand() % 12, rand() % 20);
		points[i].showInfo(i);
	}

	int indexOfNearest = 0;
	for (int i = 1; i < N; i++)
	{
		if (points[i].getZeroDistance() < points[i - 1].getZeroDistance())
			indexOfNearest = i;
	}

	cout << "Nearest point is: "; points[indexOfNearest].showInfo(indexOfNearest);
	cout << endl << "It's distance is: " << points[indexOfNearest].getZeroDistance();


	// Another struct example Triangle
	cout << endl << endl << "Size of type Triangle: " << sizeof(Triangle) << endl;

	Triangle triangle1;
	triangle1.n = 1;
	triangle1.sideA = 3;
	triangle1.sideB = 4;
	triangle1.sideC = 5;
	cout << "Size of variable triangle1: " << sizeof(triangle1);
	if (triangle1.isTriangle())
		triangle1.print();


	Triangle triangle2;
	triangle2.init(2, 2, 6, 7);
	if (triangle2.isTriangle())
		triangle2.print();

	cout << endl << triangle1.getBigger(triangle2);
	cout << endl << (triangle1.equals(triangle2) ? "equal" : "not equal");

	cout << endl << (triangle1.getArea() >= triangle1.getArea(3, 6, 7) ? "equal" : "not equal");


	Point2D point1, point2, point3;
	//inputPointXY(point1);
	//point1.input();
	point1.input(2, 6);
	point2.input(2, 3);
	point3.input(0, 0);

	point1.showInfo(1);
	point2.showInfo(2);
	point3.showInfo(3);

	cout << endl << point1.getZeroDistance();
	cout << endl << point2.getZeroDistance();
	cout << endl << point3.getZeroDistance();

	cout << endl << point1.getDistance(2, 3);
	cout << endl << point1.getDistance(point2);

	Circle circle1(3, 7, 4);
	circle1.showInfo();

	cout << endl << (circle1.contains(Point2D(-5, -2)) == true ? "Circle contains point (-5, -2)" : "Point (-5, -2) is out of circle");
	cout << endl << (circle1.contains(5, 9) == true ? "Circle contains point (5,9)" : "Point (5,9) is out of circle");
	cout << endl << circle1.center.getDistance(5, 9);

	Point3D p3d_1(1, 2, 6), p3d_2(2, 6, -5);
	p3d_1.showInfo();
	p3d_2.showInfo();

	cout << endl << "p3d_1 distance from (0, 0, 0) = " << p3d_1.getZeroDistance();
	cout << endl << "p3d_2 distance from (0, 0, 0) = " << p3d_2.getZeroDistance();
	cout << endl << "p3d_1 distance from p3d_2 = " << p3d_1.calculateDistance(p2);

	cout << endl << endl << "Sizes of different structs:" << endl;
	cout << endl << "Size of struct Point2D: " << setw(10) << sizeof(Point2D) << " bytes";
	cout << endl << "Size of struct Point3D: " << setw(10) << sizeof(Point3D) << " bytes";

	cout << endl << "Size of 'point1' variable of struct Point2D: " << setw(6) << sizeof(point1) << " bytes";
	cout << endl << "Size of 'p1' variable of struct Point3D: " << setw(10) << sizeof(p1) << " bytes";
	cout << endl;

	return 0;
}