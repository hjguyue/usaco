/*
 ID: hjguyue1
 PROG: milk3
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

class State{
    public :
    int out,in;
    int remain[3];
    State(int a,int b,int *num){
        out = a; in = b;
        for(int i = 0; i < 3; i++)
            remain[i] = num[i];
    }
    State(){}
};


int original[3] = {0};
int milk[3] = {0};
int logs[10000][3] = {0};
int logsNum = 0;
int process[6][2] = {{0,1},{1,0},{1,2},{2,1},{2,0},{0,2}};
State stack[10000];
int stackSize = 0;

int ans[10000] = {};
int ansNum = 0;

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

bool have(int *num){
    for(int i = 0; i < logsNum; i++)
        if (logs[i][0] == num[0] && logs[i][1] == num[1] && logs[i][2] == num[2])
            return true;
    return false;
}

int main(int argc, const char * argv[])
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());

    cin >> milk[0] >> milk[1] >> milk[2];
    
    original[2] = milk[2];
    for(int i = 0; i<6; i++){
        stack[stackSize] = State(process[i][0],process[i][1],original);
        stackSize++;
    }
    
    while(stackSize > 0){
        stackSize--;
        State state = stack[stackSize];
        if(state.remain[state.out] < milk[state.in] - state.remain[state.in]){
            state.remain[state.in] += state.remain[state.out];
            state.remain[state.out] = 0;
        }
        else{
            state.remain[state.out] -= milk[state.in] - state.remain[state.in];
            state.remain[state.in] = milk[state.in];
        }
        if (!have(state.remain)) {
            logsNum++;
            for(int i = 0; i < 3; i++){
                logs[logsNum-1][i] = state.remain[i];
            }
            for(int i = 0; i<6; i++){
                stack[stackSize] = State(process[i][0],process[i][1],state.remain);
                stackSize++;
            }
        }
    }
    
    for(int i = 0; i < logsNum; i++){
        if (logs[i][0] == 0) {
            ans[ansNum] = logs[i][2];
            ansNum++;
        }
    }
    
    qsort(ans, ansNum, sizeof(int), compare);
    int old = ans[0];
    cout << ans[0];
    for(int i = 1; i < ansNum; i++){
        if(ans[i] != old)
            cout << " " << ans[i];
    }
    cout << endl;
    
    return 0;
}

