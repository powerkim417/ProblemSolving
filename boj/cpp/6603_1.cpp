// next_permutation 풀이
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
int num[12];
vector<int> choose; // k개중 6개. 즉 0 6개, 1 k-6개(0이 선택한 것!)
/* 0을 고르는 수로 하는 이유
7개중 6개를 고르는거면 0 0 0 0 0 0 1 부터 시작하는데,
그래야 123456, 123457 순서로 출력이 시작된다.
1을 고르는 수로 하면 0 1 1 1 1 1 1 부터 시작되면서
234567 순서로 출력이 시작됨.
*/
int main(void){
    while (cin>>k){
        if (k==0) return 0;
        choose.clear();
        for (int i=0 ; i<k ; i++) {
            cin>>num[i];
            // 0부터 넣되, 0이 고르는 수임을 헷갈리지 말 것
            if (i<6) choose.push_back(0);
            else choose.push_back(1);
        }
        do {
            for (int i=0 ; i<k ; i++){
                if (choose[i]==0) cout<<num[i]<<" ";
            }
            cout<<"\n";
        } while (next_permutation(choose.begin(), choose.end()));
        cout<<"\n";
    }
}