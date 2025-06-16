#include "Stack.h"
#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string str;
    Stack left , right;
    string result;
    while(true){
        result ="";
        getline(cin , str);

        if(str == "q") break;

        for(char ch : str){
            if(isalnum(ch)){
                left.push(ch);
            }

            else if( ch == '<'){
                if(!left.isEmpty()){
                    char val = left.top();
                    left.pop();
                    right.push(val);
                }
            }
            else if( ch == '>'){
                if(!right.isEmpty()){
                    char val = right.top();
                    right.pop();
                    left.push(val);
                }
            }
            
        }
        Stack temp;
            while (!left.isEmpty()) {
                temp.push(left.top());
                left.pop();
        }
            while (!temp.isEmpty()) {
            cout << temp.top();
            temp.pop();
        }
            while (!right.isEmpty()) {
                cout << right.top();
                right.pop();
        }
            cout <<endl;
    }
    
    return 0;
}