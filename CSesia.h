#pragma once
#include "Irina_19621644_SIT3a_KR1.h"	
#include "CStudent.h"
#include "CProtokol.h"

class CSesia {
private:
	int semesterNumber;
	multiset<CProtokol> prot;

public:

	CSesia(int semesterNumber1);

	CSesia(int semesterNumber1, string fileName);

	int gradesCount(string disciplineName, int grade);

	double averageGrade(string disciplineName);

	string highestGradeDiscipline();

	int highestGradeGroup(string disciplineName);

	list <CStudent> failedSt(string disciplineName);

	list <string> allDisciplines();

};
