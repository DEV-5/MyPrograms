/*
 * Purpose: Write a CPP to sum
 * DATE: 17-05-2025
 *
 */
#include <iostream>

using namespace std;

template <class summable>

//T sum(T& num1, T& num2, T& num3);

/* NOTE:for some reason if the funtion prototype is above and declaration is below 
 * I am observing an error: 'T' does not name a type
 */

summable sum(const summable numarr[], unsigned int sizeOfArr)
{
    summable result = 0;
    for (unsigned int idx = 0; idx < sizeOfArr; idx ++)
    {
        result += numarr[idx];
    }
    return result;
}

int main(void)
{
    //int numarr[] = {1,2,3,4};
    double numarr[] = {1.2,2.3,3.4,4.5};
    // int result = sum(num1, num2, num3);
    //cout << "The result is = " << sum<int>(num1, num2, num3) << endl;
    cout << "The result is = " << sum(numarr, sizeof(numarr)/sizeof(numarr[0])) << endl;
}


