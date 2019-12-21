#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    /*
    4*4 의 판이라고 하면
    X O O O
    O X O O
    O O X O
    O O O X 에서 우리가 구하는 값은 O의 합.
    모든 항의 합은 (a1 + a2 + a3 + a4)^2 가 되는데,
    a의 합을 구하는데 O(n),
    그 값을 제곱하는데 O(1),
    X값(a1^2, ..., a4^2)들을 모두 빼주는데 O(n).
    이렇게 구한 값을 2로 나누면 원하는 답이 나옴
    */
    long long int sum=0, temp;
    int a[n];
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
        sum += a[i];
    }
    sum *= sum;
    for (int i=0 ; i<n ; i++){
        sum -= a[i]*a[i];
    }
    sum /= 2;
    cout<<sum;
}