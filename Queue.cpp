class Node {
 public:
  int data;
  Node* next;
  Node(int d) : data(d), next(nullptr) {}
};

class Queue {
  Node* first;
  Node* last;
  int length;

 public:
  Queue(int value) {
    first = last = new Node(value);
    length = 1;
  }

  ~Queue() {
    for (Node* t = first; t;) {
      Node* n = t->next;
      delete t;
      t = n;
    }
    first = last = nullptr;
    length = 0;
  }

  void enqueue(int value) {
    Node* newNode = new Node(value);
    if (length == 0) {
      first = last = newNode;
    } else {
      last->next = newNode;
      last = newNode;
    }
    length++;
  }

  int dequeue() {
    if (length == 0) return -1;
    Node* old = first;
    int v = old->data;
    first = first->next;
    if (length == 1) last = nullptr;
    delete old;
    length--;
    return v;
  }

  int getFirst() const { return first ? first->data : -1; }
  int getLast() const { return last ? last->data : -1; }
  int getLength() const { return length; }
};

#include <iostream>

void sample_test_queue() {
    Queue q(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "front=" << q.getFirst() << " back=" << q.getLast()
              << " len=" << q.getLength() << '\n';
    while (q.getLength() > 0)
        std::cout << "dequeue " << q.dequeue() << '\n';
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
    sample_test_queue();
    return 0;
}
#endif
