#include <iostream>
#include <vector>

#include "RegularBox.hpp"
#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

RegularBox::RegularBox(Camera* c_ptr, ViewPlane* v_ptr, size_t degree)
    : Sampler(c_ptr, v_ptr), degree{degree}, weight{1.0 / degree / degree} {}

RegularBox* RegularBox::clone() const
{ 
  return new RegularBox(*this);
}

Ray* RegularBox::get_rays(size_t px, size_t py) const
{
  /*
    Gives the rays out of the given pixel coordinates whose weights add up to 1

    @param [size_t] px : Horizontal pixel coordinate
    @param [size_t] py : Vertical pixel coordinate

    @return [Ray*] : Pointer to the array of rays
  */

  Ray* rays = new Ray[this->num_rays()];

  for (int y = 0; y < static_cast<int>(this->degree); ++y)
  {
    for (int x = 0; x < static_cast<int>(this->degree); ++x)
    {
      double xPrime = (-static_cast<int>(this->degree) + 2 * x + 1) * this->weight;
      double yPrime = (-static_cast<int>(this->degree) + 2 * y + 1) * this->weight;
      
      Point3D origin = this->viewplane_ptr->getPixelPoint(px + xPrime, py + yPrime);
      
      rays[y * this->degree + x] = Ray(origin, this->camera_ptr->get_direction(origin), weight);
    }
  }

  return rays;
}

size_t RegularBox::num_rays() const
{
  /*
    Gives the number of rays per pixel

    @return [size_t] : this->degree^2
  */

  return this->degree * this->degree;
}