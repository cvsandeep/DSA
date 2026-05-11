class Node {
 public:
  int data;
  Node* next;
  Node* prev;
  Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoubleLL {
 public:
  Node* Head;
  Node* Tail;
  int count;

  DoubleLL(int v) {
    Head = Tail = new Node(v);
    count = 1;
  }

  void append(int v) {
    Node* n = new Node(v);
    if (!Head) {
      Head = Tail = n;
      count = 1;
      return;
    }
    n->prev = Tail;
    Tail->next = n;
    Tail = n;
    count++;
  }

  void prepend(int v) {
    Node* n = new Node(v);
    if (!Head) {
      Head = Tail = n;
      count = 1;
      return;
    }
    n->next = Head;
    Head->prev = n;
    Head = n;
    count++;
  }

  void DeleteLast() {
    if (!Tail) return;
    Node* del = Tail;
    if (Head == Tail) {
      Head = Tail = nullptr;
    } else {
      Tail = Tail->prev;
      Tail->next = nullptr;
    }
    delete del;
    count--;
  }

  void DeleteFirst() {
    if (!Head) return;
    Node* del = Head;
    if (Head == Tail) {
      Head = Tail = nullptr;
    } else {
      Head = Head->next;
      Head->prev = nullptr;
    }
    delete del;
    count--;
  }

  bool Get(int i, int& out) const {
    if (i < 0 || i >= count || !Head) return false;
    Node* t = Head;
    for (int j = 0; j < i; j++) t = t->next;
    out = t->data;
    return true;
  }

  bool set(int i, int v) {
    if (i < 0 || i >= count || !Head) return false;
    Node* t = Head;
    for (int j = 0; j < i; j++) t = t->next;
    t->data = v;
    return true;
  }

  bool Insert(int i, int v) {
    if (i < 0 || i > count) return false;
    if (i == 0) {
      prepend(v);
      return true;
    }
    if (i == count) {
      append(v);
      return true;
    }
    Node* cur = Head;
    for (int j = 0; j < i - 1; j++) cur = cur->next;
    Node* n = new Node(v);
    n->next = cur->next;
    n->prev = cur;
    cur->next->prev = n;
    cur->next = n;
    count++;
    return true;
  }

  bool DeleteNode(int i) {
    if (i < 0 || i >= count || !Head) return false;
    if (i == 0) {
      DeleteFirst();
      return true;
    }
    if (i == count - 1) {
      DeleteLast();
      return true;
    }
    Node* t = Head;
    for (int j = 0; j < i; j++) t = t->next;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
    count--;
    return true;
  }

  void clear() {
    while (Head) {
      Node* n = Head->next;
      delete Head;
      Head = n;
    }
    Tail = nullptr;
    count = 0;
  }

  ~DoubleLL() { clear(); }

  DoubleLL(const DoubleLL&) = delete;
  DoubleLL& operator=(const DoubleLL&) = delete;
};

#include <iostream>

void sample_test_double_ll() {
    DoubleLL list(10);
    list.append(20);
    list.prepend(5);
    int v = 0;
    list.Get(1, v);
    std::cout << "index 1 -> " << v << " count=" << list.count << '\n';
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
    sample_test_double_ll();
    return 0;
}
#endif
