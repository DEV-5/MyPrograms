
/*
 * Date: 22th May 2020
 * Dynamic Programming
 * Input: matrix =
 * [
 * 
 *   [0,1,1,1],
 *   [1,1,1,1],
 *   [0,1,1,1]
 * 
 * ]
 * 
 * 0 1 1 1
 * 1 1 2 2
 * 0 1 2 3
 * 
 * 0 1 2 3
 * 1 3 6 9
 * 0 4 9 15
 *  
 * 15-> 9+9+(1+1+1)-6  = 15
 * 
 * [0,1,2,3],
 * [1,2,1,1],
 * [1,3,1,1]
 * 
 * Output: 15
 * 
 * Explanation: 
 * 
 * There are 10 squares of side 1.
 * There are 4 squares of side 2.
 * There is  1 square of side 3.
 * Total number of squares = 10 + 4 + 1 = 15.
 */

#include<stdio.h>

#define outmax 3
#define inmax 4

int main()
{
    int matrix [outmax][inmax] = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    int count =0;

    for(int i=0;i<outmax;i++)
    {
           for(int j=0;j<inmax;j++) //for 1x1 square
           {
                if(matrix[i][j] ==1)
                    count++;
           }
    } 
    printf("The count= %d\n",count);
}
