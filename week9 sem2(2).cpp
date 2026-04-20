#include <stdio.h>


void insertionSort(int arr[], int n) {
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


void bubbleSort(char arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


void quickSort(char arr[], int low, int high) {
    if(low < high) {
        int i = low, j = high;
        char pivot = arr[low];

        while(i < j) {
            while(arr[i] <= pivot && i < high) i++;
            while(arr[j] > pivot) j--;

            if(i < j) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        arr[low] = arr[j];
        arr[j] = pivot;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}


void printInt(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printChar(char arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%c ", arr[i]);
    printf("\n");
}


int main() {
    int a[] = {5, 2, 9, 1, 3};
    int b[] = {8, 4, 6, 2, 7};
    char c[] = {'d', 'a', 'c', 'b'};
    char d[] = {'z', 'x', 'm', 'a'};

    int n1 = 5, n2 = 5, n3 = 4, n4 = 4;

    // Insertion Sort
    insertionSort(a, n1);
    printf("Insertion Sort (Integers):\n");
    printInt(a, n1);

    // Bubble Sort
    bubbleSort(c, n3);
    printf("Bubble Sort (Characters):\n");
    printChar(c, n3);

    // Selection Sort
    selectionSort(b, n2);
    printf("Selection Sort (Integers):\n");
    printInt(b, n2);

    // Quick Sort
    quickSort(d, 0, n4 - 1);
    printf("Quick Sort (Characters):\n");
    printChar(d, n4);

    return 0;
}
