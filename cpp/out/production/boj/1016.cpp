#include <iostream>
#include <cmath>

using namespace std;

bool isNN[1000001]; // min+index 의 제곱ㄴㄴ 여부
// 2*2의 제곱인거 다 false 하고, ..., p*p<=max 까지

int main(void){
    long long int min, max;
    cin>>min>>max;
    int cnt = 0;
    int idx;
    for (int i=0 ; i<=1000000 ; i++) isNN[i] = true;
    
    for (long long int p=2 ; p*p<=max ; p++){ // 밑에 i 계산할때 p가 int면 결과값도 이미 int 선에서 잘린 상태로 저장되므로 p도 long long으로 둘 것
        for (long long int i=(ceil(min*1.0/(p*p)))*p*p ; i<=max ; i += p*p){
            // min 이상의 가장 작은 p*p의 배수 부터 시작
            isNN[i-min] = false;
        }
    }
    
    for (long long int i=min ; i<=max ; i++) {
    	idx = i-min;
        if (isNN[idx]) cnt++;
    }
    cout<<cnt;
}
        