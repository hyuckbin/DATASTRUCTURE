#include <iostream>
using namespace std;

struct item{
    string name[2];
    int price[2];
    string make[2];
};

void input(item& st){
    for(int i=0; i<2; i++){
        cin >> st.name[i] >> st.price[i] >> st.make[i];
    }
}
bool compare(item& s){
    string s1= "";
    string s2= "";
    for(char ch : s.name[0]){
        ch = toupper(ch);
        s1 += ch;
    }
    for(char ch : s.name[1]){
        ch = toupper(ch);
        s2 += ch;
    }
    if(s1 ==s2 && s.price[0] == s.price[1]) return true;

    else return false;
}
int main(){
    item item;
    input(item);
    if(!compare(item)){
        cout << item.name[0]<< " and " << item.name[1] <<" is not equal." ;
    }
    else{   
        cout << item.name[0] << " is equal."<<endl;

    }
}