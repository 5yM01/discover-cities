#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool isMaxHeap(vector<int>& arr, int size);
vector<int> ExtractMax(vector<int>& arr,vector<int>& sorted, int size);
vector<int> HeapifyDown(vector<int>& arr, int index, int size);
vector<int> HeapSort(vector<int>& numbers);
