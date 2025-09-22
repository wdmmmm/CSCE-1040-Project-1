#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

struct Student {
    int id;
    string first, last;
    int exam1, exam2, exam3;
    float mean;
};

#endif