#include "CirQueue.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
const int SIZE = 100;
int main(){
    string filename = "data.txt";
    ifstream Infile(filename);
    if(!Infile){
        cout << "can't open";
        return -1;
    }
    CirQueue q(SIZE); // 100이라 가정
    string line;
    double largestGpa = -1.0;
    double gpa;
    string name;
    while(getline(Infile , line)){
        stringstream ss(line);
        ss >> gpa >> name;
        if(largestGpa < gpa){
            q.clear();
            q.enqueue({name,gpa});
            largestGpa = gpa;
        } else if (gpa == largestGpa) {
            q.enqueue({name, gpa});
        }
    }
    
    cout << "High GPA = " << largestGpa <<endl;
    q.print();
    return 0;
}