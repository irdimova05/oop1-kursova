#include "Irina_19621644_SIT3a_KR1.h"
#include "CStudent.h"
#include "CProtokol.h"
#include "CSesia.h"


int main() {
	 
	try {
		CSesia sesia(3, "data.txt");
		string disciplineName;
		list<string> allDisciplines = sesia.allDisciplines();
		int grade;
		int option;
		do {
			cout << "Menu: " << endl;
			cout << "________________________________________________________" << endl;
			cout << "1. Find the count of grades according to the discipline. " << endl;
			cout << "2. Find the average grade according to the discipline." << endl;
			cout << "3. Find the discipline with the highest average grade. " << endl;
			cout << "4. Find the group with the highest average grade according to the discipline. " << endl;
			cout << "5. Output all failed students according to the discipline. " << endl;
			cout << "6. Exit. " << endl;
			cout << endl << "Available disciplines: ";
			for (list<string>::iterator it = allDisciplines.begin(); it != allDisciplines.end();it++) {
				cout << *it ;
				if (it != --allDisciplines.end()) {
					cout << ", ";
				}
			}
			cout << endl;
			cout << "Please, insert option: ";
			cin >> option;
			cout << endl;
			while (option < 1 || option > 7 || !cin)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "This option doesn't exist. Please, choose an option from 1 to 6: ";
				cin >> option;
				cout << endl;
			}

			system("cls");
			try {
				switch (option) {
				case 1:
					cout << "________________________________________________________________ " << endl;
					cout << "1. Find the count of grades according to the discipline. " << endl;
					cout << "Please, insert discipline: ";
					cin >> disciplineName;
					cout << "Please, insert grade: ";
					cin >> grade;
					cout << "Grades count is: " << sesia.gradesCount(disciplineName, grade) << endl;
					cout << endl;
					break;

				case 2:
					cout << "________________________________________________________________ " << endl;
					cout << "2. Find the average grade according to the discipline." << endl;
					cout << "Please, insert discipline: ";
					cin >> disciplineName;
					cout << "Average grade: " << sesia.averageGrade(disciplineName) << endl;
					cout << endl;
					break;

				case 3:
					cout << "________________________________________________________________ " << endl;
					cout << "3. Find the discipline with the highest average grade. " << endl;
					cout << "The discipline with the highest average grade is: " << sesia.highestGradeDiscipline() << endl;
					cout << endl;
					break;

				case 4:
					cout << "________________________________________________________________ " << endl;
					cout << "4. Find the group with the highest average grade according to the discipline. " << endl;
					cout << "Please, insert discipline: ";
					cin >> disciplineName;
					cout << "The group with the highest average grade is: " << sesia.highestGradeGroup(disciplineName) << endl;
					cout << endl;
					break;

				case 5: {
					cout << "________________________________________________________________ " << endl;
					cout << "5. Output all failed students according to the discipline. " << endl;
					list <CStudent> failed;
					cout << "Please, insert discipline: ";
					cin >> disciplineName;
					cout << endl;
					failed = sesia.failedSt(disciplineName);
					if (failed.empty()) {
						cout << "There are no failed students.";
					}
					else {
						for (auto f : failed) {
							cout << "The failed student is: " << f;
						}

					}
					cout << endl;
				}
						break;

				case 6:
					break;

				}

			}
			catch (int ERROR){
				switch (ERROR) {
				case DISCIPLINEERROR: cout << endl << "This discipline doesn't exists." << endl << endl;
				}
			}
		} while (option != 6);
	}

	catch (int ERROR) {
		switch (ERROR) {
		case FILEERROR: cout << "File error."; break;
		}
	}
}