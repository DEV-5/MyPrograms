#include<stdio.h>

#define SET_VALUE_AT_BIT(var, pos, val) (val ? (var |= (1 << pos)): (var &= ~(1 << pos)))

int main()
{
	int avar = 0x20;
	printf("value of SET_VALUE_AT_BIT(0x20,3,1)= %x\n", SET_VALUE_AT_BIT(avar,3,1));
	printf("value of SET_VALUE_AT_BIT(0x20,3,0)= %x\n", SET_VALUE_AT_BIT(avar,5,0));
}
