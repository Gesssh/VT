﻿/*
13) На промежутке от -128 до 127.
Подсчитать количество таких пар чисел X и Y,
что (X+Y*X) != 5000. Ответ вывести на экран. 
*/
#include <stdio.h>
short X = -128, Y = -128, X200 = 0, Y200 = 0, T = 0;
unsigned short Count = 0;

int main()
{
	__asm 
	{
		mov CX, X;//помещаем значтение Х в СХ
	M1:
		cmp CX, 127 //если СХ > 127
			jg M2;// делать М2
		mov BX, Y;//помещаем значтение Y в BХ
	M3:
		cmp BX, 127//если ВХ > 127
			jg M4; // делать 
		mov AX, CX;// помещаем в регистр АХ значение СХ
		imul BX;//умножаем ВХ на АХ(X*Y)
		add AX, CX;//складываем АХ и СХ (X+(Y*X))
		cmp AX, 5000// если АХ = 5000
			je M5;//делать М5
		inc Count;// увеличение счетчика на 1
		cmp Count, 200// если счетчик != 200
			jne M5;//делать М5
		cmp T, 1
			je M5;
		mov X200, CX;//помещаем значение 200го икса
		mov Y200, BX;//помещаем значение 200го игрека
		inc T;//условие для второй части задания

	M5:
		inc BX;// прибавить 1 к ВХ
		jmp M3;// перепрыгиваем на M3
	M4:
		inc CX;// прибавить 1 к СХ
		jmp M1;// перепрыгиваем на M1
	M2:

	};

	printf("Count: %d", Count);

	if (T==1)
		printf("\n200: X = %d, Y = %d", X200, Y200);
	else
		printf("\nCount<200");

	return 0;
}