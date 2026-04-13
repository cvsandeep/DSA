class Node{
    public: 
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};
class Stack{
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
        if(height == 0) return -1;
        Node* temp = top;
        top = top->next;
        delete temp;
        height--;
        return temp->data;
    }
    int peek() {
        if(height == 0) return -1;
        return top->data;  
    }
    bool isEmpty() {
        return height == 0;
    }
    int size() {
        return height;
    }
    void print() {
        Node* temp = top;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    };
    ~Stack() {
        while(top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        height = 0;
    }
    Stack(const Stack& other) {
        top = other.top;
        height = other.height;
    }
    Stack& operator=(const Stack& other) {
        if(this != &other) {
            top = other.top;
            height = other.height;
        }
    }
};