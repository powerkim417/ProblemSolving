#include <iostream>

using namespace std;

int seg[10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011,
                0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011};
int adj[10][10] = {};

int n,k,p,x;

int cnt_on(int bit){
    int ret = 0;
    while (bit>0){
        if (bit%2) ret++;
        bit /= 2;
    }
    return ret;
}

void init_adj(){
    // cout<<seg[0]<<" "<<seg[1]<<"\n";
    for (int i=0 ; i<10 ; i++){
        for (int j=0 ; j<10 ; j++){
            adj[i][j] = cnt_on(seg[i] ^ seg[j]);
            // cout<<adj[i][j]<<" ";
        }
        // cout<<"\n";
    }
    return;
}

int dist(int s, int e){
    int ret = 0;
    while (s>0 || e>0){
        ret += adj[s%10][e%10];
        s /= 10; e /= 10;
    }
    return ret;
}

// 1~n까지 최대 999999 이므로 O(n)으로 x와 모든 수를 비교해도 됨
// 입력 중 k는 사용하지 않음
int main(void){
    init_adj();
    cin>>n>>k>>p>>x;
    int answer = 0;
    for (int i=1 ; i<=n ; i++){
        int d = dist(x, i);
        if (d>=1 && d<=p) answer++;
    }
    cout<<answer;
    return 0;
}