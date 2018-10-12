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

typedef struct number {
	int n, is_prime, power;
} Number;

static int is_prime(int n);
static long long calculate_lcm_1_to_n(int n);
static void composite_prime_factors(Number *numbers, int n);
static long long power(int n, int exp);

void problem_5()
{
	printf("Problem 5: %I64d\n", calculate_lcm_1_to_n(20));
}

/*
 * Calculates least common multiple between numbers from 1 to N.
 * (Excuse the mess...)
 */
static long long calculate_lcm_1_to_n(int n)
{
	long long lcm = 1;
	Number *numbers;
	numbers = malloc((n) * sizeof(Number));

	for (int i = 0; i < n; i++) {
		numbers[i].n = i + 1;
		numbers[i].is_prime = is_prime(i + 1);
		numbers[i].power = 1;
	}

	for (int i = 0; i < n; i++) {
		if (! numbers[i].is_prime) {
			composite_prime_factors(numbers, numbers[i].n);
		}
	}

	for (int i = 0; i < n; i++) {
		if (numbers[i].is_prime) {
			lcm *= power(numbers[i].n, numbers[i].power);
		}
	}
	free(numbers);

	return lcm;
}

static void composite_prime_factors(Number *numbers, int n)
{
	int count = 0;

	while (n % 2 == 0) {
		n /= 2;
		count++;
	}
	if (count > numbers[1].power) {
		numbers[1].power = count;
	}

	for (int i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			n /= i;
			count++;
		}
		if (count > numbers[i - 1].power) {
			numbers[i - 1].power = count;
		}
		count = 0;
	}
}

static int is_prime(int n)
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

/*
 * Made my own implementation of pow() because of some data type weirdness.
 */
static long long power(int n, int exp)
{
	long long result = n;

	while (exp > 1) {
		result *= n;
		exp--;
	}

	return result;
}
