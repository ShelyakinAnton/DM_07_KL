﻿﻿//Умножение многочлена на x^k
//сдвиг вправо на к
//сырой алгоритм
//Васильева Людмила 5307

POLYNOMIAL MUL_Pxk_p(POLYNOMIAL num, int k)
{
	POLYNOMIAL NewNum;

	
        NewNum.degree = num.degree + k

	for (int i = 0; i < k  ; i++) //первые к элем - нули
        { 
		NewNum.factors[i].numerator = 0;
                NewNum.factors[i].denominator = 1;
                NewNum.factors[i].sign = 0;
        }
	for (int i = k; i < NewNum.degree; i++) //переписываем 
        {
		NewNum.factors[i].numerator = num.factors[i-k].numerator;
                NewNum.factors[i].denominator = num.factors[i-k].denominator;
                NewNum.factors[i].sign = num.factors[i-k].sign;
        }
	return NewNum;
}