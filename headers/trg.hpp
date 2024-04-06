// trigenomtry - P. Ahrenkiel

#ifndef _TRG_
#define _TRG_

#include <cstdlib>
#include <math.h>

namespace trg {

const double Pi(4.*atan(1.));
const double degtorad(180./Pi);

//trg
double asincos(double s, double c);
double asintan(double s, double t);
double acossin(double c, double s);
double acostan(double c, double t);
double atansin(double t, double s);
double atancos(double t, double c);

//special function(s)
double sinc(double x);

} // namespace trg

#endif
