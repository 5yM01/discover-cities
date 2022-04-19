#include "quickSort.h"
#include <iostream>
using namespace std;

//Print sorted array
//Fix to print better
/*
void printCities(int arr[], int size) {
    cout << "Cites in" << country << "in decneding order for population." << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}
*/

int main()
{
    int size = 0;

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
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }
    cout << endl;

    return 0;
    /*
    bool endProgram = false;
    //User input with programs features: QS or HS
    while (endProgram != true) {
    int input;
    cout << "Which feature would you like to use:" << endl;
    cout << "1. Find largest city by population in a country" << endl;
    cout << "2. Compare population of two cities to find the largest" << endl;
    cout << "0. Exit" << endl;
    cin >> input;

    switch (input) {
    //Largest Population while sorting the population of all cities in country

    /*
        -Printing function to print Vector with all its data
        -How to read function
        -Making a sub vector for smaller cities
        -Quick Sort algortihim


    case 1:
        //Find which country
        cout << "which city in what country do you want to find the population" << endl;
        //Make sub vector with country and sort by cities in country
        //FIND SIZE TO USE FOR SORTING

        cout << "Which method to find largest city" << endl;
        cout << "Method 1. Heap Sort" << endl;
        cout << "Method 2. Quick Sort" << endl;
        cin >> input;
        switch (input) {
        //Call HeapSort
        //Call Print to print vector
        //Call find to find the city can print it which its population
        case 1:
            cout<< "calling heap sort" << endl;
            break;
        //Call QuickSort
        //Call Print to print vector
        //Call find to find the city can print it which its population
        case 2:
            cout << "calling quick sort" << endl;
            break;
        default:
            break;
        }

        endProgram = false;
        break;


    //Compare populations
    case 2:
        cout << "Which city/country do you want to compare?" << endl;


        cout << "Which method to compare cities" << endl;
        cout << "Method 1. Heap Sort" << endl;
        cout << "Method 2. Quick Sort" << endl;
        cin >> input;
        switch (input) {
            //Call HeapSort
            //Call Print to print vector
            //Call find to find the city can print it which its population
        case 1:
            cout << "calling heap sort" << endl;
            break;
            //Call QuickSort
            //Call Print to print vector
            //Call find to find the city can print it which its population
        case 2:
            cout << "calling quick sort" << endl;
            break;
        default:
            break;
        }
        endProgram = false;
        break;

    case 0:
        endProgram = true;
        break;

    default:
        cout << "Input a valid integer." << endl;
        endProgram = false;
        break;
    }
    }
    */
}

