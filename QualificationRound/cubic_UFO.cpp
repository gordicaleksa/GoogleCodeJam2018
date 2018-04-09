//#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

double PI = 3.141592653589793;

// solved it like a boss (e.g. Grigori Perelman) ^^
// shadow theorem + some trigonometry
void rotate(double A, double& x1, double& y1, double& z1, double& x2, double& y2, double& z2, double& x3, double& y3, double& z3) {
	if (A <= 1.414213) {
		// we can rotate the cube only around z-axis! [0,45]
		double fi_z = (PI / 4.0) - acos(A / sqrt(2.0));
		x1 = 0.0; y1 = 0.0; z1 = 0.5;
		x2 = 0.5*sin(fi_z); y2 = -0.5*cos(fi_z); z2 = 0.0;
		x3 = 0.5*cos(fi_z); y3 = 0.5*sin(fi_z); z3 = 0.0;
	}
	else {
		// we rotate the cube around z-axis 45 deg and then around x-axis (0,~35] 35 <- arctan(1/sqrt(2))
		double fi_x = atan(1.0 / sqrt(2.0)) - acos(A / sqrt(3.0));
		double prefix = (sqrt(2.0) / 4.0);
		x1 = 0.0; y1 = 0.5*sin(fi_x); z1 = 0.5*cos(fi_x);
		x2 = prefix; y2 = -prefix * cos(fi_x); z2 = prefix * sin(fi_x);
		x3 = prefix; y3 = prefix * cos(fi_x); z3 = -prefix * sin(fi_x);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // gives speed to C++ IO
	int T; // # of test cases
	double A; // area

	// middle point coordinates of 3 faces of a cube
	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;

	cin >> T;
	cout.precision(15); // that's the precision of double

	// for every test case:
	for (int i = 0; i < T; i++) {
		// read in data
		cin >> A; 
		// main algorithm
		rotate(A, x1, y1, z1, x2, y2, z2, x3, y3, z3);
		// formated output:
		cout << "Case #" << i + 1 << ":" << endl;
		cout << x1 << " " << y1 << " " << z1 << endl;
		cout << x2 << " " << y2 << " " << z2 << endl;
		cout << x3 << " " << y3 << " " << z3 << endl;
	}

	return 0;
}

