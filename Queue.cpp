class Node{
    public:
    int data;
    Node* next;
    void Node(int data) : data(data), next(nullptr) {}
}

class Queue{
    private:
    Node* first;
    Node* last;
    int length;
    public: 
        Queue(int value) {
            first = last = new Node(value);
            length = 1;
        }
        ~Queue() {  
            Node* temp = first;
            while(temp != nullptr) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
            length = 0;
        }
        void enqueue(int value) {
            Node* newNode = new Node(value);
            if(length == 0) {
                first = last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
            length++;
        }
        int dequeue() {
            if(length == 0) return -1;
            if(length == 1) {
                int dequeuedValue = first->data;
                delete first;
                first = last = nullptr;
                length = 0;
                return dequeuedValue;
            } else {
                int dequeuedValue = first->data;
                first = first->next;
                delete first;
                length--;
                return dequeuedValue;
            }
        }   
        void getFirst() {
            return first->data;
        }
        void getLast() {
            return last->data;
        }
        void getLength() {
            return length;
        }
}