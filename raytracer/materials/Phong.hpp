#pragma once

#include "../brdfs/GlossySpecular.hpp"
#include "../brdfs/Lambertian.hpp"
#include "../lights/Light.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../world/World.hpp"
#include "Material.hpp"

class Phong : public Material {
 protected:
  Lambertian* ambient_brdf;
  Lambertian* diffuse_brdf;
  GlossySpecular* specular_brdf;

 public:
  Phong(void); //Constructor

   // Copy constuctor and assignment operator.
  Phong(const Phong& other);
  Phong& operator=(const Phong& other);
  
  //Virtual Copy Contructor
  virtual Phong* clone() const;

  virtual ~Phong(void); //Destructor

  virtual RGBColor shade(const ShadeInfo& sinfo);
};

