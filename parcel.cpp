#include "parcel.h"

void parcel::set_values (float a, float b, float c, float d,
		   float e, float f){
    m = a;
    v = b;
    T = c;
    P = d; 
    S = e;
    z = f;
    
}

void parcel::move (float dt){
  z += v*dt;
}
