#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>

#include "LibConstants.h"
using namespace std;

#include "parcel.h"
void swap(int *i, int *j)
{
  int t;
  t = *i;
  *i = *j;
  *j = t;
}

int main(int argc, char *argv[])
{
  float bins[15] = {0.13 ,  0.147,  0.17 ,  0.192,  0.231,  0.284,  0.352,  0.447,  0.592,  0.794,  1.039,  1.342,  1.732,  2.236,  2.739};

  //  std::cout << b << std::endl;
  float t=0, dt=.1, tf=100.;
  float initT = 292., initm = 1., initP = 98029;
  float initS = .8915, initz = 0., initV = 1.;

  parcel c;

  c.set_values(initm,initV,initT,initP,initS,initz);
  c.set_aerosolDist(bins,15);
  c.set_cloudDist(40);
  //cout << c.aerosolBins[0] <<endl;
  //cout << c.getSat() <<endl;
  //cout << c.getPartialPressure() <<endl;
  
  c.getCriticalS(15);
  


  while (t <= tf) {
    c.updateParameters(dt);

    
    t += dt;
    printf("%.2f\n",c.T);
  }

  return 0;
}

