#include <iostream>

class Node {
 public:
  int data;
  Node* next;
  Node(int d) : data(d), next(nullptr) {}
};

class Stack {
 public:
  Node* top;
  int height;

  Stack() : top(nullptr), height(0) {}

  void push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height++;
  }

  int pop() {
    if (height == 0) return -1;
    Node* temp = top;
    int v = temp->data;
    top = top->next;
    delete temp;
    height--;
    return v;
  }

  int peek() const {
    if (height == 0) return -1;
    return top->data;
  }

  bool isEmpty() const { return height == 0; }
  int size() const { return height; }

  void print() const {
    for (Node* t = top; t; t = t->next)
      std::cout << t->data << ' ';
    std::cout << '\n';
  }

  ~Stack() {
    while (top) {
      Node* t = top;
      top = top->next;
      delete t;
    }
    height = 0;
  }

  Stack(const Stack&) = delete;
  Stack& operator=(const Stack&) = delete;
};

void sample_test_stack() {
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << "peek=" << s.peek() << " pop=" << s.pop()
              << " size=" << s.size() << '\n';
    s.print();
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
    sample_test_stack();
    return 0;
}
#endif
