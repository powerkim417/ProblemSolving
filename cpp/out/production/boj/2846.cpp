#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int p[n];
    for (int i=0 ; i<n ; i++){
        cin>>p[i];
    }
    int max = 0;
    int flr = p[0];
    for (int i=1 ; i<n ; i++){
        if (p[i] <= p[i-1]){ // 오르막 깨짐
            if (max < p[i-1]-flr){
                max = p[i-1]-flr;
            } // 오르막 길이 갱신 후
            flr = p[i];
        }
    }
    if (max < p[n-1]-flr) max = p[n-1]-flr; // 마지막 따로처리
    cout<<max;
}