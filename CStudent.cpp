#pragma once
#include "CStudent.h"

CStudent::CStudent() {}// default constr

CStudent::CStudent(string name1, int fnum1) {
	name = name1;
	fnum = fnum1;
}// explicit constr

CStudent::CStudent(const CStudent& s) {
	name = s.name;
	fnum = s.fnum;
}// copy constr

string CStudent::getName() {
	return name;
}

int CStudent::getFNum() {
	return fnum;
}

void CStudent::setName(string name) {
	this->name = name;
}

void CStudent::setFNum(int fnum) {
	this->fnum = fnum;
}

istream& operator>>(istream& istr, CStudent& s) {
	istr >> s.name;
	istr >> s.fnum;
	return istr;
}

ostream& operator<<(ostream& ostr, const CStudent& s) {
	ostr << s.name << " " << s.fnum << endl;;
	return ostr;
}

bool operator<(const CStudent& s1, const CStudent& s2) {
	return s1.fnum < s2.fnum;
}


