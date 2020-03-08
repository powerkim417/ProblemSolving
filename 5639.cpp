#include <iostream>
#define MAX 100000
using namespace std;

// struct Node 포인터를 이용한 구현
struct Node {
    Node(int d): data(d), left(NULL), right(NULL){}
    int data;
    Node* left;
    Node* right;
};

Node* root;

void post(Node* cur){
    if (cur == NULL) return;
    post(cur->left);
    post(cur->right);
    cout<<cur->data<<"\n";
}

// 이진 탐색 트리!!!!!!

void insert(int x){ // 루트 있는 상태에서 노드 삽입
    Node* newNode = new Node(x);
    Node* curNode = root;
    // 루트부터 시작하여 비교.
    // 기준노드 기준으로 왼쪽이면 왼쪽 서브트리, 오른쪽이면 오른쪽 서브트리로 보내는데,
    // 왼쪽 서브트리가 비어있으면 왼쪽 자식으로 val을 넣고,
    // 왼쪽 서브트리가 차있으면 기준노드를 왼쪽 자식으로 변경하고, 재귀적으로 탐색
    while (1){
        if (x < curNode->data) { // left subtree
            if (!curNode->left) { // 왼쪽 서브트리가 NULL
                curNode->left = newNode;
                // cout<<newNode->data<<" places in "<<curNode->data<<"'s left\n";
                break;
            }
            else {
                curNode = curNode->left;
            }
        }
        else {
            if (!curNode->right) { // 왼쪽 서브트리가 NULL
                curNode->right = newNode;
                // cout<<newNode->data<<" places in "<<curNode->data<<"'s right\n";
                break;
            }
            else {
                curNode = curNode->right;
            }
        }
    }
}

int main(void){
    int temp;
    cin>>temp;
    root = new Node(temp);
    while (cin>>temp){
        insert(temp);
    }
    post(root);
    return 0;
}