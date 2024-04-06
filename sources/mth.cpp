//math - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "mth.hpp"

namespace mth{

//
double sqr(const double x)
{return x*x;}

//
double sgn(const double x)
{
	return (x>0.)?1.:(x<0.)?-1.:0.;
}

//
double sgnp(const double x)
{
	return (x>0.)?1.:(x<0.)?-1.:1.;
}

//
double pwr(const double x,const std::size_t y){return pow(x,y);}
double pwr(const double x,const int y){return pow(x,y);}
double pwr(const double x,const double y){return pow(x,y);}

double logy(const double x,const double y)
{return log(fabs(x))/log(y);}

//
std::size_t cyc(std::size_t i)
{while(i>2)i-=3;return i;}
 	
//
std::size_t cyc(std::size_t i,std::size_t N)
{
	std::size_t res=i;
	while(!(res<N))
		res-=N;
	return res;
}

//double trunc(double x){return (x>0)?floor(x):ceil(x);}

//
double roundoff(double x)
{
	double xp=fabs(x);
//	double r=(long)xp;
	double r=trunc(xp);
	if(xp-r>0.5)r++;
	if(x<0)r*=-1;

	return r; 	
}

//
double rndom()
{return 1./(RAND_MAX+1.)*rand();}

//
double Kdelta(std::size_t i,std::size_t j)
{return (i==j)?1:0;}

/*
*/
double dexp(double x)
{return exp(x);}

//
double magsqr(double *x,const std::size_t N)
{
	double res=0.;
	for(std::size_t i=0;i<N-1;++i)
		res+=sqr(x[i]);
	return res;
}
double min(const double x,const double y){if(x<y)return x;else return y;}
double max(const double x,const double y){if(x>y)return x;else return y;}

double dmod(const double x,const double y)
{
	return x-y*floor(x/y);
}

int mod(const int x,const int y)
{
	return (x>=0)?x%y:(y-(-x)%y)%y;
}

}
