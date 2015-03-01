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
  float N; // number distribution of aerosols
  float H; // atmospheric height; [m]

  float aerosolBins[15];
  float aerosolDist[15];
  float SCrit[15];

  float cloudBins[40];
  float cloudDist[40];

  void set_values (float, float, float, float,
		   float, float);
  void move (float);

  //  void set_distribution (std::array<float,15>);
  void set_aerosolDist (float[15], int);
  void set_cloudDist (int);

  float getSat();
  float getPartialPressure();
  float getW();

  void getCriticalS(int);

  void updateParameters(float);
    
};

#endif
