#include <iostream>
#include <map>

using namespace std;

map<char, string> m;

int main(void){
    int n; cin>>n; cin.ignore();
    string val; char key;
    for (int i=0 ; i<n ; i++){
        cin>>val>>key;
        m[key] = val;
    }
    string after = "";
    string before; cin>>before;
    for (char c: before){
        after += m[c];
    }
    int s, e; // 길이는 e-s+1
    cin>>s>>e;
    // cout<<after<<"\n";
    cout<<after.substr(s-1, e-s+1);
    return 0;
}