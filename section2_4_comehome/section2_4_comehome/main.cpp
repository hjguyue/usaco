//
/*
 ID: hjguyue1
 PROG: comehome
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int P = 0;
int edge[100][100] = {0};
int cows[100] = {0};

int main(int argc, const char * argv[])
{
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> P;
    for (int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++){
            edge[i][j] = 1000000;
            if (i == j) {
                edge[i][j] = 0;
            }
        }
    }
    for(int i = 0; i< P; i++){
        char c1,c2;
        int v1,v2,dis;
        cin >> c1 >> c2 >> dis;
        v1 = (c1 >= 97)? c1 - 97 + 26 : c1 - 65;
        v2 = (c2 >= 97)? c2 - 97 + 26 : c2 - 65;
        if (edge[v1][v2] > dis) {
            edge[v1][v2] = dis;
        }
        if (edge[v2][v1] > dis) {
            edge[v2][v1] = dis;
        }
        if (c1 < 97)
            cows[v1] = 1;
        if (c2 < 97)
            cows[v2] = 1;
    }
    
    for (int k = 0; k < 52; k++) {
        for(int i = 0; i < 52; i++){
            for(int j = 0; j < 52; j++){
                if (edge[i][j] > edge[i][k] + edge[k][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
    }
    
    int min = 1000000;
    int minID = 0;
    for(int i = 0; i <= 24; i++){
        if(min > edge[i][25] && cows[i] == 1){
            min = edge[i][25];
            minID = i;
        }
    }

    cout << char(minID+65) << " " << min << endl;
    return 0;
}

