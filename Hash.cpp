#define HASH_SIZE 16
class Node {
    public: 
        string key;
        int value;
        Node* next;
    Node(string key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};
class HashTable {
    private: 
        Node* HashMap[HASH_SIZE]; //std::array<Node*, HASH_SIZE> HashMap;
        int Hash(string s) {
            int hash = 0;
            int len = strlen(s);
            
            for(int i = 0; i < len; i++) {
                hash = hash * 31 + (int)s[i];  // Better distribution
                //hash = (hash + (int)s[i] *  23) % HASH_SIZE; // Since 23 is prime Number
            }
            return abs(hash) % HASH_SIZE;  // Handle negative values
        }
    deleteLL(Node* current){
        if(current == nullptr) return;
        delete(current->next)
        delete current;
    }
    
    public: 
        HashTable(){
            HashMap.fill(nullptr);
        }
        ~HashTable(){
            for(auto& bucket : HashMap) {  // Range-based for
                deleteLL(bucket);
                bucket = nullptr;
            }
        }
        void set(const string key,const int value) {
            int index = Hash(key);
            Node* current = HashMap[index];
            while(current != nullptr) { // Check if Key already exists and update the value if it is.
                if(current->key == key) {
                    current->value = value;
                    return;
                }
                current = current->next;
            }
            // Key doesn't exist, insert new node at head
            Node* newNode = new Node(key,value);
            newNode->next = HashMap[index];
            HashMap[index] = newNode;
        }
        int get(const string key) {
            int index = Hask(key);
             while(current != nullptr) { 
                if(current->key == key) return current->value;
                current = current->next;
            }
            return 0;
        }
    vector<string> keys() {
        vector<string> allkeys;
        for(int i=0; i<HASH_SIZE; i++) {
            Node* temp = HashMap[i];
            while(temp != nullptr) {
                allkeys.pushback(temp->key);
                temp = temp->next;
            }
        }
        return allkeys;
    }
};


