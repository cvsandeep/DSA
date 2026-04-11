#define HASH_SIZE 16

int Hash(const char* s) {
    int hash = 0;
    int len = strlen(s);
    
    for(int i = 0; i < len; i++) {
        hash = hash * 31 + (int)s[i];  // Better distribution
    }
    return abs(hash) % HASH_SIZE;  // Handle negative values
}
