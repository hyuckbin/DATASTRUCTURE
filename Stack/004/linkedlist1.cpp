#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack s;
    string command;

    while(true){
        cin >> command;
        if(command == "push"){
            int val;
            cin >> val;
            s.push(val);
        }
        else if(command == "pop"){
            s.pop();
        }
        else if(command == "print"){
            s.printAll();
        }
        
        else if(command == "q"){
            break;
        }
      
    }
    return 0;   
}