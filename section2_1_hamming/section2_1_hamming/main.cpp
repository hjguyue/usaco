/*
 ID: hjguyue1
 PROG: hamming
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int N,B,D;
int ans[100];
int num = 0;

int dis(int a, int b){
    int cnt = 0;
    for(int i = 0; i < B; i++){
        if(a %2 != b % 2)
            cnt++;
        a = a >> 1;
        b = b >> 1;
    }
    return cnt;
}

int main(int argc, const char * argv[])
{
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> B >> D;
    
    num = 1;
    ans[0] = 0;
    while (num < N) {
        for(int i = ans[num-1]+1; ; i++){
            bool OK = true;
            for(int k = 0; k < num; k++){
                if (dis(i,ans[k]) < D) {
                    OK = false;
                }
            }
            if (OK) {
                ans[num] = i;
                num++;
                break;
            }
        }
    }
    for(int i = 0; i < num; i++){
        cout << ans[i];
        if (i % 10 != 9 && i != num-1)
            cout << " ";
        if(i % 10 == 9)
            cout << endl;
    }
    if (num % 10 != 0) {
        cout << endl;
    }
    
    return 0;
}

