#pragma once
#include "Irina_19621644_SIT3a_KR1.h"
#include "CStudent.h"

class CProtokol {
private:
	string disciplineName;
	int groupNumber;
	map<CStudent, unsigned> grades;

public:

	CProtokol();//default constr

	CProtokol(const CProtokol& p); // copy constr

	void setGroupNumber(int groupNumber);

	int getGroupNumber();

	void setGrades(map<CStudent, unsigned> grades);

	map<CStudent, unsigned> getGrades();

	void setDisciplineName(string disciplineName);

	string getDisciplineName();

	double averageSuccess();

	list<CStudent*> failedStudents();

	void operator=(CProtokol& p);

	friend istream& operator>>(istream& istr, CProtokol& p);

	friend bool operator<(const CProtokol& left, const CProtokol& right);

};