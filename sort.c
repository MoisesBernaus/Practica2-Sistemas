#include <stdint.h>

#define N 12

void sort (int8_t a[], int size) {
    for(int i = size; i > 1; i--) {
        for(int j = 0; j < i - 1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

}

void checkSort() {

     int8_t	array[N];
     int i;
    for (i = 0; i < N; ++i){
               // Assume numbers in array are integers in range [0,16]
        __CPROVER_assume(array[i] >= 0 && array[i] <= 16);
    }

    sort (array, N);

    // write the assertions to check that the array is sorted
    for(int i =0; i < N - 1; i++) {
        __CPROVER_assert(array[i] <= array[i + 1], "Check for all a[i] the next is upper than the next");
    }
}

int main() {
    checkSort();
}
