/*
 ID: hjguyue1
 PROG: humble
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int K, N;
int num[100];
int ans[1000010];
int Max = 0;
int cursor = 0;

int binarySearch(int val){
    int left = 0;
    int right = cursor;
    while (left < (right-1)) {
        if (ans[(left + right) / 2] >= val) {
            right = (left + right) / 2;
        }
        else{
            left = (left + right) / 2;
        }
    }
    if (ans[left] == val) {
        return left;
    }
    return right;
}

int main(int argc, const char * argv[])
{
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> K; cin >> N;
    for(int i = 0; i < K; i++)
        cin >> num[i];
    
    ans[0] = 1;
    Max = num[0];
    while(cursor <= N){
        int Min = 2100000000;
        for(int i = 0; i < K; i++){
            int x = Max / num[i] + 1;
            int temp = num[i] * ans[binarySearch(x)];
            if (temp > 0 && Min > temp)
                Min = temp;
        }
        cursor++;
        ans[cursor] = Min;
        Max = Min;
    }
    cout << ans[N] << endl;
    
    return 0;
}

