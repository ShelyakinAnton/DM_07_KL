﻿﻿//Производная многочлена
//Власов Д.Ю 5307
POLYNOMINAL DER_P_P(POLYNOMINAL Polynominal)
{	
	POLYNOMINAL NewPol;
	NewPol.factors = (RATIONAL*)malloc((Polynominal.degree - 1)*sizeof(RATIONAL));
	NewPol.degree = Polynominal.degree - 1;
	for (int i = 1; i <= Polynominal.degree;  i++)
	{
		NewPol.factors[i - 1].numerator = MUL_ND_N(Polynominal.factors[i].numerator,i);
		NewPol.factors[i - 1].denominator = Polynominal.factors[i].denominator;
		NewPol.factors[i - 1].sign = Polynominal.factors[i].sign;
	}
	return NewPol;
}