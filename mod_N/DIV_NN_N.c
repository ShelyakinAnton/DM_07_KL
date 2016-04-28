﻿//Частное от деления большего натурального числа на меньшее
//или равное натуральное с остатком (делитель отличен от нуля)

---
Правиленко Михаил гр. 5307
Pre-Alpha
---

Используемые модули:
DIV_NN_Dk
SUB_NDN_N

struct NATURAL DIV_NN_N(struct NATURAL a, struct NATURAL b)
{
	struct NATURAL temp;  //Временное делимое
	struct NATURAL minus; //Остаток от деления на i-ом шаге
	struct NATURAL c;     //Частное
	int k;		      //Номер разряда частного
	int countdown;        //Размер врем. делимого на i-ом шаге
	int *resize;	      //Временное хранение c

	c.index = a.index-b.index+1;
	c.number = new int [c.index];

	k = c.index-1;
	
	temp.index = a.index;
	temp.number = new int [temp.index];

	minus.index = b.index;
	minus.number = new int [minus.index];

	for (int i=0; i<temp.index; i++)
		temp.number[i]=a.number[i];

	countdown = a.index;

	do
	{
		c = DIV_NN_Dk(&temp, b, &k); //temp - делимое, b - делитель, k - номер позиции (temp и k изменяются в ходе выполнения модуля
		minus = SUB_NDN_N(temp, b, c.number[k]); // temp - уменьшаемое, b - вычитаемое, c.number[k] - множитель

		delete [] temp.number;
		temp.number = nullptr;

		temp.index = countdown-temp.index+minus.index;
		temp.number = new int [temp.index];
		countdown = temp.index;

		for (int i=0; i<temp.index-minus.index; i++)
			temp.number[i]=a.number[i];
		for (int i=minus.index; i<temp.index; i++)
			temp.number[i]=minus.number[i];

		k--;
	}
	while (k>0);

	resize = new int [c.index];     //Отсечение пустых элементов массива
	for (int i=0; i<c.index; i++)
		resize[i]=c.number[i];
	delete [] c.number;
	c.number = nullptr;
	c.number = new int [c.index];
	for (int i=0; i<c.index; i++)
		c.number[i]=resize[i];

	return c;
}