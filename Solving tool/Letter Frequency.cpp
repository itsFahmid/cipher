#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int str_len = 0;

    unordered_map<char, int> mp;

    // Count frequency of each lowercase letter
    for (char c : s) {
        if (isalpha(c)) {
            mp[tolower(c)]++;
        }
        if(c != ' '){
            str_len++;
        }
    }

    // Find the character with the maximum frequency
    char max_char = 'a';
    int max_freq = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        int freq = mp[c];
        cout << c << " " << freq << endl;
        if (freq > max_freq) {
            max_freq = freq;
            max_char = c;
        }
    }

    cout << "Monogram frequencies: " << endl;

    for (char c = 'a'; c <= 'z'; c++) {
        int freq = mp[c];
        cout << c << ": " << ((freq * 1.0) / str_len) << endl;
    }

    cout << "\nCharacter with maximum frequency: " << max_char
         << " (" << max_freq << " times)" << endl;

    cout << "The code for caesar cypher is: ";
    if(max_char - 'e' < 0){
        cout << 26 - (max_char - 'e');
    }
    else{
        cout << max_char - 'e' << endl;
    }

    return 0;
}
