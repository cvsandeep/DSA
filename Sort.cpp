#include <iostream>
#include <vector>
using namespace std;
class Sort{
    public:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for(int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

void sample_test_sort() {
    Sort s;
    std::vector<int> a = {5, 2, 8, 1, 9};
    std::vector<int> b = a, c = a;
    s.bubbleSort(a);
    s.selectionSort(b);
    s.insertionSort(c);
    std::cout << "bubble: ";
    for (int x : a) std::cout << x << ' ';
    std::cout << "\nselection: ";
    for (int x : b) std::cout << x << ' ';
    std::cout << "\ninsertion: ";
    for (int x : c) std::cout << x << ' ';
    std::cout << '\n';
}

#if defined(SAMPLE_TEST_MAIN)
int main() {
    sample_test_sort();
    return 0;
}
#endif
