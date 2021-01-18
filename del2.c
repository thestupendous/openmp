#include<stdio.h>
#include<omp.h>
#include<math.h>

static long num_steps = 10000;
#define NUM_THREADS 4
int main()
{
	int i,nthreads; double x, step, pi, sum[NUM_THREADS] ;
	
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);
	printf("printing before\n");
	for(int k=0;k<NUM_THREADS;k++) printf("%d , sum[i]=%f\n",k,sum[k]);
	printf("--------------------------------\n");

	#pragma omp parallel
	{
		
		//int i,id,nthrds;
		//double x;
		int id = omp_get_thread_num();
		sum[id]=id;
//		nthrds = omp_get_num_threads();
//		if(id==0) nthreads = nthrds;

//		for(i=id,sum[id]=0.0;i<num_steps;i+=nthrds)
//		{
//			x = (i+0.5) * step;
			//printf("modifying index %d of array \n",id);
//			sum[id] += 4.0 / (1.0 + x*x) ;
//		}
//
	}

//	for (i=0,pi=0.0;i<nthreads;i++) pi += sum[i]*step;

	printf("printing after\n");
	for(int k=0;k<NUM_THREADS;k++) printf("%d , sum[i]=%f\n",k,sum[k]);
	printf("--------------------------------\n");

	printf("value of PI as found is %f\nvalue of constant PI is %f",pi,M_PI);

	return 0;
}
