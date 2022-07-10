#include <iostream>

using namespace std;

int main(void){
    int n, m;
    cin>>n>>m;
    int j; cin>>j;
    int loc = 1;
    int answer = 0;
    int temp;
    for (int i=0 ; i<j ; i++){
        cin>>temp;
        // loc ~ loc+m-1 까지가 바구니
        if (loc+m-1 < temp){
            answer += temp-(loc+m-1);
            loc += temp-(loc+m-1);
        }
        else if (temp < loc){
            answer += loc-temp;
            loc -= loc-temp;
        }
        // cout<<loc<<"\n";
    }
    cout<<answer;
    return 0;
}