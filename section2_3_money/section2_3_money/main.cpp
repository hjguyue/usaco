//
/*
 ID: hjguyue1
 PROG: money
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int V,N;
int type[30] = {0};
long long num[20000] = {0};

int main(int argc, const char * argv[])
{
    ifstream fin("money.in");
    ofstream fout("money.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());

    cin >> V >> N;
    for(int i = 0; i < V; i++)
        cin >> type[i];
    
    num[0] = 1;
    for (int i = 0; i < V; i++) {
        for(int remain = N; remain >= 0; remain--){
            int temp = remain;
            while (temp >= type[i]) {
                num[remain] += num[temp-type[i]];
                temp -= type[i];
            }
        }
//        for(int k = 0; k <= N; k++)
//            cout<< num[k] << " ";
//        cout << endl;
    }
    
    cout << num[N] << endl;
    
    return 0;
}

