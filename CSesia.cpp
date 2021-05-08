#pragma once
#include "CSesia.h"

CSesia::CSesia(int semesterNumber1) {
	semesterNumber = semesterNumber1;
}

CSesia::CSesia(int semesterNumber1, string fileName) {
	semesterNumber = semesterNumber1;
	ifstream f(fileName);
	if (f.is_open()) {
		while (!f.eof()) {
			CProtokol data;
			f >> data;
			prot.insert(data);
		}
	}
	else {
		throw FILEERROR;
	}
}

int CSesia::gradesCount(string disciplineName, int grade) {
	int result = 0;
	bool found = false;
	transform(disciplineName.begin(), disciplineName.end(), disciplineName.begin(), ::tolower);
	for (auto p : prot) {
		if (p.getDisciplineName() == disciplineName) {
			found = true;
			for (auto g : p.getGrades()) {
				if (g.second == grade) {
					result++;
				}
			}
		}
	}
	if (!found) {
		throw DISCIPLINEERROR;
	}
	return result;
}

double CSesia::averageGrade(string disciplineName) {
	double result = 0.0;
	int gradesCount = 0;
	bool found = false;
	transform(disciplineName.begin(), disciplineName.end(), disciplineName.begin(), ::tolower);
	for (auto p : prot) {
		if (p.getDisciplineName() == disciplineName) {
			found = true;
			gradesCount = p.getGrades().size();
			for (auto g : p.getGrades()) {
				result += g.second;
			}
		}
	}
	if (!found) {
		throw DISCIPLINEERROR;
	}
	return result / gradesCount;
}

string CSesia::highestGradeDiscipline() {
	CProtokol max(*prot.begin());
	for (auto p : prot) {
		if (p.averageSuccess() > max.averageSuccess()) {
			max = p;
		}
	}
	return max.getDisciplineName();
}

int CSesia::highestGradeGroup(string disciplineName) {
	double max = 0.0; // zapisva nai-visokiq uspeh
	int groupNum = 0; // zapisva nomer na grupata
	bool found = false;
	transform(disciplineName.begin(), disciplineName.end(), disciplineName.begin(), ::tolower);
	for (auto p : prot) {
		if (disciplineName == p.getDisciplineName()) {
			found = true;
			if (p.averageSuccess() > max) {
				max = p.averageSuccess();
				groupNum = p.getGroupNumber();
			}
		}
	}
	if (!found) {
		throw DISCIPLINEERROR;
	}
	return groupNum;
}

list<CStudent> CSesia::failedSt(string disciplineName) {
	list<CStudent> failed;
	list<CStudent*> temp;
	bool found = false;
	transform(disciplineName.begin(), disciplineName.end(), disciplineName.begin(), ::tolower);
	for (auto p : prot) {

		if (disciplineName == p.getDisciplineName()) {
			found = true;
			temp = p.failedStudents();
			for (auto t : temp) {
				failed.push_back(*t);
			}
		}
	}
	if (!found) {
		throw DISCIPLINEERROR;
	}
	return failed;
}

list<string> CSesia::allDisciplines() {
	list <string> allD;
	for (auto p : prot) {
		allD.push_back(p.getDisciplineName());
	}
	unique(allD.begin(), allD.end());
	return allD;
}
