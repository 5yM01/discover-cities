#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//read in Country, country code, city, and population with variables passed in
void ReadFile(string& fileName, string& country, string& countryCode, string& city, int& population);

//read in, put cities into countries map, put populations into city map
void ReadFile(string& fileName,unordered_map<string,vector<string>>& countries, unordered_map<string, int>& cities);
