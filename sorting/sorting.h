#ifndef SORTING_H
#define SORTING_H

class sorting{
    public:
        void selectSorting(int* list,int size );
        void insertSorting(int* list,int size );

        void ascendingBubbleSort(int* list,int size); // 오름차순 버블정렬
        void DescendingBubbleSort(int* list,int size);// 내림차순 버블정렬

        void quickSorting(int* list,int low, int high );
        int partition(int* arr , int low , int high);

        void mergeSorting(int* list,int left, int mid,int right);
        void merge(int* arr ,int left,int mid , int right);
        
        void printAll(int* arr , int n);
        void swap(int& a , int& b);
};
#endif