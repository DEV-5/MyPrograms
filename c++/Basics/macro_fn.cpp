
#include<iostream>
using  namespace std;
#define abs(a) a<0?-a:a //absolute value of a signed integer
int main()
{
    int a;
    cout<<"please enter a number who's absolute is to be displayed:"<<endl;
    cin>>a;
    cout<<"the absolute value  of the number entered is:"<<(abs(a)) <<endl;

    return 0;
}

