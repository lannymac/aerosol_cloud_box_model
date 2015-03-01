#include <stdio.h>
#include <iostream>
#include <array>
#include "parcel.h"
#include <math.h>
#include "LibConstants.h"
using namespace std;
using namespace PhysicalConstants;
const double pi = 3.14159;

void parcel::set_values (float a, float b, float c, float d,
			 float e, float f){
    m = a;
    v = b;
    T = c;
    P = d; 
    S = e;
    z = f;
    H = R*T/(MAir*g);
}


// void parcel::set_distribution (array<float,15> bins){

//   cout << bins[0] << endl;
// }

void parcel::set_aerosolDist(float bins[15], int n){
  // set array pointer to parcelBins
  float tmp[n];

  for (int i =0; i<n; i++){
    aerosolBins[i] = bins[i];
      }
  //aerosolBins = tmp;
  // *aerosolBins = *bins;

  float N1 = 132.42446871, sigma1 = 1.36771854, Dpg1 = 0.16184106;
  float N2 = 27.70694184, sigma2 = 1.05953403, Dpg2 = 0.15558948;

  float N_dist[n];
  int i;

  for (i=0;i<n;i++){
    aerosolBins[i] /= 1e6;
    aerosolDist[i] = log(10)*bins[i]*(N1/(sqrt(2*pi)*bins[i]*log(sigma1)))*exp(-pow(log(bins[i]) - log(Dpg1),2)/(2*pow(log(sigma1),2)))
      +log(10)*bins[i]*(N2/(sqrt(2*pi)*bins[i]*log(sigma2)))*exp(-pow(log(bins[i]) - log(Dpg2),2)/(2*pow(log(sigma2),2)));
    aerosolDist[i] *= 1e6;

    //std::cout << N_dist[i] << " "<< bins[i] << " "<< i << std::endl;
  }    
  //  aerosolDist = N_dist;
}

void parcel::set_cloudDist(int n){
  //float tmp[n];
  cloudDist[0] = 1.12246205e-06;  
  for (int i =1; i<n; i++){
    cloudDist[i] = pow(2,log2(cloudDist[i-1]) + 1/3.);
    //std::cout << tmp[i] << endl;
  }
}


float parcel::getSat(){
  return 100.*exp(53.68 - 6743./T - 4.845*log(T));
}

float parcel::getPartialPressure(){
  return S*getSat();
}

float parcel::getW(){
  return (getPartialPressure()*0.622)/(P - getPartialPressure());
}

void parcel::getCriticalS(int n){
  float A;
  //std::cout << aerosolBins[7] << endl;
  A = 4.*mwH2O*st_w/(R*T*rhoH2O);
  for (int i = 0; i<n; i++){
    SCrit[i] = exp(sqrt((4.*pow(A,3)/(27.*kappa*pow(aerosolBins[i],3.)))));
    //    std::cout << SCrit[i] << endl;
  }
}

void parcel::updateParameters(float dt){
  float dz = v*dt;
  z += v*dt; 

  T=T-0.00976*(dz);
  H=R*T/(MAir*g);
  P=P*exp(-(dz)/H);

}
