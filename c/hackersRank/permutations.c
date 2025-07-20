#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// uint factorial(uint n)
// {
//     if(n == 1)
//         return n;
//     else
//         return (n * factorial(n-1)); 
// }

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/

//     int i = n - 2;
//     while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) {
//         i--;
//     }
//     if (i < 0) {
//         return 0;
//     }
//     int j = n - 1;
//     while (strcmp(s[j], s[i]) <= 0) {
//         j--;
//     }
//     swap(&s[i], &s[j]);
//     for (int k = i + 1, l = n - 1; k < l; k++, l--) {
//         swap(&s[k], &s[l]);
//     }
//     return 1;

        int i = n - 1;
        while (i > 0 && strcmp(s[i - 1], s[i]) >= 0) {
        i--;
        }
        if (i <= 0) {
                return 0; // No more permutations
        }

        int j = n - 1;
        while (strcmp(s[j], s[i - 1]) <= 0) {
                j--;
        }
        swap(&s[i - 1], &s[j]);

        j = n - 1;
        while (i < j) {
                swap(&s[i], &s[j]);
                i++;
                j--;
        }
        return 1; // Next permutation found
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
