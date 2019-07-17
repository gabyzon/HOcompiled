#include <stdlib.h>
#include "c-sum.h"

int sum_abs(int *in, int num) {
	int i,sum;
	printf("empieza la suma");
	for (i=0,sum=0; i < num; ++i) {
		sum += abs(in[i]);
		printf("%d \n",sum);
	}
	return sum;
}
 
