class Node{
  int data;
  Node* next;
  Node(int data) {
    self->data = data;
    self->next = nullptr;
  }
};

class SingleLL {
  piblic:
    Node* Head;
    int count; \\ Optional
  
    SingleLL(int value){
      Head = new Node(value);
      Tail = Head;
      count = 1;
    }
    void append(int value){ //Insert at Last
      if (Head == nullptr) SingleLL(value); // Linked list is Empty
      Node* temp = Head;
      while(temp->next == nullptr) temp = temp->next;
      temp->next == new Node(value);
      count++;
    }   
        
    Node* removeLast(){
      if (Head == nullptr) return nullptr // Linked list is Empty
      Node* temp = Head;
      while(temp->next == nullptr) temp = temp->next;
      delete temp;
      temp = nullptr;
      count--;
    }

    void prepend(int value){
      Node* newNode = new Node(value);
      newNode->next = Head;
      count++;
    }
    bool insert(int index, int value){
      if(index > count) return false;
      
    }
    Node* remove(int index);
};
