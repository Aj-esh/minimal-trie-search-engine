#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using namespace std;

vector<string> get_array(string filename);
vector<string> linear_search4_pre(vector<string> data, string prefix);
bool linear_search4_exact(vector<string> data, string word);
vector<int> computeLPS(string pattern, int m);
vector<int> KMPsearch(string text, string pattern);
vector<string> search(vector<string> data, string pattern);

#endif