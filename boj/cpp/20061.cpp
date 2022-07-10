#include <iostream>
#include <vector>

using namespace std;

struct point {
    int x;
    int y;

    bool operator==(const point& that) const {
        return (x==that.x && y==that.y);
    }
};

bool blue[6][4] = {};
bool green[6][4] = {};
int score = 0;

void add_blue(int type, int x){
    int target_i = 5;
    switch (type){
        case 1:
        for (int i=1 ; i<6 ; i++){
            if (blue[i][x]){
                target_i = i-1;
                break;
            }
        }
        blue[target_i][x] = true;
        break;

        case 2:
        for (int i=2 ; i<6 ; i++){
            if (blue[i][x]){
                target_i = i-1;
                break;
            }
        }
        blue[target_i][x] = true; blue[target_i-1][x] = true;
        break;
        

        case 3:
        for (int i=1 ; i<6 ; i++){
            if (blue[i][x] || blue[i][x+1]){
                target_i = i-1;
                break;
            }
        }
        blue[target_i][x] = true; blue[target_i][x+1] = true;
        break;
    }
}

void add_green(int type, int y){
    int target_i = 5;
    switch (type){
        case 1:
        for (int i=1 ; i<6 ; i++){
            if (green[i][y]){
                target_i = i-1;
                break;
            }
        }
        green[target_i][y] = true;
        break;

        case 2:
        for (int i=1 ; i<6 ; i++){
            if (green[i][y] || green[i][y+1]){
                target_i = i-1;
                break;
            }
        }
        green[target_i][y] = true; green[target_i][y+1] = true;
        break;

        case 3:
        for (int i=2 ; i<6 ; i++){
            if (green[i][y]){
                target_i = i-1;
                break;
            }
        }
        green[target_i][y] = true; green[target_i-1][y] = true;
        break;
    }
}

// 서로 떨어진 두 줄이 한번에 채워지는 경우는 없음(블럭의 길이가 최대 2이므로)
void remove_and_drop(){
    // BLUE
    int lines = 0;
    int drop_bottom = -1;
    for (int i=5 ; i>=0 ; i--){
        if (blue[i][0] && blue[i][1] && blue[i][2] && blue[i][3]) {
            for (int j=0 ; j<4 ; j++) blue[i][j] = false;
            lines++;
            drop_bottom = i-1;
        }
    }
    if (lines > 0){
        for (int i=drop_bottom ; i>=0 ; i--){
            for (int j=0 ; j<4 ; j++){
                blue[i+lines][j] = blue[i][j];
            }
        }
        for (int i=lines-1 ; i>=0 ; i--){
            for (int j=0 ; j<4 ; j++) blue[i][j] = false;
        }
    }
    score += lines;
    
    // GREEN
    lines = 0;
    drop_bottom = -1;
    for (int i=5 ; i>=0 ; i--){
        if (green[i][0] && green[i][1] && green[i][2] && green[i][3]) {
            for (int j=0 ; j<4 ; j++) green[i][j] = false;
            lines++;
            drop_bottom = i-1;
        }
    }
    if (lines > 0){
        for (int i=drop_bottom ; i>=0 ; i--){
            for (int j=0 ; j<4 ; j++){
                green[i+lines][j] = green[i][j];
            }
        }
        for (int i=lines-1 ; i>=0 ; i--){
            for (int j=0 ; j<4 ; j++) green[i][j] = false;
        }
    }
    score += lines;
}

void push_away(){
    // BLUE
    int pushes = (blue[1][0] || blue[1][1] || blue[1][2] || blue[1][3]) + (blue[0][0] || blue[0][1] || blue[0][2] || blue[0][3]);
    if (pushes > 0){
        for (int i=5 ; i>=2 ; i--){
            for (int j=0 ; j<4 ; j++){
                blue[i][j] = blue[i-pushes][j];
            }
        }
        // i=1~0은 비워짐
        for (int i=1 ; i>=0 ; i--){
            for (int j=0 ; j<4 ; j++) blue[i][j] = false;
        }
    }
    // GREEN
    pushes = (green[1][0] || green[1][1] || green[1][2] || green[1][3]) + (green[0][0] || green[0][1] || green[0][2] || green[0][3]);
    if (pushes > 0){
        for (int i=5 ; i>=2 ; i--){
            for (int j=0 ; j<4 ; j++){
                green[i][j] = green[i-pushes][j];
            }
        }
        // i=1~0은 비워짐
        for (int i=1 ; i>=0 ; i--){
            for (int j=0 ; j<4 ; j++) green[i][j] = false;
        }
    }

}

void print(){
    cout<<"BLUE\n";
    for (int j=0 ; j<4 ; j++){
        for (int i=0 ; i<6 ; i++){
            cout<<blue[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"GREEN\n";
    for (int i=0 ; i<6 ; i++){
        for (int j=0 ; j<4 ; j++){
            cout<<green[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(void){
    int n;
    cin>>n;
    int t,x,y;
    for (int i=0 ; i<n ; i++){
        cin>>t>>x>>y;
        add_blue(t, x); add_green(t, y);
        remove_and_drop(); // 줄들이 없어지고 그 빈자리만큼 땡겨오는거라 반복되지 않음
        push_away();
    }
    // print();
    cout<<score<<"\n";
    int cnt = 0;
    for (int i=2 ; i<=5 ; i++){
        for (int j=0 ; j<4 ; j++){
            if (blue[i][j]) cnt++;
            if (green[i][j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}