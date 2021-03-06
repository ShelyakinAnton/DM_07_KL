﻿﻿//Сложение многочленов
//Используется модуль ADD_QQ_Q

struct POLYNOMIAL ADD_PP_P(struct POLYNOMIAL first, struct POLYNOMIAL second)
{
	struct POLYNOMIAL rezult;
	rezult.factors = NULL; 			//обнуляем коэффициенты
	nex = 0;						//вспомогательная для цикла
	if (first.degree >= second.degree)	
	{
		rezult.degree = first.degree;
		rezult.factors = (RATIONAL*) realloc(rezult.factors, rezult.degree);
		for (int i = 0; i < second.degree; i++)
		{
			rezult.factors[i] = ADD_QQ_Q(first.factors[i], second.factors[i]); 
			nex = i;
		}
		for (int i = nex; i < first.degree; i++)
		{
			rezult.factors[i] = first.factors[i];
		}
	}
	else
	{
		rezult.degree = second.degree;
		rezult.factors = (RATIONAL*)realloc(rezult.factors, rezult.degree);
		for (int i = 0; i < first.degree; i++)
		{
			rezult.factors[i] = ADD_QQ_Q(first.factors[i], second.factors[i]);
			nex = i;
		}
		for (int i = nex; i < second.degree; i++)
		{
			rezult.factors[i] = second.factors[i];
		}
	}
	return rezult;