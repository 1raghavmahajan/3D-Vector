#pragma once

#include <iostream>
#include <vector>
//#include <cmath>

class Vector3D
{

	double x, y, z;

public:

	// Constructor
	Vector3D();

	//Operator Overloading
	bool operator == (const Vector3D& v2) const;
	
	Vector3D operator + (const Vector3D& v2) const;
	Vector3D& operator += (const Vector3D& v);
	
	Vector3D operator - (const Vector3D& v2) const;
	Vector3D& operator -= (const Vector3D& v);

	// Scalar Multiplication
	Vector3D operator * (double scalar) const;
	Vector3D& operator *= (double scalar);
	
	// Dot product
	Vector3D operator * (const Vector3D& v2);
	Vector3D& operator *= (const Vector3D& v);


	//IO

	//Print Vector3D
	friend std::ostream &operator << (std::ostream &out, const Vector3D &v);
	//Input Vector3D
	friend std::istream &operator >> (std::istream &out, Vector3D v);

};

