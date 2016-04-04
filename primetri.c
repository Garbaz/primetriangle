#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEFORM_LEN 64
#define SIZE_LIMIT_M (2/30)
#define SIZE_LIMIT_B 3.0

void sieveOfEratosthenes(unsigned char marked[], unsigned long max);
void print_prime_line(long p[], unsigned long pc);

char lineForm[LINEFORM_LEN];

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("\nUsage: \"%s MAXIMUM [ONLY_TOP_PRIMES]\"\n\nIf second argument is \"VECTOR\" a point form (x,y) will be printed\n", argv[0]);
		return 1;
	}
	unsigned long max = atoi(argv[1]), pc = 0;
	
	unsigned int printLen = (unsigned int)(SIZE_LIMIT_M * ((double)max) + SIZE_LIMIT_B) + 3;
	
	sprintf(lineForm, "%%%uli", printLen);
	
	long primes[max];
	unsigned char marked[max],point_print;
	if(argc > 2) point_print = (strcmp(argv[2], "VECTOR") == 0);
	sieveOfEratosthenes(marked, max);
	
	for(unsigned long i = 0; i < max; i++)
	{
		if(marked[i]){primes[pc] = i; pc++;}
	}
	
	for(unsigned long i = 0; i < pc; i++)
	{
		if(argc == 2)
		{
			print_prime_line(primes, pc-i);
			for(unsigned long j = 0; j < i * printLen/2; j++)
			{
				putchar(' ');
			}
			if(i * printLen/2 == 0) putchar(' ');
		}
		else
		{
			if(point_print)
			{
				printf("[%li, %li],", i, primes[0]);
			}
			else
			{
				printf("%li, ", primes[0]);
			}
		}
		
		for(unsigned long j = 0; j < pc-i; j++)
		{
			if(j != pc-i-1) primes[j] = primes[j+1] - primes[j];
		}
	}
	putchar('\n');
	return 0;
}

void sieveOfEratosthenes(unsigned char marked[], unsigned long max)
{
	marked[0] = marked[1] = 0;
	for(unsigned long i = 2; i < max; i++)
	{
		marked[i] = 1;
	}
	
	for(unsigned long i = 2; i < max/2; i++)
	{
		if(marked[i] == 1)
		{
			for(unsigned long j = i*i; j < max; j+=i)
			{
				marked[j] = 0;
			}
		}
	}
}

void print_prime_line(long p[], unsigned long pc)
{
	//TODO: Print more beautiful
	
	for(unsigned long i = 0; i < pc; i++)
	{
		printf(lineForm, p[i]);
	}
	printf("\n");
}
