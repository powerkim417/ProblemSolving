#include <iostream>

using namespace std;

// CDLL 을 직접 구현!!
class Node {
    
    public: 
    int val;
    Node *next;
    Node *prev;

    Node(int v){
        val = v;
    }
};

class CDLL {
    public:
    Node *tail;
    Node *cur;
    int size;

    CDLL(){
        tail = nullptr;
        cur = nullptr;
        size = 0;
    }

    void insertLast(int i){
        Node *newnode = new Node(i);
        if (cur == nullptr) {
            newnode->next = newnode;
            newnode->prev = newnode;
            tail = newnode;
            cur = newnode;
        }
        else {
            newnode->next = tail->next;
            newnode->prev = tail;
            tail->next = newnode;
            newnode->next->prev = newnode;
            tail = newnode;
            cur = cur->next; // tail이 계속 cur
        }
        size++;
        // cout<<"node "<<cur->val<<" inserted"<<endl;
    }

    void moveNext(int k){
        for (int i=0 ; i<k ; i++){
            cur = cur->next;
        }
    }

    void removeCur(){
        cout<<cur->val;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur = cur->prev;
        // cout<<"->"<<cur->val<<endl;
        size--;
    }

    void printAll(){
        for (int i=0 ; i<size ; i++){
            cout<<cur->val<<" ";
            moveNext(1);
        }
        cout<<endl;
    }
};

int main(void){
    int n,k;
    cin>>n>>k;
    CDLL *cdll = new CDLL();

    for (int i=1 ; i<=n ; i++){
        cdll->insertLast(i);
    }
    cdll->moveNext(k); // tail의 바로 다음이 head
    cout<<"<";
    for (int i=0 ; i<n ; i++){
        if (i!=0) cout<<", ";
        cdll->removeCur();
        cdll->moveNext(k);
        // cdll->printAll();
    } 
    cout<<">";
}