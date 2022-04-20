#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//USE THIS FUNCTION
void ReadFile(string& fileName, unordered_map<string, vector<pair<string, int>>>& countries) {
    ifstream readFile(fileName);

    if (readFile.is_open()) {
        //read heading line
        string lineInput;
        getline(readFile, lineInput);

        //variables
        string country;
        string countryCode;
        string city;
        string popStr;
        int population;

        //loop through all lines and store data into variables
        while (getline(readFile, lineInput)) {
            string temp;
            istringstream stream(lineInput);

            //temporary variables to store the data from file
            getline(stream, temp, ';');

            //City Name
            getline(stream, city, ';');

            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            //Country Name
            getline(stream, countryCode, ';');
            //Country Code
            getline(stream, country, ';');

            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');

            //Population
            getline(stream, popStr, ';');
            //had to generate random values due to bad/invalid population values in original data set
            population = rand() * 50 + rand();
            //cout << population << endl;

            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');

            countries[country].push_back(make_pair(city, population));
        }
    }
    readFile.close();
}