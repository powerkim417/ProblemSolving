#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    int K;
    cin>>K;
    for (int t=1 ; t<=K ; t++){
        cout<<"Data Set "<<t<<":"<<endl;
        int h;
        cin>>h;
        string work;
        cin>>work;
        for (int i=0 ; i<work.length() ; i++){
            if (work[i] == 'c') h++;
            else h--;
        }
        cout<<h<<endl<<endl;
    }
}