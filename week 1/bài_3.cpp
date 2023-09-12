bài 3:
= Selection sort:
#include <iostream>
using namespace std;

void selectionSort(int a[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int iMin = i;
        for (int j = i + 1; j < size; ++j) {
            if (a[j] < a[iMin]) {
                iMin = j;
            }
        }
        if (iMin != i) {
            swap(a[iMin], a[i]);
        }
    }
}

- Insertion sort:
#include <iostream>
using namespace std;

void insertionSort(int a[], int size) {
    for (int i = 0; i < size; i++) {
        int j = i;
        if (j != 0) {
            while(j > 0 && a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                j--;
            }
        }
    }
}

- Bubble sort:
#include <iostream>
using namespace std;

void bubbleSort(int a[], int size) {
    int i, j, flag;
    for (i = 0; i < size - 1; i++) {
        flag = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

- Merge sort: