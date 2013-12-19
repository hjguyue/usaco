/*
 ID: hjguyue1
 PROG: castle
 LANG: C++
 */

#include <iostream> 
#include <fstream>
using namespace std;

int M = 0, N = 0;
int areaNum = 0;
int area[10000] = {0};
int areaMax = 0;
int areaMax2 = 0;

class Grid{
public:
    int val;
    int id;   // grid id
    int s[4]; // 0:left  1:up  2:right  3:down  
    int area;
};

Grid grid[200][200];

bool check(int row, int col){
    if (row < 0 || col < 0 || row >= M || col >= N) {
        return false;
    }
    return true;
}

int rshift[4] = {0,-1,0,+1};
int cshift[4] = {-1,0,+1,0};

int main(int argc, const char * argv[])
{
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        for(int j =0; j < N; j++){
            int value;
            cin >> value;
            grid[i][j] = Grid();
            grid[i][j].val = value;
            for(int k = 0; k < 4; k++)
                grid[i][j].s[k] = (value >> k) % 2;
        }
    }
    
    int count = 0;
    while(true){
        while(grid[count/N][count%N].id != 0){
            count++;
        }
        if (count >= M*N) break;
        
        areaNum ++;
        grid[count/N][count%N].id = areaNum;
        area[areaNum]++;
        while(true){
            int oldArea = area[areaNum];
            for(int i = 0; i < M; i++){
                for(int j =0; j < N; j++){
                    if (grid[i][j].id == areaNum) {
                        for(int k = 0; k < 4; k++){
                            int x = i + rshift[k];
                            int y = j + cshift[k];
                            if (check(x, y) && grid[i][j].s[k] == 0 && grid[x][y].id == 0) {
                                grid[x][y].id = areaNum;
                                area[areaNum]++;
                            }
                        }
                    }
                }
            }
            if (area[areaNum] == oldArea) break;
        }
    }
    cout << areaNum << endl;
    for(int i = 0; i <= areaNum; i++){
        if (areaMax < area[i]) {
            areaMax = area[i];
        }
    }
    cout << areaMax << endl;
    int xx,yy,kk;
    for(int i = 0; i < M; i++){
        for(int j =0; j < N; j++){
            for(int k = 0; k < 4; k++){
                int x = i + rshift[k];
                int y = j + cshift[k];
                if (check(x, y) && grid[i][j].s[k] == 1 && grid[i][j].id != grid[x][y].id) {
                    if (areaMax2 < area[grid[i][j].id] + area[grid[x][y].id]) {
                        areaMax2 = area[grid[i][j].id] + area[grid[x][y].id];
                        xx = i;
                        yy = j;
                        kk = k;
                    }
                    if (areaMax2 ==  area[grid[i][j].id] + area[grid[x][y].id]) {
                        if (j < yy || (j == yy && i >  xx)) {
                            xx = i;
                            yy = j;
                            kk = k;
                        }
                    }
                }
            }
        }
    }
    cout << areaMax2 << endl;
    cout << xx+1 << " " << yy+1 << " ";
    switch(kk){
//        case 0: cout << xx << " " <<yy-1<< " " << "E" << endl; break;
        case 1: cout << "N" << endl; break;
        case 2: cout << "E" << endl; break;
//        case 3: cout <<xx+1<< " " << yy << " " << "N" << endl; break;
    }

    return 0;
}

