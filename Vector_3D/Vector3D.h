#pragma once

#include <iostream>
#include <vector>
#include <cassert>
//#include <cmath>

class Vector3D
{
public:

	/* 
	 * I didn't see any reason to make the vector components private. 
	 * Any client could in any case independently modify them via a "Set" method. 
	 * As, there's no internal state to maintain or no invariant to protect, it's better to make them private for better code readability.
	 */
	double x, y, z;

	// Constructors
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const Vector3D &v2);

	//IO

	//Print Vector3D
	friend std::ostream &operator << (std::ostream &out, const Vector3D &v);
	//Input Vector3D
	friend std::istream &operator >> (std::istream &out, Vector3D v);


	//Operator Overloading

	bool operator == (const Vector3D& v2) const;
	
	Vector3D operator + (const Vector3D& v2) const;
	Vector3D& operator += (const Vector3D& v);
	
	Vector3D operator - (const Vector3D& v2) const;
	Vector3D& operator -= (const Vector3D& v2);

	// Scalar Multiplication
	Vector3D operator * (double scalar) const;
	Vector3D& operator *= (double scalar);

	// Dot Product
	Vector3D operator * (const Vector3D& v2) const;
	Vector3D& operator *= (const Vector3D& v2);

	// Scalar Division
	Vector3D operator / (double scalar) const;
	Vector3D& operator /= (double scalar);


	//Member Functions

	//Magnitude Square |v|^2
	double mag_square() const;

	// Magitude / Absolute |v|
	double mag() const;

	// Normalize v = v / |v|
	Vector3D normalize();

	// Cross Product
	Vector3D cross_product(const Vector3D& v2) const;

	// 3D Distance |v - v2|
	double distance(const Vector3D& v2) const;


};

