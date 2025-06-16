// class MinHeap {
//     vector<int> heap;

// public:
//     void insert(int value) {
//         heap.push_back(value);
//         int i = heap.size() - 1;

//         while (i > 0) {
//             int parent = (i - 1) / 2;
//             if (heap[parent] <= heap[i]) break;
//             swap(heap[parent], heap[i]);
//             i = parent;
//         }
//     }

//     void removeMin() {
//         if (heap.empty()) return;

//         heap[0] = heap.back();
//         heap.pop_back();

//         int i = 0;
//         int n = heap.size();
//         while (true) {
//             int left = 2 * i + 1;
//             int right = 2 * i + 2;
//             int smallest = i;

//             if (left < n && heap[left] < heap[smallest]) smallest = left;
//             if (right < n && heap[right] < heap[smallest]) smallest = right;
//             if (smallest == i) break;

//             swap(heap[i], heap[smallest]);
//             i = smallest;
//         }
//     }

//     int getMin() const {
//         return heap.empty() ? -1 : heap[0];
//     }

//     void printHeap() const {
//         for (int val : heap) cout << val << " ";
//         cout << endl;
//     }
// };
