#include <iostream>
#include <queue>

using namespace std;

bool isPrime[10000];
bool visited[10000] = {};

struct state {
    int num;
    int dist;
};

void find_prime(){
    for (int i=2 ; i<=9999 ; i++) isPrime[i] = true;
    for (int i=2 ; i*i<=9999 ; i++){
        if (!isPrime[i]) continue;
        for (int p=i*i ; p<=9999 ; p += i){
            isPrime[p] = false;
        }
    }
}

int nextnum(int num, int i, int j){
    string str = "";
    for (int t=0 ; t<4 ; t++){
        str = (char)(num%10 + '0') + str;
        num /= 10;
    }
    str[i] = j+'0';
    int ret = 0;
    for (char c: str){
        ret *= 10;
        ret += c-'0';
    }
    return ret;
}

int bfs(int s, int e){
    queue<state> q;
    q.push({s, 0});
    visited[s] = true;
    while (!q.empty()){
        state cur = q.front();
        q.pop();
        if (cur.num == e){
            return cur.dist;
        }
        for (int i=0 ; i<4 ; i++){ // 자리
            for (int j=0 ; j<=9 ; j++){ // 치환될 숫자
                int temp = nextnum(cur.num, i, j);
                if (temp>=1000 && isPrime[temp] && !visited[temp]){
                    visited[temp] = true;
                    q.push({temp, cur.dist+1});
                }
            }
        }
    }
    return -1;
}

int main(void){
    find_prime();
    int t;
    cin>>t;
    int s, e, answer;
    while (t--){
        cin>>s>>e;
        for (int i=1000 ; i<=9999 ; i++) visited[i] = false;
        answer = bfs(s, e);
        if (answer==-1) cout<<"Impossible\n";
        else cout<<answer<<"\n";
    }
    return 0;
}