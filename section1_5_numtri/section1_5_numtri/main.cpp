/*
 ID: hjguyue1
 PROG: numtri
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int num[1000][1000];

int main(int argc, const char * argv[])
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());

    int R = 0;
    cin >> R;
    for(int i = 0; i < R; i++){
        for(int j = 0; j <= i; j++){
            cin >> num[i][j];
        }
    }
    if(R == 1){
        cout << num[0][0] << endl;
        return 0;
    }
    
    for(int i = 1; i < R; i++){
        for(int j = 0; j <= i; j++){
            int Max = 0;
            if (j == 0)
                Max = num[i-1][j];
            if (j == i)
                Max = num[i-1][j-1];
            if(j != 0 && j != i){
                Max = max(num[i-1][j-1], num[i-1][j]);
            }
            num[i][j] += Max;
        }
    }
    int max = 0;
    for(int i = 0; i < R; i++){
        if (max < num[R-1][i]) {
            max = num[R-1][i];
        }
    }
    cout << max << endl;
    
    return 0;
}

