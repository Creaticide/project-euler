#include <stdio.h>

/*
 * Objective: "Find the sum of all the multiples of 3 or 5 below 1000"
 */

void problem_1()
{
	int sum = 0;

	for (int i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	printf("Problem 1: %d\n", sum);
}
