#include <iostream>

using namespace std;

int main(void){
    char x[20];
    // 1000000 = 03641100 = 0xf4240
    cin>>x;
    int val = 0;
    if (x[0] == '0' && x[1] == 'x'){ // 16진법
        for (int i=2 ; x[i]!='\0' ; i++){
            val *= 16;
            if (x[i] >= 'a') val += x[i] - 'a' + 10; 
            else val += x[i] - '0';
        }
        cout<<val;
        return 0;
    }
    else if (x[0] == '0'){ // 8진법
        for (int i=1 ; x[i]!='\0' ; i++){
            val *= 8;
            val += x[i] - '0';
        }
        cout<<val;
        return 0;
    }
    else {
        cout<<x;
        return 0;
    }
}