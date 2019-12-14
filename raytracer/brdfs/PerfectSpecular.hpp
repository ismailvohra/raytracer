#pragma once
#include "BRDF.hpp"

class PerfectSpecular : public BRDF {
 private:
  float kr;
  RGBColor cr;

 public:
  // constructor
  PerfectSpecular();
  PerfectSpecular(const PerfectSpecular& ps);
  virtual PerfectSpecular* clone() const;    // virtual copy constructor

  virtual ~PerfectSpecular() = default;    // destructor

  virtual RGBColor f(const ShadeInfo& sinfo, const Vector3D& wo,
                     const Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi, float& pdf) const;
  virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const;

  void set_kr(const float k);
  void set_cr(const RGBColor& c);
  void set_cr(const float r, const float g, const float b);
  void set_cr(const float c);
};

