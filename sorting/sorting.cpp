#include "sorting.h"
#include <iostream>
#define DEBUG
using namespace std; 

void sorting::swap(int& a , int& b){
        int temp = a;
        a = b;
        b = temp;
    }
void sorting::printAll(int* arr , int n){
        for(int i=0; i<n; i++){
            cout << "[" <<arr[i]<<"] ";
        }
        cout << endl;
    }

void sorting::selectSorting(int* list,int size ){
    for(int i = 0 ; i< size - 1; i++){
        int min =i;
        for(int j = i+1; j<size; j++){
            if(list[j] <= list[min]) min = j;
        }
        swap(list[min],list[i]);
#ifdef DEBUG  //debug가 정의되어 있다면 진행 과정을 출력
    printAll(list,size);
#endif  
    }
}
void sorting::insertSorting(int* list,int size ){
    for(int i = 0; i <size; i++){
        int key = list[i];
        int j = i-1;
        while(j>=0 && list[j] >key){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
#ifdef DEBUG  //debug가 정의되어 있다면 진행 과정을 출력
    printAll(list,size);
#endif  
    }
}
           
        // 오름차순 버블정렬
        void sorting::ascendingBubbleSort(int* list,int size){
            for(int i =0; i<size-1; i++){
                for(int j=0; j<size-1-i; j++){
                    if(list[j] > list[j+1]) swap(list[j+1],list[j]);
                        }
        #ifdef DEBUG  //debug가 정의되어 있다면 진행 과정을 출력
            printAll(list,size);
        #endif  
            }
        }
 // 내림차순 버블정렬
        void sorting::DescendingBubbleSort(int* list,int size){
            for(int i =0; i<size-1; i++){
                for(int j=0; j<size-1-i; j++){
                    if(list[j] < list[j+1]) swap(list[j+1],list[j]);
                }
#ifdef DEBUG  //debug가 정의되어 있다면 진행 과정을 출력
    printAll(list,size);
#endif  
        }
    }

        void sorting::quickSorting(int* list,int low, int high ){
            if(low<high){
                int p= partition(list,low,high);
                quickSorting(list,low,p-1);
#ifdef DEBUG
     printAll(list,high+1);
#endif

                quickSorting(list,p+1,high);
    }
            }
        
        int sorting::partition(int* arr , int low , int high){
            int pivot = arr[high]; // 맨 마지막값 피벗으로 설정
            int i = low -1; // 피벗보다 작은 값들이 모여있는 영역의 마지막 인덱스

            for(int j = low ; j<=high ; j++){
                if(arr[j] < pivot){
                    i ++;
                    swap(arr[i],arr[j]); // arr[i] = pivot 보다 크거나 같은 값 , arr[j] = pivot 보다 작은 값
                }

            }
            swap(arr[i+1],arr[high]); // pivot 값과 pivot보다 큰 값이 처음 나오는 인덱스와 swap
            return i+1; // pivot 위치 반환
        }

void sorting::mergeSorting(int* arr , int left , int right, int size){
    if(left >= right) return;

    int mid = left + (right - left) /2;
    mergeSorting(arr, left, mid,size);

    mergeSorting(arr, mid + 1, right,size);

    merge(arr, left, mid, right);
#ifdef DEBUG // DEBUG가 정의된 경우에만 과정 출력
    printAll(arr,size);
#endif
}


void sorting::merge(int* arr ,int left,int mid , int right){
    int n1 = mid -left +1;
    int n2 = right - mid; 

    int* L = new int[n1];
    int* R = new int[n2];
    
    for(int i= 0; i< n1 ; i++){
        L[i] = arr[left+i];
    }
  
    for(int j= 0; j< n2 ; j++){
        R[j] = arr[mid+j+1];
    }
    int i = 0, j=0;
    int k = left;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

