#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    int h[100000];
    for (int i=0 ; i<n ; i++){
        cin>>h[i];
    }
    int answer = 0;
    int tallest = -1;
    for (int i=n-1 ; i>=0 ; i--){
        if (tallest < h[i]) {
            tallest = h[i];
            answer++;
        }
    }
    cout<<answer;
    return 0;
}