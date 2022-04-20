#include <string>
#include <iostream>
#include "quickSort.h"
#include "ReadFile.h"
using namespace std;

//Compare Function
//Print Vector Function
void printVector(vector<pair<string, int>> cities, string country) {
    cout << "---------------------------------------------" << endl;
    cout << "Future Cities Populations in " << country << endl;
    for (unsigned int i = 0; i < cities.size(); i++) {
        cout <<"City: "<< cities[i].first << ", Population: " << cities[i].second << endl;
    }
    cout << "---------------------------------------------" << endl;
}

int main()
{
    string file = "geonames.csv";
    unordered_map<string, vector<pair<string, int>>> countries;
    ReadFile(file, countries);

    //vector<pair<string, int>> sortVec2 = countries["United States"];
    //int endRoot = sortVec2.size();
    //quickSort(sortVec2, 0, endRoot - 1);
    //for (unsigned int i = 0; i < sortVec2.size(); i++) {
        //cout << sortVec2[i].first << " " << sortVec2[i].second << endl;
    //}


    /*TESTING
    vector<int> numbers;
    for(int i = 0; i < 2000; i++){
        numbers.push_back(i);
    }
    int size = numbers.size();
    quickSort(numbers, 0, size-1);
    for(unsigned int i = 0; i < numbers.size(); i++){
       cout << numbers[i] << endl;
    }
    unordered_map<string, vector<pair<string, int>>> ::iterator iter;
    vector<pair<string, int>> sortVec = countries[country];
    int endRoot = sortVec.size();
    quickSort(sortVec, 0, endRoot-1);

    //printing
    for (unsigned int i = 0; i < sortVec.size(); i++) {
        cout << sortVec[i].first << " " << sortVec[i].second << endl;
    }

    
    //TESSTING QUICK SORT
    //Get the input data
    cout << "Enter Size of array: " << endl;
    cin >> size;
    int* myarray = new int[size];

    //Read the data and store it into a ....
    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> myarray[i];
    }
    quickSort(myarray, 0, size - 1);
    printCities(myarray, size);
    */
    
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
                    cout << "Calling heap sort" << endl;
                    //HeapSort(sortVec);
                    //PRINT SORTED VECTOR
                    //Print CITY WITH LARGEST POPULATION

                    break;
                };

                case 2:
                {
                    cout << "Calling quick sort" << endl;
                    int endRoot = sortVec.size();
                    quickSort(sortVec, 0, endRoot - 1);
                    printVector(sortVec, country);
                    
                    
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


                cout << "What is the second city you want to " << city1 << ", " << country1 << "?" << endl;
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
                    cout << "Calling heap sort" << endl;
                    //HeapSort(sortVec1);
                    //HeapSort(sortVec2);
                    //PRINT BOTH SORTED VECTORS
                    //COMPARE CITIES POPULATION AND PRINT BIGGERR POPULATION
                    break;
                };

                case 2: {
                    cout << "Calling quick sort" << endl;
                    int endRoot1 = sortVec1.size();
                    quickSort(sortVec1, 0, endRoot1 - 1);
                    printVector(sortVec1, country1);

                    int endRoot2 = sortVec2.size();
                    quickSort(sortVec2, 0, endRoot2 - 1);
                    printVector(sortVec2, country2);
                    //COMPARE CITIES POPULATION PRINT BIGGER POPULATION


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
}

