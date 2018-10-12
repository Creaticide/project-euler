#include <stdio.h>

/*
 * Objective: "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum."
 */

static long long difference(int n);

void problem_6()
{
	printf("Problem 6: %I64d\n", difference(100));
}

static long long difference(int n)
{
	int sum = 0;
	long long sum_of_squares = 0;

	for (int i = 1; i <= n; i++) {
		sum_of_squares += (i * i);
		sum += i;
	}

	return (sum * sum) - sum_of_squares;
}
