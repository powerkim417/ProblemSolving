#include <iostream>

using namespace std;

int main(void){
    int p1,s1,s2,p2;
    cin>>p1>>s1>>s2>>p2;
    if (p1+p2>s1+s2) cout<<"Persepolis";
    else if (p1+p2<s1+s2) cout<<"Esteghlal";
    else {
        if (p2>s1) cout<<"Persepolis";
        else if (p2<s1) cout<<"Esteghlal";
        else cout<<"Penalty";
    }
    return 0;
}