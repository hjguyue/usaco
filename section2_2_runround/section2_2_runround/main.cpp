/*
 ID: hjguyue1
 PROG: runround
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int M = 0;

bool check(int k){
    int dig[10] = {0};
    int temp = k;
    int size = 0;
    int nums[100] = {0};
    int count[100] = {0};
    while (temp > 0) {
        nums[size] = temp % 10;
        dig[nums[size]] ++;
        temp /= 10;
        size ++;
    }
    for(int i = 1; i< 10; i++){
        if (dig[i] > 1) {
            return false;
        }
    }
    for(int i = 0; i < size/2; i++){
        swap(nums[i], nums[size-1-i]);
    }
    int current = 0;
    for(int i = 0; i < size; i++){
        current += nums[current];
        current %= size;
        count[current]++;
    }
    if (current != 0) {
        return false;
    }
    for(int i = 0; i < size; i++){
        if (count[i] != 1) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    ifstream fin("runround.in");
    ofstream fout("runround.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    cin >> M;
    M++;
    while (!check(M)) {
        M++;
    }
    cout << M << endl;
    
    return 0;
}

