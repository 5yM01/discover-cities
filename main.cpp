#include <iostream>
#include <iterator>
#include <chrono>
#include "HeapSort.h"
#include "quickSort.h"
#include "ReadFile.h"

//code for using chrono execution time from geeksforgeeks.org

//Print Vector Function
void printVector(vector<pair<string, int>> cities, string country) {
    cout << "---------------------------------------------" << endl;
    cout << "Future Cities Populations in " << country << endl;
    for (unsigned int i = 0; i < cities.size(); i++) {
        cout <<"City: "<< cities[i].first << ", Population: " << cities[i].second << endl;
    }
    cout << "---------------------------------------------" << endl;
}

int main() {
    string file = "geonames.csv";
    unordered_map<string, vector<pair<string, int>>> countries;
    ReadFile(file, countries);

    bool endProgram = false;
    //User input with programs features: QS or HS
    while (endProgram != true) {
        int input;
        cout << "Which feature would you like to use:" << endl;
        cout << "1. Find largest city by population in a country" << endl;
        cout << "2. Compare population of two cities to find the largest" << endl;
        cout << "0. Exit" << endl;
        cin >> input;
        cin.ignore();

        switch (input) {
            //Largest Population while sorting the population of all cities in country
            case 1: {
                string city;
                string country;
                cout << "Which city do you want to find the population?" << endl;
                getline(cin, city);
                cout << "What country is " << city << " in?" << endl;
                getline(cin, country);

                //Make sub vector with country and sort by cities in country
                vector<pair<string, int>> sortVec = countries[country];

                cout << "Which method do you want to use to find the population of "<< city <<", " <<country << "?" << endl;
                cout << "Method 1. Heap Sort" << endl;
                cout << "Method 2. Quick Sort" << endl;
                cin >> input;
                switch (input) {

                    case 1:
                    {
                        //measure execution time
                        cout << "Calling heap sort" << endl;
                        auto start = std::chrono::high_resolution_clock::now();
                        HeapSort(sortVec);
                        auto stop = std::chrono::high_resolution_clock::now();
                        auto duration = std :: chrono :: duration_cast<std::chrono::microseconds>(stop - start);

                        //PRINT SORTED VECTOR
                        printVector(sortVec, country);
                        cout << "Time taken to sort by Heap Sort: " << duration.count() << " microseconds" << endl;

                        //Print CITY WITH LARGEST POPULATION
                        cout << "City with largest population in " << country << " is " << sortVec[sortVec.size() - 1].first << " with a population of " << sortVec[sortVec.size() - 1].second << endl;
                        cout << endl;
                        break;
                    };

                    case 2:
                    {
                        //measure execution time
                        cout << "Calling quick sorts" << endl;
                        int endRoot = sortVec.size();
                        auto start = std::chrono::high_resolution_clock::now();
                        quickSort(sortVec, 0, endRoot - 1);
                        auto stop = std::chrono::high_resolution_clock::now();
                        auto duration = std :: chrono :: duration_cast<std::chrono::microseconds>(stop - start);

                        //PRINT SORTED VECTOR
                        printVector(sortVec, country);
                        cout << "Time taken to sort by Quick Sort: " << duration.count() << " microseconds" << endl;

                        //Print CITY WITH LARGEST POPULATION
                        cout << "City with largest population in " << country << " is " << sortVec[sortVec.size() - 1].first << " with a population of " << sortVec[sortVec.size() - 1].second << endl;
                        cout << endl;
                        break;
                    };
                    default: {
                        break;
                    };
                }

                endProgram = false;
                break;
            };

            //Compare populations
            case 2: {
                string city1, country1;
                cout << "What is the first city you want to compare?" << endl;
                getline(cin, city1);

                cout << "What country is " << city1 << " in?" << endl;
                getline(cin, country1);

                //SUB VECTOR WITH ALL CITIES IN COUNTRY
                vector<pair<string, int>> sortVec1 = countries[country1];

                cout << "What is the second city you want to compare to " << city1 << ", " << country1 << "?" << endl;
                string country2, city2;
                getline(cin, city2);
                cout << "What country is " << city2 << " in?" << endl;
                getline(cin, country2);

                //SUB VECTOR WITH ALL CITIES IN COUNTRY
                vector<pair<string, int>> sortVec2 = countries[country2];

                cout << "Which method do you want to use to compare "<< city1 <<","<<country1 << " and "<< city2<<", "<<country2 <<"?" << endl;
                cout << "Method 1. Heap Sort" << endl;
                cout << "Method 2. Quick Sort" << endl;
                cin >> input;
                switch (input) {
                    case 1: {
                        //get execution time of 1st sort
                        cout << "Calling heap sorts" << endl;
                        auto start = std::chrono::high_resolution_clock::now();
                        HeapSort(sortVec1);
                        auto stop = std::chrono::high_resolution_clock::now();
                        auto duration = std :: chrono :: duration_cast<std::chrono::microseconds>(stop - start);

                        //get execution time of 2nd sort
                        auto start2 = std::chrono::high_resolution_clock::now();
                        HeapSort(sortVec2);
                        auto stop2 = std::chrono::high_resolution_clock::now();
                        auto duration2 = std :: chrono :: duration_cast<std::chrono::microseconds>(stop2 - start2);

                        //PRINT BOTH SORTED VECTORS
                        printVector(sortVec1, country1);
                        printVector(sortVec2, country2);

                        //COMPARE CITIES POPULATION AND PRINT BIGGER POPULATION
                        string bigCity;
                        string smallCity;
                        int population1;
                        int population2;
                        vector<pair<string, int>> :: iterator iter;
                        vector<pair<string, int>> :: iterator iter2;

                        //go through vector 1
                        for(iter = sortVec1.begin(); iter != sortVec1.end(); iter++){
                            if(iter->first == city1){
                                population1 = iter->second;
                                break;
                            }
                        }

                        //go through vector 2
                        for(iter2 = sortVec2.begin(); iter2 != sortVec2.end(); iter2++){
                            if(iter2->first == city2){
                                population2 = iter->second;
                                break;
                            }
                        }

                        //compare populations
                        if(population1 > population2){
                            bigCity = city1;
                            smallCity = city2;
                        }
                        else{
                            bigCity = city2;
                            smallCity = city1;
                        }

                        cout << "First Heap Sort takes " << duration.count() << " microseconds" << endl;
                        cout << "Second Heap Sort takes " << duration2.count() << " microseconds" << endl;
                        cout << bigCity << " has a bigger population than " << smallCity << endl;
                        cout << endl;
                        break;
                    };

                    case 2: {
                        //get execution time of 1st sort
                        cout << "Calling quick sort" << endl;
                        int endRoot1 = sortVec1.size();
                        auto start = std::chrono::high_resolution_clock::now();
                        quickSort(sortVec1, 0, endRoot1 - 1);
                        auto stop = std::chrono::high_resolution_clock::now();
                        auto duration = std :: chrono :: duration_cast<std::chrono::microseconds>(stop - start);
                        printVector(sortVec1, country1);

                        //get execution time of 2nd sort
                        int endRoot2 = sortVec2.size();
                        auto start2 = std::chrono::high_resolution_clock::now();
                        quickSort(sortVec2, 0, endRoot2 - 1);
                        auto stop2 = std::chrono::high_resolution_clock::now();
                        auto duration2 = std :: chrono :: duration_cast<std::chrono::microseconds>(stop2 - start2);
                        printVector(sortVec2, country2);


                        //COMPARE CITIES POPULATION AND PRINT BIGGER POPULATION
                        string bigCity;
                        string smallCity;
                        int population1;
                        int population2;
                        vector<pair<string, int>> :: iterator iter;
                        vector<pair<string, int>> :: iterator iter2;

                        //go through vector 1
                        for(iter = sortVec1.begin(); iter != sortVec1.end(); iter++){
                            if(iter->first == city1){
                                population1 = iter->second;
                                break;
                            }
                        }

                        //go through vector 2
                        for(iter2 = sortVec2.begin(); iter2 != sortVec2.end(); iter2++){
                            if(iter2->first == city2){
                                population2 = iter->second;
                                break;
                            }
                        }

                        if(population1 > population2){
                            bigCity = city1;
                            smallCity = city2;
                        }
                        else{
                            bigCity = city2;
                            smallCity = city1;
                        }

                        cout << "First Quick Sort takes " << duration.count() << " microseconds" << endl;
                        cout << "Second Quick Sort takes " << duration2.count() << " microseconds" << endl;
                        cout << bigCity << " has a bigger population than " << smallCity << endl;
                        cout << endl;

                        break;
                    };
                    default: {
                        break;
                    };
                }
                endProgram = false;
                break;
            };
            case 0: {
                //Breaks while loop and ends code
                endProgram = true;
                break;
            };
            default: {
                cout << "Input a valid integer." << endl;
                endProgram = false;
                break;
            };
        }
    }

    return 0;
}
