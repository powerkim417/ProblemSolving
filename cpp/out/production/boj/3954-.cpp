#include <iostream>
#include <deque>

using namespace std;

int main(void){
    int T;
    cin>>T;
    for (int t=0 ; t<T ; t++){
        int size_m,size_c,size_i;
        cin>>size_m>>size_c>>size_i;
        int memory[size_m];
        char code[size_c];
        char input[size_i];
        int cur_m = 0;
        int cur_i = 0;
        int time = 0;
        bool isInfLoop = false;
        deque<int> loopin, loopout;
        deque<int> curloopin;
        for (int i=0 ; i<size_m ; i++){
            memory[i] = 0;
        }
        for (int i=0 ; i<size_c ; i++){
            cin>>code[i];
            if (code[i] == '[') loopin.push_back(i);
            else if (code[i] == ']') loopout.push_front(i);
        }
        for (int i=0 ; i<size_i ; i++){
            cin>>input[i];
        }
        for (int cur_c=0 ; cur_c<size_c ; ){
            if (time >= 50000000) {
                isInfLoop = true;
                break;
            }
            time++;
            switch (code[cur_c]){
                case '-':
                    memory[cur_m] = (memory[cur_m]-1)%256;
                    cur_c++;
                    break;
                case '+':
                    memory[cur_m] = (memory[cur_m]+1)%256;
                    cur_c++;
                    break;
                case '<':
                    cur_m = (cur_m-1)%256;
                    cur_c++;
                    break;
                case '>':
                    cur_m = (cur_m+1)%256;
                    cur_c++;
                    break;
                case '[':
                    if (memory[cur_m] == 0){
                        for (int j=0 ; j<loopin.size() ; j++){
                            if (loopin.at(j) == cur_c) {
                                cur_c = loopout.at(j);
                                // cout<<"go to "<<cur_c<<endl;
                                break;
                            }
                        }
                    }
                    else {
                        curloopin.push_back(cur_c);
                        cur_c++;
                    }
                    break;
                case ']':
                    if (memory[cur_m] != 0){
                        for (int j=0 ; j<loopout.size() ; j++){
                            if (loopout.at(j) == cur_c) {
                                cur_c = loopin.at(j);
                                // cout<<"Go to "<<cur_c<<endl;
                                break;
                            }
                        }
                    }
                    else {
                        curloopin.pop_back();
                        cur_c++;
                    }
                    break;
                case '.':
                    // cout<<memory[cur_m];
                    cur_c++;
                    break;
                case ',':
                    memory[cur_m] = (cur_i == size_i-1) ? 255 : input[cur_i++];
                    cur_c++;
                    break;
            }
        }
        int curloopout = -1;
        // cout<<"-----"<<endl;
        // cout<<loopin.size()<<endl;
        // cout<<loopout.size()<<endl;
        // cout<<curloopin.size()<<endl;
        for (int i=0 ; i<loopin.size() ; i++){
            if (loopin.at(i) == curloopin.back()) {
                curloopout = loopout.at(i);
                break;
            }
        }
        if (isInfLoop) cout<<"Loops "<<curloopin.back()<<" "<<curloopout<<endl;
        else cout<<"Terminates"<<endl;
    }
}