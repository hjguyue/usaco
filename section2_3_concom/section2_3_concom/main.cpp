//
/*
 ID: hjguyue1
 PROG: concom
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int oldP[101][101] = {0};
int control[101][101] = {0};

int main(int argc, const char * argv[])
{
    ifstream fin("concom.in");
    ofstream fout("concom.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int n = 0;
    cin >> n;
    
    for(int i= 0; i < n; i++){
        int comA,comB,P;
        cin >> comA >> comB >> P;
        oldP[comA][comB] = P;
        if (P > 50) {
            control[comA][comB] = 1;
        }
    }
    for(int i= 1; i <= 100; i++){
        control[i][i] = 1;
    }
    int count = 0;
    while (true) {
        int temp = count;
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                // judge: i -> j
                if(control[i][j] == 0){
                    int sum = 0;
                    for(int k = 1; k <= 100; k++){
                        if (control[i][k] == 1) {
                            sum += oldP[k][j];
                        }
                    }
                    if (sum > 50) {
                        control[i][j] = 1;
                        count++;
                    }
                }
            }
        }
        if (temp == count) {
            break;
        }
    }
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if (control[i][j] == 1 && i != j) {
                cout << i << " " << j << endl;
            }
        }
    }
    
    return 0;
}

