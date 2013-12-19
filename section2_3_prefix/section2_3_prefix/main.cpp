//
/*
 ID: hjguyue1
 PROG: prefix
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

string line;
string subStr[200];
int state[300000] = {0};
int subSize = 0;

int main(int argc, const char * argv[])
{
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    string strTemp;
    while (cin >> strTemp) {
        if(strTemp.compare(".") != 0){
            subStr[subSize] = strTemp;
            subSize++;
        }
        else
            break;
    }
    while (cin >> strTemp) {
        line = line + strTemp;
    }
    
    int max = 0;
    state[0] = 1;
    for(int i = 1; i <= line.length(); i++){
        if (state[i-1] == 1) {
            for(int j = 0; j < subSize; j++){
                int len = (int)subStr[j].length();
                if (state[i+len-1] == 1) {
                    continue;
                }
                else{
                    if (line.substr(i-1,len).compare(subStr[j]) == 0) {
                        state[i+len-1] = 1;
                        if (max < (i+len-1)) {
                            max = i+len-1;
                        }
                    }
                }
            }
        }
    }
    cout << max << endl;
    
    return 0;
}

