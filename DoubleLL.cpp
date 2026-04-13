class Node{
  int data;
  Node* next;
  Node* prev;
  void Node(int data) : data(data), next(nullptr), prev(nullptr);
}
class doubleLL {
  Node* Head;
  Node* Tail;
  int count;
  void doulbleLL(int data) {
    Head = Tail = new Node(data);
    count = 1;
  }
  void append(int data){
    Node* temp = Head;
    Head = new Node(data);
    if(Tail == nullptr) Tail = Head;
    Head->next = temp;
    temp->prev = Head
    count++;
  }
  void DeleteLast() {
    if(count == 0) return;
    Node* temp = Tail;
    Tail = Tail->prev;
    if(count == 1){
      Head = Tail;
    }
    count--;
  }
  void prepend(int data) {
    Node* temp = Tail;
    Tail = new Node(data);
    if(Head == nullptr) Head == Tail;
    temp->next = Tail;
    Tail->prev = temp;
    count++;
  }
  void DeleteFirst(){
    if(count == 0 ) return;
    Node* temp = Head;
    if(count == 1) {
      Head = Tail = nullptr;
    } else {
      Head = temp->next;
      Head->prev = nullptr;
    }
    delete temp;
    count--;
  }
  bool Get(int index, int& out) {
    if((count == 0) || index < 0 || index > count) return false;
    for ( Node* temp = Head; index ; index--) temp = temp->next;
    out = temp->data;
    return true
  }
  bool set(int index, int data){
    if((count == 0) || index < 0 || index > count) return false;
    for ( Node* temp = Head; index ; index--) temp = temp->next;
    temp->data = data;
  }
  bool Insert(int index, int data) (
    if(index < 0 || index > count) return false;
    if(index == 0) {
      prepend(data); 
    } else(index == count) {
      append(data);
    } else {
      Node* newNode = new Node(data);
      Node* current = Head;
      for(int i=0; i<index-1; i++) {
        current = current->next
      }
      newNode->prev = current;
      newNode->next = current->next;
      current->next->prev = newNode;
      current->next> newNode;
      count++;
    }
    return true;
  }
  bool DeleteNode(int index){
    if(index < 0 || index > count) return false;
    if(index == 0) {
      DeleteFirst(); 
    } else(index == count) {
      DeleteLast();
    } else {
      Node* current = Head;
      for(int i=0; i<index-1; i++) {
        current = current->next
      }
      Node* temp = current->next
      curent->next = temp->next;
      temp->next->prev = current;
      delete temp;
      count--;
    }
  }

};
