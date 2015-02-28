#ifndef PARCEL_H
#define PARCEL_H

class parcel {
 public:
  float m; // mass [kg]
  float v; // veloctiy [m/s]
  float T; // temperature [K]
  float P; // pressure [Pa]
  float S; // saturation
  float z; // height [m]
  
  void set_values (float, float, float, float,
		   float, float);
  void move (float);
};

#endif
