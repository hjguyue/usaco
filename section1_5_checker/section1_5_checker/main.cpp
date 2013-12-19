/*
 ID: hjguyue1
 PROG: checker
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int N = 0;
int current = 0;
int g[15][15] = {0};
int ans[15] = {0};
int sum = 0;

int srow[15] = {0};
int scol[15] = {0};
int sL[30] = {0};
int sR[30] = {0};

bool safe(int row, int column)
{
    if(srow[row] == 0 && scol[column] == 0 && sL[row+column] == 0 && sR[row-column+N] == 0)
        return true;
    return false;
}

void handle(int row, int column){
    if (safe(row, column)) {
        if(row < N-1){
            ans[row] = column;
            srow[row] = 1;
            scol[column] = 1;
            sL[row+column] = 1;
            sR[row-column+N] = 1;
            for(int i = 0; i < N; i++){
                handle(row+1, i);
            }
            srow[row] = 0;
            scol[column] = 0;
            sL[row+column] = 0;
            sR[row-column+N] = 0;
        }
        if (row == N-1) {
            sum++;
            ans[row] = column;
            if (sum<=3) {
                cout << ans[0]+1;
                for(int j = 1; j < N; j++)
                    cout << " " << ans[j]+1;
                cout << endl;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    ifstream fin("checker.in");
    ofstream fout("checker.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        handle(0, i);
    }
    cout << sum << endl;
    
    return 0;
}

