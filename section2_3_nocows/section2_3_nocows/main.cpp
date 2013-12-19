//
/*
 ID: hjguyue1
 PROG: nocows
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

#define MODULO 9901
int N,K;
int num[100][200] = {0};

int main(int argc, const char * argv[])
{
//    ifstream fin("nocows.in");
//    ofstream fout("nocows.out");
//    cin.rdbuf(fin.rdbuf());
//    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> K;
    
    for(int i = 1; i <= K; i++)
        num[i][1] = 1;
    for(int i = 2; i <= K; i++){
        for(int j = 3; j <= N; j+=2){
            for(int t = 1; t <= j-2; t++){
                num[i][j] += (num[i-1][t] % MODULO)*(num[i-1][j-1-t] % MODULO) % MODULO;
                num[i][j] %= MODULO;
            }
        }
    }
    int solution = num[K][N] - num[K-1][N];
    solution %= MODULO;
    solution += MODULO;
    solution %= MODULO;
    cout << solution << endl;
    return 0;
}

