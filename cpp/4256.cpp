#include <iostream>
#include <vector>

using namespace std;

int n;
int pre[1000], in[1000]; // 1000개의 노드를 저장

void post(int ps, int pe, int is, int ie){ // [s, e)
    // 전달받은 배열의 전위순회 부분: [ps, pe)
    // 전달받은 배열의 중위순회 부분: [is, ie)
    if (ps == pe) return; // pre, is중 하나만 비교해도 됨. 어차피 같은 크기로 전달해줄 것이므로
    // cout<<"post("<<ps<<", "<<pe<<", "<<is<<", "<<ie<<") called\n";
    int root = pre[ps]; // 루트를 먼저 찾아내고,
    int root_idx;
    for (int i=is ; i<ie ; i++){
        if (in[i] == root){
            root_idx = i; // 0부터 시작하므로 주의!
            break;
        }
    }
    // 찾아낸 루트를 통해 pre와 in 순회순서를 각각 부모, 왼쪽서브트리, 오른쪽서브트리로 분리할 수 있다.
    // cout<<"root: "<<root<<"(inorder idx: "<<root_idx<<")\n";
    // cout<<"left subtree: pre["<<(ps+1)<<", "<<(ps+(root_idx-is)+1)<<") / in["<<(is)<<", "<<(root_idx)<<")\n";
    // cout<<"right subtree: pre["<<(ps+(root_idx-is)+1)<<", "<<pe<<") / in["<<(root_idx+1)<<", "<<(ie)<<")\n";
    // pre: [C][  L  ][  R  ]
    // in:  [  L  ][C][  R  ]
    
    // root_idx가 inorder 기준이므로 preorder 기준으로 Left subtree의 끝은 ps + (root_idx-is) 이다.
    // 인덱스 문제로 엄청 헤맸으니 조심할것!!!!
    // 왼쪽 서브트리: 전위순회 [ps+1, ps+(root_idx-is)+1) / 중위순회 [is, root_idx)
    // 오른쪽 서브트리: 전위순회 [ps+(root_idx-is)+1, pe) / 중위순회 [root_idx+1, ie)
    post(ps+1, ps+(root_idx-is)+1, is, root_idx); // 왼쪽 서브트리에 대한 preorder와 inorder를 알고 있으므로, 재귀
    post(ps+(root_idx-is)+1, pe, root_idx+1, ie);
    cout<<root<<" ";
}

// 트리의 전위, 중위 순회를 알고 있을 때 후위 순회를 찾아내는 문제!!!!!!
// 다른 둘이 주어졌을 때 나머지 하나를 찾아내는 것도 가능.
// 재귀 잘 활용할 것

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=0 ; i<n ; i++){
            cin>>pre[i];
        }
        for (int i=0 ; i<n ; i++){
            cin>>in[i];
        }
        post(0, n, 0, n); // 전위와 중위를 인풋으로 전달해야 함
        cout<<"\n";
    }
    return 0;
}