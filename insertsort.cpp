#include <iostream>
#include <cstdlib>
#include <ctime>

void insertSortIterative (int array[], int n);
void insertSortRecursive (int array[], int n);
void aprint (int array[], int n);

int main (void) {
    srand(time(NULL));
    int array[100] = {0};
    for (int k = 0; k < 100; k++)
        array[k] = std::rand();
    aprint(array, 100);
    insertSortIterative(array, 100);
    aprint(array, 100);

    std::cout << std::endl;
    std::cout << std::endl;

    for (int k = 0; k < 100; k++)
        array[k] = std::rand();
    aprint(array, 100);
    insertSortRecursive(array, 100);
    aprint(array, 100);

    return 0;
}

void insertSortIterative (int array[], int n) {
    int key = {0}, j;
    for (int i = 0; i < n; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        } array[j+1] = key;
    }
}

void insertSortRecursive (int array[], int n) {
    if (n <= 1)
        return;
    
    insertSortRecursive(array, n-1);
    int last = array[n-1],
        j = n - 2;
    
    while(j >= 0 && array[j] > last) {
        array[j+1] = array[j];
        j--;
    } array[j+1] = last;
}

void aprint (int array[], int n) {
    std::cout << "[" << array[0];
    for(int i = 1; i < n; i++) {
        std::cout << "," << array[i];
    }
    std::cout << "]" << std::endl;
}