//
/*
 ID: hjguyue1
 PROG: preface
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//I   1     L   50    M  1000
//V   5     C  100
//X  10     D  500
char chr[7] = {'I','V','X','L','C','D','M'};
int cnt[7] = {0};
int num[20] = {1,4,5,9,10,40,50,90,100,400,500,900,1000,4000};
string str[20] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
string ans[4000] = {};

int main(int argc, const char * argv[])
{
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int N = 0;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        int loc = 0;
        while (num[loc] < i) {
            loc++;
        }
        int number = i;
        string temp = "";
        while (number > 0) {
            int k = number / num[loc];
            for(int j = 0; j < k; j++){
                temp += str[loc];
            }
            number = number % num[loc];
            loc--;
        }
        ans[i] = temp;
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < ans[i].length(); j++){
            char s = ans[i][j];
            for(int t = 0; t < 7; t++)
                if (s == chr[t]) {
                    cnt[t]++;
                }
        }
    }
    for(int t = 0; t < 7; t++){
        if (cnt[t] > 0) {
            cout << chr[t] << " " << cnt[t] << endl;
        }
    }
    return 0;
}

