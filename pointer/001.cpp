#include <iostream>
using namespace std;

struct Menu{
    string menu;
    int price;
};
struct Cafe{
    string name;
    int menuCount;
    Menu* menuList;
};
void addCafe(Cafe &cafe) {
    getline(cin,cafe.name);

    cin >> cafe.menuCount;
    cin.ignore();  

    cafe.menuList = new Menu[cafe.menuCount];
}

void addMenu(Menu &menu) {
    cin >> menu.menu;
    cin >> menu.price;
}

void displayMenus(Cafe &cafe) {
   cout << "===== "<<cafe.name <<" ===== " << endl ;
    for (int i = 0; i < cafe.menuCount; ++i) {
         cout << cafe.menuList[i].menu << " " << cafe.menuList[i].price << endl;
    }
    cout << "=========== " << endl ;
}  
int main(){
    Cafe myCafe;
    addCafe(myCafe);

    for (int i = 0; i < myCafe.menuCount; ++i) {
        addMenu(myCafe.menuList[i]);
    }

    displayMenus(myCafe);

    delete[] myCafe.menuList;  // 메모리 해제
    return 0;
    return 0;
}