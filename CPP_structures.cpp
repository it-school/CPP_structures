// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <cmath>
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
	return sideA + sideB + sideC;
}

float Triangle::getArea()
{
	return getArea(sideA, sideB, sideC);
}

inline float Triangle::getArea(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
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
	return ((sideA + sideB > sideC) && (sideA + sideC > sideB) && (sideB + sideC > sideA)) ? true : false;
}


struct point2D
{
	int x;
	int y;

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
	}

	void showInfo(const int n)
	{
		std::cout << "\nPoint" << (n + 1) << " (" << x << ", " << y << ")\n";
	}

	void showInfo()
	{
		std::cout << "\nPoint (" << x << ", " << y << ")\n";
	}

	double getZeroDistance()
	{
		return sqrt(x * x + y * y);
	}
};


struct point3D
{
	int x;
	int y;
	int z;

	void input()
	{
		cout << "\nInput X: ";
		cin >> x;
		cout << "\nInput Y: ";
		cin >> y;
		cout << "\nInput Z: ";
		cin >> z;
	}

	void input(int a, int b, int c)
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

	double calculateDistance(const point3D* point)
	{
		return calculateDistance(point->x, point->y, point->z);
	}
};


int main()
{
	// point2D
	point2D p11, p12, p13;
	p11.input(1, 7);
	p12.input(2, 6);
	p13.input(3, 5);

	p11.showInfo();
	cout << "Distance to (0, 0): " << p11.getZeroDistance() << endl;

	p12.showInfo();
	cout << "Distance to (0, 0): " << p12.getZeroDistance() << endl;

	p13.showInfo();
	cout << "Distance to (0, 0): " << p13.getZeroDistance() << endl;


	p11.input();
	cout << "Distance to (0, 0): " << p11.getZeroDistance() << endl;
	

	// point3D
	point3D* p1 = new point3D;
	p1->input();
	p1->showInfo();
	cout << "Distance to (0, 0, 0): " << p1->getZeroDistance() << endl;


	point3D* p2 = new point3D;
	const int x = 1, y = 4, z = 8; // x - first test coordinate
	p2->input(x, y, z);
	p2->showInfo();
	cout << "Zero distance: " << p2->getZeroDistance();

	cout << endl << "p1 <-> p2 distance: " << p1->calculateDistance(p2->x, p2->y, p2->z);
	cout << endl << "p1 <-> p2 distance: " << p1->calculateDistance(p2);


	// Array of point2D
	const int N = 10;
	point2D points [N];
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

	return 0;
}
