#include <iostream>
#include <string>
#include <vector>
using namespace std;

//CHANGE TO USE A VECTOR
//Splitting the array from the pivot
int partition(vector<int>& arr, int start, int end)
{
    //create a pivot with the start value
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    //Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    //Sorting left and right parts of the pivot element
    int leftSide = start;
    int rightSide = end;

    while (leftSide < pivotIndex && rightSide > pivotIndex) {

        while (arr[leftSide] <= pivot) {
            leftSide++;
        }

        while (arr[rightSide] > pivot) {
            rightSide--;
        }

        if (leftSide < pivotIndex && rightSide > pivotIndex) {
            swap(arr[leftSide++], arr[rightSide--]);
        }
    }

    return pivotIndex;
}

//modified to take in pair vector
int partition(vector<pair<string,int>>& arr, int start, int end)
{
    //create a pivot with the start value
    int pivot = arr[start].second;

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i].second <= pivot)
            count++;
    }

    //Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    //Sorting left and right parts of the pivot element
    int leftSide = start;
    int rightSide = end;

    while (leftSide < pivotIndex && rightSide > pivotIndex) {

        while (arr[leftSide].second <= pivot) {
            leftSide++;
        }

        while (arr[rightSide].second > pivot) {
            rightSide--;
        }

        if (leftSide < pivotIndex && rightSide > pivotIndex) {
            swap(arr[leftSide++], arr[rightSide--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int>& arr, int start, int end)
{
    //Checks if the sort is valid to be able to sort
    if (start >= end){
        return;
    }
    //Partitioning the array
    int p = partition(arr, start, end);
    //Sorting the left part
    quickSort(arr, start, p - 1);
    //Sorting the right part
    quickSort(arr, p + 1, end);
}

//modified to take in pair vector
void quickSort(vector<pair<string,int>>& arr, int start, int end)
{
    //Checks if the sort is valid to be able to sort
    if (start >= end){
        return;
    }
    //Partitioning the array
    int p = partition(arr, start, end);
    //Sorting the left part
    quickSort(arr, start, p - 1);
    //Sorting the right part
    quickSort(arr, p + 1, end);
}