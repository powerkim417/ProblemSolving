#include <iostream>

using namespace std;

int main(void){
    int n;
    int s[10], t[10];
    int dist;
    while (cin>>n){
        if (n==-1) break;
        dist = 0;
        for (int i=0 ; i<n ; i++){
            cin>>s[i]>>t[i];
            if (i==0) dist += s[i]*t[0];
            else dist += s[i]*(t[i]-t[i-1]);
        }
        cout<<dist<<" miles\n";
    }
    return 0;
}