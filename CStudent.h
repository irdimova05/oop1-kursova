#pragma once
#include "Irina_19621644_SIT3a_KR1.h"

class CStudent {
private:
	string name;
	int fnum;

public:

	CStudent(); // default constr

	CStudent(string name1, int fnum1); // explicit constr

	CStudent(const CStudent& s); // copy constr

	string getName();

	int getFNum();

	void setName(string name);

	void setFNum(int fnum);

	friend istream& operator>>(istream& istr, CStudent& s);

	friend ostream& operator<<(ostream& ostr, const CStudent& s);

	friend bool operator<(const CStudent& s1, const CStudent& s2);

};

