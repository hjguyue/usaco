//
/*
 ID: hjguyue1
 PROG: zerosum
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <strstream>
using namespace std;

int num[10] = {0};
int result[10] = {0};
int type[10] = {0};
string strs[10000];
int cnt = 0;

int main(int argc, const char * argv[])
{
    ifstream fin("zerosum.in");
    ofstream fout("zerosum.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());

    int N = 0;
    cin >> N;
    
    int count = (int)pow(3, N-1);
    
    for(int i = 0; i < count; i++){
        int temp = i;
        for(int k = 0; k < N-1; k++){
            num[k] = temp % 3;
            temp = temp / 3;
        }
        int size = 0;
        result[size] = 1;
        for (int j = 0; j < N-1; j++) {
            if (num[j] == 0) {
                result[size] = result[size] * 10 + (j+2);
            }
            else {
                type[size] = num[j];
                size++;
                result[size] = j+2;
            }
        }
        int val = result[0];
        for (int j = 1; j <= size; j++) {
            if (type[j-1] == 1) {
                val += result[j];
            }
            if (type[j-1] == 2) {
                val -= result[j];
            }
        }
        if (val == 0) {
            strs[cnt] = "1";
            for (int j = 0; j <= N-2; j++) {
                int next = j+2;
                strstream ss;
                string stemp;
                ss << next;
                ss >> stemp;
                if (num[j] == 0) {
                    strs[cnt] += " "+stemp;
                }
                if (num[j] == 1) {
                    strs[cnt] += "+"+stemp;
                }
                if (num[j] == 2) {
                    strs[cnt] += "-"+stemp;
                }
            }
            cnt++;
        }
    }
    
    for(int i = 0; i < cnt-1; i++){
        for(int j = 0; j < cnt-1-i; j++){
            if (strs[j].compare(strs[j+1]) > 0) {
                swap(strs[j], strs[j+1]);
            }
        }
        
    }
    for (int k = 0; k<cnt; k++) {
        cout << strs[k] << endl;;
    }
    
    return 0;
}

