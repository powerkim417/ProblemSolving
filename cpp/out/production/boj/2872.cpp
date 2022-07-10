#include <iostream>

using namespace std;

int n;
int num[300001]; // 이 배열에 i번째 위치의 책 번호를 저장하는게 아니라, i번째 번호 책의 위치를 저장하는 것이 아이디어!!

/*
아이디어!!!
우선, 책의 갯수가 N개라면 최대 N-1번만에 정렬 가능하다.
(최악의 경우가 N-1, N-2, ..., 2, 1번을 차례대로 빼서 올려놓는 경우)
123: 0
132: 2
213: 1
231: 1
312: 2
321: 2

n-1이 n보다 앞에 있는지 확인.
    앞에 있다면 다음으로 넘어감
    만약 뒤에 있다면 n-1을 뽑아서 맨 앞으로 넘김. 이 경우 n-2, ..., 1이 모두 n-1 뒤에 가게 되어 n-2번 다 뒤집어야 한다. 그럼 답은 1+n-2=n-1
n-2가 n-1보다 앞에 있는지 확인
    앞에 있다면 다음으로 넘어감
    만약 뒤에 있다면 n-2를 뽑아서 맨앞으로. 이 경우 나머지도 다 뽑아야 하므로 답은 n-2
...

이런 식으로 판단 가능!
*/

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int temp;
    for (int i=1 ; i<=n ; i++){
        cin>>temp;
        num[temp] = i; // temp번 책의 위치: i
    }

    for (int cur=n-1 ; cur>=1 ; cur--){
        if (num[cur]<num[cur+1]) continue;
        cout<<cur;
        return 0;
    }
    // 전부다 정렬된 경우
    cout<<"0";
    return 0;
}