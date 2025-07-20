#include <stdio.h>

int main(){
	int res;
    	__asm__("mov $338, %rax");
    	__asm__("int $0x80");
    	__asm__("mov %rax, -4(%rbp)");
    	printf("val returned by Syscall %d\n", res);
    	return 0;
}
