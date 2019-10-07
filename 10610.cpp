#include <iostream>

using namespace std;

int main(void){
    string s;
    cin>>s;
    int digit[10]; // N에서 특정 숫자의 갯수
    for (int i=0 ; i<10 ; i++){
        digit[i] = 0;
    }
    int len = s.length();
    int rem = 0; // 최대 9*10^5 = 900000 까지 가능
    for (int i=0 ; i<len ; i++){
        digit[s[i]-'0']++;
        rem += s[i]-'0';
    }
    rem %= 3;
    /* 재구성한 수가 30의 배수이려면,
    1. N의 각자리의 합이 3의 배수여야 하고 (3의 배수)
    2. 재구성한 수의 마지막 자리가 0이어야 한다. -> digit[0]이 1 이상이어야 함 (10의 배수) */
    if (rem%3 != 0 || digit[0] < 1){
        cout<<"-1";
        return 0;
    }
    else {
        for (int i=9 ; i>=0 ; i--){
            for (int j=0 ; j<digit[i] ; j++){
                cout<<i;
            }
        }
        return 0;
    }
}