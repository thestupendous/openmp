#include<stdio.h>
#include<omp.h>

#define NUM_THREADS 5

int main()
{
	int size = NUM_THREADS ;

	int array[NUM_THREADS]={0};
	for(int i=0;i<size;i++)
	{
		printf("array[%d] = %d\n",i,array[i]);
	}
printf("---------------------------------------\n");
	omp_set_num_threads(size);

#pragma omp parallel
	{
		int id = omp_get_thread_num();
		printf("id %d,  a[i] = %d\n", id,array[id]);
		array[id] = id;
		printf("after a[i] %d\n",array[id]);
		

	}


	for(int i=0;i<size;i++)
	{
		printf("array[%d] = %d\n",i,array[i]);
	}

	return 0;
}


