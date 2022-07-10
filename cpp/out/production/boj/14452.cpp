#include <iostream>
#include <queue>
#include <functional> // greater

using namespace std;

int n, T;
int dur[10000];

// 이진 탐색
/* 무대에 최소 몇마리까지가 제한 시간 안에 수행이 가능한지 찾는 문제
____----- 형식으로 시뮬레이션을 돌린다
*/
priority_queue<int, vector<int>, greater<int>> pq;
// vector로 하면 중간에 0을 교체하려 찾는데 오래 걸리므로 0이 앞에 자동으로 나오는 pq 사용

bool able(int k){ // 무대 크기 k마리일 때
    while (!pq.empty()) pq.pop(); // 초기화
    int time;
    int cur = 0;
    int add;
    for (int i=0 ; i<k ; i++) {
        pq.push(dur[cur++]); // 처음 k마리 채우고 시작
    }
    /* pq에 교체로 투입되는 소의 시간을 넣을 때의 아이디어!!!!!!!
    ex) 5 4 3 7 8 2 이 있고, 무대 크기가 3일 때
    pq = 3, 4, 5, 7
    3초 뒤 pq = 4-3, 5-3, 7-3, 8
    4초 뒤 pq = 5-3-1, 2, 7-3-1, 8-1
    중간에 들어간 원소들은 결국 각각 최초 기준으로 8+3초, 2+3+1초 후에 끝난다.
    결론적으로 구하고자 하는 시간은 모든 dur을 넣었을 때 가장 마지막 값과 관련이 있다.
    이를 한번에 구하기 위해 초마다 pq의 값이 깎이는 개념이 아니라, 해당 초만큼을 더한 새 값이 더해진다고 구현(깎이는 것은 구현하기도 힘듦)
    <개념 적용 후>
    0초일 때 pq = 3, 4, 5, 7
    3초 뒤 pq = 4, 5, 7, 8+3
    4초 뒤 pq = 5, 2+4, 7, 8+3
    (여기서 +3, +4는 각각 넣기 전 top값과 같음. 결국 해당 소가 끝난 시간이 새 기점이므로)
    */
    while (cur < n){ // 다 차있을 때. cur가 n-1번째 원소까지 다 넣고 나면 탈출
        time = pq.top();
        pq.pop();
        pq.push(dur[cur++]+time);
    }
    while (pq.size() != 1){
        pq.pop(); // pq 사이즈가 1이 될 때까지 뺀다. 가장 마지막 원소를 찾기 위해
    }
    // cout<<pq.top()<<"\n";
    // pq.top()이 걸린 시간이 됨
    if (pq.top() <= T) return true;
    else return false;
}

int main(void){
    cin>>n>>T;
    for (int i=0 ; i<n ; i++){
        cin>>dur[i];
    }
    int L = 1-1, R = n, M; // 무대의 크기
    // 가능한 최소값을 골라야 하므로 LR: XO 형태가 되어 R을 반환하는 식으로 가야 함
    // 그러려면 R에 1도 들어가야 하므로 L=1-1로 초기화
    while (L+1<R){
        M = (L+R)>>1;
        // cout<<"M="<<M<<": "<<able(M)<<"\n";
        if (!able(M)){
            L = M;
        }
        else {
            R = M;
        }
    }
    // L R
    // X O
    cout<<R;
    return 0;
}