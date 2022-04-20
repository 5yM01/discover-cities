#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> HeapifyDown(vector<int>& arr, int index, int size);
vector<pair<string,int>> HeapifyDown(vector<pair<string,int>>& arr, int root, int size);
vector<int> HeapSort(vector<int>& numbers);

//USE THIS FUNCTION
vector<pair<string,int>> HeapSort(vector<pair<string,int>>& numbers);
