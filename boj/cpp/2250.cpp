#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int left;
    int right;
};

node tree[10001];
int height[10001];
int loc[10001];
int parent[10001];
int root;

int idx = 1;

void inorder(int cur, int h){
    if (cur == -1) return;
    inorder(tree[cur].left, h+1);
    loc[cur] = idx++;
    height[cur] = h;
    inorder(tree[cur].right, h+1);
}

int main(void){
    int n;
    cin>>n;
    int c, l, r;
    root = n*(n+1)/2; // 모든 노드의 번호를 합함
    for (int i=0 ; i<=n ; i++){
        height[i] = 1;
        loc[i] = 0;
        parent[i] = 0;
    }
    for (int i=1 ; i<=n ; i++){
        cin>>c>>l>>r;
        tree[c] = {l, r};
        parent[l] = c;
        parent[r] = c;
        // 입력에서 자식으로는 한번씩만 언급되므로 언급된 자식의 번호를 다 빼주면 루트의 번호만 남음!
        if (l != -1) root -= l;
        if (r != -1) root -= r;
    }
    inorder(root, 1);

    int max_height = 0;
    for (int i=1 ; i<=n ; i++){
        // cout<<height[i]<<" "<<loc[i]<<"\n";
        if (max_height < height[i]) max_height = height[i];
    }

    int min[max_height+1], max[max_height+1];
    for (int h=1 ; h<=max_height ; h++){
        min[h] = 10001;
        max[h] = 0;
    }
    for (int i=1 ; i<=n ; i++){ // height별 최대최소 loc 갱신
        if (max[height[i]] < loc[i]) max[height[i]] = loc[i];
        if (min[height[i]] > loc[i]) min[height[i]] = loc[i];
    }

    int answer = 1;
    int width = -1;
    for (int h=1 ; h<=max_height ; h++){
        if (max[h]-min[h] > width){
            answer = h;
            width = max[h]-min[h];
        }
    }
    width += 1;
    cout<<answer<<" "<<width;
}