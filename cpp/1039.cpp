#include <iostream>

using namespace std;

string n, nextstr;
int k, m;
int answer = -1;

bool visited[1000001][11] = {};

int s2i(string s){
    int ret = 0;
    for (char c: s){
        ret *= 10;
        ret += c-'0';
    }
    return ret;
}

string swap(string s, int i, int j){
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
    return s;
}

// 같은 숫자로 되돌아와도 됨
// 그러나 같은 숫자-같은 변환횟수가 여러번 오면 안되므로
// visited 도입
void dfs(string num, int cnt){
    int numi = s2i(num);
    visited[numi][cnt] = true;
    // cout<<num<<" "<<cnt<<"\n";
    if (cnt==k){
        if (answer < numi){
            answer = numi;
        }
        return;
    }
    for (int i=0 ; i<m ; i++){
        for (int j=i+1 ; j<m ; j++){
            // cout<<i<<" "<<j<<"\n";
            if (i==0 && num[j]=='0') continue;
            nextstr = swap(num, i, j);
            if (visited[s2i(nextstr)][cnt+1]) continue;
            dfs(nextstr, cnt+1);
        }
    }
    return;
}

int main(void){
    cin>>n>>k;
    m = n.size();
    dfs(n, 0);
    cout<<answer;
    return 0;
}