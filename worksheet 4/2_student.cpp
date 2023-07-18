#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNo;
    char grade;

public:
    Student(){
    };

    Student(const string& name, int rollNo, char grade)
        : name(name), rollNo(rollNo), grade(grade) {}

    void displayStudentInfo() const {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Grade: " << grade << endl;
    }

    static bool compareByRollNo(const Student& s1, const Student& s2) {
        return s1.rollNo > s2.rollNo;
    }

    void readStudentInfo() {
        cout << "Enter name: ";
        getline(cin >> ws, name);
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter grade: ";
        cin >> grade;
    }
};

int main() {
    const int MAX_STUDENTS = 3;

    Student students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        students[i].readStudentInfo();
    }
    
    cout << "\nStudent Information:\n";
    for (const Student& student : students) {
        student.displayStudentInfo();
    }

    for (int i = 0; i < MAX_STUDENTS - 1; ++i) {
        for (int j = 0; j < MAX_STUDENTS - i - 1; ++j) {
            if (Student::compareByRollNo(students[j], students[j + 1])) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "\nSorted Student Information (based on Roll No):\n";
    for (const Student& student : students) {
        student.displayStudentInfo();
    }

    return 0;
}

