#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100][100];
int occur[101];
vector<pair<int, int>> v; // 횟수, 숫자

// 횟수 오름차순, 횟수 같으면 숫자 오름차순
int main(void){
    int r,c,k;
    cin>>r>>c>>k;
    r--; c--;
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++){
            cin>>arr[i][j];
        }
    }
    int time = 0;
    int row = 3, col = 3; // 현재 배열에서 행과 열의 길이
    // 초기 A배열의 원소의 크기가 최대 100이고, 최대 100행, 100열이므로 늘어나서 새로 생기는 숫자들의 최대값도 100이다.
    while (arr[r][c] != k){
        int newrow = row, newcol = col;
        if (row >= col){
            // R 연산
            for (int i=0 ; i<row ; i++){
                // occur 배열 초기화
                for (int j=1 ; j<=100 ; j++) occur[j] = 0;
                // 행에서 숫자별 등장 횟수 카운팅
                for (int j=0 ; j<col ; j++){
                    occur[arr[i][j]]++;
                }
                // 숫자쌍 생성
                for (int j=1 ; j<=100 ; j++){
                    if (occur[j] != 0) v.push_back({occur[j], j});
                }
                sort(v.begin(), v.end());
                // for (int j=0 ; j<v.size() ; j++){
                //     cout<<v[j].second<<" "<<v[j].first<<" ";
                // }
                // cout<<"\n";
                // 생성된 숫자쌍 값을 arr 배열에 넣음
                int temp = v.size()*2;
                if (temp > newcol) newcol = temp; 
                for (int j=0 ; j<temp ; j+=2){
                    arr[i][j] = v[j/2].second;
                    arr[i][j+1] = v[j/2].first;
                    if (j==98) break; // arr[i][99] 까지만 저장되도록
                }
                for (int j=temp ; j<100 ; j+=2){ // 새 값이 들어가고 남는 공간은 0으로 채운다.
                    arr[i][j] = 0;
                    arr[i][j+1] = 0;
                }
                v.clear();
            }
        }
        else {
            // C 연산
            for (int i=0 ; i<col ; i++){
                // occur 배열 초기화
                for (int j=1 ; j<=100 ; j++) occur[j] = 0;
                // 행에서 숫자별 등장 횟수 카운팅
                for (int j=0 ; j<row ; j++){
                    occur[arr[j][i]]++;
                }
                // 숫자쌍 생성
                for (int j=1 ; j<=100 ; j++){
                    if (occur[j] != 0 ) v.push_back({occur[j], j});
                }
                sort(v.begin(), v.end());
                // 생성된 숫자쌍 값을 arr 배열에 넣음
                int temp = v.size()*2;
                if (temp > newrow) newrow = temp; 
                for (int j=0 ; j<temp ; j+=2){
                    arr[j][i] = v[j/2].second;
                    arr[j+1][i] = v[j/2].first;
                    if (j==98) break; // arr[99][i] 까지만 저장되도록
                }
                for (int j=temp ; j<100 ; j+=2){ // 새 값이 들어가고 남는 공간은 0으로 채운다.
                    arr[j][i] = 0;
                    arr[j+1][i] = 0;
                }
                v.clear();
            }
        }
        row = newrow;
        col = newcol;
        // for (int i=0 ; i<row ; i++){
        //     for (int j=0 ; j<col ; j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"------\n";
        time++;
        if (time > 100){
            cout<<"-1";
            return 0;
        }
    }
    cout<<time;
    return 0;
}