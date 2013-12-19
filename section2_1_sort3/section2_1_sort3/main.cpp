/*
 ID: hjguyue1
 PROG: sort3
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int N = 0;
int num[1000]={0};
int seg[4];

int exchange(int a, int b){
    int count = 0;
    int left = 0;
    int right = N-1;
    int rightMin = 0;
    if (a == 3 && b == 1) {
        rightMin = N - seg[3] - 1;
    }
    while(left < right && right > rightMin){
        while(left < right){
            if (num[left] != a) {
                left++;
            }
            else
                break;
        }
        while(left < right && right > rightMin){
            if (num[right] != b) {
                right--;
            }
            else
                break;
        }
        if (left < right && num[left] == a && num[right] == b && right > rightMin) {
            swap(num[left], num[right]);
            count++;
        }
    }
    return count;
}

int main(int argc, const char * argv[])
{
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());


    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
        seg[num[i]]++;
    }

    int count = 0;
    count += exchange(3,1);
    count += exchange(3,2);
    count += exchange(2,1);
    cout << count << endl;
    
    return 0;
}

