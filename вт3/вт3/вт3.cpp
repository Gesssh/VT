//13) A(word), B(byte), C(word).
//Вычислить: D = (B - C)* (B + C); E = (B * A) / C.
#include <iostream>
int main();
int main()
{
	__int16 A = 3000;
	__int8 B = 100;
	__int16 C = 50;
	__int32 D = 0;  // Результат выражения D = (B - C)* (B + C)
	__int16 E = 0;  // Результат выражения E = (B * A) / C.
	printf("input: A = %d, B = %d, C = %d, hex: A = %x, B = %x, C = %x\n", A, B, C, A, B, C);
	__asm {
		MOV AL, B;  // Заносим переменную B в регистр AL
		cbw;//расширяет байт в AL до слова в AX
		ADD AX, C;// сложение АХ и С, результат в АХ
		MOV BX, AX;
		SUB BX, C;//вычитание из BХ С
		SUB BX, C;
		imul BX; //Умножаем переменную D на регистр AX;
		MOV word ptr D, AX;	// Заносим в переменную D значение регистра AХ
		MOV word ptr D + 2, DX;

		mov AL, B;
		cbw;// Расширяем содержимое регистра AL до слова в AX 
		imul A;//Умножаем переменную A на регистр AX;
		idiv C;//Делим переменную С на регистр DX,AX результат в AX;
		mov E, AX;

	}
	printf("\noutput: D = %d, E = %d, hex: D = %x, E = %x\n", D, E, D, E);
	return 0;
}