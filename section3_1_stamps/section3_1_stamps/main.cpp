/*
 ID: hjguyue1
 PROG: stamps
 LANG: C++
 */

#include <iostream>
#include <fstream>
#define MAX_VAL 2000000
using namespace std;

int K,N;
int value[100];
int f[MAX_VAL];

int main(int argc, const char * argv[])
{
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());

    cin >> K;   cin >> N;
    for(int i = 0; i < N; i++){
        cin >> value[i];
    }
    
    // initial:
    f[0] = 0;
    
    // dp:
    for(int i = 1; i <= MAX_VAL; i++){
        int Min = K + 1;
        for(int t = 0; t < N; t++){
            if((i >= value[t])){
                if (Min > (f[i-value[t]] + 1)) {
                    Min = f[i-value[t]] + 1;
                }
            }
        }
        f[i] = Min;
        if (Min > K) {
            cout << i - 1 << endl;
            return 0;
        }
    }
    
    return 0;
}

