#include <iostream>

using namespace std;

// 배열을 이용한 max heap 구현
// index를 2배하면 왼쪽 자식, index를 2배+1 하면 오른쪽 자식
// index를 2로 나누면 부모

// 특정 노드의 자식 여부를 볼 때 2i+1에 접근하므로 단순히 최대 크기만큼 만들면 터질 수 있음
// N의 2배보다 큰 2의 거듭제곱 수를 배열 크기로 둘 것
int a[262145];
int heap_size = 0;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void remove_heapify(){
    // root로 들어간 마지막 값을 왼쪽 자식부터 비교하여 아래로 내린다.
    for (int cur=1 ; cur<=heap_size ;){
        int target_idx;
        if (2*cur > heap_size) break;
        // 두 자식중 큰 자식이랑 swap해야 하는데, 자식이 하나 뿐이면 그 자식을 선택
        if (2*cur + 1 > heap_size) target_idx = 2*cur;
        else { // 두 자식 다 존재
            if (a[2*cur] > a[2*cur + 1]) target_idx = 2*cur;
            else target_idx = 2*cur + 1;
        }
        if (a[cur] < a[target_idx]){
            swap(a[cur], a[target_idx]);
            cur = target_idx;
        }
        else break;
    }
}

void insert_heapify(){
    // 마지막 값을 부모와 비교하면서 위로 올린다.
    for (int cur=heap_size ; cur>=1 ; cur /= 2){
        // cur/2 가 가장 작게 나오는 index인데, 이게 1 이상이어야 한다.
        if (cur/2 >= 1 && a[cur]>a[cur/2]){
            swap(a[cur], a[cur/2]);
        }
        else break;
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int x;
    for (int i=0 ; i<n ; i++){
        cin>>x;
        if (x==0){ // max 출력 후 배열에서 제거
            if (heap_size == 0){
                cout<<"0\n";
                continue;
            }
            cout<<a[1]<<"\n";
            a[1] = a[heap_size];
            heap_size--;
            remove_heapify();
        }
        else { // 자연수 x를 넣는다.
            heap_size++;
            a[heap_size] = x;
            insert_heapify();
        }
        // cout<<"heap: ";
        // for (int j=1 ; j<=heap_size ; j++){
        //     cout<<a[j]<<" ";
        // }
        // cout<<endl;
    }
}