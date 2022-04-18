//referenced lecture/discussion slides and Stepik problems
#include "HeapSort.h"

vector<int> HeapifyDown(vector<int>& arr, int root, int size){
    //indices
    int leftIndex = root * 2 + 1;
    int rightIndex = root * 2 + 2;
    int swapIndex = root;

    //values
    int leftChild = arr[(root * 2) + 1];
    int rightChild = arr[(root * 2) + 2];
    int swapValue = arr[root];

    //check for largest left-wise and check if it's a valid child index
    if(leftChild > swapValue && leftIndex < size){
        swapValue = leftChild;
        swapIndex = (root * 2) + 1;
    }
    //check for largest right-wise and check if it's a valid child index
    if(rightChild > swapValue && rightIndex < size){
        swapValue = rightChild;
        swapIndex = (root * 2) + 2;
    }
    //if one of children is larger than root, swap them and heapify
    if(swapValue != arr[root]){
        int temp = arr[root];
        arr[root] = swapValue;
        arr[swapIndex] = temp;
        HeapifyDown(arr,swapIndex, size);
    }
    return arr;
}

vector<int> ExtractMax(vector<int>& arr,vector<int>& sorted, int size){
    //remove root (max) item, put into sorted array
    sorted.push_back(arr[0]);
    arr[0] = arr[size - 1];
    arr = HeapifyDown(arr,0,size - 1);

    return arr;
}

bool isMaxHeap(vector<int>& arr, int size){
    //check every value in array against their children
    for(int i = 0; i < size; i++){
        int root = arr[i];

        if((i * 2) + 1 >= size){
            break;
        }

        int left = arr[(i * 2) + 1];
        int right = arr[(i * 2) + 2];

        if(left > root || right > root){
            return false;
        }
        else{
            continue;
        }

    }
    return true;
}

//Average Time Complexity - O(n log n)
vector<int> HeapSort(vector<int>& numbers){
    int size = numbers.size();
    vector<int> sorted;

    //1. build heap in place - O(n)
    for(int i = size/2; i >= 0; i--){
        HeapifyDown(numbers ,i, size);
    }

    int heapSize = size;
    //loop through tree - O(log n)
    for(int m = size - 1; m >= 0; m--){
        //2. while heap size > 1, swap root with last element and reduce size by 1
        int temp = numbers[0];
        numbers[0] = numbers[m];
        numbers[m] = temp;
        heapSize--;

        //3. Make sure heap is still a heap
        numbers = HeapifyDown(numbers,0,heapSize);

        //4.repeat step 2 - for loop
    }
    return numbers;
}


