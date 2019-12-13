#include <iostream>
#include <vector>

#include "Simple.hpp"
#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

Simple::Simple(Camera* c_ptr, ViewPlane* v_ptr) : Sampler(c_ptr, v_ptr) {}

Simple* Simple::clone() const
{
  return new Simple(*this);
}

Ray* Simple::get_rays(size_t px, size_t py) const
{
  /*
    Gives the rays from the center of given pixel coordinates

    @param [size_t] px : Pixel along x-direction
    @param [size_t] py : Pixel along y-direction

    @return [Ray] : Pointer to the array of Ray objects
  */

  Ray* rays = new Ray[1];
  Point3D origin = viewplane_ptr->getPixelPoint(px, py);
  rays[0] = Ray(origin, camera_ptr->get_direction(origin));
  return rays;
}

size_t Simple::num_rays() const
{
  /*
    Gives the number of rays shot from a single pixel

    @return [size_t] : 1
  */
  return 1;
}
