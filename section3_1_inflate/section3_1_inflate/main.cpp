/*
 ID: hjguyue1
 PROG: inflate
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int M,N;
int points[10005];
int minutes[10005];
int Ans[10005];
int Stat[10005];

int func(int m){
    if (Stat[m] == 1) {
        return Ans[m];
    }
    int Max = 0;
    for(int i = 0; i < N; i++){
        if (m < minutes[i]) {
            continue;
        }
        int temp = points[i] + func(m-minutes[i]);
        if (Max < temp) {
            Max = temp;
        }
    }
    Stat[m] = 1;
    Ans[m] = Max;
    return Ans[m];
}

int main(int argc, const char * argv[])
{
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> M; cin >> N;
    for(int i = 0; i < N; i++){
        cin >> points[i];
        cin >> minutes[i];
    }
    
    Stat[0] = 1;
    Ans[0] = 0;
    cout << func(M) << endl;
    
    return 0;
}

