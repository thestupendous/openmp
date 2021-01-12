#include<omp.h>
#include<stdio.h>

int main(){
	int x=4;
	int *p = &x;	
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		printf("hello bro and x is %d\n",*p);
		++(*p);
		printf("this is thread number %d\n",id);
	}

	printf("finally, value of x is %d\n",x);

	return 0;
}
