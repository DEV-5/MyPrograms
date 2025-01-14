//DATE:28-5-2018
#include<iostream>
using namespace std;

class hello
{

    public:
     int a;
    hello(int a=0)
    {
        this->a =a;
         cout<<"intiallizing a hello object"<<endl;//
    }

    int  adder(int a,int b)const
    {
        a=a+b;
        return a;
    }
};

int main()
{
    hello obj;
    cout<<"value of a is ="<<obj.a<<" and the sum of a and b is "<<obj.adder(12,9)<<endl;
    return 0;
}

