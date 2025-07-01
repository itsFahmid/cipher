#include<bits/stdc++.h>
using namespace std;

int main(){
    int choice;
    cout << "Please input 1 to encode, 2 to decode: " << endl;
    cin >> choice;
    getchar();

    if(choice == 1){
        string s;
        cout << "Please input your text to convert it into morse code: " << endl;
        getline(cin, s);

        for(auto x : s){

            x = tolower(x);

            if(x == ' '){
                cout << "/";
            }
            else if(x == 'a'){
                cout << ".-";
            }
            else if(x == 'b'){
                cout << "-...";
            }
            else if(x == 'c'){
                cout << "-.-.";
            }
            else if(x == 'd'){
                cout << "-..";
            }
            else if(x == 'e'){
                cout << ".";
            }
            else if(x == 'f'){
                cout << "..-.";
            }
            else if(x == 'g'){
                cout << "--.";
            }
            else if(x == 'h'){
                cout << "....";
            }
            else if(x == 'i'){
                cout << "..";
            }
            else if(x == 'j'){
                cout << ".---";
            }
            else if(x == 'k'){
                cout << "-.-";
            }
            else if(x == 'l'){
                cout << ".-..";
            }
            else if(x == 'm'){
                cout << "--";
            }
            else if(x == 'n'){
                cout << "-.";
            }
            else if(x == 'o'){
                cout << "---";
            }
            else if(x == 'p'){
                cout << ".--.";
            }
            else if(x == 'q'){
                cout << "--.-";
            }
            else if(x == 'r'){
                cout << ".-.";
            }
            else if(x == 's'){
                cout << "...";
            }
            else if(x == 't'){
                cout << "-";
            }
            else if(x == 'u'){
                cout << "..-";
            }
            else if(x == 'v'){
                cout << "...-";
            }
            else if(x == 'w'){
                cout << ".--";
            }
            else if(x == 'x'){
                cout << "-..-";
            }
            else if(x == 'y'){
                cout << "-.--";
            }
            else if(x == 'z'){
                cout << "--..";
            }
            else if(x == '.'){
                cout << ".-.-.-";
            }
            else if(x == ','){
                cout << "--..--";
            }
            else if(x == '!'){
                cout << "-.-.--";
            }
            else if(x == '?'){
                cout << "..--..";
            }

            cout << " ";
        }
    }
    else if(choice == 2){

    }
    else{
        cout << "error with your choice.";
        exit(0);
    }
}
