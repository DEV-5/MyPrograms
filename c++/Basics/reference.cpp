#include<iostream>
using namespace std;

int adder(int&,int&);

int main()
{
    int a = 111, b = 222;
    int &refa = a, &refb = b;
    printf("There is no spoon\r\n");
    printf(" %d + %d = %d\r\n", a, b, adder(refa,refb));
    printf("addr are as follows A:%d refa:%d b:%d refb:%d\r\n", &a, &refa, &b, &refb);
    cout<<"refa="<<a<<endl;
    return 0;
}

int adder(int &a, int &b)
{
    a = a + b;
    return a;
}
