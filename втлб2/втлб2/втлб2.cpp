/*Вариант 13
Даны три переменные A B и C (int) (int) (long int). Переставить байты в переменных по следующейсхеме:
Начальная нумерация байт После перестановки
A = 11 22        A = 33 44
B = 33 44        B = 66 77
C = 55 66 77 88  C = 88 22 11 55

*/

//#include "stdafx.h"
#include "locale.h"
#include "stdio.h"
#include "stdlib.h"

int main();

int main()
{
	int A;
	A = 0x1122;
	int B;
	B = 0x3344;
	long int C;
	C = 0x55667788;

	printf("%x, %x, %x\n", A, B, C);

	__asm {
		mov AX, word ptr B;
		xchg AX, word ptr A;
		xchg AL,AH;
		xchg AX, word ptr C + 1;
		mov word ptr B, AX;
		mov Al, byte ptr C[3]; 
		xchg AL, byte ptr C[0];
		mov byte ptr C[3], Al;
	}

	printf("\n%x, %x, %x", A, B, C);

	getchar();
}