#include <iostream>

using namespace std;

int ball[5] = {0, 1, 0, 0, 2}; // 1: small, 2: big

void swap(int i, int j){
    int& a = ball[i];
    int& b = ball[j];
    int temp = a;
    a = b;
    b = temp;
}

int main(void){
    string cmd;
    cin>>cmd;
    int len = cmd.length();
    int temp;
    for (int i=0 ; i<len ; i++){
        switch (cmd[i]){
            case 'A':
                swap(1, 2);
                break;
            case 'B':
                swap(1, 3);
                break;
            case 'C':
                swap(1, 4);
                break;
            case 'D':
                swap(2, 3);
                break;
            case 'E':
                swap(2, 4);
                break;
            case 'F':
                swap(3, 4);
                break;
        }
    }
    for (int i=1 ; i<=4 ; i++){
        if (ball[i] == 1) cout<<i<<"\n";
    }
    for (int i=1 ; i<=4 ; i++){
        if (ball[i] == 2) cout<<i<<"\n";
    }
}