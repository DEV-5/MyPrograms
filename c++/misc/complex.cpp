//date:18-3-17
#include<iostream>
#include"complex.h"
using namespace std;

com::com()
{ real=1;imag=1;}

com::com(float real,float imag)
{
 this->real=real;
 this->imag=imag; 
}

void com::show()
{cout<<"the complex number is "<<real<<"+i"<<imag<<endl;}

//com com::operator+(com in)
com com::operator+(com in)
{
 com temp;
 temp.real=real+in.real;
 temp.imag=imag+in.imag;
 return temp;
}
//com com::operator
com com::operator-(com in)
{
 com temp;
 temp.real=real-in.real;
 temp.imag=imag-in.imag;
 return temp;
}
com com::operator*(com in)
{
 com temp;
 temp.real=(real*in.real)-(imag*in.imag);
 temp.imag=(real*in.imag)+(imag*in.real);
 return temp;
}
