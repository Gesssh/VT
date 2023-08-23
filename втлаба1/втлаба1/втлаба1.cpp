#include <stdio.h>
#include <stdlib.h>

void Output(int i, unsigned char* pb, unsigned char b)
{
	for (i -= 1; i >= 0; i--) 
	{
		for (int j = 7; j >= 0; j--) printf("%d", (pb[i] >> j) % 2);
		printf(" ");
	}
	printf("\n\n");
}

int main()
{
	system("chcp 1251");
	system("cls");

	unsigned char x1, * pb, b;
	unsigned short x2;
	unsigned int x3;
	char x4;
	short int x5;
	int x6;
	float x7;
	double x8;

	printf("Целое беззнаковое(1): "); scanf("%d", &x1);
	pb = (unsigned char*)&x1; b = pb[0] % 2;
	Output(sizeof(x1), pb, b);

	printf("Целое беззнаковое(2): "); scanf("%hu", &x2);
	pb = (unsigned char*)&x2; b = pb[0] % 2;
	Output(sizeof(x2), pb, b);

	printf("Целое беззнаковое(4): "); scanf("%u", &x3);
	pb = (unsigned char*)&x3; b = pb[0] % 2;
	Output(sizeof(x3), pb, b);

	printf("Целое знаковое(1): "); scanf("%d", &x4);
	pb = (unsigned char*)&x4; b = pb[0] % 2;
	Output(sizeof(x4), pb, b);

	printf("Целое знаковое(2): "); scanf("%hi", &x5);
	pb = (unsigned char*)&x5; b = pb[0] % 2;
	Output(sizeof(x5), pb, b);

	printf("Целое знаковое(4): "); scanf("%d", &x6);
	pb = (unsigned char*)&x6; b = pb[0] % 2;
	Output(sizeof(x6), pb, b);

	printf("Вещественное(4): "); scanf("%f", &x7);
	pb = (unsigned char*)&x7; b = pb[0] % 2;
	Output(sizeof(x7), pb, b);

	printf("Вещественное(8): "); scanf("%lf", &x8);
	pb = (unsigned char*)&x8; b = pb[0] % 2;
	Output(sizeof(x8), pb, b);

	return 0;
}