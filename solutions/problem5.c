#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Objective: "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?"
 */

/*
 * Prime numbers 1...20: 2, 3, 5, 7, 11, 13, 17, 19.
 * Composite numbers 1...20: 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20.
 * Break the composite numbers down to their prime factors & multiply every prime factor's highest power:
 * 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19 = 232 792 560.
 * Now let's C.
 */

int is_prime(int n);
long long calculate_lcm_1_to_n(int n);
void composite_prime_factors(int **primes, int n);

void problem_5()
{
	/*
	 * Calculates least common multiple between numbers from 1 to N.
	 * (Excuse the mess...)
	 */
	printf("%I64d\n", calculate_lcm_1_to_n(20));
}

long long calculate_lcm_1_to_n(int n)
{
	long long lcm = 1;
	int **primes = malloc((n + 1) * sizeof(int));

	for (int i = 1; i < (n + 1); i++) {
		primes[i] = malloc(2 * sizeof(int));
		primes[i][0] = 0;
		primes[i][1] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (is_prime(i)) {
			primes[i][0] = i;
		} else {
			composite_prime_factors(primes, i);
		}
	}

	for (int i = 1; i < n; i++) {
		if (primes[i][0] > 0) {
			if (primes[i][1] > 1) {
				lcm *= (long long) pow((double) i, (double) primes[i][1]);
			} else {
				lcm *= i;
			}
			free(primes[i]);
		}
	}
	free(primes);

	return lcm;
}

void composite_prime_factors(int **primes, int n)
{
	int count = 0;

	while (n % 2 == 0) {
		n /= 2;
		count++;
	}
	if (count > primes[2][1]) {
		primes[2][1] = count;
	}

	for (int i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			n /= i;
			count++;
		}
		if (count > primes[i][1]) {
			primes[i][1] = count;
		}
		count = 0;
	}
}

int is_prime(int n)
{
	if (n < 2) {
		return 0;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}
