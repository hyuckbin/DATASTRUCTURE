#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
const int SIZE = 100;

class MyStack{
    int size,top;
    string* list;

    public:
        MyStack(int cap) : size(cap) , top(-1){
            list = new string[cap];
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

        void push(string val){
            if(isFull()) return;
            list[++top] = val;
        }
        string pop(){
            if(isEmpty()) return "";
            string temp = list[top];
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
    string filename;
    getline (cin,filename);

    ifstream inFile(filename);
    if(!inFile){
        cout << "못읽어" <<endl;
        return 1;
    }
    MyStack s(SIZE);

    double maxGPA =  -1.0;
    string line;

    while(getline(inFile,line)){
        stringstream ss (line);
        double gpa;
        string name;
        ss>>gpa>>name;

        if(gpa > maxGPA){
            s.clean();
            s.push(name);
            maxGPA = gpa;
        }
        else if(gpa == maxGPA) s.push(name);

        else{
            continue;
        }
    }

    s.print();

    return 0;
}