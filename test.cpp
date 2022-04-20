#include <iostream>
#include <iterator>
#include "HeapSort.h"
#include "ReadFile.h"

int main() {
    //vector<int> numbers = {1, 7, 5, 2, 3, 8, 9, 10, 4, 6};
    //int size = numbers.size();
//    vector<int> numbers;
//    for(int i = 0; i < 2000; i++){
//        numbers.push_back(i);
//    }
//    numbers = HeapSort(numbers);
//    for(int i = 0; i < numbers.size(); i++){
//        cout << numbers[i] << endl;
//    }

    //Heap Sort and Read File test
    string file = "geonames.csv";

    unordered_map<string, vector<pair<string,int>>> countries;
    ReadFile(file,countries);

    unordered_map<string, vector<pair<string,int>>> :: iterator iter;
    vector<pair<string,int>> sortVec = countries["Belgium"];
    HeapSort(sortVec);
    for(int i = 0; i < sortVec.size(); i++){
        cout << sortVec[i].first <<  " " << sortVec[i].second << endl;
    }

//    for(int i = 0; i < countries["Italy"].size(); i++){
//        cout << countries["Italy"][i] << endl;
//    }

    return 0;
}
