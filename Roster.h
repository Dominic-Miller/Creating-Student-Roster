#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Roster {
public:
   friend ostream & operator << (ostream &out, const Roster &r);

   Roster();
   void processFile();


private:
   vector<int> studentID;
   vector<string> studentName;
   vector<double> projectAverage;
   vector<double> participationAverage;
   vector<double> testAverage;
   vector<double> finalGrade;
   const double PARTICIPATION_WEIGHT = .15;
   const double PROJECT_WEIGHT = .40;
   const double TEST_WEIGHT = .45;
};
#endif