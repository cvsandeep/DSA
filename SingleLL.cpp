#include <iostream>

class Node {
 public:
  int data;
  Node* next;
  Node(int d) : data(d), next(nullptr) {}
};

class SingleLL {
 public:
  Node* Head;
  int count;

  SingleLL(int v) {
    Head = new Node(v);
    count = 1;
  }

  void append(int v) {
    if (!Head) {
      Head = new Node(v);
      count = 1;
      return;
    }
    Node* t = Head;
    while (t->next) t = t->next;
    t->next = new Node(v);
    count++;
  }

  void removeLast() {
    if (!Head) return;
    if (!Head->next) {
      delete Head;
      Head = nullptr;
      count = 0;
      return;
    }
    Node* t = Head;
    while (t->next->next) t = t->next;
    delete t->next;
    t->next = nullptr;
    count--;
  }

  void prepend(int v) {
    Node* n = new Node(v);
    n->next = Head;
    Head = n;
    count++;
  }

  bool insert(int i, int v) {
    if (i < 0 || i > count) return false;
    if (i == 0) {
      prepend(v);
      return true;
    }
    if (i == count) {
      append(v);
      return true;
    }
    Node* t = Head;
    for (int j = 0; j < i - 1; j++) t = t->next;
    Node* n = new Node(v);
    n->next = t->next;
    t->next = n;
    count++;
    return true;
  }

  bool remove(int i) {
    if (i < 0 || i >= count || !Head) return false;
    if (i == 0) {
      Node* t = Head;
      Head = Head->next;
      delete t;
    } else {
      Node* p = Head;
      for (int j = 0; j < i - 1; j++) p = p->next;
      Node* t = p->next;
      p->next = t->next;
      delete t;
    }
    count--;
    return true;
  }

  bool empty() const { return !Head; }

  bool get(int i, int& out) const {
    if (i < 0 || i >= count || !Head) return false;
    Node* t = Head;
    for (int j = 0; j < i; j++) t = t->next;
    out = t->data;
    return true;
  }

  int indexOf(int v) const {
    int i = 0;
    for (Node* t = Head; t; t = t->next, i++)
      if (t->data == v) return i;
    return -1;
  }

  void print() const {
    for (Node* t = Head; t; t = t->next)
      std::cout << t->data << (t->next ? " " : "");
    std::cout << "\n";
  }

  void clear() {
    while (Head) {
      Node* t = Head;
      Head = Head->next;
      delete t;
    }
    count = 0;
  }

  ~SingleLL() { clear(); }

  SingleLL(const SingleLL&) = delete;
  SingleLL& operator=(const SingleLL&) = delete;
};

void sample_test_single_ll() {
    SingleLL list(1);
    list.append(2);
    list.prepend(0);
    std::cout << "list: ";
    list.print();
    int x = 0;
    if (list.get(2, x)) std::cout << "index 2 -> " << x << '\n';
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
    sample_test_single_ll();
    return 0;
}
#endif
