#include <stdio.h>
#include <string.h>

/*
 * Objective: "Find the largest palindrome made from the product of two 3-digit numbers."
 */

static int is_palindrome(int n);

void problem_4()
{
	int a, b, c, max = 0;

	for (a = 100; a < 1000; a++) {
		for (b = 100; b < 1000; b++) {
			c = a * b;
			if (is_palindrome(c) == 1 && c > max) {
				max = c;
			}
		}
	}

	printf("Problem 4: %d\n", max);
}

static int is_palindrome(int n)
{
	char str[6];
	int len;

	sprintf(str, "%d", n);
	len = strlen(str);

	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			return 0;
		}
	}

	return 1;
}
