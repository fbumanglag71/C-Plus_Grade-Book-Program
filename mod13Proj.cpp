/*Author: Francisco Bumanglag
Project: Grade Book Program
Assignment: Module 13 Project 10
Course: C++ Santa Ana College
Class: CMPR120 Dr. Tahir Aziz
Date: May 16, 2024*/

#include <iostream>  //input/output stream operations library
#include <string>    //string manipulation orperations library
#include <iomanip>   //input/output manipulation operations library

using namespace std;

//function to calculate the average scores
double calcAverage(double scores[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += scores[i];
    }
    return sum / size;
}

//if-else function to get the letter grade
char getGrade(double averageScore) {
    if (averageScore >= 90)
        return 'A';
    else if (averageScore >= 80)
        return 'B';
    else if (averageScore >= 70)
        return 'C';
    else if (averageScore >= 60)
        return 'D';
    else
        return 'F';
}

int main() {
    const int STUDENTS = 5;
    const int TESTS = 4;

    string studentName[STUDENTS];
    char grades[STUDENTS];
    double getScores[STUDENTS][TESTS];

    //user inputs the student names (5) and the scores (5)
    for (int i = 0; i < STUDENTS; ++i) {
        cout << "Enter the name of student " << i + 1 << ": ";
        getline(cin, studentName[i]);

        for (int j = 0; j < TESTS; ++j) {
            do {
                cout << "Enter the test score " << j + 1 << " for " << studentName[i] << ": ";
                cin >> getScores[i][j];
                if (getScores[i][j] < 0 || getScores[i][j] > 100)
                    cout << "Invalid. Enter a test score between 0 and 100." << endl;
            } while (getScores[i][j] < 0 || getScores[i][j] > 100);
        }
        cin.ignore(); //ignore the newline character

        //calculate the average score and assign the letter grade
        double average = calcAverage(getScores[i], TESTS);
        grades[i] = getGrade(average);
    }

    //display the results 
    cout << "\nStudent Name\t\tAverage Score\t\tLetter Grade" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < STUDENTS; ++i) {
        cout << setw(20) << left << studentName[i] << "\t\t";
        cout << setw(15) << left << calcAverage(getScores[i], TESTS) << "\t\t";
        cout << grades[i] << endl;
    }    

    return 0;
}
