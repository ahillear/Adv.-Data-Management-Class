#include "student.h"
#include <iostream>

// Default constructor
Student::Student() {
    // Initialize variables to default values
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 0;
    daysToCompleteCourses = nullptr;
    degreeProgram = DegreeProgram::SECURITY; // default degree program
}

// Parameterized constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysToCompleteCourses, DegreeProgram degreeProgram) {
    // Assign values to class members
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToCompleteCourses = daysToCompleteCourses;
    this->degreeProgram = degreeProgram;
}

// Destructor
Student::~Student() {
    // Free memory if dynamically allocated
    delete[] daysToCompleteCourses;
}

// Accessors (getters)
string Student::getStudentID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

int* Student::getDaysToCompleteCourses() const {
    return daysToCompleteCourses;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

// Mutators (setters)
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToCompleteCourses(int* daysToCompleteCourses) {
    this->daysToCompleteCourses = daysToCompleteCourses;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Print specific student data
void Student::print() const {
    cout << "Student ID: " << studentID << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Email Address: " << emailAddress << endl;
    cout << "Age: " << age << endl;
    cout << "Degree Program: ";
    switch (degreeProgram) {
        case DegreeProgram::SECURITY:
            cout << "Security";
            break;
        case DegreeProgram::NETWORK:
            cout << "Network";
            break;
        case DegreeProgram::SOFTWARE:
            cout << "Software";
            break;
    }
    cout << endl;
    cout << "Days to Complete Courses: ";
    for (int i = 0; i < 3; ++i) {
        cout << daysToCompleteCourses[i] << " ";
    }
    cout << endl;
}
