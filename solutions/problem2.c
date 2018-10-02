#include <stdio.h>

/*
 * Objective: "By considering the terms in the Fibonacci sequence whose values do not exceed four million,
 * find the sum of the even-valued terms."
 */

void problem_2()
{
	int sum = 0, previous = 0, current = 1, next = 1;

	while (current <= 4000000) {
		if (current % 2 == 0) {
			sum += current;
		}

		next = previous + current;
		previous = current;
		current = next;
	}

	printf("Problem 2: %d\n", sum);
}
