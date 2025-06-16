#include <iostream>
#include <vector>
#include <algorithm> // std::swap 사용

using namespace std;

#define _DEBUG
#define MAX 20 // 이 MAX는 예시로 Max Heap의 크기 제한에 사용됩니다.

// 설명을 위해 Max Heap과 Min Heap을 별도의 벡터로 관리합니다.
vector<int> max_heap;
vector<int> min_heap;

// 힙 내용을 출력하는 함수 (Max/Min 힙 모두 사용 가능)
void printHeap(const vector<int>& h, const string& name) {
    cout << "==> " << name << " : ";
    if (h.empty()) {
        cout << "Empty";
    } else {
        for (int v : h) cout << v << " ";
    }
    cout << endl;
}

// 요소 교환 함수 (기존 코드에 있음)
// void swap(int& a, int& b) { ... }

// --- 기존 Max-Heap 관련 함수 (이름 변경) ---

// Max Heap에 값 삽입 (heapify-up)
void insertMaxHeap(int value) {
    if (max_heap.size() >= MAX) {
        cout << "\n[Overflow] Max Heap is full. Could not insertKey\n";
        return;
    }

    max_heap.push_back(value);
    int i = max_heap.size() - 1;

    // 부모보다 크면 swap (Max-heap property)
    while (i > 0 && max_heap[(i - 1) / 2] < max_heap[i]) {
        swap(max_heap[i], max_heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

#ifdef _DEBUG
    printHeap(max_heap, "Max Heap");
#endif
}

// Max Heap에서 heapify-down
void maxHeapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int size = max_heap.size();

    if (left < size && max_heap[left] > max_heap[largest])
        largest = left;
    if (right < size && max_heap[right] > max_heap[largest])
        largest = right;

    if (largest != i) {
        swap(max_heap[i], max_heap[largest]);
        maxHeapify(largest);
    }
}

// Max Heap에서 최댓값 삭제 (루트 삭제)
void deleteMaxHeap() {
    int size = max_heap.size();
    if (size == 0) {
        cout << "\nCould not delete from Max Heap (Heap is empty)\n";
        return;
    }

#ifdef _DEBUG
    cout << "=> Delete Max: " << max_heap[0] << endl;
#endif

    max_heap[0] = max_heap[size - 1]; // 마지막 요소를 루트로 이동
    max_heap.pop_back(); // 마지막 요소 제거

    maxHeapify(0);  // 루트부터 다시 정렬 (heapify-down)

#ifdef _DEBUG
    printHeap(max_heap, "Max Heap");
#endif
}

// --- Min-Heap 관련 함수 (새로 추가) ---

// Min Heap에서 heapify-down
// h: 대상 벡터, i: 현재 노드 인덱스
void minHeapify(vector<int>& h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int size = h.size();

    // 왼쪽 자식이 현재 노드보다 작으면 smallest 갱신 (Min-heap property)
    if (left < size && h[left] < h[smallest])
        smallest = left;

    // 오른쪽 자식이 현재 노드 또는 왼쪽 자식보다 작으면 smallest 갱신 (Min-heap property)
    if (right < size && h[right] < h[smallest])
        smallest = right;

    // 현재 노드가 가장 작지 않으면 (자식 중 더 작은 노드가 있으면) swap하고 재귀 호출
    if (smallest != i) {
        swap(h[i], h[smallest]);
        minHeapify(h, smallest);
    }
}

// Min Heap에 값 삽입 (heapify-up)
// h: 대상 벡터, value: 삽입할 값
void insertMinHeap(vector<int>& h, int value) {
    // Min Heap에 대한 별도의 크기 제한이 필요하다면 여기에 추가
    // if (h.size() >= MAX_MIN_HEAP) { ... }

    h.push_back(value); // 벡터의 마지막에 새 값 추가
    int i = h.size() - 1; // 새로 추가된 값의 인덱스

    // 부모보다 작으면 swap (Min-heap property)
    // i > 0: 루트 노드가 아닐 때까지
    // h[(i - 1) / 2] > h[i]: 부모 노드의 값이 현재 노드의 값보다 크면 (최소 힙 속성 위반)
    while (i > 0 && h[(i - 1) / 2] > h[i]) {
        swap(h[i], h[(i - 1) / 2]); // 부모와 현재 노드 교환
        i = (i - 1) / 2; // 현재 노드의 인덱스를 부모의 인덱스로 업데이트
    }

#ifdef _DEBUG
    printHeap(h, "Min Heap");
#endif
}

// Min Heap에서 최솟값 삭제 (루트 삭제)
// h: 대상 벡터
void deleteMinHeap(vector<int>& h) {
    int size = h.size();
    if (size == 0) {
        cout << "\nCould not delete from Min Heap (Heap is empty)\n";
        return;
    }

#ifdef _DEBUG
    cout << "=> Delete Min: " << h[0] << endl; // Min Heap의 최솟값은 항상 루트 (인덱스 0)
#endif

    h[0] = h[size - 1]; // 마지막 요소를 루트로 이동
    h.pop_back(); // 마지막 요소 제거

    // 루트부터 다시 최소 힙 속성을 만족하도록 정렬 (heapify-down)
    minHeapify(h, 0);

#ifdef _DEBUG
    printHeap(h, "Min Heap");
#endif
}

// --- main 함수 (Max/Min Heap 선택 기능 추가) ---
int main() {
    int menu;
    int heap_type; // 1: Max Heap, 2: Min Heap

    // 사용자에게 어떤 힙을 사용할지 선택하도록 합니다.
    cout << "Choose heap type (1: Max Heap, 2: Min Heap): ";
    cin >> heap_type;

    while (1) {
        cout << "\n--- ";
        if (heap_type == 1) cout << "Max Heap";
        else if (heap_type == 2) cout << "Min Heap";
        cout << " Operations ---" << endl;
        cout << "1. insert 2. delete 3. print 4. quit > ";
        cin >> menu;

        if (menu == 1) { // 삽입
            int value;
            cout << "new value? ";
            cin >> value;
            if (heap_type == 1) insertMaxHeap(value); // Max Heap에 삽입
            else insertMinHeap(min_heap, value); // Min Heap에 삽입
        }
        else if (menu == 2) { // 삭제
            if (heap_type == 1) deleteMaxHeap(); // Max Heap에서 삭제
            else deleteMinHeap(min_heap); // Min Heap에서 삭제
        }
        else if (menu == 3) { // 출력
            if (heap_type == 1) printHeap(max_heap, "Max Heap"); // Max Heap 출력
            else printHeap(min_heap, "Min Heap"); // Min Heap 출력
        }
        else break; // 종료
    }

    cout << "Bye!" << endl;
    return 0;
}
