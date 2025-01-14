//DATE: 21st july 2020
//Author: vasudev
//cpp Tutorial
//https://www.youtube.com/watch?v=gnkw3tjc4ck

#include<iostream>
#include<cstdlib>
#include<string>
#include<limits>
#include<vector>
#include<sstream>
#include<numeric>
#include<ctime>
#include<cmath>

using namespace std;

int imGlobal = 0;
const double PI = 3.141; //constant gloabal variable

//Function Declaration
void Size_fn();

int main(int argc, char** argv)
{
    string str;
    //std::cout<<"Hello World"<<std::endl;
    cout<<"Hello World"<<endl; // '<<' is called the stream insertion operator.
    //cin>>str; //user input 
    //cout<<"==> You typed="<<str<<endl;
    bool fast = false;
    char mygrade = 'A';
    Size_fn();
    float  f1 = 1.11111;
    float  f2 = 1.1111111;
    double d1 = 1.1111111111111111; 
    cout<<"Float1 = "<<f1<<" Float2= "<<f2<<endl;
    cout<<"double = "<<d1<<endl;
    printf("d1 = %.16f\n",(d1));
    printf("2 x d1 = %.16f\n",(2*d1));//16th decimal place is not accurate

    auto whoami = true;
    auto whoami2 = "i am not sure if this works";
    auto whoami3 = {1,2,3,4,5,6};
    cout<<"size of whoami = "<<sizeof(whoami)<<endl;//compiler will assign data type
    cout<<"size of whoami2 = "<<sizeof(whoami2)<<endl;
    cout<<"no of elements in whoami3 = "<<whoami3.size()<<endl;

    return 0;
}

void Size_fn()
{
    cout<<"Min unsigned short int "<<std::numeric_limits<unsigned short int>::min()<<endl;
    cout<<"Max unsigned short int "<<std::numeric_limits<unsigned short int>::max()<<endl;
    cout<<"Min signed short int "<<std::numeric_limits<signed short int>::min()<<endl;
    cout<<"Max signed short int "<<std::numeric_limits<signed short int>::max()<<endl;
    cout<<"Min int "<<std::numeric_limits<int>::min()<<endl;
    cout<<"Max int "<<std::numeric_limits<int>::max()<<endl;
    cout<<"Min long int "<<std::numeric_limits<long int>::min()<<endl;
    cout<<"Max long int "<<std::numeric_limits<long int>::max()<<endl;
    cout<<"Min long long int "<<std::numeric_limits<long long int>::min()<<endl;
    cout<<"Max long long int "<<std::numeric_limits<long long int>::max()<<endl;
    cout<<"Min float "<<std::numeric_limits<float>::min()<<endl;
    cout<<"Max float "<<std::numeric_limits<float>::max()<<endl;
    cout<<"Min double "<<std::numeric_limits<double>::min()<<endl;
    cout<<"Max double "<<std::numeric_limits<double>::max()<<endl;
    cout<<"Min long double "<<std::numeric_limits<long double>::min()<<endl;
    cout<<"Max long double "<<std::numeric_limits<long double>::max()<<endl;
}
