//trigonometry - P. Ahrenkiel

#include <cstdlib>
#include <iostream>
#include <math.h>

#include "mth.hpp"
#include "trg.hpp"

namespace trg {

//
double asincos(double s,double c)
{
	double a=acos(c);
	if(s<0.)a*=-1.;
	return a;
}

//
double asintan(double s,double t)
{
	return asincos(s,acos(s/t));
}

//
double acossin(double c,double s)
{
	return asincos(s,c);
}

//
double acostan(double c,double t)
{
	return asincos(c*t,c);
}

//
double atansin(double t,double s)
{
	return asincos(s,acos(s/t));
}

//
double atancos(double t,double c)
{
	return asincos(c*t,c);
}

//
double sinc(double x)
{
	if (fabs(x)<1.e-10) return 1.;
	return sin(x)/x;
}

}
