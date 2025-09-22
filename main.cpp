#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Student.h"
using namespace std;

int i, j;

int getValidScore(const string& examName) {
    int score;
    while (true) {
        cout << "Enter " << examName << " score: ";
        cin >> score;

        if (cin.fail() || score < 0 || score > 100) {
            cin.clear();                 
            cin.ignore(1000, '\n');      
            cout << "Invalid score! Please enter a number between 0 and 100.\n";
        } else {
            break;  // valid input
        }
    }
    return score;
}

int main( )
{
 /* Author: Michael Ajayi (OlumideAjayi@my.unt.edu)
 Date: 9/9/25
 Instructor: Dr Maharjan CSCE 1040
 Description: This program creates a menu for students exam information.
 */

 Student* arr = new Student[25];
 int ctr = 0;
 bool quit = false;
 int input, sId;
 float min = INFINITY;
 float max = -INFINITY;
 float sum = 0.0;
 float ans;


 cout << "+----------------------------------------------+" << endl << endl;
 cout << "|\tComputer Science and Engineering\t |" << endl << endl;
 cout << "|\tCSCE 1040 - Computer Science II\t\t |" << endl << endl;
 cout << "| Michael Ajayi oa0274 OlumideAjayi@my.unt.edu |" << endl << endl;
 cout << "+----------------------------------------------+" << endl << endl;

 do {
  cout << endl << endl << "*********************** Menu **********************" << endl << endl;
  cout << "| 1. Display list of students' information	     |" << endl << endl;
  cout << "| 2. Add student information    		     |" << endl << endl;
  cout << "| 3. Update student's information	             |" << endl << endl;
  cout << "| 4. Compute mean of list of students exams       |" << endl << endl;
  cout << "| 5. Compute minimum of the mean of the exams     |" << endl << endl;
  cout << "| 6. Compute maximum of the mean of the exams     |" << endl << endl;
  cout << "| 7. Exit Program			             |" << endl << endl;
  cout << "***************************************************" << endl << endl;

  cin >> input;

  switch (input) {
   case 1:
    if (ctr == 0) {
     cout << endl << "Empty list of students" << endl;
    }
    else {
     cout << "*********************** Students Information ***********************" << endl << endl;
     cout << left
             << setw(12) << "Id"
             << setw(16) << "First name"
             << setw(16) << "Last name"
             << setw(8)  << "Exam1"
             << setw(8)  << "Exam2"
             << setw(8)  << "Exam3"
             << setw(8)  << "Mean"
             << endl;
     cout << "_________________________________________________________________________" << endl << endl;
     for (i = 0; i < ctr; i++) {
            cout << left
                 << setw(12) << arr[i].id
                 << setw(16) << arr[i].first
                 << setw(16) << arr[i].last
                 << setw(8)  << arr[i].exam1
                 << setw(8)  << arr[i].exam2
                 << setw(8)  << arr[i].exam3
                 << setw(8)  << fixed << setprecision(2) << arr[i].mean
                 << endl;
        }
        cout << endl;
    }
    break;


   case 2:
    cout << "Enter student's information" << endl;

    cout << "Id: ";
    cin >> arr[ctr].id;
    cout << "First name: ";
    cin >> arr[ctr].first;
    cout << "Last name: ";
    cin >> arr[ctr].last;
    arr[ctr].exam1 = getValidScore("exam 1");
    arr[ctr].exam2 = getValidScore("exam 2");
    arr[ctr].exam3 = getValidScore("exam 3");


    arr[ctr].mean = (static_cast<float>(arr[ctr].exam3) + static_cast<float>(arr[ctr].exam2) + static_cast<float>(arr[ctr].exam1)) / 3.0;

    cout << "New student with id " << arr[ctr].id << " added." << endl;
    ctr ++;
    break;

   case 3:
    cout << endl << "Please enter student id: ";
    cin >> sId;

    for (i = 0; i < ctr; i++) {
     if (arr[i].id == sId) {
      cout << "Update student's information:" << endl;

      cout << "Id: ";
      cin >> arr[i].id;
      cout << "First name: ";
      cin >> arr[i].first;
      cout << "Last name: ";
      cin >> arr[i].last;
      arr[i].exam1 = getValidScore("exam 1");
      arr[i].exam2 = getValidScore("exam 2");
      arr[i].exam3 = getValidScore("exam 3");


      arr[i].mean = (static_cast<float>(arr[i].exam3) + static_cast<float>(arr[i].exam2) + static_cast<float>(arr[i].exam1)) / 3;

      cout << "Students information with id " << arr[i].id << " updated." << endl;
      break;
     }
     else {
      cout << endl << "Id not found. " << endl;
     }
    }
    break;

   case 4:
    for (i = 0; i < ctr; i++) {
     sum = sum + arr[i].mean;
     ans = sum / (i+1);
    }

    cout << endl << "Mean of the exams: " << ans << endl;
    sum = 0.0;
    ans = 0.0;
    break;

   case 5:
    for (i = 0; i < ctr; i++) {
     if (arr[i].mean < min) {
      min = arr[i].mean;
     }
    }

    cout << endl << "Minimum of the mean of the exams: " << min << endl;
    min = INFINITY;
    break;

   case 6:
    for (i = 0; i < ctr; i++) {
     if (arr[i].mean > max) {
      max = arr[i].mean;
     }
    }

    cout << endl << "Maximum of the mean of the exams: " << max << endl;
    max = -INFINITY;

    break;

   case 7:
    cout << endl << "Thank you for using this program. Goodbye!" << endl << endl;
    quit = true;
    break;

   default:
    cout << endl << "Please enter 1-7." << endl;
    break;
  }

 } while (quit == false);

 delete[] arr;
}
