#include <iostream>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    string op;
    int n;
    char c;
    cin>>T;
    int cnt[26];
    bool cw = true; // 시계방향이면 26+1, 반시계방향이면 26-1. 그뒤 %26
    for (int i=0 ; i<26 ; i++) cnt[i] = 0;
    int time = 1;
    int cur = 0; // 'a'
    int all = 0;
    for (int t=0 ; t<T ; t++){
        cin>>op>>n;
        if (n-time > 26){ // 다음 명령어까지 26 이상 걸리는건 시간을 줄이기 위해 몫으로 따로 매겨줌
            int add = (n-time)/26;
            time += 26*add;
            all += add;
        }
        while (time<=n){
            cnt[cur]++;
            // cout<<(char)(cur+'a');
            cur += 26 + 1*((cw)?(1):(-1));
            cur %= 26;
            time++;
        }
        if (op == "SMJER") {
            cw = !cw;
            // 바뀐게 반시계면 -2, 시계면 +2 해줘야 함
            if (!cw) cur += 24;
            else cur += 2;
            cur %= 26;
        }
        if (op == "UPIT"){
            cin>>c;
            cout<<cnt[c-'a']+all<<"\n";
        }
    }
}