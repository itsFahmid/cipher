#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Please press 1 to encode and 2 to decode in Caesar Cypher: ";
    int choice;
    cin >> choice;
    if(choice == 1){
        string s;
        cout << "Please input a string: ";
        getchar();
        getline(cin, s);

        cout << "Please input a number between 0 to 31: ";
        int n;
        cin >> n;

        if (n < 0 || n > 31) {
            cout << "Invalid number! Please enter between 0-31." << endl;
            return 1;
        }

        for (auto &x : s) {
            if (x >= 'a' && x <= 'z') {
                x = 'a' + ((x - 'a' + n) % 26 );
            }
            if (x >= 'A' && x <= 'Z') {
                x = 'a' + ((x - 'a' - n) % 26);
            }
        }
        cout << "Shifted string: " << s << endl;
    }
    else if(choice == 2){
        string s;
        cout << "Please input a string: ";
        getchar();
        getline(cin, s);

        cout << "Please input a number between 0 to 31: ";
        int n;
        cin >> n;

        if (n < 0 || n > 31) {
            cout << "Invalid number! Please enter between 0-31." << endl;
            return 1;
        }

        for (auto &x : s) {
            if (x >= 'a' && x <= 'z') {
                x = 'a' + ((x - 'a' - n) % 26);
            }
            if (x >= 'A' && x <= 'Z') {
                x = 'a' + ((x - 'a' - n) % 26);
            }
        }
        cout << "Decoded string: " << s << endl;
    }
    else{
        cout << "Choice selection error.";
        return 1;
    }
    return 0;
}
