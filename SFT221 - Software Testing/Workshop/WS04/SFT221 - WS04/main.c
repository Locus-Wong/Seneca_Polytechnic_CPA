//SFT221 - WS04
//Student Name : Tsz Wa Wong
//Student ID : 152181228
//Student email : twwong9@myseneca.ca
//Session : NBB
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 13
struct FactorialResults
{
	int results[MAX_FACTORIALS];
	int numResults;
};
int factorial(const int n)
{
	return (n >= 1) ? n * factorial(n - 1) : 1;
}
int reduceFactorial(const int n)
{
	int i = 0;
	while(n > factorial(i))
	{
		i++;
	}
	return (i > 0) ? n / i : n;
}
void computeFactorials(struct FactorialResults* results, int numFactorials)
{
	int i;
	for (i = 0; i < numFactorials; i++)
	{
		results->results[i] = factorial(i);
	}
	results->numResults = numFactorials;
}
int main(void)
{
	struct FactorialResults results = { {0}, 0 };
	int i;
	computeFactorials(&results, NUM_FACTS);
	for (i = 0; i < NUM_FACTS; i++)
	{
		results.results[i] = reduceFactorial(results.results[i]);
		printf("%5d %12d\n", i, results.results[i]);
	}
	return 0;
}