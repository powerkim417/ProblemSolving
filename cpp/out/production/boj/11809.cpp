#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    vector<int> N,M;
    string n,m;
    cin>>n>>m;
    int nLen = n.length();
    int mLen = m.length();
    for (int i=0 ; i<nLen ; i++){
        N.push_back(n[i]-'0');
    }
    for (int i=0 ; i<mLen ; i++){
        M.push_back(m[i]-'0');
    }
    reverse(N.begin(), N.end());
    reverse(M.begin(), M.end());
    int smallLen = (nLen<mLen)?nLen:mLen;
    int n_cnt = 0, m_cnt = 0;
    for (int i=0 ; i<smallLen ; i++){
        if (N[i]<M[i]) {
            N[i] = -1;
            n_cnt++;
        }
        else if (M[i]<N[i]){
            M[i] = -1;
            m_cnt++;
        } 
    }
    int nSize = N.size();
    int mSize = M.size();
    int n_sum = 0, m_sum = 0;
    reverse(N.begin(), N.end());
    reverse(M.begin(), M.end());
    if (nSize == n_cnt) cout<<"YODA";
    else {
        for (int i=0 ; i<nSize ; i++){
            if (N[i] != -1) {
                n_sum *= 10;
                n_sum += N[i];
            }
        }
        cout<<n_sum;
    }
    cout<<"\n";
    if (mSize == m_cnt) cout<<"YODA";
    else {
        for (int i=0 ; i<mSize ; i++){
            if (M[i] != -1) {
                m_sum *= 10;
                m_sum += M[i];
            }
        }
        cout<<m_sum;
    }
}