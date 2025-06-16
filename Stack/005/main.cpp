#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


int oper(int a , int b , string op){
    if (op == "+") return a + b;
    else if (op == "-") return a - b;
    else if (op == "*") return a * b;
    else if (op == "/") {
        if(b == 0){
            cout << " Division by 0" <<endl;
            return -1;
        }
        return a / b;
    }
}
void cal(string line){
    Stack s;
    stringstream ss(line);
    string token;
    
    while(ss >> token){
        if(token[0] == '#'){
            try{
                int num = stoi(token.substr(1));
                s.push(num);
            }catch(exception e){
                cout << "Expression error"<<endl;
                return;
            }       
        }
        else if(token == "+" || token == "-" || token == "*" || token == "/"){
            if(s.getNodeCount() < 2){
                cout << " 수가 2개 미만임" <<endl;
                return;
            }
            int b = s.top();
            s.pop();
            int a = s. top();
            s.pop();

            int result = 0;
            result = oper(a,b,token);
            s.push(result);
        }

        else if(token == "="){
            if(s.isEmpty()){
                return;
            }
            int result = s.top();
            s.pop();
            if(!s.isEmpty()){
                cout << endl<<"=> Too many operands !!!" << endl;
                return;
            }
            cout << result << endl;
        }
        else {
            cout <<endl<< "=>Expression error !!!" << endl;
            return;
        }
    }
}


int main(){
    string filename = "data.txt";

    ifstream inFile(filename);
    if(!inFile){
        cerr << "can't open"<<endl;
        return -1;
    }

    string line;
    while(getline(inFile,line)){
        cout << line << " ";    
        cal(line);
    }

    return 0;
}
