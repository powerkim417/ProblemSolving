#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int food[10][10]; 
int A[10][10];

vector<int> tree[10][10]; // 나이

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

// vector.erase 사용해도 시간초과. (매 접근마다 O(N) 이라서 그런듯)
// priority_queue 사용해도 시간초과. (원인은 매번 배열 원소들을 다 뺐다가 다시 넣는게 오래 걸려서)
// vector<int> tree[10][10] 해서 n*n개의 vector를 만들고, 각 위치에 나무의 나이를 push_back한다.

// vector<int> tree[10][10] 으로 age를 받는 것이 포인트!!!!

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            food[i][j] = 5;
            cin>>A[i][j];
        }
    }
    int x, y, z;
    for (int i=0 ; i<m ; i++){
        cin>>x>>y>>z;
        tree[x-1][y-1].push_back(z);
    }
    vector<int> temp;
    int tree2food;
    // 봄과 여름을 따로 짜면 죽은 나무들에 대해 vector<int> dead[10][10]가 또 필요하므로 메모리 초과?
    // 그래서 양분값에 방해를 주지 않는 선에서 한번에 짜도록 한다.
    while (k--){
        // 봄, 여름
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                // 봄
                if (tree[i][j].size() == 0) continue;
                if (tree[i][j].size() > 1) sort(tree[i][j].begin(), tree[i][j].end());
                temp.clear();
                tree2food = 0;
                for (auto age: tree[i][j]){
                    if (age <= food[i][j]){ // 양분을 먹을 수 있는 경우
                        food[i][j] -= age;
                        age++;
                        temp.push_back(age);
                    }
                    else { // 양분을 먹을 수 없는 경우
                        tree2food += age/2;
                    }
                }
                tree[i][j] = temp;
                // 여름
                food[i][j] += tree2food;
            }
        }
        // 가을
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                for (auto age: tree[i][j]){
                    if (age%5 != 0) continue;
                    for (int d=0 ; d<8 ; d++){
                        if (!isRange(i+dr[d], j+dc[d])) continue;
                        tree[i+dr[d]][j+dc[d]].push_back(1); // 새로 추가되는 나무는 5의 배수가 아니므로 중간에 추가해도 가을 연산에 영향 X
                    }
                }
            }
        }
        // 겨울
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                food[i][j] += A[i][j];
            }
        }
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            answer += tree[i][j].size();
        }
    }
    cout<<answer;
    return 0;
}