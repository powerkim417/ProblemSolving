#include <iostream>

using namespace std;

bool bulb[4000];

int main(void){
    int n, m;
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        cin>>bulb[i];
    }
    int a, b, c;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b>>c;
        switch (a){
            case 1:
            bulb[b-1] = c;
            break;
            case 2:
            for (int j=b-1 ; j<=c-1 ; j++) bulb[j] = !bulb[j];
            break;
            case 3:
            for (int j=b-1 ; j<=c-1 ; j++) bulb[j] = false;
            break;
            case 4:
            for (int j=b-1 ; j<=c-1 ; j++) bulb[j] = true;
            break;
        }
        // for (int i=0 ; i<n ; i++){
        //     cout<<bulb[i]<<" ";
        // }
        // cout<<"\n";
    }
    for (int i=0 ; i<n ; i++){
        cout<<bulb[i]<<" ";
    }
    return 0;
}