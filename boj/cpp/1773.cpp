#include <iostream>

using namespace std;

bool fire[2000001];

int main(void){
    int n, c;
    cin>>n>>c;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        int time = temp;
        while (time<=c){
            fire[time] = true;
            // cout<<time<<"\n";
            time += temp;
        }
    }
    int cnt = 0;
    for (int i=0 ; i<=c ; i++){
        if (fire[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}