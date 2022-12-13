#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>

class Solid {
public:
	virtual double GetVolume()=0;
	virtual double GetSurface()=0;
};

class Box :public Solid {
private:
	double width;
	double height;
	double depth;

public:
	Box(double width, double height, double depth) {
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	double GetVolume() {
		return width * height * depth;
	}
	double GetSurface() {
		return (width * height) * 2 + (width * depth) * 2 + (height * depth) * 2;
	}
};

class Cylinder :public Solid {
private:
	double radius;
	double height;

public:
	Cylinder(double radius, double height) {
		this->radius = radius;
		this->height = height;
	}
	double GetVolume() {
		return (M_PI * radius * radius) * height;
	}
	double GetSurface() {
		return (M_PI * radius * radius) * 2 + (M_PI * radius * 2) * height;
	}
};

class Cone :public Solid {
private:
	double radius;
	double height;

public:
	Cone(double radius, double height) {
		this->radius = radius;
		this->height = height;
	}
	double GetVolume() {
		return (M_PI * radius * radius * height) / 3;
	}
	double GetSurface() {
		double busbar = (radius * radius) + (height * height) * sqrt(2);
		return (M_PI * radius * (busbar + radius));
	}
};

class Sphere :public Solid {
private:
	double radius;

public:
	Sphere(double radius) {
		this->radius = radius;
	}
	double GetVolume() {
		return (double)4 / (double)3 * (M_PI * radius * radius * radius);
	}
	double GetSurface() {
		return (double)4 * (M_PI * radius * radius);
	}
};
int main()
{
	double width;
	double height;
	double depth;
	double radius;

	cout << "箱の幅を入力:";
	cin >> width;
	cout << "箱の高さを入力:";
	cin >> height;
	cout << "箱の奥行きを入力:";
	cin >> depth;
	
	Box* box = new Box(width, height, depth);
	cout << "箱の体積は" << box->GetVolume() << endl;
	cout << "箱の面積は" << box->GetSurface() << endl;

	cout << "円柱の半径を入力:";
	cin >> radius;
	cout << "円柱の高さを入力:";
	cin >> height;

	Cylinder* cylinder = new Cylinder(radius, height);
	cout << "円柱の体積は" << cylinder->GetVolume() << endl;
	cout << "円柱の面積は" << cylinder->GetSurface() << endl;

	cout << "円錐の半径を入力:";
	cin >> radius;
	cout << "円錐の高さを入力:";
	cin >> height;

	Cone* cone = new Cone(radius, height);
	cout << "円錐の体積は" << cone->GetVolume() << endl;
	cout << "円錐の面積は" << cone->GetSurface() << endl;

	cout << "球の半径を入力:";
	cin >> radius;

	Sphere* sphere = new Sphere(radius);
	cout << "球の体積は" << cone->GetVolume() << endl;
	cout << "球の面積は" << cone->GetSurface() << endl;

}