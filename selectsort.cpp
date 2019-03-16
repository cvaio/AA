#include <iostream>
#include <cstdlib>
#include <ctime>

void swap (int *a, int *b);
void selectsort (int array[], int n);
void aprint (int array[], int n);

int main (void) {
    srand(time(NULL));

    int array[100] = {0};

    for (int k = 0; k < 100; k++)
        array[k] = std::rand();

    aprint(array, 100);
    selectsort(array, 100);
    aprint(array, 100);

    return 0;
}

void swap (int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void selectsort (int array[], int n) {
    int i, j , min_idx;

    for(i = 0; i < n-1; i++) {
        min_idx = i;

        for(j = i+1; j < n; j++)
            if (array[j] < array[min_idx])
                min_idx = j;

        swap(&array[min_idx], &array[i]); 
    }
}

void aprint (int array[], int n) {
    std::cout << "[" << array[0];
    
    for(int i = 1; i < n; i++) {
        std::cout << "," << array[i];
    }
    
    std::cout << "]" << std::endl;
}