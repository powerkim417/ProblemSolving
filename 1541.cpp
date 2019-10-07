#include <iostream>

using namespace std;

int main(void){
    string s;
    cin>>s;
    int len = s.length();
    // GREEDY IDEA
    // a-b+c-d+e-f-g의 경우 a-(b+c)-(d+e)-f-g 와 같이 묶으면 최소!
    // 첫 -가 나오기 전까지는 다 더하고, 그 이후는 다 빼버린다!!
    int temp = 0;
    int sum = 0;
    bool minus = false;
    for (int i=0 ; i<len ; i++){
        if (s[i] != '+' && s[i] != '-'){
            temp *= 10;
            temp += s[i]-'0';
        }
        else {
            if (minus) sum -= temp;
            else sum += temp;
            if (s[i] == '-') minus = true;
            temp = 0;
        }
    }
    // (a-) (b+) c 순으로 연산을 하므로 마지막 남은 숫자는 따로 연산해줘야 함
    if (minus) sum -= temp;
    else sum += temp;
    cout<<sum;
}