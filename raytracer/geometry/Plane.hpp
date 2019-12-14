#pragma once
/**
   This file declares the Plane class which represents a plane defined by an
   included point and its normal.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"

#include "Geometry.hpp"

class Plane : public Geometry {
 protected:
  Point3D a;   // point on the plane.
  Vector3D n;  // normal to the plane, store as unit vector.

 public:
  // Constructors.
  Plane();  // set plane to xz-plane.
  Plane(const Point3D& pt,
        const Vector3D& n);  // set point and normal, then normalize.

  // Copy constructor and assignment operator.
  Plane(const Plane& object) = default;
  Plane& operator=(const Plane& rhs) = default;

  virtual ~Plane() = default;   // Destructor.


  virtual Plane* clone() const;   // Virtual copy constructor.


  virtual BoundingBox get_bounding_box() const;   // Bounding box computation.


  // Ray intersection. Set t and sinfo as per intersection with this object.
  virtual bool hit(const Ray& ray, ShadeInfo& s) const;
};

