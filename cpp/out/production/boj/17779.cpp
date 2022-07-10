#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[21][21];
int num[21][21];
vector<int> cnt;
int answer = 40000+1;

int main(void){
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            cin>>map[i][j];
        }
    }
    // d1, d2 >= 1
    // 1 <= x < x+d1+d2 <= n
    // 1 <= y-d1 < y < y+d2 <= n
    for (int x=1 ; x<=n ; x++){
        for (int y=1 ; y<=n ; y++){
            for (int d1=1 ; d1<=n-2 ; d1++){
                for (int d2=1 ; d2<=n-2 ; d2++){
                    // 문제에 나온 부등식 조건들
                    if (!(x+d1+d2<=n)) continue;
                    if (!(d1+1<=y)) continue;
                    if (!(y+d2<=n)) continue;
                    for (int r=1 ; r<=n ; r++){
                        for (int c=1 ; c<=n ; c++){
                            // 여기 5구역의 범위를 먼저 정하는 것이 문제의 핵심!!!!
                            if (x+y<=r+c && r+c<=x+y+2*d2 && x-y<=r-c && r-c<=x-y+2*d1) num[r][c] = 5;
                            else if (1<=r && r<x+d1 && 1<=c && c<=y) num[r][c] = 1;
                            else if (1<=r && r<=x+d2 && y<c && c<=n) num[r][c] = 2;
                            else if (x+d1<=r && r<=n && 1<=c && c<y-d1+d2) num[r][c] = 3;
                            else if (x+d2<r && r<=n && y-d1+d2<=c && c<=n) num[r][c] = 4;
                        }
                    }
                    // // 특정 x,y,d1,d2일 때 구역 분할 현황 출력
                    // if (x==4 && y==3 && d1==1 && d2==1){
                    //     for (int r=1 ; r<=n ; r++){
                    //         for (int c=1 ; c<=n ; c++){
                    //             cout<<num[r][c]<<" ";
                    //         }
                    //         cout<<"\n";
                    //     }
                    //     return 0;
                    // }
                    cnt.clear();
                    for (int i=0 ; i<5 ; i++) cnt.push_back(0);
                    for (int r=1 ; r<=n ; r++){
                        for (int c=1 ; c<=n ; c++){
                            cnt[num[r][c]-1] += map[r][c];
                        }
                    }
                    sort(cnt.begin(), cnt.end());
                    // cout<<"<"<<x<<" "<<y<<" "<<d1<<" "<<d2<<">\n";
                    // for (int i=0 ; i<5 ; i++) cout<<cnt[i]<<" "; cout<<"\n";
                    if (cnt[4]-cnt[0] < answer) answer = cnt[4]-cnt[0];
                }
            }
        }
    }
    cout<<answer;
    return 0;
}