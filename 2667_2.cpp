#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char map[25][25];
bool visited[25][25] = {};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int i, int j){
	return (i>=0 && i<n && j>=0 && j<n);
}

// 같은 풀이지만, 컴포넌트의 크기값을 처리하는 로직이 좀 더 간결함
// dfs함수의 반환값을 int로 해서 한 컴포넌트의 탐색이 끝날 때 그 컴포넌트의 크기를 반환할 수 있게 리턴값을 재귀화
int dfs(int i, int j){
	int ret = 1;
	visited[i][j] = true;
    // 오른쪽, 아래만 탐색하지 말고 왼쪽과 위도 봐야 하는데, '그' 모양이나 'U' 모양과 같은 경우에서 왼쪽이나 위로 가야 한 컴포넌트를 전부 볼 수 있기 때문
	for (int d=0 ; d<4 ; d++){
		int ni = i+dr[d];
		int nj = j+dc[d];
		if (isRange(ni, nj) && map[ni][nj]=='1' && !visited[ni][nj]) ret += dfs(ni, nj);
	}
	return ret;
}

int main() {
	cin>>n;
	vector<int> answer;
	for (int i=0 ; i<n ; i++){
		for (int j=0 ; j<n ; j++){
			cin>>map[i][j];
		}
	}
	for (int i=0 ; i<n ; i++){
		for (int j=0 ; j<n ; j++){
			if (map[i][j]=='1' && !visited[i][j]){
				answer.push_back(dfs(i, j));
			}
		}
	}
	cout<<answer.size()<<"\n";
	sort(answer.begin(), answer.end());
	for (int a: answer){
		cout<<a<<"\n";
	}
	return 0;
}