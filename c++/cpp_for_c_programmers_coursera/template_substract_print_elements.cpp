/*
 * DATE: 25 - 05 - 2025
 * About: Iterate substraction over the data, Write a template function that outputs the elemts in an array 
 */

#include <iostream>

using namespace std;

template <class T>

T sub(const T data[], uint size, T total = 0)
{
	total = data[0];
	for (uint idx = 1; idx < size ; idx++){
		total -= data[idx];
	}
	return total;
}

int main(void)
{
	int intarr[] 	= { 200, 12 , 13, 15};
       	double dblarr[] = { 125, 22.5, 101.5, 131};
	
	cout << "Result 1 is " << sub(intarr, 4)<<endl; 
	cout << "Result 1 is " << sub(dblarr, 4)<<endl; 
}
