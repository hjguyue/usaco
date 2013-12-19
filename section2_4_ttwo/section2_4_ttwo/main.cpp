//
/*
 ID: hjguyue1
 PROG: ttwo
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int state[400][400] = {0};
int grid[10][10] = {0};

// 0: N  1:E  2:S  3:W
int C[3] = {0,0,0};
int F[3] = {0,0,0};

void move(int &dir, int &x, int &y){
    switch (dir) {
        case 0:
            if (x == 0 || grid[x-1][y] == 1) {
                dir++;
                dir%=4;
            }
            else{ x--;}
            break;
        case 1:
            if (y == 9 || grid[x][y+1] == 1) {
                dir++;
                dir%=4;
            }
            else{ y++;}
            break;
        case 2:
            if (x == 9 || grid[x+1][y] == 1) {
                dir++;
                dir%=4;
            }
            else{ x++;}
            break;
        case 3:
            if (y == 0 || grid[x][y-1] == 1) {
                dir++;
                dir%=4;
            }
            else{ y--;}
            break;
        default:
            break;
    }
}

int main(int argc, const char * argv[])
{
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    string line[10];
    for(int i = 0; i < 10; i++){
        cin >> line[i];
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (line[i][j] != '*') {
                grid[i][j] =   0;
            }
            if (line[i][j] == '*') {
                grid[i][j] = 1;
            }
            if (line[i][j] == 'C') {
                C[1] = i; C[2] = j;
            }
            if (line[i][j] == 'F') {
                F[1] = i; F[2] = j;
            }
        }
    }
    
    int step = 0;
    bool FIND = false;
    while(true){
        step ++;
        move(C[0],C[1],C[2]);
        move(F[0],F[1],F[2]);
//        cout << "--------" << endl;
//        cout << C[0] << "," << C[1] << "," << C[2] << endl;
//        cout << F[0] << "," << F[1] << "," << F[2] << endl;
        int x=0,y=0;
        for(int i = 0; i <= 2; i++){
            x = 10 * x + C[i];
            y = 10 * y + F[i];
        }
        if (C[1] == F[1] && C[2] == F[2]) {
            FIND = true;
            break;
        }
        if(state[x][y] == 1){
            break;
        }
        state[x][y] = 1;
    }
    if (!FIND) {
        cout << "0" << endl;
    }
    else
        cout << step << endl;
    
    return 0;
}

