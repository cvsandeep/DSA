#include <array>
#include <iostream>
#include <string>
#include <vector>

#define HASH_SIZE 16

class Node {
 public:
  std::string key;
  int value;
  Node* next;
  Node(std::string k, int v) : key(std::move(k)), value(v), next(nullptr) {}
};

class HashTable {
  std::array<Node*, HASH_SIZE> HashMap{};

  static int indexFor(const std::string& s) {
    unsigned h = 0;
    for (unsigned char c : s) h = h * 31u + c;
    return static_cast<int>(h % HASH_SIZE);
  }

  static void deleteLL(Node* cur) {
    while (cur) {
      Node* n = cur->next;
      delete cur;
      cur = n;
    }
  }

 public:
  HashTable() { HashMap.fill(nullptr); }

  ~HashTable() {
    for (Node* b : HashMap) deleteLL(b);
  }

  void set(const std::string& key, int value) {
    int idx = indexFor(key);
    for (Node* cur = HashMap[idx]; cur; cur = cur->next) {
      if (cur->key == key) {
        cur->value = value;
        return;
      }
    }
    Node* n = new Node(key, value);
    n->next = HashMap[idx];
    HashMap[idx] = n;
  }

  int get(const std::string& key) const {
    int idx = indexFor(key);
    for (Node* cur = HashMap[idx]; cur; cur = cur->next)
      if (cur->key == key) return cur->value;
    return 0;
  }

  std::vector<std::string> keys() const {
    std::vector<std::string> out;
    for (Node* head : HashMap) {
      for (Node* t = head; t; t = t->next) out.push_back(t->key);
    }
    return out;
  }
};

void sample_test_hash() {
    HashTable t;
    t.set("a", 1);
    t.set("b", 2);
    t.set("a", 10);
    std::cout << "a=" << t.get("a") << " b=" << t.get("b") << '\n';
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
    sample_test_hash();
    return 0;
}
#endif
