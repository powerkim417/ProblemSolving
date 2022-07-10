#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P; // 중요도, 번호

int main(void){
    int t;
    cin>>t;
    int n, m, temp;
    while (t--){
        cin>>n>>m;
        queue<P> q;
        priority_queue<int> pq;
        for (int i=0 ; i<n ; i++){
            cin>>temp;
            pq.push(temp);
            q.push({temp, i});
        }
        int seq = 1;
        while (!q.empty()){
            P cur = q.front();
            // cout<<"cur: "<<cur.first<<" "<<cur.second<<", pq top: "<<pq.top()<<"\n";
            if (cur.first < pq.top()){ // 인쇄 X
                q.push(cur);
                q.pop();
            }
            else { // 인쇄
                q.pop();
                pq.pop();
                if (cur.second == m) {
                    cout<<seq<<"\n";
                    break;
                }
                seq++;
            }
        }
    }
    return 0;
}