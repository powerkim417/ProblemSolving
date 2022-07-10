#include <iostream>

using namespace std;

// stack 자료구조 대신 string을 써서 저장한 풀이
int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int t; cin>>t;
    cin.ignore();
    char c;
    string word = "";
    string line;
    while (getline(cin, line)){
        for (int i=0 ; i<=line.size() ; i++){
            if (i==line.size() || line[i]==' '){
                cout<<word;
                word = "";
                if (i!=line.size()) cout<<" ";
            }
            else word = line[i]+word;
        }
        cout<<"\n";
    }
    return 0;
}