#include <iostream>

using namespace std;

string i2b(int n){
    string ret = "";
    for (int i=0 ; i<6 ; i++){
        ret = (char)((n%2)+'0') + ret;
        n /= 2;
    }
    return ret;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int h, m, s;
    char c; // : 받아내는 역할
    while (n--){
        cin>>h>>c>>m>>c>>s;
        string timeb[3] = {i2b(h), i2b(m), i2b(s)};
        for (int i=0 ; i<6 ; i++){
            for (int j=0 ; j<3 ; j++){
                cout<<timeb[j][i];
            }
        }
        cout<<" ";
        for (int i=0 ; i<3 ; i++){
            for (int j=0 ; j<6 ; j++){
                cout<<timeb[i][j];
            }
        }
        cout<<"\n";
    }
}