#include "roster.h"
#include <sstream>

// Constructor
Roster::Roster() {
    classRosterArray = new Student*[MAX_STUDENTS];
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;
}

// Parse student data and add to the roster
void Roster::parseAndAddStudent(const string& studentData) {
    stringstream ss(studentData);
    string token;

    // Extracting student details from the string
    string studentID, firstName, lastName, emailAddress;
    int age, daysInCourse1, daysInCourse2, daysInCourse3;
    DegreeProgram degreeProgram;

    getline(ss, studentID, ',');
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, emailAddress, ',');
    getline(ss, token, ',');
    age = stoi(token);
    getline(ss, token, ',');
    daysInCourse1 = stoi(token);
    getline(ss, token, ',');
    daysInCourse2 = stoi(token);
    getline(ss, token, ',');
    daysInCourse3 = stoi(token);
    getline(ss, token, ',');
    degreeProgram = static_cast<DegreeProgram>(stoi(token));

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// Add student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToCompleteCourses[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    // Create a student object and add it to the roster
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourses, degreeProgram);
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = newStudent;
            break;
        }
    }
}

// Remove student from the roster by ID
void Roster::remove(string studentID) {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            cout << "Student with ID " << studentID << " removed from roster." << endl;
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found in roster." << endl;
}

// Print all students in the roster
void Roster::printAll() const {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
            cout << "--------------------------" << endl;
        }
    }
}

// Print average days to complete courses for a specific student
void Roster::printAverageDaysInCourse(string studentID) const {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            int* daysToCompleteCourses = classRosterArray[i]->getDaysToCompleteCourses();
            double averageDays = (daysToCompleteCourses[0] + daysToCompleteCourses[1] + daysToCompleteCourses[2]) / 3.0;
            cout << "Average days to complete courses for student " << studentID << ": " << averageDays << endl;
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found in roster." << endl;
}

// Print invalid email addresses
void Roster::printInvalidEmails() const {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->getEmailAddress();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
                cout << "Invalid email address: " << email << " for student with ID: " << classRosterArray[i]->getStudentID() << endl;
            }
        }
    }
}

// Print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            cout << "--------------------------" << endl;
        }
    }
}
