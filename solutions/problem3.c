#include <stdio.h>
#include <math.h>

/*
 * Objective: "What is the largest prime factor of the number 600851475143 ?"
 */

int max_prime_factor(long long n);

void problem_3()
{
	printf("Problem 3: %d\n", max_prime_factor(600851475143));
}

int max_prime_factor(long long n)
{
	int max = 0;

	while (n % 2 == 0) {
		max = 2;
		n /= 2;
	}

	for (int i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			max = i;
			n /= i;
		}
	}

	if (n > 2) {
		max = n;
	}

	return max;
}
