#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<2*n-1 ; i++){
        if (i==0 || i==2*n-2){
            for (int j=0 ; j<n ; j++) cout<<"*";
            for (int j=0 ; j<2*n-3 ; j++) cout<<" ";
            for (int j=0 ; j<n ; j++) cout<<"*";
        }
        else if (i==n-1){ // 가운데줄
            for (int j=0 ; j<i ; j++) cout<<" ";
            cout<<"*";
            for (int j=0 ; j<n-2 ; j++) cout<<" ";
            cout<<"*";
            for (int j=0 ; j<n-2 ; j++) cout<<" ";
            cout<<"*";
        }
        else if (i<n){
            for (int j=0 ; j<i ; j++) cout<<" ";
            cout<<"*";
            for (int j=0 ; j<(n-2) ; j++) cout<<" ";
            cout<<"*";
            for (int j=0 ; j<2*n-3-2*i ; j++) cout<<" ";
            cout<<"*";
            for (int j=0 ; j<(n-2) ; j++) cout<<" ";
            cout<<"*";
        }
        else {
            for (int j=0 ; j<2*(n-1)-i ; j++) cout<<" ";
            cout<<"*";
            for (int j=0 ; j<(n-2) ; j++) cout<<" ";
            cout<<"*";
            for (int j=0 ; j<2*n-3-2*(2*(n-1)-i) ; j++) cout<<" ";
            cout<<"*";
            for (int j=0 ; j<(n-2) ; j++) cout<<" ";
            cout<<"*";
        }
        cout<<"\n";
    }
}