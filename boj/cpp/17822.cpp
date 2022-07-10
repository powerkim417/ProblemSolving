#include <iostream>

using namespace std;

int n, m, t;
int arr[50][50];
bool same[50][50];
int x, d, k;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 12시 방향이 index 0을 의미
void rotate(int x, int d, int k){ // O(n*k*m). 최대 125000
    // cout<<"ROTATE\n";
    int temp;
    for (int i=0 ; i<n ; i++){ // 모든 원판 탐색
        // 원판 번호: i+1
        if ((i+1)%x!=0) continue;
        for (int loop=0 ; loop<k ; loop++){ // k회 회전
            if (d==0){ // 시계
                temp = arr[i][m-1];
                for (int j=m-1 ; j>0 ; j--){
                    arr[i][j] = arr[i][j-1];
                }
                arr[i][0] = temp;
            }
            else { // 반시계
                temp = arr[i][0];
                for (int j=0 ; j<m-1 ; j++){
                    arr[i][j] = arr[i][j+1];
                    // arr[0] = arr[1] 이므로 1시 방향의 수가 12시 방향으로 갔다. 즉 반시계
                }
                arr[i][m-1] = temp;
            }
        }
    }
}

bool remove(){
    // cout<<"REMOVE\n";
    bool ret = false;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            same[i][j] = false;
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            for (int dir=0 ; dir<4 ; dir++){
                int ni = i+dr[dir];
                int nj = j+dc[dir];
                if (ni<0 || ni>=n) continue;
                if (arr[i][j]==0) continue;
                if (arr[i][j] == arr[ni][(nj+m)%m]){
                    same[i][j] = true;
                    same[ni][(nj+m)%m] = true;
                    ret = true;
                }
            }
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (same[i][j]) arr[i][j] = 0;
        }
    }
    return ret;
}

void modify(){
    // cout<<"MODIFY\n";
    double avg = 0;
    int cnt = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            avg += arr[i][j];
            if (arr[i][j]!=0) cnt++;
        }
    }
    avg /= cnt;
    // cout<<"avg: "<<avg<<"\n";
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (arr[i][j]==0) continue;
            if (avg>arr[i][j]) arr[i][j]++;
            else if (avg<arr[i][j]) arr[i][j]--;
        }
    }
}

void print(){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"-------------\n";
}

int main(void){
    // n개의 원판, m개의 숫자, t회의 회전
    cin>>n>>m>>t;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>arr[i][j];
        }
    }
    for (int i=0 ; i<t ; i++){ // O(t*n*k*m) = 6250000
        cin>>x>>d>>k;
        // cout<<"TIME "<<(i+1)<<"\n";
        // print();
        rotate(x,d,k);
        // print();
        bool changed = remove();
        // print();
        // cout<<changed<<"\n";
        if (!changed) modify();
        // print();
    }

    int answer = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            answer += arr[i][j];
        }
    }
    cout<<answer;
    return 0;
}