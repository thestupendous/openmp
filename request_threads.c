#include<stdio.h>
#include<omp.h>


int main()
{
	double a[500];
	omp_set_num_threads(4);
#pragma omp parallel
	{
		int id = omp_get_thread_num();
		fun(id,a);
	}

	printf("done");

	return 0;
}
