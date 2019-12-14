#include <cmath>

#include "RGBColor.hpp"

RGBColor::RGBColor() : r{0}, g{0}, b{0} {}

RGBColor::RGBColor(double c) : r{c}, g{c}, b{c} {}

RGBColor::RGBColor(double _r, double _g, double _b) : r{_r}, g{_g}, b{_b} {}

RGBColor RGBColor::operator+(const RGBColor& c) const
{
  /*
    Operator overload: Addition
  */

  return RGBColor(r + c.r, g + c.g, b + c.b);
}

RGBColor& RGBColor::operator+=(const RGBColor& c)
{
  /*
    Operator overload: Compound addition
  */

  *this = *this + c;
  return *this;
}

RGBColor RGBColor::operator*(const double a) const
{
  /*
    Operator overload: Multiplication by a float
  */


  return RGBColor(r * a, g * a, b * a);
}

RGBColor RGBColor::operator*(const RGBColor& c) const
{
  /*
    Operator overload: Multiplication by a RGBColor
  */


  return RGBColor(r * c.r, g * c.g, b * c.b);
}

RGBColor& RGBColor::operator*=(const double a)
{
  /*
    Operator overload: Compound multiplication by a float
  */

  *this = *this * a;
  return *this;
}

RGBColor RGBColor::operator/(const double a) const
{
  /*
    Operator overload: Division by a float
  */

  return RGBColor(r / a, g / a, b / a);
}

RGBColor& RGBColor::operator/=(const double a)
{
  /*
    Operator overload: Compound division by a float
  */

  *this = *this / a;
  return *this;
}

bool RGBColor::operator==(const RGBColor& c) const
{
  /*
    Operator overload: Equality
  */

  return r == c.r && g == c.g && b == c.b;
}

RGBColor RGBColor::powc(double p) const
{
  /*
    Operator overload: Raise components to a power
  */

  return RGBColor(pow(r, p), pow(g, p), pow(b, p));
}

double RGBColor::average() const
{ 
  /*
    Operator overload: Average of components
  */

  return (r + g + b) / 3.0;
}

RGBColor operator*(const double a, const RGBColor& c)
{
  return c * a;
}
