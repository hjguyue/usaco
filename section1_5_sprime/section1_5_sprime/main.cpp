/*
 ID: hjguyue1
 PROG: sprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int primes[1300]={0};

bool isPrime(int k){
    if (k == 1) {
        return false;
    }
    if (k == 2) {
        return true;
    }
    int i = 0;
    while(primes[i] <= sqrt(k)){
        if (k % primes[i] == 0) {
            return false;
        }
        i++;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int N = 0;
    cin >> N;
    
    int k = 0;
    for(int i = 2; i <= 10500; i++){
        if (isPrime(i)) {
            primes[k] = i;
            k++;
        }
    }

    int oldNum[10000] = {2,3,5,7}; int old_size = 4;
    int newNum[10000] = {0}; int new_size = 0;
    for(int i = 1; i < N; i++){
        new_size = 0;
        for(int k = 0; k < old_size; k++){
            for(int t = 0; t <= 9; t++){
                int temp = 10 * oldNum[k] + t;
                if (isPrime(temp)) {
                    newNum[new_size] = temp;
                    new_size ++;
                }
            }
        }
        for(int j = 0; j < new_size; j++){
            oldNum[j] = newNum[j];
        }
        old_size = new_size;
    }
    for(int i = 0; i < old_size; i++)
        cout << oldNum[i] << endl;
    
    return 0;
}

