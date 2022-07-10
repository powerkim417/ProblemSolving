#include <iostream>

using namespace std;

int part[15000]; // i번째 재료의 숫자
bool exist[100001] = {}; // i번 숫자를 가진 재료의 존재 여부

// 이 풀이는 O(n) 수학이지만, 정렬하고 이분탐색으로 짝재료를 찾을 수도 있을 듯
// 이 풀이는 고유번호가 100000까지라서 exist[] 배열을 만들기에 부담이 적지만, 이 수가 크게 늘어난다면 이분탐색을 활용해야 할 듯

int main(void){
    int n,m,temp;
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        cin>>part[i];
        exist[part[i]] = true;
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        // part[i]와 맞는 재료(m-part[i]) 탐색
        if (part[i]*2==m) continue; // 숫자는 고유이므로 2개 존재할 수 없어서 m/2인 경우는 짝을 맞출 수 없다.
        if (m-part[i]<=0 || m-part[i]>100000) continue;
        if (exist[m-part[i]]){
            answer++;
            exist[m-part[i]] = false;
            exist[part[i]] = false;
        }
    }
    cout<<answer;
    return 0;
}