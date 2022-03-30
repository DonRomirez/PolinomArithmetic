#pragma once
#include <iostream>
#include <string>
#include "Lists.h"

using namespace std;
#define MAX_STEP 10
#define N 3
struct MonomValue
{
	double  a;
	unsigned int s;
	MonomValue(double _a , unsigned int _s ) :a(_a), s(_s) {}
	MonomValue(double _a = 0, int x = 0, int y = 0, int z = 0) :a(_a)
	{
		s = x+y* pow(MAX_STEP, 1) + z* pow(MAX_STEP, 2);
	}
	MonomValue(const MonomValue& m) {
		a = m.a;
		s = m.s;
	}
	MonomValue& operator=(const MonomValue& m) {
		if ((m.a == a) && (m.s == s))
			return *this;
		a = m.a;
		s = m.s;
		return *this;
	}

	int getStep(int i)
	{
		int p = pow(MAX_STEP, i);
		int t = s / p;

		return t % MAX_STEP;
	}
	unsigned int GetS() { return s; }
	double GetA() { return a; }


	friend ostream& operator <<(ostream& out, MonomValue& m)
	{
		out << "Coeff: " << m.a << "\n";
		out << "Step: \n";

		for (int i = 0; i < N; i++)
		{
			out << m.getStep(i) << endl;
		}
		//cout << m.s << endl;

		return out;
	}
	friend bool operator==(const MonomValue& left, const MonomValue& right) {
		return left.s == right.s;
	}
	friend bool operator<(const MonomValue& left, const MonomValue& right) {
		return left.s < right.s;
	}
	friend bool operator>(const MonomValue& left, const MonomValue& right) {
		return left.s > right.s;
	}
	friend bool operator<=(const MonomValue& left, const MonomValue& right) {
		return left.s < right.s;
	}
	friend bool operator>=(const MonomValue& left, const MonomValue& right) {
		return left.s > right.s;
	}
	friend bool operator!=(const MonomValue& left, const MonomValue& right) {
		return left.s != right.s;
	}
	MonomValue& operator*(MonomValue& p) {
		MonomValue res;
		res.a = this->a * p.a;
		res.s = this->s + p.s;
		return res;
	}


};
