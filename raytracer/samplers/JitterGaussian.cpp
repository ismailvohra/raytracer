#include <time.h>
#include <iostream>
#include <vector>

#include "JitterGaussian.hpp"
#include "../cameras/Camera.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

std::mt19937 JitterGaussian::generator(time(NULL));

JitterGaussian::JitterGaussian(Camera* c_ptr, ViewPlane* v_ptr, size_t degree,
                               double sigma)
    : Sampler(c_ptr, v_ptr),
      degree{degree},
      step{1.0 / degree / degree},
      invSigma{1.0 / sigma} {}

JitterGaussian* JitterGaussian::clone() const
{
  return new JitterGaussian(*this);
}

Ray* JitterGaussian::get_rays(size_t px, size_t py) const
{
  /*
    Gives the rays out of the given pixel coordinates whose weights add up to 1

    @param [size_t] px : Horizontal pixel coordinate
    @param [size_t] py : Vertical pixel coordinate

    @return [Ray*] : Pointer to the array of rays
  */

  Ray* rays = new Ray[this->num_rays()];
  
  std::uniform_real_distribution<double> dist(-step, step);

  double totalWeight = 0;

  for (int y = 0; y < static_cast<int>(this->degree); ++y)
  {
    for (int x = 0; x < static_cast<int>(this->degree); ++x)
    {
      double xPrime = (-static_cast<int>(this->degree) + 2 * x + 1) * step + dist(this->generator);
      double yPrime = (-static_cast<int>(this->degree) + 2 * y + 1) * step + dist(this->generator);
      
      double weight = gaussian(sqrt(xPrime * xPrime + yPrime * yPrime));

      Point3D origin = viewplane_ptr->getPixelPoint(px + xPrime, py + yPrime);
      rays[y * this->degree + x] = Ray(origin, this->camera_ptr->get_direction(origin), weight);
      
      totalWeight += weight;
    }
  }

  for (size_t i = 0; i < this->num_rays(); ++i)
  {
    rays[i].w /= totalWeight;
  }

  return rays;
}

size_t JitterGaussian::num_rays() const
{
  /*
    Gives the number of rays per pixel

    @return [size_t] : this->degree^2
  */

  return this->degree * this->degree;
}

double JitterGaussian::gaussian(double x) const
{
  /*
    Computes the Gaussian value for given x

    @return [size_t] : Gaussian value
  */

  return exp(-0.5 * x * x * this->invSigma * this->invSigma) * this->invSigma / (2 * PI);
}
