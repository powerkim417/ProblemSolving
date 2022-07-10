#include <iostream>
#include <map>

using namespace std;

int s2i(string s){
    int ret = 0;
    for (char c: s){
        ret *= 10;
        ret += c-'0';
    }
    return ret;
}

int main(void){
    // 입출력 최적화 안해주면 시간초과 남
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    map<string, int> s2i_map;
    map<int, string> i2s_map;
    string s;
    for (int i=1 ; i<=n ; i++){
        cin>>s;
        s2i_map.insert({s,i});
        i2s_map.insert({i,s});
    }
    for (int i=0 ; i<m ; i++){
        cin>>s;
        if (s[0]>='A' && s[0]<='Z'){
            cout<<s2i_map[s]<<"\n";
        }
        else {
            cout<<i2s_map[s2i(s)]<<"\n";
        }
    }
    return 0;
}