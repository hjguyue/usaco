/*
 ID: hjguyue1
 PROG: lamps
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int N, C;
int onNum = 0;
int offNum = 0;
int ons[1000];
int offs[1000];

int shifts[4][1000] = {0};
int ans[16][1000] = {0};
int ansNum = 0;
int list[16] = {0};

int larger(int i, int maxID){
    for (int k = 0; k < N; k++) {
        if (ans[i][k] > ans[maxID][k]) {
            return 1;
        }
        if (ans[i][k] < ans[maxID][k]) {
            return -1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> C;
    int temp;
    while (cin >> temp) {
        if (temp == -1)
            break;
        ons[onNum] = temp-1;
        onNum ++;
    }
    while (cin >> temp) {
        if (temp == -1)
            break;
        offs[offNum] = temp-1;
        offNum ++;
    }
    
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < N; k++){
            if (i == 0) 
                shifts[i][k] = 1;
            if (i == 1 && k % 2 == 0) 
                shifts[i][k] = 1;
            if (i == 2 && k % 2 == 1)
                shifts[i][k] = 1;
            if (i == 3 && k % 3 == 0)
                shifts[i][k] = 1;
        }
    }
    
    for(int i = 0; i < 16; i++){
        int bits[4] = {0};
        int sum = 0;
        for(int t = 0; t < 4; t++){
            bits[t] = (i>>t) % 2;
            sum += bits[t];
        }
        int final[1000] = {0};
        if ((C - sum) % 2 == 0 && C >= sum) {
            for(int k = 0; k < 4; k++){
                for(int id = 0; id < N; id++){
                    final[id] += bits[k] * shifts[k][id];
                    final[id] = final[id] % 2;
                }
            }
            bool RIGHT = true;
            for(int id = 0; id < onNum; id++){
                if (final[ons[id]] == 1) {
                    RIGHT = false;
                    break;
                }
            }
            for(int id = 0; id < offNum; id++){
                if (final[offs[id]] == 0) {
                    RIGHT = false;
                    break;
                }
            }
            if (RIGHT) {
                for (int id = 0; id < N; id++) {
                    ans[ansNum][id] = final[id];
                }
                ansNum ++;
            }
        }
    }
    if (ansNum == 0) {
        cout <<"IMPOSSIBLE" << endl;
    }
    else{
        for(int k = 0; k < ansNum; k++){
            int maxID;
            for(int i = 0; i < ansNum; i++){
                if (list[i] == 0){
                    maxID = i;
                    break;
                }
            }
            for(int i = 0; i < ansNum; i++){
                if (list[i] == 0 && larger(i,maxID) == 1) {
                    maxID = i;
                }
            }
            list[maxID] = 1;
            for(int i = 0; i < N; i++){
                cout << 1-ans[maxID][i];
            }
            cout << endl;
        }
    }
    
    return 0;
}

