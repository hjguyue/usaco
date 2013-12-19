//
/*
 ID: hjguyue1
 PROG: fracdec
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int N,D;

int main(int argc, const char * argv[])
{
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> D;
    
    if( N % D == 0){
        cout << N/D << ".0" << endl;
        return 0;
    }
    
    int temp = D;
    int x2 = 0;
    int x5 = 0;
    
    while(temp % 2 == 0) {
        temp = temp/2;
        x2++;
    }
    
    while(temp % 5 == 0){
        temp = temp / 5;
        x5++;
    }
    int x = (x2>x5)?x2:x5;
    
    int remain = temp;
    int list[10000] = {0};
    if (remain == 1) {
        list[0] = N/D;
        N = N - N/D * D;
        cout << list[0] << ".";
        for(int i = 1; i <= x; i++){
            list[i] = 10 * N / D;
            N = 10 * N - list[i] * D;
            cout << list[i];
        }
        cout << endl;
        return 0;
    }
    int y = 1;
    int num = 9;
    while (num%remain != 0) {
        num = num * 10 + 9;
        num %= remain;
        y++;
    }
    
    list[0] = N/D;
    N = N - N/D * D;
    int segment = 0;
    int number = list[0];
    if (number == 0) {
        segment ++;
    }
    while (number > 0) {
        number /= 10;
        segment++;
    }
    cout << list[0] << ".";
    segment++;
    for(int i = 1; i <= x+y; i++){
        if (i == x+1) {
            segment++;
            if (segment % 76 == 1) {
                cout << endl;
            }
            cout << "(";
        }
        list[i] = 10 * N / D;
        N = 10 * N - list[i] * D;
        segment++;
        if (segment % 76 == 1) {
            cout << endl;
        }
        cout << list[i];
    }
    segment++;
    if (segment % 76 == 1) {
        cout << endl;
    }
    cout <<")" << endl;
    return 0;
}

