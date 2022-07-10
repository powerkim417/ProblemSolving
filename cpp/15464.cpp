#include <iostream>

using namespace std;

int order[101];
int rev_order[101];
int id[101];

int main(void){
    int n;
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>order[i]; // order[5] = 2
        rev_order[order[i]] = i; // rev_order[2] = 5
    }
    int temp;
    for (int i=1 ; i<=n ; i++){
        cin>>temp;
        id[rev_order[rev_order[rev_order[i]]]] = temp;
    }
    for (int i=1 ; i<=n ; i++){
        cout<<id[i]<<"\n";
    }
    return 0;
}