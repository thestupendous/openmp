#include<stdio.h>
#include<omp.h>
#include<math.h>

static long num_steps = 10000;
double step;
int main()
{
	int i; double x, pi, sum=0.0 ;
	
	step = 1.0/(double) num_steps;
	for (i=0; i<num_steps; i++)
	{
		x= (i+0.5)*step;
		sum += 4.0 / (1.0 + x*x) ;
	}

	pi = step*sum;
	printf("value of PI as found is %f\nvalue of constant PI is %f",pi,M_PI);

	return 0;
}
