#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//read in, put country as key and value as vector of pairs of city and population - USE THIS FUNCTION
void ReadFile(string& fileName,unordered_map<string,vector<pair<string,int>>>& countries);