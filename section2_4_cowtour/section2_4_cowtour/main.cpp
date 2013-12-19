//
/*
 ID: hjguyue1
 PROG: cowtour
 LANG: C++
 */
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int N = 0;

int loc[200][2] = {0};
int edge[200][200] = {0};
double val[200][200] = {0};
double maxVal[200] = {0};
int ID[200] = {0};
int IDNum = 0;
double minDis[200][200] = {0};

int main(int argc, const char * argv[])
{
    ifstream fin("cowtour.in");
    cin.rdbuf(fin.rdbuf());
    freopen("cowtour.out","w",stdout);    
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> loc[i][0] >> loc[i][1];
    }
    
    string line;
    getline(cin, line);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        for(int j = 0; j < N; j++){
            int a = (line[j] == '1') ? 1 : 0;
            edge[i][j] = a;
            if (edge[i][j] == 1 || i == j)
                val[i][j] = sqrt(pow(loc[i][0]-loc[j][0], 2)+pow(loc[i][1]-loc[j][1], 2));
            else
                val[i][j] = 1000000;
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (val[i][j] > val[i][k] + val[k][j]) {
                    val[i][j] = val[i][k] + val[k][j];
                }
            }
        }
    }
    
    double MAX = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (val[k][i] < 1000000 && maxVal[k] < val[k][i]) {
                maxVal[k] = val[k][i];
            }
            minDis[k][i] = 1000000;
        }
        ID[k] = -1;
        if (MAX < maxVal[k]) {
            MAX = maxVal[k];
        }
    }
    
    ID[0] = IDNum;
    for (int k = 0; k < N; k++) {
        if (ID[k] == -1) {
            IDNum++;
        }
        for (int i = 0; i < N; i++) {
            if (ID[i] == -1 && val[k][i] < 1000000) {
                ID[i] = IDNum;
            }
        }
    }
//    for (int k = 0; k < N; k++) {
//        cout << k << ":" << ID[k] << endl;
//    }
    
    for (int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++){
            if (val[i][j] >= 1000000) {
                double temp = maxVal[i] + maxVal[j] + sqrt(pow(loc[i][0]-loc[j][0], 2)+pow(loc[i][1]-loc[j][1], 2));
                if (minDis[ID[i]][ID[j]] > temp) {
                    minDis[ID[i]][ID[j]] = temp;
//                    cout << "i,j " <<  i << "," << j << " " <<minDis[ID[i]][ID[j]] << endl;
                }
            }
        }
    }
    
    double minVal = 1000000;
    for(int i = 0; i <= IDNum; i++){
        for(int j = 0; j <= IDNum; j++){
            if(minVal > minDis[i][j] && minDis[i][j] != 1000000){
                minVal = minDis[i][j];
            }
        }
    }
    
    if (minVal > MAX) {
        MAX = minVal;
    }
    
    printf("%.6f\n",MAX);
    
    return 0;
}

