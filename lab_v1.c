#include <stdio.h>
#include "stdlib.h"
#include <time.h>

#define N   16

void sorting_choice (int A[], int n);
void init_array (int A[], int n);
void print_array (const int A[], int n);

int main(void) {
    int   ARR[N];
    init_array (ARR, N);
    printf ("Elements in an array : \n");
    print_array (ARR, N);
    sorting_choice(ARR, N);
    printf("Sorted array : \n");
    print_array (ARR, N);
    printf ("\n");
    return 0;
}

void sorting_choice(int A[], int n) {
    for (int i = 0; i < N; i++) {
        int i_min = i;
        int j;
        for (j = i; j < N; j++) {
            i_min = A[j] < A[i_min] ? j : i_min;
            }
        int tmp = A[i_min];
        for (j = i_min; j > i - 1; j--) {
            A[j] = A[j - 1];
        }
        A[i] = tmp;
    }
}

void init_array (int A[], int n) {
    srand (time(NULL)); 
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
}

void print_array (const int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf ("%4d", A[i]);
    }
    printf ("\n");
}
