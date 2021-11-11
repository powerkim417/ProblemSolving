#include <iostream>
#include <queue>

using namespace std;

// n개가 하나로 합쳐지기 위해서는 무조건 n-1개의 연산이 이뤄져야 하는데,
// 이 때 더해지는 두 수는 이후 연산에도 계속 더해지기 때문에 먼저 더해지는 수가 가장 많이 더해진다
// 즉, 더 많이 더해져야 하는 수일수록 더 작으면 전체 합이 더 작아질 수 있다.
// 정렬 후, 가장 작은 두 수를 더한 뒤 pq에 다시 넣음. 그 뒤 나오는 가장 작은 두 수를 더한 뒤 또 pq에 넣음.. 반복
// 그리디 + 우선순위 큐
int main(void){
    int n; cin>>n;
    int temp;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0 ; i<n ; i++) {
        cin>>temp;
        pq.push(temp);
    }
    int answer = 0;
    // n=1일 때의 탈출문 일반화가 애매.. 어차피 딱 n-1번 도는 것을 알기 때문에 그냥 for문으로
    for (int i=0 ; i<n-1 ; i++){
        temp = pq.top(); pq.pop();
        temp += pq.top(); pq.pop();
        answer += temp;
        pq.push(temp);
    }
    cout<<answer;
    return 0;
}