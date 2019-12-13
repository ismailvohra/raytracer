#pragma once

#include "../brdfs/Lambertian.hpp"
#include "../lights/Light.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../world/World.hpp"
#include "Material.hpp"

class Matte : public Material {
private:
  Lambertian* ambient_brdf;

  Lambertian* diffuse_brdf;
 public:
  
  Matte(void); // constructor

  
  Matte(const Matte& m); // copy constructor
  
  // virtual copy constructor
  virtual Material* clone() const;

    //assignment operator.

  Matte& operator=(const Matte& rhs);
  
  ~Matte(void);   // destructor

  // setters
  void set_ka(const float k);
  void set_kd(const float k);
  void set_cd(const RGBColor c);
  void set_cd(const float r, const float g, const float b);
  void set_cd(const float c);

  virtual RGBColor shade(const ShadeInfo& sr);

 
};

