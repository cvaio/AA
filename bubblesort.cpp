#include <iostream>
#include <cstdlib>
#include <ctime>

void swap (int *a, int *b);
void bubblesortIterative (int array[], int n);
void bubblesortRecursive (int array[], int n);
void aprint (int array[], int n);

int main (void) {
    srand(time(NULL));
    int array[100] = {0};
    for (int k = 0; k < 100; k++)
        array[k] = std::rand();
    aprint(array, 100);
    bubblesortIterative(array, 100);
    aprint(array, 100);

    std::cout << std::endl;
    std::cout << std::endl;

    for (int k = 0; k < 100; k++)
        array[k] = std::rand();
    aprint(array, 100);
    bubblesortRecursive(array, 100);
    aprint(array, 100);

    return 0;
}

void swap (int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void bubblesortIterative (int array[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (array[j] > array[j+1])
                swap (&array[j], &array[j+1]);
}

void bubblesortRecursive (int array[], int n) {
    if (n == 1)
        return;
    for (int i = 0; i < n-1; i++)
        if (array[i] > array[i+1])
            swap(&array[i], &array[i+1]);
    bubblesortRecursive (array, n-1);
}

void aprint (int array[], int n) {
    std::cout << "[" << array[0];
    for(int i = 1; i < n; i++) {
        std::cout << "," << array[i];
    }
    std::cout << "]" << std::endl;
}