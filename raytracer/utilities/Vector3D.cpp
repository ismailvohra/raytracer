/**
   This file implements the class Vector3D which represents a 3D vector.
*/

#include <cmath>

#include "Vector3D.hpp"
#include "Point3D.hpp"

Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(double c) : x(c), y(c), z(c) {}

Vector3D::Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

Vector3D::Vector3D(const Point3D& p) : x(p.x), y(p.y), z(p.z) {}

Vector3D& Vector3D::operator=(const Point3D& rhs)
{
  /*
    Operator overload: Assignment Operator from a point

    @param [Point3D] rhs : Any other point

    @return [Vector3D] : Vector formed from the passed point
  */

  x = rhs.x;
  y = rhs.y;
  z = rhs.z;

  return *this;
}

Vector3D Vector3D::operator-() const
{
  /*
    Operator overload: Unary Minus

    @return [Vector3D] : Vector after unary minus operation
  */

  return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator+(const Vector3D& v) const
{
  /*
    Operator overload: Addition of vectors

    @param [Vector3D] v : Any other vector

    @return [Vector3D] : Vector after addition
  */

  return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
  /*
    Operator overload: Compound addition

    @param [Vector3D] v : Any other vector

    @return [Vector3D] : Vector after compound addition
  */

  x += v.x;
  y += v.y;
  z += v.z;

  return *this;
}

Vector3D Vector3D::operator-(const Vector3D& v) const
{
  /*
    Operator overload: Subtraction of vectors

    @param [Vector3D] v : Any other vector

    @return [Vector3D] : Vector after subtraction
  */

  return Vector3D(x - v.x, y - v.y, z - v.z);
}

Vector3D& Vector3D::operator-=(const Vector3D& v)
{
  /*
    Operator overload: Compound subtraction

    @param [Vector3D] v : Any other vector

    @return [Vector3D] : Vector after compound subtraction
  */

  x -= v.x;
  y -= v.y;
  z -= v.z;

  return *this;
}

Vector3D Vector3D::operator*(const double a) const
{
  /*
    Operator overload: Multiplication

    @param [double] a : Any scaling value

    @return [Vector3D] : Vector after multiplication
  */

  return Vector3D(x * a, y * a, z * a);
}

Vector3D Vector3D::operator/(const double a) const
{
  /*
    Operator overload: Division

    @param [double] a : Any scaling value

    @return [Vector3D] : Vector after division
  */

  return Vector3D(x / a, y / a, z / a);
}

Vector3D& Vector3D::normalize()
{
  /*
    Nomalize - convert to a unit vector

    @return [Vector3D] : Vector after normalization
  */

  double len = this->length();

  x /= len;
  y /= len;
  z /= len;
  
  return *this;
}

double Vector3D::length()
{
  /*
    Computes the length of this vector

    @return [double] : length of vector
  */

  return std::sqrt(this->len_squared());
}

double Vector3D::len_squared()
{
  /*
    Computes the square length of this vector

    @return [double] : square length of vector
  */

  return std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(this->z, 2);
}

double Vector3D::operator*(const Vector3D& b) const
{
  /*
    Operator overload: Dot product

    @param [double] b : Any other vector

    @return [Vector3D] : Dot product of vectors
  */

  return (x * b.x) + (y * b.y) + (z * b.z);
}

Vector3D Vector3D::operator^(const Vector3D& v) const
{
  /*
    Operator overload: Cross product

    @param [double] v : Any other value

    @return [Vector3D] : Cross product of vectors
  */

  double xPrime = (y * v.z) - (z * v.y);
  double yPrime = (z * v.x) - (x * v.z);
  double zPrime = (x * v.y) - (y * v.x);
  
  return Vector3D(xPrime, yPrime, zPrime);
}

Vector3D operator*(const double a, const Vector3D& v)
{ 
  return v * a;
}
