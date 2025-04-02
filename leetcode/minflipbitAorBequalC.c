#include <stdio.h>
unsigned int countBits(int a)
{
    unsigned int result;
    for(result=0; a>0; a>>=1)
    {
        if(a & 1) { result++; }
    }
    return result;
}
int minFlips(int a, int b, int c){
    //variable declaration
    int counta, countb, countc, countac,countab, countbc, countabc, result;



    if((a|b) == c) { return 0; }
    else
    {
        // tempvar -= c;
        // tempvar = tempvar?tempvar:(-tempvar)
        // tempvar & (~c)
        counta  = countBits(a);
        countb  = countBits(b);
        countc  = countBits(c);
        countab = countBits(a&b);
        countac = countBits(a&c);
        countbc = countBits(b&c);
        countabc = countBits(a&b&c);
        result = ((counta - countac) + (countb - countbc) + (countc -(countac + countbc) + countabc));

        printf("counta=%d, countb=%d, countc=%d,countab=%d countac=%d, countbc=%d and result=%d", counta, countb, countc,countab, countac, countbc, result);

       //  countc  = countBits(c);
       //  countac = countBits(a&c);
       //  countbc = countBits(b&c);
       //  countab = countBits(a&b);
       //  printf("counta=%d, countb=%d, countc=%d,countab=%d, countac=%d and countbc=%d, ", counta, countb, countc,countab, countac, countbc);
       //  return (countc - countac - countbc + countab);
       return result;
    }

}


int main(void)
{
    minFlips(2,6,5);
    minFlips(7,3,9);
}











