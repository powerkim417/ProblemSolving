#include <iostream>

using namespace std;

int w,h,n;
typedef pair<int, int> P; // 방향, 거리
P store[101];

int abs(int x){
    return (x>0)?x:-x;
}

int min(int a, int b){
    return (a>b)?b:a;
}

int main(void){
    cin>>w>>h>>n;
    int dir, dist;
    // store[0]~store[n-1]: 각 상점
    // store[n]: 동근
    for (int i=0 ; i<n+1 ; i++){
        cin>>store[i].first>>store[i].second;
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        // 1. 같은 경계인 경우
        if (store[i].first == store[n].first){
            answer += abs(store[i].second-store[n].second);
        }
        // 2. 반대 경계인 경우(1-2, 3-4)
        else if (abs(store[i].first-store[n].first)==1 && store[i].first+store[n].first!=5){
            int temp = store[i].second + store[n].second;
            if (store[i].first+store[n].first == 3){ // 남북
                answer += h + min(temp, 2*w-temp);
            }
            else {
                answer += w + min(temp, 2*h-temp);
            }
        }
        // 3. 옆 경계인 경우
        else {
            if (store[i].first == 1){
                answer += store[n].second;
                if (store[n].first == 3) answer += store[i].second;
                if (store[n].first == 4) answer += w-store[i].second;
            }
            if (store[i].first == 2){
                answer += h-store[n].second;
                if (store[n].first == 3) answer += store[i].second;
                if (store[n].first == 4) answer += w-store[i].second;
            }
            if (store[i].first == 3){
                answer += store[n].second;
                if (store[n].first == 1) answer += store[i].second;
                if (store[n].first == 2) answer += h-store[i].second;
            }
            if (store[i].first == 4){
                answer += w-store[n].second;
                if (store[n].first == 1) answer += store[i].second;
                if (store[n].first == 2) answer += h-store[i].second;
            }
        }
    }
    cout<<answer;
    return 0;
}