#include <iostream>
#include "sorting.h"
#define DEBUG
using namespace std;

//정렬 방식을 선택한후 크기와 크기에 맞는 숫자를 입력한다
//각 파일들은 DEBUG가 명시되어 있어 진행 과정을 출력하고 만약 결과만 출력하고싶다면 각 파일의 DEBUG정의를 제거하면 된다
int main() {
    int choice;
    sorting s;
    int count;
    while(true){
        
        cout << "1.selection 2.insertion 3.bubble 4.quick 5.merge 6.exit > ";
        cin >> choice;

        if(choice == 6) {
            cout <<"bye!"; 
            break;
        }   
        cout << "Enter count: ";
        cin >> count;
        
        int* arr = new int[count];
        cout << "Enter numbers: ";
        for(int i=0; i<count; i++){
            cin >> arr[i];
            }

        switch (choice)
        {
        case 1:
            cout <<"==== selection sort ===="<<endl;
            s.printAll(arr,count);
            s.selectSorting(arr,count);
            break;
        case 2:
            cout <<"==== insertion sort ===="<<endl;
            s.printAll(arr,count);
            s.insertSorting(arr,count);
            break;
        case 3:
            cout <<"==== bubble sort ===="<<endl;
            int n;
            cout <<" 1 - 오름차순 정렬 , 2 - 내림차순 정렬 : ";
            cin >>n;
            // 1을 입력하면 오름차순정렬 , 2를 입력하면 내림차순 정렬
            if(n == 1){
                s.printAll(arr,count);
                s.ascendingBubbleSort(arr,count);
            }
            else if(n == 2){
                s.printAll(arr,count);
                s.DescendingBubbleSort(arr,count);
            }
            break;
        case 4:
            cout <<"==== quick sort ===="<<endl;
            s.printAll(arr,count);
            s.quickSorting(arr,0,count-1);
            break;
#ifndef DEBUG
    s.printAll(arr,count);
#endif 
        case 5:
            cout <<"==== merge sort ===="<<endl;
            s.printAll(arr,count);
            s.mergeSorting(arr,0,count-1,count);
#ifndef DEBUG
    s.printAll(arr,count);
#endif  
            break;
        default:
            break;
        }
        
    delete[] arr;       
   }

    return 0;
}