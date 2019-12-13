#include "Parallel.hpp"

Parallel::Parallel()
	:	dir(Vector3D(0,0,-1))
{}

Parallel::Parallel(float c)
	//:	dir(Vector3D(c).normalize())
{
    Vector3D vect(c);
    vect.normalize();
    this->dir = vect;
}

Parallel::Parallel(float x, float y, float z)
{
    Vector3D vect(x,y,z);
    vect.normalize();
    this->dir = vect;
}

Parallel::Parallel(const Vector3D &d)
{
    Vector3D vect(d);
    vect.normalize();
    this->dir = vect;
}

Parallel* Parallel::clone() const { return new Parallel(*this); }

Vector3D Parallel::get_direction(const Point3D& p) const {
  (void)p;  //Parallel camera will have same dir
  return dir;
}
