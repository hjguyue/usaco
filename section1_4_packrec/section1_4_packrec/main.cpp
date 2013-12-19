/*
 ID: hjguyue1
 PROG: packrec
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int rec[4][2]={0};
int serial[24][4]={};
//3 2 1 0;2 3 1 0;3 1 2 0;1 3 2 0;2 1 3 0;1 2 3 0;3 2 0 1;2 3 0 1;3 0 2 1;0 3 2 1;2 0 3 1;0 2 3 1;
//3 1 0 2;1 3 0 2;3 0 1 2;0 3 1 2;1 0 3 2;0 1 3 2;2 1 0 3;1 2 0 3;2 0 1 3;0 2 1 3;1 0 2 3;0 1 2 3;
int serial_2[16][4]={0};
//0 0 0 0;1 0 0 0;0 1 0 0;1 1 0 0;0 0 1 0;1 0 1 0;0 1 1 0;1 1 1 0;0 0 0 1;1 0 0 1;0 1 0 1;1 1 0 1;0 0 1 1;1 0 1 1;0 1 1 1;1 1 1 1;

int ans[10000] = {0};
int ansSize = 0;
int Min = 10000;

void update(int wide,int height){
    if (height * wide <= Min) {
        if (height * wide < Min) {
            Min = height * wide;
            ansSize = 0;
        }
        ans[ansSize] = height+wide-max(height, wide);
        ansSize++;
    }
}

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main(int argc, const char * argv[])
{
    ifstream fin("packrec.in");
    ofstream fout("packrec.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    for(int i = 0; i < 4; i++){
        cin >> rec[i][0] >> rec[i][1];
    }
    
    // serial:
    int K = 0;
    for(int i = 0; i < 24; i++){
        while (true) {
            int temp = K;
            for(int j = 0; j < 4; j++){
                serial[i][j] = temp % 4;
                temp = temp / 4;
            }
            K++;
            if (!(serial[i][0] == serial[i][1] || serial[i][0] == serial[i][2] || serial[i][0] == serial[i][3] ||
                serial[i][1] == serial[i][2] || serial[i][1] == serial[i][3] || serial[i][2] == serial[i][3]))
                break;
        }
    }
    // serial_2:
    for(int i = 0; i < 16; i++){
        int temp = i;
        for(int j = 0; j < 4; j++){
            serial_2[i][j] = temp % 2;
            temp = temp >> 1;
        }
    }
    
    int wide = 0;
    int height = 0;
    for(int s = 0; s < 24; s++){
        for(int t = 0; t < 16; t++){
            int wides[4]={0};
            int heights[4]={0};
            for(int i = 0; i < 4; i++){
                wides[i] = rec[serial[s][i]][serial_2[t][i]];
                heights[i] = rec[serial[s][i]][1-serial_2[t][i]];
            }
            // 1:
            height = max(max(max(heights[0],heights[1]),heights[2]),heights[3]);
            wide = wides[0]+wides[1]+wides[2]+wides[3];
            update(wide, height);
            // 2:
            height = heights[0]+max(max(heights[1],heights[2]),heights[3]);
            wide = max(wides[1]+wides[2]+wides[3],wides[0]);
            update(wide, height);
            // 3:
            height = max(max(heights[0]+heights[3],heights[1]+heights[3]),heights[2]);
            wide = wides[2]+max(wides[0]+wides[1],wides[3]);
            update(wide, height);
            // 4:
            height = max(max(heights[1]+heights[3],heights[0]),heights[2]);
            wide = wides[0]+wides[2]+max(wides[1],wides[3]);
            update(wide, height);
            // 5:
            height = max(max(heights[0]+heights[1],heights[2]),heights[3]);
            wide = wides[2]+wides[3]+max(wides[0],wides[1]);
            update(wide, height);
            // 6:
            height = max(heights[0]+heights[3],heights[1]+heights[2]);
            wide = max(wides[2]+wides[3],wides[0]+wides[1]);
            if(!(wides[0]>wides[3] || heights[2] < heights[3] || wides[0]+wides[1] > wides[2] +wides[3])){
                update(wide, height);
            }
        }
    }
    cout << Min << endl;
    qsort(ans, ansSize, sizeof(int),compare);
    cout << ans[0] << " " << Min/ans[0] << endl;
    int old = ans[0];
    for(int i = 1; i < ansSize; i++){
        if(ans[i] != old){
            cout << ans[i] << " " << Min/ans[i] << endl;
            old = ans[i];
        }
    }
    
    return 0;
}

