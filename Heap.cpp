#include <climits>
#include <vector>

class Heap {
  std::vector<int> heap;

  static int leftChild(int i) { return 2 * i + 1; }
  static int rightChild(int i) { return 2 * i + 2; }
  static int parent(int i) { return (i - 1) / 2; }

  void swap(int i, int j) {
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
  }

  void sinkDown(int i) {
    while (true) {
      int maxI = i;
      int L = leftChild(i);
      int R = rightChild(i);
      if (L < (int)heap.size() && heap[L] > heap[maxI]) maxI = L;
      if (R < (int)heap.size() && heap[R] > heap[maxI]) maxI = R;
      if (maxI == i) return;
      swap(i, maxI);
      i = maxI;
    }
  }

 public:
  void insert(int v) {
    heap.push_back(v);
    int i = (int)heap.size() - 1;
    while (i > 0 && heap[i] > heap[parent(i)]) {
      swap(i, parent(i));
      i = parent(i);
    }
  }

  int remove() {
    if (heap.empty()) return INT_MIN;
    int top = heap[0];
    if (heap.size() == 1) {
      heap.pop_back();
      return top;
    }
    heap[0] = heap.back();
    heap.pop_back();
    sinkDown(0);
    return top;
  }

  int peek() const { return heap.empty() ? INT_MIN : heap[0]; }

  bool empty() const { return heap.empty(); }
  int size() const { return (int)heap.size(); }
};
