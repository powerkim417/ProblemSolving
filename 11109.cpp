#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;

    for (int i=0 ; i<t ; i++){
        int d,n,s,p;
        cin>>d>>n>>s>>p;
        if (d+p*n > s*n) cout<<"do not parallelize"<<endl;
        else if (d+p*n < s*n) cout<<"parallelize"<<endl;
        else cout<<"does not matter"<<endl;
    }
}