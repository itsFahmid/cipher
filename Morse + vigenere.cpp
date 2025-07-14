#include <iostream>
#include <unordered_map>
#include <sstream>
#include <cctype>
using namespace std;

// Morse maps
unordered_map<char, string> charToMorse = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"},
    {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {'.', ".-.-.-"},{',', "--..--"},{'?', "..--.."}, {'!', "-.-.--"},
    {'-', "-....-"},{'/', "-..-."}, {'@', ".--.-."}, {'"', ".-..-."}, {'\'', ".----."}
};
unordered_map<string, char> morseToChar;

void initializeMorseToChar() {
    for (auto& p : charToMorse) {
        morseToChar[p.second] = p.first;
    }
}

// Vigenère cipher
string vigenereEncrypt(string& s, const string& key) {
    string result;
    int j = 0;
    for(int i=0; i<s.length(); i++){
            if (isupper(s[i])){
                s[i] = tolower(s[i]);
            }
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(j >= key.length()){
                    j = 0;
                }
                if((int)s[i] + (int)key[j] - 96 <= 122){
                    s[i] += ((int)key[j] - 96);
                } else{
                    s[i] += ((int)key[j] - 96 - 26);
                }

                j++;
            }
        }
    return s;
}

string vigenereDecrypt(string& s, const string& key) {
    string result;
    int j = 0;
    for(int i = 0; i < s.length(); i++){
            if (isupper(s[i])){
                s[i] = tolower(s[i]);
            }
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(j >= key.length()){
                    j = 0;
                }
                if((int)s[i] - (int)key[j] + 96 >= 97){
                    s[i] -= ((int)key[j] - 96);
                } else {
                    s[i] -= ((int)key[j] - 96 - 26);
                }

                j++;
            }
        }
    return s;
}

// Morse encode/decode
string textToMorse(const string& text) {
    string result;
    for (char ch : text) {
        if (ch == ' ') {
            result += "/ ";
        } else {
            ch = toupper(ch);
            if (charToMorse.count(ch))
                result += charToMorse[ch] + " ";
            else
                result += "? ";
        }
    }
    return result;
}

string morseToText(const string& morse) {
    stringstream input(morse);
    string token, result;
    while (input >> token) {
        if (token == "/")
            result += ' ';
        else if (morseToChar.count(token))
            result += morseToChar[token];
        else
            result += '?';
    }
    return result;
}

int main() {
    initializeMorseToChar();

    cout << "Enter 1 to encode (Vigenère + Morse)\n";
    cout << "Enter 2 to decode (Morse -> Vigenère)\n";
    int choice;
    cin >> choice;
    cin.ignore();

    string key;
    cout << "Enter key for Vigenère cipher (alphabet only): ";
    getline(cin, key);

    if (choice == 1) {
        string text;
        cout << "Enter text to encode:\n";
        getline(cin, text);
        string encrypted = vigenereEncrypt(text, key);
        string morse = textToMorse(encrypted);
        cout << "\nMorse Code:\n" << morse << endl;
    } else if (choice == 2) {
        string morse;
        cout << "Enter Morse code to decode (letters separated by space, words by /):\n";
        getline(cin, morse);
        string decoded = morseToText(morse);
        string original = vigenereDecrypt(decoded, key);
        cout << "\nDecoded Text:\n" << original << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
