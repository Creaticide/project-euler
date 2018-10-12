#include <stdio.h>
#include <time.h>
#include "problems.h"

void execution_time(clock_t begin, clock_t end);

int main()
{
	clock_t begin, end;

	begin = clock();
	problem_6();
	end = clock();
	execution_time(begin, end);

	return 0;
}

void execution_time(clock_t begin, clock_t end)
{
	double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("Execution time: %f\n", time_spent);
}
