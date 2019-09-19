#include <iostream>
#include <cstring>
using namespace std;
void ascendSort(int rank[], int right[], int score[], int teamno[], int size) //오름차순으로 만드는 버블소트
{
    int i,j,temp;
    for (i=size-1 ; i>=0 ; i--)
    {
        for (j=0 ; j<i ; j++)
        {
            if (rank[j]>rank[j+1]) // 랭크숫자가 낮은 순부터
            {
                temp = rank[j];
                rank[j] = rank[j+1];
                rank[j+1] = temp;
                temp = right[j];
                right[j] = right[j+1];
                right[j+1] = temp;
                temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
                temp = teamno[j];
                teamno[j] = teamno[j+1];
                teamno[j+1] = temp;
            }
        }
    }
}
int main(void){
    int n,m,q;
    cin>>n>>m>>q;
    int score[n];
    int wrong[n][m];
    int right[n];
    int rank[n];
    int teamno[n];
    bool correct[n][m];
    for (int i=0 ; i<n ; i++){
        score[i] = 0;
        right[i] = 0;
        rank[i] = 1;
        teamno[i] = i+1;
        for (int j=0 ; j<m ; j++){
            wrong[i][j] = 0;
            correct[i][j] = false;
        }
    } //initialization
    int time, team, quest;
    char res[4];
    for (int i=0 ; i<q ; i++){
        cin>>time>>team>>quest>>res;
        if (strcmp(res, "AC")==0){
            if (correct[team-1][quest-1]) continue; // 이미 맞은 문제에 대한 제출은 거름
            correct[team-1][quest-1] = true;
            score[team-1] += wrong[team-1][quest-1]*20 + time;
            right[team-1]++;
        }
        else
            wrong[team-1][quest-1]++;
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (right[i]<right[j]) rank[i]++; // 맞은 순
            else if (right[i] == right[j]){
                if (score[i]>score[j]) rank[i]++; // 점수 순
                else if (score[i] == score[j]){
                    if (teamno[i]>teamno[j]) rank[i]++; // 팀 번호 순
                }
            }
        }
    }
    ascendSort(rank, right, score, teamno, n);
    for (int i=0 ; i<n ; i++){
        cout<<teamno[i]<<" "<<right[i]<<" "<<score[i]<<endl;
    }
}