#include <iostream>
using namespace std;

class MyStack{
    int size,top;
    int* list;

    public:
        MyStack(int cap) : size(cap) , top(-1){
            list = new int[cap];
        }
        ~MyStack(){
            delete[] list;
        }
        bool isEmpty () const{
            return top ==-1;
        }
        
        bool isFull () const{
            return top +1 == size;
        }

        void push(int val){
            if(isFull()) return;
            list[++top] = val;
        }
        int pop(){
            if(isEmpty()) return -1;
            int temp = list[top];
            top --;

            return temp;
        }
        void clean(){
            top = -1;
        }

        void print(){
            
            for(int i=top; i>=0 ; i--){
                 std::cout<< list[i]<<std::endl;
            }
            cout << " =>null"<< endl;
        }
    };
int main(){
    int count;
    cin >> count; 
    MyStack s(count);
    string choice;
    int val; // push 용 
    while(true){
        cin >> choice;
        if(choice == "push"){
            cin >> val;
            s.push(val);
        }
        if(choice == "pop") s.pop();

        if(choice == "print"){
            s.print();
            break;
        }
    }
    return 0;
}