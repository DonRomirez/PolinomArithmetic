#include "Functions.h"
List<string> LexicalAnalisis(string str) {
	List<string> ListStrMonom;
	string t = "";
	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') continue;
		if ((str[i] == '+') || (str[i] == '-'))
		{
			if (t.size() > 0)
			{
				ListStrMonom.addlast(t);
				t = str[i];
			}
		}
		else
		{
			t += str[i];
		}
	}
	if (t.size() > 0)
	{
		ListStrMonom.addlast(t);
	}
	return ListStrMonom;
}
List<MonomValue> PolinomList(List<string> ListStrMonom) {
	string t = "";
	Iterator<string> itr(ListStrMonom.GetFirst());
	List<MonomValue> listPolinom;
	while (itr.hasNext()) {
		t = itr.next();
		unsigned int pow[N] = { 0 };
		double a = 1.0;
		string t2 = "";
		int ipow = -1;
		for (int i = 0; i < t.size(); i++) {
			if ((t[i] == 'x') || (t[i] == 'y') || (t[i] == 'z'))
			{
				if (ipow == -1)
				{
					if (t2.size() > 0)
					{
						a = atof(t2.c_str());
						t2 = "";
					}
					if (t[i] == 'x') ipow = 0;
					if (t[i] == 'y') ipow = 1;
					if (t[i] == 'z') ipow = 2;
					i++;
				}
				else
				{
					pow[ipow] = atoi(t2.c_str());
					t2 = "";
					if (t[i] == 'x') ipow = 0;
					if (t[i] == 'y') ipow = 1;
					if (t[i] == 'z') ipow = 2;
					i++;
				}
			}
			else
			{
				t2 += t[i];
			}
		}
		if ((ipow >= 0) && (t2.size() > 0)) {
			pow[ipow] = atoi(t2.c_str());
		}
		if ((ipow < 0) && (t2.size() > 0))
			a = atoi(t2.c_str());
		listPolinom.addlast(MonomValue(a, pow[0], pow[1], pow[2]));
	}
	return listPolinom;
}
Polynom AddPolynom(List<string> ListStrMonom){
	Polynom p;
	string t = "";
	Iterator<string> itr(ListStrMonom.GetFirst());
	while (itr.hasNext()) {
		t = itr.next();
		unsigned int pow[N] = { 0 };
		double a = 1.0;
		string t2 = "";
		int ipow = -1;
		for (int i = 0; i < t.size(); i++) {
			if ((t[i] == 'x') || (t[i] == 'y') || (t[i] == 'z'))
			{
				if (ipow == -1)
				{
					if (t2.size() > 0)
					{
						a = atof(t2.c_str());
						t2 = "";
					}
					if (t[i] == 'x') ipow = 0;
					if (t[i] == 'y') ipow = 1;
					if (t[i] == 'z') ipow = 2;
					i++;
				}
				else
				{
					pow[ipow] = atoi(t2.c_str());
					t2 = "";
					if (t[i] == 'x') ipow = 0;
					if (t[i] == 'y') ipow = 1;
					if (t[i] == 'z') ipow = 2;
					i++;
				}
			}
			else
			{
				t2 += t[i];
			}
		}
		if ((ipow >= 0) && (t2.size() > 0)) {
			pow[ipow] = atoi(t2.c_str());
		}
		if ((ipow < 0) && (t2.size() > 0))
			a = atoi(t2.c_str());
		p.AddMonom(MonomValue(a, pow[0], pow[1], pow[2]));
	}
	return p;
}