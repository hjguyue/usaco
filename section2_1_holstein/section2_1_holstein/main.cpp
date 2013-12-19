/*
 ID: hjguyue1
 PROG: holstein
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int V=0;
int G=0;
int needs[100] = {0};
int val[100][100] = {0};

int numbers[100000][15] = {0};
int ansNum = 0;
void show(int k){
    for(int i = 0; i < ansNum; i++){
        for(int j = 0; j < k; j++){
            cout << numbers[i][j] << " ";
        }
        cout << endl;
    }
}

void next(int k){
    bool has = false;
    int index = 0;
    for(int i = 0; i < k; i++){
        index = k - 1 - i;
        if (numbers[ansNum-1][index] < (G-i)) {
            has = true;
            break;
        }
    }
    if (!has)
        return;
    for(int i = 0; i < k; i++){
        if (i < index)
            numbers[ansNum][i] = numbers[ansNum-1][i];
        else if(i == index)
            numbers[ansNum][i] = numbers[ansNum-1][i]+1;
        else
            numbers[ansNum][i] = numbers[ansNum][index] + i - index;
    }
    ansNum ++;
    next(k);
}

// C(N,k):
void getRange(int k){
    for(int i = 0; i < k; i++){
        numbers[ansNum][i] = i+1;
    }
    ansNum++;
    next(k);
}

int main(int argc, const char * argv[])
{
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> V;
    for(int i = 0; i < V; i++){
        cin >> needs[i];
    }
    cin >> G;
    for(int i = 0; i < G; i++){
        for(int j = 0; j < V; j++){
            cin >> val[i][j];
        }
    }
    // get i feedtype:
    for(int i = 1; i <= G; i++){
        ansNum = 0;
        getRange(i);
        // for each solution:
        bool OK = true;
        for(int k = 0; k < ansNum; k++){
            OK = true;
            for(int j = 0; j < V; j++){
                int sum = 0;
                for(int t = 0; t < i; t++)
                    sum+=val[numbers[k][t]-1][j];
                if (sum < needs[j]) {
                    OK = false;
                    break;
                }
            }
            if (OK) {
                cout << i << " " << numbers[k][0];
                for(int p = 1; p < i; p++)
                    cout << " " << numbers[k][p];
                cout << endl;
                break;
            }
        }
        if (OK) {
            break;
        }
    }
    return 0;
}

