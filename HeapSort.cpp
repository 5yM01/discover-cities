//referenced lecture/discussion slides and Stepik problem 9.1 resources
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

vector<pair<string,int>> HeapifyDown(vector<pair<string,int>>& arr, int root, int size){
    //indices
    int leftIndex = root * 2 + 1;
    int rightIndex = root * 2 + 2;
    int swapIndex = root;

    //values
    int leftChild = arr[(root * 2) + 1].second;
    int rightChild = arr[(root * 2) + 2].second;
    int swapValue = arr[root].second;

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
    if(swapValue != arr[root].second){
        pair<string, int> temp = arr[root];
        arr[root] = arr[swapIndex];
        arr[swapIndex] = temp;
        HeapifyDown(arr,swapIndex, size);
    }
    return arr;
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

//USE THIS FUNCTION
vector<pair<string,int>> HeapSort(vector<pair<string,int>>& numbers){
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
        pair<string, int> temp = numbers[0];
        numbers[0] = numbers[m];
        numbers[m] = temp;
        heapSize--;

        //3. Make sure heap is still a heap
        numbers = HeapifyDown(numbers,0,heapSize);

        //4.repeat step 2 - for loop
    }
    return numbers;
}

