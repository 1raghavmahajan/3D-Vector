#pragma once

#include <iostream>
#include <vector>
#include <cassert>

#ifndef PI_
#define PI_ 3.14159265358979323846  /* pi */
#endif
#define DEG_TO_RAD(x) ((x * PI_) / 180.0)


class Vector3D
{
public:

	/* 
	 * I didn't see any reason to make the vector components private. 
	 * Any client could in any case independently modify them if a "Set" method was created. 
	 * As, there's no internal state to maintain or no invariant to protect, it's better to make them public for better code readability.
	 */
	double x, y, z;

	// Constructors Destructors
	Vector3D();
	~Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const Vector3D &v2);

	//Print Vector3D
	friend std::ostream &operator << (std::ostream &out, const Vector3D &v);


	//Operator Overloading

	Vector3D& operator = (const Vector3D& v2);
	bool operator == (const Vector3D& v2) const;

	Vector3D operator + (const Vector3D& v2) const;
	Vector3D& operator += (const Vector3D& v2);
	
	Vector3D operator - (const Vector3D& v2) const;
	Vector3D& operator -= (const Vector3D& v2);

	// Scalar Multiplication
	friend Vector3D operator * (double scalar, const Vector3D& v2 );
	Vector3D operator * (double scalar) const;
	Vector3D& operator *= (double scalar);

	// Dot Product
	Vector3D operator * (const Vector3D& v2) const;
	Vector3D& operator *= (const Vector3D& v2);

	// Scalar Division
	Vector3D operator / (double scalar) const;
	Vector3D& operator /= (double scalar);


	//Member Functions

	/**
	 * Magnitude Square ( |v|^2 )
	 */
	double mag_square() const;

	/**
	 * Norm / Magitude / Absolute ( ||v|| )
	 */
	double length() const;

	/**
	 * Normalize Vector ( v = v / |v| )
	 */
	Vector3D normalize();

	/*
	 * Cross Product ( V X V2 )
	 */
	Vector3D cross_product(const Vector3D& v2) const;

	/**
	 * 3D Distance |v - v2|
	 */
	double distance(const Vector3D& v2) const;

	/**
	 * Linear interpolation
	 * @param factor Factor of interpolation [ 0.0 , 1.0 ]
	 * @param v2 Second Vector 
	 */
	Vector3D lerp(double factor, const Vector3D& v2) const;

	/**
	 * Rotate vector around three axis. Angle in degrees
	 * @param ax Angle around X-axis.
	 * @param ay Angle around Y-axis.
	 * @param az Angle around Z-axis.
	 */
	void rotate(double ax, double ay, double az);

};

