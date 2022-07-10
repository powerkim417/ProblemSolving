#include <iostream>

using namespace std;

int main(void){
    char sik[12]; // -10000x-10000. 최대 11글자
    char prev = ' ';
    string answer = "";
    cin>>sik;
    for (int i=0 ; ; i++){
        if (sik[i]=='x'){
            if (prev == ' ' || prev == '-') answer += "1";
            break;
        }
        else if (sik[i]=='\0') {
            answer = "0";
            break; // 입력으로 상수 하나만 있을 때(0차식)
        }
        else answer += sik[i];
        prev = sik[i];
    }
    cout<<answer;
}