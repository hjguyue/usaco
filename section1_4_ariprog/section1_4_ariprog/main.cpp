/*
 ID: hjguyue1
 PROG: ariprog
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int N,M;
int ans[10000][2] = {0};
int bis[125000] = {0};

bool bisquares(int n){
    bool ok = false;
    for(int i = (int)sqrt(n/2); i <= sqrt(n) && i <= M;i++){
        int temp = n - i * i;
        int sqt = (int)sqrt(temp);
        if ( sqt * sqt == temp) {
            ok = true;
        }
    }
    return ok;
}

int main(int argc, const char * argv[])
{
    
    ifstream in("ariprog.in");
    ofstream out("ariprog.out");
    
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    
    cin >> N >> M;
    
    for(int i = 0; i <= M * M * 2; i++){
        if (bisquares(i)) {
            bis[i] = 1;
        }
    }
    
    int size = 0;
    for(int i = 0; i <= M * M * 2; i++){
        if (bis[i] != 1) {
            continue;
        }
        for(int d = 1; d <= M * M * 2 / (N-1); d++){
            bool ok = true;
            int num = i;
            for(int k = 0; k < N; k++){
                if (bis[num] == 1) {
                    num += d;
                }
                else{
                    ok = false;
                    break;
                }
            }
            if (ok){
                ans[size][0] = i;
                ans[size][1] = d;
                size++;
            }
        }
    }
    if(size == 0){
        cout << "NONE" << endl;
        return 0;
    }
    
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-1-i; j++){
            if (ans[j][1] > ans[j+1][1]) {
                swap(ans[j][0], ans[j+1][0]);
                swap(ans[j][1], ans[j+1][1]);
            }
        }
    }
    for (int i = 0; i<size; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    
    
    return 0;
}

