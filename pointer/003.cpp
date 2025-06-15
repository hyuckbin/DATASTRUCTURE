#include <iostream>
#include <string>
using namespace std;

string trim(string& s){
    int first = s.find_first_not_of(" \t");
    if(first == string::npos) return "";
    int last = s.find_last_not_of(" \t");

    return s.substr(first,last-first+1);
}
int main(){
    string s1;
    getline(cin , s1);
    string trimmed = trim(s1);

    cout << trimmed;
    return 0;
}