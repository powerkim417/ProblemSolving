#include <iostream>

using namespace std;

int min(int a, int b){
    if (a<b) return a;
    else return b;
}

int main(void){
    int n,m,k;
    cin>>n>>m>>k;
    // n개 카드 중 앞면은 m개가 O, n-m개가 X
    // 뒷면은 k개가 O, n-k개가 X
    /*
    O O O O .... O X X
    O O X X .... X X X 와 같은 형태로 보아
    앞뒷면이 같은 카드의 갯수는
    min(m,k) + min(n-m, n-k) 개 이다!
    */
    cout<<(min(m, k) + min(n-m, n-k));
}