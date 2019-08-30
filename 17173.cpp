#include <iostream>

using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    int k[m];
    int sum = 0;
    for (int j=0 ; j<m ; j++){
        cin>>k[j];
    }
    for (int i=1 ; i<=n ; i++){
        for (int j=0 ; j<m ; j++){
            if (i%k[j]==0) {
                sum += i;
                // cout<<i<<endl;
                break;
            }
        }
    }
    cout<<sum;
}