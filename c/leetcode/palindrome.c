/* 
 * Den: fails for inx =1234567899
 * 
 *
 */

bool isPalindrome(int x) {
    int n = 0;
    if(x == 0)
        return 1;
    else if (x >= 0){
        for ( int i = x; i > 0; i/=10){
            n *= 10; 
            n += i%10;
            printf("n = %d and i= %d\n", n , i);

        }
        printf("n = %d and x= %d\n", n , x);
        if (n == x)
            return true;
    }
    return false;
}
