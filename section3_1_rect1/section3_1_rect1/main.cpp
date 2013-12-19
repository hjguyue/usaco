/*
 ID: hjguyue1
 PROG: rect1
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int A,B,N;
int s[1002][2];
int e[1002][2];
int color[1002];
int ans[2502];

int x[10002];
int y[10002];
int lengthX;
int lengthY;
int rx[2005];
int ry[2005];
int lx[2005];
int ly[2005];

// 1: interact
int judge(int i, int j, int k){
    if (rx[i] >= s[k][0] && rx[i+1] <= e[k][0] && ry[j] >= s[k][1] && ry[j+1] <= e[k][1]) {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    ifstream fin("rect1.in");
    ofstream fout("rect1.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> A; cin >> B; cin >> N;
    s[0][0] = 0;    s[0][1] = 0;
    e[0][0] = A;    e[0][1] = B;
    x[0] = 1; x[A] = 1;
    y[0] = 1; y[B] = 1;
    color[0] = 1;
    
    for(int i = 1; i <= N; i++){
        cin >> s[i][0]; x[s[i][0]] = 1;
        cin >> s[i][1]; y[s[i][1]] = 1;
        cin >> e[i][0]; x[e[i][0]] = 1;
        cin >> e[i][1]; y[e[i][1]] = 1;
        cin >> color[i];
    }
    
    for(int i = 0; i <= A; i++){
        if (x[i] == 1) {
            rx[lengthX] = i;
            lengthX++;
        }
    }
    lengthX--;

    for(int i = 0; i <= B; i++){
        if (y[i] == 1) {
            ry[lengthY] = i;
            lengthY++;
        }
    }
    lengthY--;
    
    for(int i = 0; i < lengthX; i ++){
        lx[i] = rx[i+1] - rx[i];
    }
    for(int i = 0; i < lengthY; i ++){
        ly[i] = ry[i+1] - ry[i];
    }
    
    for(int i = 0; i < lengthX; i++){
        for(int j = 0; j < lengthY; j++){
            for(int k = N; k >= 0; k--){
                if (judge(i, j, k) == 1) {
                    ans[color[k]] += lx[i] * ly[j];
                    break;
                }
            }
        }
    }
    
    for(int i = 1; i <= 2500; i++){
        if (ans[i] != 0)
            cout << i << " " << ans[i] << endl;
    }
    
    return 0;
}

