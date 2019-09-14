#include <iostream>

using namespace std;

int main(void){
    string song[14] = {"baby", "sukhwan", "tururu", "turu", // turu는 2,3,6,7,10,11. 즉 나머지가 2,3
                        "very", "cute", "tururu", "turu",
                        "in", "bed", "tururu", "turu",
                        "baby", "sukhwan"};
    int n;
    cin>>n;
    n--;
    int idx = n%14;
    int loop = n/14;
    if (idx%4==0 || idx%4==1) cout<<song[idx];
    else {
        if ((idx%4==2 && loop<=2) || (idx%4==3 && loop<=3)){ 
            cout<<song[idx];
            for (int i=0 ; i<loop ; i++){
                cout<<"ru";
            }
        }
        else {
            cout<<"tu+ru*";
            if (idx%4==2) cout<<loop+2;
            if (idx%4==3) cout<<loop+1;
        }
    } 
}