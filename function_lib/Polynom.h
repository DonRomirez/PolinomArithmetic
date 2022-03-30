#pragma once
#include "Monom.h"
#include "Lists.h"
class Polynom {
	List<MonomValue> polynom;
public:
	Polynom() {
		List<MonomValue> p;
		polynom = p;
	}
	void PrintPolynom() {
		polynom.PrintL();
	}
	int GetSize() {
		return polynom.getSize();
	}
	void AddMonom(MonomValue val) {
		if (val.a == 0)
			return;
		Link<MonomValue>* t = polynom.GetFirst();
		if (t->next == polynom.GetFirst()) {
			polynom.add(val, 0);
			return;
		}
		int index = 0;
		while ((t->next != polynom.GetFirst()) && (val > t->next->val)) {
			t = t->next;
			index++;
		}
		if (t->next->val == val) {
			t->next->val.a += val.a;
		}
		else
		polynom.add(val, index);
	}
	Polynom& operator+(Polynom& p) {
		Polynom res;
		Iterator<MonomValue> itr1(this->polynom.GetFirst()), itr2(p.polynom.GetFirst());
		MonomValue m1 = itr1.next(), m2 = itr2.next(), empt;
		while (true) {
			if ((m1.a == 0) && (m2.a != 0)) {
			res.AddMonom(m2);
			if (itr2.hasNext())
				m2 = itr2.next();
			else m2 = empt;
		}
			if ((m2.a == 0) && (m1.a != 0)) {
				res.AddMonom(m1);
				if (itr1.hasNext())
					m1 = itr1.next();
				else m1 = empt;
			}
			if (m1 < m2) {
				res.AddMonom(m1);
				if (itr1.hasNext())
					m1 = itr1.next();
				else m1 = empt;
			}
			if (m2 < m1) {
				res.AddMonom(m2);
				if (itr2.hasNext())
					m2 = itr2.next();
				else m2 = empt;
			}
			if (m1 == m2) {
				if ((m1.a == 0.0) && (m2.a == 0.0))
					break;
				MonomValue m3 = m1;
				m3.a = m1.a + m2.a;
				if (itr1.hasNext())
					m1 = itr1.next();
				else m1 = empt;
				if (itr2.hasNext())
					m2 = itr2.next();
				else m2 = empt;
				res.AddMonom(m3);
			}
		}
		return res;
	}
	Polynom& operator-(Polynom& p) {
		Polynom res;
		Iterator<MonomValue> itr1(this->polynom.GetFirst()), itr2(p.polynom.GetFirst());
		MonomValue m1 = itr1.next(), m2 = itr2.next(), empt, m3;
		while (true) {
			if ((m1.a == 0) && (m2.a != 0)) {
				m3 = m2;
				m3.a = -m3.a;
				res.AddMonom(m3);
				if (itr2.hasNext())
					m2 = itr2.next();
				else m2 = empt;
			}
			if ((m2.a == 0) && (m1.a != 0)) {
				m3 = m1;
				res.AddMonom(m3);
				if (itr1.hasNext())
					m1 = itr1.next();
				else m1 = empt;
			}
			if (m1 < m2) {
				m3 = m1;
				res.AddMonom(m3);
				if (itr1.hasNext())
					m1 = itr1.next();
				else m1 = empt;
			}
			if (m2 < m1) {
				m3 = m2;
				m3.a = -m3.a;
				res.AddMonom(m3);
				if (itr2.hasNext())
					m2 = itr2.next();
				else m2 = empt;
			}
			if (m1 == m2) {
				if ((m1.a == 0.0) && (m2.a == 0.0))
					break;
				 m3 = m1;
				m3.a = m1.a - m2.a;
				if (itr1.hasNext())
					m1 = itr1.next();
				else m1 = empt;
				if (itr2.hasNext())
					m2 = itr2.next();
				else m2 = empt;
				res.AddMonom(m3);
			}
		}
		return res;
	}
	Polynom& operator*(Polynom& p) {
		Polynom res;
		Iterator<MonomValue> itr1(this->polynom.GetFirst());
		MonomValue m1, m2, m3;
		while (itr1.hasNext()) {
			Iterator<MonomValue> itr2(p.polynom.GetFirst());
			m1 = itr1.next();
			while (itr2.hasNext()) {
				m2 = itr2.next();
				m3 = m1 * m2;
				res.AddMonom(m3);
			}
		}
		return res;
	}
	Link<MonomValue>* GetFirst() {
		return polynom.GetFirst();
	}
	friend ostream& operator <<(ostream& out, Polynom& p) {
		Iterator<MonomValue> itr1(p.polynom.GetFirst());
		if (itr1.hasNext()) {
			MonomValue m = itr1.next();
			out << m.a;
			if (m.getStep(0) != 0)
				out << "*x^" << m.getStep(0);
			if (m.getStep(1) != 0)
				out << "*y^" << m.getStep(1);
			if (m.getStep(2) != 0)
				out << "*z^" << m.getStep(2);
		}
		while (itr1.hasNext()) {
			MonomValue m = itr1.next();
			if (m.a > 0)
				out << "+";
			out << m.a;
			if (m.getStep(0) != 0)
				out << "*x^" << m.getStep(0);
				if (m.getStep(1) != 0)
					out << "*y^" << m.getStep(1) ;
					if (m.getStep(2) != 0)
						out << "*z^" << m.getStep(2);

		}
		return out;

	}
	friend bool operator==(Polynom left, Polynom right) {
		if(left.GetSize()!=right.GetSize())
			return false;
		Iterator<MonomValue> itr1(left.polynom.GetFirst()), itr2(right.polynom.GetFirst());
		bool b;
		while (itr1.hasNext()) {
			MonomValue m1 = itr1.next(), m2 = itr2.next();
			if ((m1 == m2) && (m1.a == m2.a))
				continue;
			else return false;
		}
		return true;
	}
	};
