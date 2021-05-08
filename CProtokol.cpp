#pragma once
#include "CProtokol.h"

CProtokol::CProtokol() {}

CProtokol::CProtokol(const CProtokol& p) {
	disciplineName = p.disciplineName;
	groupNumber = p.groupNumber;
	grades = p.grades;
}// copy constr

void CProtokol::setDisciplineName(string disciplineName) {
	this->disciplineName = disciplineName;
}

void CProtokol::setGroupNumber(int groupNumber) {
	this->groupNumber = groupNumber;
}

int CProtokol::getGroupNumber() {
	return groupNumber;
}

void CProtokol::setGrades(map<CStudent, unsigned> grades) {
	this->grades = grades;
}

map<CStudent, unsigned> CProtokol::getGrades() {
	return grades;
}

string CProtokol::getDisciplineName() {
	return disciplineName;
}

double CProtokol::averageSuccess() {
	int sum = 0;
	double size = 0;
	for (auto& g : grades) {
		sum += g.second;
		size++;
	}
	return size ? sum / size : 0;
}

list<CStudent*> CProtokol::failedStudents() {
	list<CStudent*> failed;
	for (map<CStudent, unsigned>::iterator g = grades.begin(); g != grades.end(); ++g) {
		if (g->second == 2) {
			failed.push_back(const_cast<CStudent*>(&g->first));
		}
	}
	return failed;
}

istream& operator>>(istream& istr, CProtokol& p) {
	istr >> p.disciplineName;
	istr >> p.groupNumber;
	int stCount = 0;
	istr >> stCount;
	for (int i = 0; i < stCount; i++) {
		CStudent stud;
		istr >> stud;
		unsigned int grade = 0;
		istr >> grade;
		p.grades.insert(pair<CStudent, unsigned>(stud, grade));
	}
	return istr;
}

void CProtokol::operator=(CProtokol& p) {
	disciplineName = p.disciplineName;
	groupNumber = p.groupNumber;
	grades = p.grades;
}

bool operator<(const CProtokol& left, const CProtokol& right) {
	return left.disciplineName < right.disciplineName && left.groupNumber < right.groupNumber;
}