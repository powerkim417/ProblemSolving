#include <iostream>

using namespace std;

bool card[4][13] = {}; // PKHT 

int main(void){
    string s;
    cin>>s;
    for (int i=0 ; i<s.length() ; i+=3){
        int shape, num; // num: 0~12
        switch (s[i]){
            case 'P':
            shape=0;
            break;
            case 'K':
            shape=1;
            break;
            case 'H':
            shape=2;
            break;
            case 'T':
            shape=3;
            break;
        }
        num = (s[i+1]-'0')*10 + (s[i+2]-'0') - 1;
        if (card[shape][num]){
            cout<<"GRESKA";
            return 0;
        }
        else {
            card[shape][num] = true;
        }
    }
    for (int i=0 ; i<4 ; i++){
        int temp = 13;
        for (int j=0 ; j<13 ; j++){
            if (card[i][j]) temp--;
        }
        cout<<temp<<" ";
    }
    return 0;
}