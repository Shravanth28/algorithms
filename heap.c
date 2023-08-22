#include <stdio.h>
#include <malloc.h>
#include <time.h>

void heapify(int *arr, int n, int i){
    int largest = i, left = 2*i + 1, right = 2*i + 2, temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n){
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main(){
    int n, *arr, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    clock_t start_time = clock();

    heapSort(arr, n);

    clock_t end_time = clock();

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting: %f seconds\n", time_taken);

    return 0;
}
