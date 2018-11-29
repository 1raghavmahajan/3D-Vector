#include "Vector3D.h"


//Default initialisations
Vector3D::Vector3D(): x(0), y(0), z(0)
{
}

//Default destructor
Vector3D::~Vector3D()
{
	
}

Vector3D::Vector3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D(const Vector3D& v2)
{
	x = v2.x;
	y = v2.y;
	z = v2.z;
}



std::ostream& operator<<(std::ostream& out, const Vector3D& v)
{
	out << "< " << v.x << " , " << v.y << " , " << v.z << " >";
	return out;
}


Vector3D& Vector3D::operator=(const Vector3D& v2)
{
	x = v2.x;
	y = v2.y;
	z = v2.z;
	return *this;
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


Vector3D operator * (double scalar, const Vector3D& v2)
{
	Vector3D t;
	t.x = v2.x * scalar;
	t.y = v2.y * scalar;
	t.z = v2.z * scalar;
	return t;
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


Vector3D Vector3D::operator*(const Vector3D& v2) const
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
	return *this;
}


Vector3D Vector3D::operator/(double scalar) const
{
	Vector3D t;
	t.x = x * scalar;
	t.y = y * scalar;
	t.z = z * scalar;
	return t;
}

Vector3D& Vector3D::operator/=(double scalar)
{
	x/=scalar;
	y/=scalar;
	z/=scalar;
	return *this;
}




Vector3D Vector3D::cross_product(const Vector3D &v2) const
{
    double ni = y*v2.z - z*v2.y;
    double nj = z*v2.x - x*v2.z;
    double nk = x*v2.y - y*v2.x;
    return Vector3D (ni, nj, nk);
}

double Vector3D::length() const
{
    return sqrt(mag_square());
}

double Vector3D::mag_square() const
{
    return x*x+y*y+z*z;
}

Vector3D Vector3D:: normalize()
{
    assert(length()!=0);
    *this /= length();
    return *this;
}

double Vector3D::distance(const Vector3D &v2) const
{
    Vector3D dist=*this-v2;
    return dist.length();
}

Vector3D Vector3D::lerp(double factor, const Vector3D& v2) const
{
	return ( (*this) + ((v2 - (*this)) * factor));
}

void Vector3D::rotate(double ax, double ay, double az)
	{
		double a = cos(DEG_TO_RAD(ax));
		double b = sin(DEG_TO_RAD(ax));
		double c = cos(DEG_TO_RAD(ay));
		double d = sin(DEG_TO_RAD(ay));
		double e = cos(DEG_TO_RAD(az));
		double f = sin(DEG_TO_RAD(az));
		double nx = c * e * x - c * f * y + d * z;
		double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
		double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
		x = nx;
		y = ny;
		z = nz;
	}

