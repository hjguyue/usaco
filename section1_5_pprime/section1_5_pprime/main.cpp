/*
 ID: hjguyue1
 PROG: pprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int a,b;
int primes[1300]={0};

bool isPrime(int k){
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

bool isPalindrome(int a){
    int len = 0;
    int temp = a;
    while(temp > 0){
        temp = temp / 10;
        len++;
    }
    int num[10];
    for(int i = 0; i < len; i++){
        num[i] = a % 10;
        a = a / 10;
    }
    for(int i = 0; 2*i < len; i++)
        if (num[i] != num[len-1-i])
            return false;
    return true;
}

int main(int argc, const char * argv[])
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> a >> b;
    
    int k = 0;
    for(int i = 2; i <= 10500; i++){
        if (isPrime(i)) {
            primes[k] = i;
            k++;
        }
    }

    if(b>=10000000)
        b = 10000000;
    for(int i = a; i <= b; i++){
        if (isPalindrome(i) && isPrime(i)) {
            cout << i << endl;
        }
    }
    
    
    return 0;
}

