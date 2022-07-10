#include <iostream>

using namespace std;

bool line[10000];

int main(void){
    int n;
    cin>>n;
    int x,y;
    for (int i=0 ; i<n ; i++){
        cin>>x>>y; // 1 9 면 line[1]~line[8] true
        for (int j=x ; j<y ; j++){
            line[j] = true;
        }
    }
    int cnt = 0;
    for (int i=0 ; i<10000 ; i++){
        if (line[i]) cnt++;
    }
    cout<<cnt;
}