
#include<iostream>
#include<string>
using namespace std;
class base
{
 public:
 int a;
 template<typename any1,typename any2>
 any1 add(any1 a,any2 b)
 {
  return a+b;
 }
};

class subclass1 : public  base
{
 public:
 int var1;
 template<typename any1,typename any2>
 any1 sub(any1 a,any2 b)
 { return a-b; }
};
class subclass2 : public  base
{
 public:
 int var2;
 template<typename any1,typename any2>
 any2 mul(any1 a,any2 b)
 { return a*b;  }
};
class root : public subclass1,public subclass2
{
 public:
 int var3;
 template<typename any1,typename any2>
 any1 div(any1 a,any2 b)
 { return a/b;  }
};

int main()
{ 
 int a=12,b=6;
 root ob;
 subclass1 ob2;
 cout<<"the sum of "<<a<<"+"<<b<<" = "<<ob.div(a,b)<<endl;
 return 0; 
}
