#include <stdio.h>

/*
 * Objective: "There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc."
 */

static long long product_of_abc(int abc_sum);

void problem_9()
{
	printf("Problem 9: %I64d\n", product_of_abc(1000));
}

static long long product_of_abc(int abc_sum)
{
	int c = 0;

	for (int a = 1; a < abc_sum; a++) {
		for (int b = a + 1; b < (abc_sum - (a + b)); b++) {
			c = abc_sum - (a + b);
			if ((c * c) == (a * a) + (b * b)) {
				return (long long) a * b * c;
			}
		}
	}

	return 0;
}
