#include <stdio.h>
#include "stdlib.h"
#include <time.h>

#define N   16

void sorting_choice(int A[], int n, int order);
void init_array (int A[], int n);
void print_array (const int A[], int n);

int main(void) {
    int   ARR[N];
    int order;
    init_array (ARR, N);
    printf ("Elements in an array : \n");
    print_array (ARR, N);
    printf("Sorting order? (Ascending/descending) = 1 or 0 : ");
    scanf ("%d", &order);
    sorting_choice(ARR, N, order);
    printf("Sorted array : \n");
    print_array (ARR, N);
    printf ("\n");
    return 0;
}

void sorting_choice(int A[], int n, int order) {
    for (int i = 0; i < N; i++) {
        int index = i;
        int j;
        for (j = i; j < N; j++) {
            if (order == 0) index = A[j] > A[index] ? j : index;
            else index = A[j] < A[index] ? j : index;
        }
        int tmp = A[index];
        for (j = index; j > i - 1; j--) {
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
