# Sorting Algorithms

## Topics
1. [Bubble Sort](#bubble-sort)
2. [Selection Sort](#selection-sort)
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
out put
```
iteration 1 : 2 3 4 5 8 1 6 0 7 9 
iteration 2 : 2 3 4 5 1 6 0 7 8 9 
iteration 3 : 2 3 4 1 5 0 6 7 8 9 
iteration 4 : 2 3 1 4 0 5 6 7 8 9 
iteration 5 : 2 1 3 0 4 5 6 7 8 9 
iteration 6 : 1 2 0 3 4 5 6 7 8 9 
iteration 7 : 1 0 2 3 4 5 6 7 8 9 
iteration 8 : 0 1 2 3 4 5 6 7 8 9 
iteration 9 : 0 1 2 3 4 5 6 7 8 9
```
## Selection Sort

Selection Sort repeatedly finds the smallest (or largest) element from the unsorted portion of the array and swaps it with the first unsorted element. It’s simple, but not efficient for large datasets.

```cpp
#include <iostream>

void print(int *arr,int size,int iter){
    std::cout<<"iteration "<<iter<<" : ";
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

void selection_sort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        int m=i;
        for(int j=i+1;j<size;j++){
            if(arr[m]>arr[j]){
            m=j;  
            }
        }
        std::swap(arr[m],arr[i]);
        print(arr, size, i + 1);
    }
}

int main()
{
    int arr[]={2,4,3,5,9,8,1,6,0,7}; 
    int arr2[]={0,1,2,3,4,5,6,7,8,9};
    selection_sort(arr,10);
    return 0;
}
```
out put
```
iteration 1 : 0 4 3 5 9 8 1 6 2 7 
iteration 2 : 0 1 3 5 9 8 4 6 2 7 
iteration 3 : 0 1 2 5 9 8 4 6 3 7 
iteration 4 : 0 1 2 3 9 8 4 6 5 7 
iteration 5 : 0 1 2 3 4 8 9 6 5 7 
iteration 6 : 0 1 2 3 4 5 9 6 8 7 
iteration 7 : 0 1 2 3 4 5 6 9 8 7 
iteration 8 : 0 1 2 3 4 5 6 7 8 9 
iteration 9 : 0 1 2 3 4 5 6 7 8 9
```
