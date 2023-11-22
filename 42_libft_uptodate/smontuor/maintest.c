#include <stdio.h>

void test(int *vet)
{
	vet[0] = 10;
}

int main()
{
	int vet[10] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};

	test(vet);
	printf("%d\n", vet[0]);	
	return (0);
}