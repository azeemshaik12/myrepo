# Sorting Algorithms

## Topics
1. [Bubble Sort](#bubble-sort)
2. [Quick Sort](#quick-sort)
3. [Merge Sort](#merge-sort)

---

## Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

### Bubble Sort Code Example

```cpp
#include <iostream>

void print(int *arr, int size, int iter) {
    std::cout << "iteration " << iter << " : ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void bubble_sort(int *arr, int size) {
    bool swaped = false;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }
        print(arr, size, i + 1);
        if (!swaped) break;
    }
}

int main() {
    int arr[] = {2, 4, 3, 5, 9, 8, 1, 6, 0, 7};
    int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bubble_sort(arr2, 10);
    return 0;
}
```
## Quick Sort
