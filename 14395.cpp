#include <iostream>
#include <set>
#include <queue>

using namespace std;

long long s, t;
set<long long> visited;
string op[4] = {"*", "+", "-", "/"};

long long nexts(long long s, int d){
    switch (d){
        case 0:
        return s*s;
        case 1:
        return s+s;
        case 2:
        return s-s;
        case 3:
        return 1;
    }
}

struct state {
    long long num;
    string opstr;
    int time;
};

string bfs(){
    queue<state> q;
    q.push({s, "", 0});
    visited.insert(s);

    while (!q.empty()){
        state cur = q.front();
        q.pop();

        if (cur.num == t) return cur.opstr;

        for (int d=0 ; d<4 ; d++){
            long long nextnum = nexts(cur.num, d);
            if (visited.find(nextnum) != visited.end()) continue;
            visited.insert(nextnum);
            q.push({nextnum, cur.opstr + op[d], cur.time+1});
        }
    }

    return "-1"; // 바꿀수 없는 경우도 -1 출력
}

int main(void){
    cin>>s>>t;
    if (s==t) {
        cout<<"0";
        return 0;
    }
    cout<<bfs();
    return 0;
}