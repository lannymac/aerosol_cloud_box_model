#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

//  File Name : LibConstants.hpp    Purpose : Global Constants for Lib Utils
namespace PhysicalConstants
{
  const float mwH2O = 0.018; // molecular weight water; [kg/mol]  
  const float R = 8.314472; // gas constant, J/(mol K)
  const float MAir = 0.028966; // molecular mass of air, kg/mol
  const float g = 9.81; // gravity, m/s2
  const float st_w = 7.3e-2; // surface tension, N/m
  const float rhoH2O = 1000.; // water density,kg/m3
  const float Cp_air = 1000.; // specific heat of air J/(kg K)
  const float Lw = 2270000.; // latent heat fo condensation for water, J/kg
  const float Hv = 2260000.; // heat of vaporisation of water, J/kg
  const float ka = 0.0257; // thermal conductivety of air, W/(m K)
  const float rhoSulfate = 1770.; // density from previous assignment, kg/m3, assuming sulfate
  const float Dg = 2.e-5;// diffusivity of water, m2/s
  const float mu=17.6E-6;//Viscosity of air [kg/m s]
  const float st=7.56E-2;//Surface tension of water [kg s^-2]
  const float g_f=.85;
  const float F0=342.;
  const float Ac=1.;
  const float Ta=.76;
  const float kappa = 0.5; // hygroscopicity
}

namespace MathConstants
{
  const float pi = 3.1415926; // 
}

#endif
