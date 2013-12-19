/*
 ID: hjguyue1
 PROG: frac1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;

class Number{
    public :
    int a;
    int b;
    double value;
    Number(int A, int B){
        a = A;
        b = B;
        value = (double) A / B;
    }
};

int compare (const Number & a, const Number & b)
{
    return ( a.value < b.value );
}

bool isFrac(int a, int b){
    int m = (a<b)?a:b;
    if (b == 1) {
        return true;
    }
    for(int i = 2; i <= m; i++)
        if (a%i == 0 && b%i == 0)
            return false;
    return true;
}

int main(int argc, const char * argv[])
{
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    vector<Number> vec;
    vec.push_back(Number(0,1));
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            vec.push_back(Number(i,j));
        }
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    for(int i = 0; i < vec.size(); i++){
        if (isFrac(vec.at(i).a, vec.at(i).b)) {
            cout << vec.at(i).a << "/" << vec.at(i).b << endl;
        }
    }
    
    return 0;
}

