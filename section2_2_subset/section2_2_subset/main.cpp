/*
 ID: hjguyue1
 PROG: subset
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int N = 0;
int S = 0;
long long int num[100000]={0};

int main(int argc, const char * argv[])
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    if (N % 4 == 1 || N % 4 == 2) {
        cout << 0 << endl;
        return 0;
    }
    S = (N+1)*N/4;
    
    num[0] = 1;
    for (int i = 1; i <= N; i++) {
        for(int k = i * (i+1)/2; k >= i; k--){
            num[k] += num[k-i];
        }
    }
    cout << num[S] / 2 << endl;
    
    return 0;
}

