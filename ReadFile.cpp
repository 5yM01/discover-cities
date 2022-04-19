#include "ReadFile.h"

void ReadFile(string& fileName, string& country, string& countryCode, string& city, int& population){
    ifstream readFile(fileName);

    if(readFile.is_open()){
        //read heading line
        string lineInput;
        getline(readFile, lineInput);

        //loop through all lines and store data into variables
        while(getline(readFile, lineInput)){
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
            getline(stream, temp, ';');
            //population = stoi(temp);

            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
        }
    }
    readFile.close();
}

void ReadFile(string& fileName,unordered_map<string,vector<string>>& countries, unordered_map<string, int>& cities){
    ifstream readFile(fileName);

    if(readFile.is_open()){
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
        while(getline(readFile, lineInput)){
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
            population = rand() % 10000 + 1000;
            cout << population << endl;

            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');

            countries[country].push_back(city);
            cities[city] = population;
        }
    }
    readFile.close();
}

//USE THIS FUNCTION
void ReadFile(string& fileName,unordered_map<string,vector<pair<string,int>>>& countries){
    ifstream readFile(fileName);

    if(readFile.is_open()){
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
        while(getline(readFile, lineInput)){
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
            population = rand() % 10000 + 1000;
            //cout << population << endl;

            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');
            getline(stream, temp, ';');

            countries[country].push_back(make_pair(city,population));
        }
    }
    readFile.close();
}