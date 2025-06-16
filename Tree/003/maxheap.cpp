#include <iostream>
#include <vector>
#include <algorithm>  // for swap
using namespace std;

class MaxHeap {
    vector<int> heap;

public:
    // 삽입: 새 값을 마지막에 넣고 위로 끌어올리기 (heapify up)
    void insert(int value) {
        heap.push_back(value);
        int i = heap.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] >= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    // 최대값 삭제: 루트를 제거하고 마지막 값을 루트로 올린 뒤 아래로 내려감 (heapify down)
    void removeMax() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    int getMax() const {
        return heap.empty() ? -1 : heap[0];
    }

    void printHeap() const {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};
