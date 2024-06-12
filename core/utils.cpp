#include <bits/stdc++.h>

using namespace std;

vector<string> get_array(string src){
    fstream file(src);

    string word;
    vector<string> words;

    if(!file){
        cerr << "\nFile can't open -" << src;
        return words;
    }

    while(!file.eof()){
        getline(file, word);
        if(word.size())
            words.push_back(word);
        word = "\0";
    }
    return words;
}

vector<string> linear_search4_pre(vector<string> v, string str){
    vector<string> results;
    auto start = chrono::high_resolution_clock::now();

    for(auto s : v){
        bool match = true;
        for(int i=0; i<str.size(); i++)
            if(s[i] != str[i]){
                match = false;
                break;
            }
        if (match)
            results.push_back(s);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::nanoseconds> (stop-start);

    cerr << "\033[32m\n" << results.size() << 
        double(dur.count()) / double(1000000) << "ms.\033[0m\n\n";
    return results;
}

bool linear_search4_exact(vector<string> v, string str){
    auto start = chrono::high_resolution_clock::now();
    bool found = false;
    
    for (auto s : v)
        if (s == str){
            found = true;
            break;
        }       
    auto stop = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::nanoseconds> (stop-start);

    cerr << "\033[32m\n" << "found" << double(dur.count()) / double(1000000) 
        << "ms.\033[0m\n\n";
    return found;
}

// KMP search
vector<int> computeLPS(string pat, int m){
    int p = 0, i=1;
    vector<int> lps(m);
    lps[0] = 0;
    while(i<m){
        if (pat[i] == pat[p])
            lps[i++] = ++p; // lps[i] = p+1, and p = p+1, i = i+1 
        else
            if(p)
                p = lps[p-1];
            else
                lps[i++] = 0;
    }
    return lps;
}

int KMPsearch(string pat, string txt){
    int m = pat.size(), n = txt.size();

    vector<int> lps = computeLPS(pat, m);
    int i = 0, j = 0;

    while(i<n){
        if(txt[i] == pat[j]){
            i++; j++;
        }
        
        if(j==m)
            return i-j;
        
        else{
            if (j)
                j = lps[j-1];
            else    
                i++;
        }
    }
    return -1;
}

vector<string> search(vector<string> v, string pat){
    vector<string> results;

    auto start = chrono::high_resolution_clock::now();
    for(auto s : v)
        if(KMPsearch(pat, s) != -1)
            results.push_back(s);
    
    auto stop = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::nanoseconds> (stop-start);

    cerr << "\033[32m\n" << results.size() << " results in " << 
        double(dur.count() / double(1000000)) << " ms.\033[0m\n\n";

    return results;
}