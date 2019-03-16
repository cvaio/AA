#include <iostream>
#include <cstdlib>
#include <ctime>

void merge(int left[], int right[], int array[], int sl, int sr);
void mergesort (int array[], int l, int r);
void aprint (int array[], int n);

int main (void) {
    srand(time(NULL));

    int array[100] = {0};

    for (int k = 0; k < 100; k++)
        array[k] = std::rand();

    aprint(array, 100);
    mergesort(array, 0, 99);
    aprint(array, 100);

    return 0;
}

void merge(int array[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l+i];
    for (j = 0; j < n2; j++)
        R[j] = array[m+1+j];

    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    } while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    } while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergesort (int array[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergesort(array, l, m);
        mergesort(array, m+1, r);
        merge(array, l, m, r);
    }
}

void aprint (int array[], int n) {
    std::cout << "[" << array[0];
    
    for(int i = 1; i < n; i++) {
        std::cout << "," << array[i];
    }
    
    std::cout << "]" << std::endl;
}