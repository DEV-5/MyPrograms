#include <stdio.h>
#include "dep.h"

void x(void){
	printf("\n %s \n", __func__);
	a();
}

void y(void){
	printf("\n %s \n", __func__);
	b();
}
