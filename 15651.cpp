#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    n /= 3; // 나눠진 n을 '그냥' 자연수 3개로 분리!
    /* n을 3개로 나눈다는 것은
    n개의 노드, 즉 끝을 제외하고 n-1개의 간격에 2개의 가림막을 놓는것과 같음
    즉 (n-1)C2 = (n-1)(n-2)/2. */

    cout<<(n-1)*(n-2)/2;
}