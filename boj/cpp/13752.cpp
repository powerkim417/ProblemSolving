#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        for (int j=0 ; j<temp ; j++) cout<<"=";
        cout<<"\n";
    }
}