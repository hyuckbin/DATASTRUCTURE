#include <iostream>
#include <iomanip>
using namespace std;
const int SIZE = 50;
int main(){
    string s1 ;
    getline(cin,s1);
    int alphacount[26] = {0};
    int blankcount =0; 

    for(char ch : s1){
        if(isalpha(ch)){
            ch = toupper(ch);
            alphacount[ch-'A'] ++;
        }

        if(ch ==' ') blankcount ++;
    }
    
    cout << "blanks : "<<blankcount <<endl;

    for(int i= 0; i< 26 ; i++){
        if(alphacount[i] >0){
            cout << char('A'+i) << " : "<< alphacount[i] <<endl;
        }
    }
}