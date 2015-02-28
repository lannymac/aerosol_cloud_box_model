#include <stdio.h>
#include "parcel.h"
void swap(int *i, int *j)
{
  int t;
  t = *i;
  *i = *j;
  *j = t;
}

const double pi = 3.14159;

int main(int argc, char *argv[])
{
  float t=0,dt=.1,tf=100.;
  float initT = 293., initm = 1., initP = 98029;
  float initS = .8925, initz = 0., initV = 1.;
  parcel c;
   
  c.set_values(initm,initV,initT,initP,initS,initz);

  while (t <= tf) {
    c.move(dt);
    t += dt;
    printf("%.2f\n",c.z);
  }

  return 0;
}
