#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }

        while (i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int *elements = (int *) malloc(N * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &elements[i]);
    }

    printf("Unsorted elements: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");


    quickSort(elements, 0, N - 1);

    printf("Sorted elements of Quick sort: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");


    free(elements);

    return 0;
}
