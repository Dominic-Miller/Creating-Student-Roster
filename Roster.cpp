#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Roster.h"

using namespace std;

ostream & operator << (ostream &out, const Roster &r) {
   out << left << setw(6) << "ID" << setw(20) << "Student Name" << setw(14) << "Participation" << setw(8) << "Project" << setw(6) << "Test" << setw(6) << "Final" << endl << right;
   for (unsigned long int i = 0; i < r.studentName.size(); i++) {
      out << right << setfill('0') << setw(5) << r.studentID.at(i) << " " << left << setfill(' ') << setw(20) << r.studentName.at(i) << left << setw(14) << setprecision(2) << fixed << r.participationAverage.at(i) << left << setw(8) << r.projectAverage.at(i) << left << setw(5) << r.testAverage.at(i) << left << " " << r.finalGrade.at(i) << endl;
   }
   return out;
}

Roster::Roster() {
   processFile();
}

void Roster::processFile() {
   string file;
   cout << "Please enter the name of the roster file" << endl;
   cin >> file;

   fstream fin;
   fin.open(file);

   string line;
   int ID;
   string name;
   vector<int>marks;

   while (fin) {
      marks.clear();
      getline(fin, line);
      if (line.find(" ") == -1)
            break;

   ID = stoi(line.substr(0, line.find(" ")));
   line = line.substr(line.find(" ") + 1);

   name = line.substr(0, line.find(" "));
   line = line.substr(line.find(" ") + 1);
   name += (" " + line.substr(0, line.find(" ")));
   line = line.substr(line.find(" ") + 1);

   studentID.push_back(ID);
   studentName.push_back(name);

   for (int i = 0; i < 8; i++) {
      marks.push_back(stoi(line.substr(0, line.find(" "))));
      line = line.substr(line.find(" ") + 1);
      }
   marks.push_back(stoi(line));

   participationAverage.push_back((marks[0] + marks[1] + marks[2]) * 1.0 / 3);
   projectAverage.push_back((marks[3] + marks[4] + marks[5]) * 1.0 / 3);
   testAverage.push_back((marks[6] + marks[7] + marks[8]) * 1.0 / 3);

   finalGrade.push_back((participationAverage.back() * PARTICIPATION_WEIGHT) + (projectAverage.back() * PROJECT_WEIGHT) + (testAverage.back() * TEST_WEIGHT));
   }
}