#include <iostream>
#include <stack>

using namespace std;

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int t; cin>>t;
    cin.ignore();
    char c;
    stack<char> st;
    string line;
    while (getline(cin, line)){
        for (int i=0 ; i<=line.size() ; i++){
            if (i==line.size() || line[i]==' '){
                while (!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
                cout<<" ";
            }
            else st.push(line[i]);
        }
        cout<<"\n";
    }
    return 0;
}