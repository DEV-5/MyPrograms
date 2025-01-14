//Date: 16th March 2020
//purpose: demonstrate a variable argument list

#include <stdio.h>
#include <stdarg.h>
  
// this function will take the number of values to average
// followed by all of the numbers to average
double average ( int num, ... )
{
  va_list valist;                     // A place to store the list of arguments
  double sum = 0;
 
  va_start (valist, num );           // Initializing arguments to store all values after num
  for ( int x = 0; x < num; x++ )        // Loop until all numbers are added
    sum += va_arg ( valist, double ); // Adds the next value in argument list to sum.
  va_end ( valist );                  // Cleans up the list
  return sum/ (double)num;                      // Returns the average
}

int main()
{
    // this computes the average of 13.2, 22.3 and 4.5 (3 indicates the number of values to average)
    printf("average = %lf\n",average( 3, 12.2, 22.3, 4.5));//result:39/3 = 13
    // here it computes the average of the 5 values 3.3, 2.2, 1.1, 5.5 and 3.3
    printf("average = %lf\n",average( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ));//result:15.4/5
}
