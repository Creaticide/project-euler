#include <stdio.h>
#include <math.h>

/*
 * Objective: "What is the 10 001st prime number?"
 */

static long long nth_prime(int n);
static int is_prime(int n);

void problem_7()
{
	printf("Problem 7: %I64d\n", nth_prime(10001));
}

static long long nth_prime(int n)
{
	int count = 0;
	long long largest_prime = 0;

	int i = 1;
	while (count < n) {
		if (is_prime(i)) {
			largest_prime = i;
			count++;
		}
		i++;
	}

	return largest_prime;
}

static int is_prime(int n)
{
	if (n < 2) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	if (n % 2 == 0) {
		return 0;
	}

	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}
