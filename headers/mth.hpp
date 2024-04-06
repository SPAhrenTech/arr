// math - P. Ahrenkiel

#ifndef _MTH_
#define _MTH_

#include <cstdlib>
#include <math.h>

namespace mth {

double sqr(const double);
double sgn(const double);
double sgnp(const double);
double pwr(const double x,const std::size_t y);
double pwr(const double x,const int y);
double pwr(const double x,const double y);
double logy(const double x,const double y);
//double ln(const double x){return log(x);}
//double log10(const double x){return xlog10(x);}
//double abs(double x){return fabs(x);}
std::size_t cyc(std::size_t i);
std::size_t cyc(std::size_t i, std::size_t N);
//double trunc(double x);
double roundoff(const double x);
double rndom();
double Kdelta(std::size_t i, std::size_t j);
double dexp(const double x);
double magsqr(double *x,const size_t N);
double min(const double x,const double y);//{if(x<y)return x;else return y;}
double max(const double x,const double y);//{if(x>y)return x;else return y;}
//void swap(double &x,double &y){double z=x;x=y;y=z;}
//void swap(std::size_t &x,std::size_t &y){std::size_t z=x;x=y;y=z;}
double dmod(double x,double y);
int mod(const int x,const int y);

} // namespace mth

#endif
