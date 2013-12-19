//
/*
 ID: hjguyue1
 PROG: maze1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int W,H;
int grid[300][300] = {0};
int grid2[300][300] = {0};
int minMov[300][300] = {0};
int out[300][2] = {0};
int outNum = 0;

int main(int argc, const char * argv[])
{
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> W >> H;
    
    string line;
    getline(cin, line);
    for(int i = 0; i <= 2 * H; i++){
        getline(cin, line);
        for (int j = 0; j <= 2 * W; j++) {
            if (line[j] != ' ')
                grid[i][j] = 9;
            else
                grid[i][j] = 0;
            minMov[i][j] = 20000;
        }
    }
    
    for(int i = 0; i <= 2 * H; i++){
        for (int j = 0; j <= 2 * W; j++) {
            if (grid[i][j] == 0 && (i == 0 || j == 0 || i == 2*H || j == 2*W)) {
                if (i == 0) {
                    out[outNum][0] = 1;
                    out[outNum][1] = j;
                    minMov[1][j] = 1;
                }
                if (j == 0) {
                    out[outNum][0] = i;
                    out[outNum][1] = 1;
                    minMov[i][1] = 1;
                }
                if (i == 2*H) {
                    out[outNum][0] = 2*H-1;
                    out[outNum][1] = j;
                    minMov[2*H-1][j] = 1;
                }
                if (j == 2*W) {
                    out[outNum][0] = i;
                    out[outNum][1] = 2*W-1;
                    minMov[i][2*W-1] = 1;
                }
//                cout << out[outNum][0] << "; " << out[outNum][1] << endl;
                outNum++;
            }
        }
    }
    for(int k = 0; k < outNum; k++){
        for(int i = 0; i <= 2 * H; i++){
            for (int j = 0; j <= 2 * W; j++) {
                grid2[i][j] = grid[i][j];
            }
        }
        int x = out[k][0];
        int y = out[k][1];
//        cout << "x,y" << x << "," << y << endl;
        grid2[x][y] = 1;
        int step = 1;
        int reach = 1;
        bool MOVE = false;
        while (true) {
            int reached = reach;
            for(int i = 0; i <= 2 * H; i++){
                for (int j = 0; j <= 2 * W; j++) {
                    if (i % 2 == 1 && j % 2 == 1 && grid2[i][j] == step && grid[i][j] != 9) {
                        if (i > 1 && grid[i-1][j] == 0 && grid2[i-2][j] == 0) {
                            grid2[i-2][j] = step+1;
                            MOVE = true;
                            reach++;
                            if (minMov[i-2][j] > step+1) {
                                minMov[i-2][j] = step+1;
                            }
                        }
                        if (j > 1 && grid[i][j-1] == 0 && grid2[i][j-2] == 0) {
                            grid2[i][j-2] = step+1;
                            MOVE = true;
                            reach++;
                            if (minMov[i][j-2] > step+1) {
                                minMov[i][j-2] = step+1;
                            }
                        }
                        if (i < 2 * H-1 && grid[i+1][j] == 0 && grid2[i+2][j] == 0) {
                            grid2[i+2][j] = step+1;
                            MOVE = true;
                            reach++;
                            if (minMov[i+2][j] > step+1) {
                                minMov[i+2][j] = step+1;
                            }
                        }
                        if (j < 2 * W-1 && grid[i][j+1] == 0 && grid2[i][j+2] == 0) {
                            grid2[i][j+2] = step+1;
                            MOVE = true;
                            reach++;
                            if (minMov[i][j+2] > step+1) {
                                minMov[i][j+2] = step+1;
                            }
                        }
                    }
                }
            }
//            cout<< "---------" << endl;
//            for(int i = 0; i <= 2 * H; i++){
//                for (int j = 0; j <= 2 * W; j++) {
//                    cout << grid2[i][j] ;
//                }
//                cout << endl;
//            }
            if(MOVE){
                step++;
            }
            if (reached == reach || reach == W*H ) {
//                cout << reached <<  "," << reach << endl;
                break;
            }
            
        }
//        cout << "##################" << endl;
    }
    
    int max = 0;
    for(int i = 0; i <= 2 * H; i++){
        for (int j = 0; j <= 2 * W; j++) {
            if (i % 2 == 1 && j % 2 == 1 && max < minMov[i][j])
                max = minMov[i][j];
        }
    }
    
    cout << max << endl;
    
    return 0;
}
//1 1
//+-+
//
//+-+
