﻿#include "Monom.h"
#include "Functions.h"
#include "Polynom.h"

int main()
{
	
		cout << ">>>\tSAMPLE\t<<<<" << endl;
		string str1, str2; //= "3x^1+2";
		 //= "5x^1+1+3z^2";
		cout << "Print two polynomials, please: ";
		cin >> str1 >> str2;
		List<string> ListStrMonom1 = LexicalAnalisis(str1);
		List<string> ListStrMonom2 = LexicalAnalisis(str2);
		Polynom p1, p2, res;
		p1 = AddPolynom(ListStrMonom1);
		p2 = AddPolynom(ListStrMonom2);
		res = p1 * p2;
		cout <<"The result of multiply is: "<< res << endl;
		res = p1 + p2;
		cout << "The result of sum is: " << res << endl;
		res = p1 - p2;
		cout << "The result of subtraction is: " << res << endl;
		//res.PrintPolynom();
		cout << ">>>\tSAMPLE\t<<<<" << endl;

		


	return 0;
}
 