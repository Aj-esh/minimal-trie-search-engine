#include <bits/stdc++.h>

#include "trie.cpp"
#include "utils.cpp"

using namespace std;

void test(){}

int main(int argc, char **argv){
    string file;
    Trie T;
    vector<string> data;

    if(argc > 1)
        data = get_array(argv[1]);
    else{
        cout << "Enter file name.. \n";
        cin >> file;
        cerr << "loading...";
        data = get_array(file);
        cerr<<"Done!";
    }

    for(string word : data)
        T.ins(word);
    
    int choice;

    if(argc > 2){
        string pat = argv[2];
        for (string s: search(data, pat))
            cout << s << endl;
        return 0;
    }

    do{
        cout << "------------------------\n";
        cout << "MENU\n";
        cout << "1. Exact Search.\n";
        cout << "2. Prefix Search.\n";
        cout << "3. Universal Search.\n";
        cout << "0. Exit.\n";

        cin >> choice;
        getchar();
        
        string pat;
        if(choice){
            cout << "Enter search text: ";
            getline(cin, pat);
        }

        switch(choice){
            case 1:
            if(T.search_exact(pat))
                cout << "String found.\n";
            else
                cout << "String not found.\n";
            break;

            case 2:
            for(string s : T.search_pre(pat))
                cout << s <<endl;
            break;

            case 3:
            for(string s: search(data, pat))
                cout << s << endl;
            break;

            default:
            break;
        }
        cout << "\n\npress any key to continue.";
        getchar();
        system("clear");

    }while(choice != 0);
    return 0;
}