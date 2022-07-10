#include <iostream>

using namespace std;

// N=1000000 이므로 nlogn 정렬 해야함
// "힙소트"
// max heap을 구성해서 루트에 오는 max 값을 가장 마지막으로 보내고, 힙 크기를 하나씩 줄임

int arr[1000000];
/*
0이 root
i의 왼쪽 자식은 2i+1, 오른쪽 자식은 2i+2
*/

void swap(int i1, int i2){
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
    return;
}

void heapify(int c, int size){
    // cout<<c<<" "<<size<<"\n";
    // cur를 루트로 하는 서브트리에서의 최대값을 cur로 올리는 작업
    while (c < size){
        int l = 2*c+1;
        int r = 2*c+2;
        int temp = c;
        if (l<size && arr[temp]<arr[l]) temp = l;
        if (r<size && arr[temp]<arr[r]) temp = r;
        if (temp == c) break;
        swap(temp, c);
        c = temp;
    }
    return;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    // Heap sort: 전체 배열을 한번에 받은 상태에서 heapify하는 방법
    // heapify해서 제일 큰 값을 맨 마지막 노드와 바꾸고, n-1개에 대해서 다시 heapify
    for (int i=(n-2)/2 ; i>=0 ; i--){ // 가장 마지막 리프 노드의 부모까지만 보면 됨.
    // 가장 마지막 리프 노드(n-1)의 부모((n-1-1)/2)가 가장 큰 '리프 아닌 노드'
        heapify(i, n);
    }

    for (int i=n-1 ; i>0 ; i--){
        swap(0, i); // heapify된 배열에서의 최대값을 맨 뒤로 보내고
        // cout<<arr[i];
        heapify(0, i); // 다시 heapify
    }
    for (int i=0 ; i<n ; i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
}