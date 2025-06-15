//prefix
#include <iostream>
using namespace std;

string cal(string* p , string* s){
    int i = 0 ;
    while(i < p->size() && i< s-> size() && (*p)[i] == (*s)[i] ){
        i++;
    }

    return p->substr(0,i);
}
int main(){ 
    string prefix;

    string* s = new string[3];
    for(int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    prefix = s[0];

    for(int i=1; i<3; i++){
        prefix = cal(&prefix , &s[i]);
        if(prefix.empty()) break;
    }

    cout << prefix;
    return 0;
}