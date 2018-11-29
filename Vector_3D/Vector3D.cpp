#include "Vector3D.h"

//Default initialisations
Vector3D::Vector3D(): x(0), y(0), z(0)
{
}

bool Vector3D::operator==(const Vector3D& v2) const
{
	return (x==v2.x && y==v2.y && z==v2.z);
}

Vector3D Vector3D::operator+(const Vector3D& v2) const
{
	Vector3D t;
	t.x = x + v2.x;
	t.y = y + v2.y;
	t.z = z + v2.z;
	return t;
}

Vector3D& Vector3D::operator+=(const Vector3D& v2)
{
	x+=v2.x;
	y+=v2.y;
	z+=v2.z;
	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& v2) const
{
	Vector3D t;
	t.x = x - v2.x;
	t.y = y - v2.y;
	t.z = z - v2.z;
	return t;
}

Vector3D& Vector3D::operator-=(const Vector3D& v2)
{
	x-=v2.x;
	y-=v2.y;
	z-=v2.z;
	return *this;
}

Vector3D Vector3D::operator*(double scalar) const
{
	Vector3D t;
	t.x = x * scalar;
	t.y = y * scalar;
	t.z = z * scalar;
	return t;
}

Vector3D& Vector3D::operator*=(double scalar)
{
	x*=scalar;
	y*=scalar;
	z*=scalar;
	return *this;
}

Vector3D Vector3D::operator*(const Vector3D& v2)
{
	Vector3D t;
	t.x = x * v2.x;
	t.y = y * v2.y;
	t.z = z * v2.z;
	return t;
}

Vector3D& Vector3D::operator*=(const Vector3D& v2)
{
	x*=v2.x;
	y*=v2.y;
	z*=v2.z;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& v)
{
	out << "< " << v.x << " , " << v.y << " , " << v.z << " >";
}

std::istream& operator>>(std::istream& in, Vector3D v)
{
	in >> v.x >> v.y >> v.z;
}
