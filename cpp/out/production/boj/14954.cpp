#include <iostream>

using namespace std;

bool occurred[730]; // 0 ~ 729

int f(int x){
    int temp = 0;
    while (x>0){
        temp += (x%10)*(x%10);
        x /= 10;
    }
    return temp;
}

int main(void){
    string s;
    cin>>s;
    for (int i=0 ; i<730 ; i++) occurred[i] = false;
    int n = 0;
    int len = s.length();
    for (int i=0 ; i<len ; i++){
        n += (s[i]-'0')*(s[i]-'0');
    }
    occurred[n] = true;
    n = f(n);
    // 999,999,999일 때 81*9 = 729. f(x)값은 최대 729
    while (1){
        if (n==1) {
            cout<<"HAPPY"; // 숫자가 1로 수렴한 경우: HAPPY
            return 0;
        }
        if (occurred[n]){ // 사이클이 반복되어 이미 나온 수가 또 나온 경우: UNHAPPY
            cout<<"UNHAPPY";
            return 0;
        }
        else {
            occurred[n] = true;
            n = f(n);
        }
    }
}