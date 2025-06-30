#include<bits/stdc++.h>
using namespace std;

int main(){
    int j = 0, t;
    cout << "press 0 to encode or press 1 to decode: " << endl;
    cin >> t;
    if(t == 0){
        getchar();
        string s, key;
        cout << "Please input your text: " << endl;
        getline(cin, s);
        cout << "Please input your key: " << endl;
        getline(cin, key);
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
        cout << s;
    }
    else if(t == 1){
        getchar();
        string s, key;
        cout << "Please input your text: " << endl;
        getline(cin, s);
        cout << "Please input your key: " << endl;
        getline(cin, key);
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
        cout << s;
    }
    else{
        cout << "entry error";
        exit(0);
    }
    return 0;
}
