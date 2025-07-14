#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Please press 1 to encode and 2 to decode in Caesar Cipher: ";
    int choice;
    cin >> choice;

    cin.ignore(); // Clear leftover newline after cin

    if (choice == 1 || choice == 2) {
        string s;
        cout << "Please input a string: ";
        getline(cin, s);

        cout << "Please input a number between 0 to 26: ";
        int n;
        cin >> n;

        if (n < 0 || n > 26) {
            cout << "Invalid number! Please enter between 0–31." << endl;
            return 1;
        }

        for (auto &x : s) {
            if (x >= 'a' && x <= 'z') {
                if (choice == 1) // encode
                    x = 'a' + (x - 'a' + n) % 26;
                else // decode
                    x = 'a' + (x - 'a' - n + 26) % 26;
            }
            else if (x >= 'A' && x <= 'Z') {
                if (choice == 1) // encode
                    x = 'A' + (x - 'A' + n) % 26;
                else // decode
                    x = 'A' + (x - 'A' - n + 26) % 26;
            }
        }

        if (choice == 1)
            cout << "Encoded string: " << s << endl;
        else
            cout << "Decoded string: " << s << endl;
    }
    else {
        cout << "Choice selection error." << endl;
        return 1;
    }

    return 0;
}
