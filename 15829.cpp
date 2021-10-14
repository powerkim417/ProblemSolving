#include <iostream>
#define r 31L
#define M 1234567891L

using namespace std;

long long power[50];

long long hash_val(char c, int i){
    long long ret = c-'a'+1;
    ret *= power[i];
    ret %= M;
    return ret;
}

int main(void){
    int l;
    string s;
    cin>>l>>s;
    long long answer = 0;
    power[0] = 1;
    for (int i=1 ; i<l ; i++){
        power[i] = power[i-1] * r;
        power[i] %= M; 
    }
    for (int i=0 ; i<l ; i++){
        answer += hash_val(s[i], i);
        answer %= M;
    }
    cout<<answer;
    return 0;
}