#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int cap;
    cin >> cap;

    Stack stack(cap);
    stack.clean();

    string cmd;
    while (cin >> cmd) {
        if (cmd == "+") {
            element e;
            cin >> e.rank >> ws;
            getline(cin, e.gift);
            stack.push(e);
        }
        else if (cmd == "-") {
            element popped = stack.pop();
            if (popped.rank != -1) {
                cout << popped.rank << "등 " << popped.gift << endl;
            }
        }
        else if (cmd == "q") {
            break;
        }
    }

    return 0;
}