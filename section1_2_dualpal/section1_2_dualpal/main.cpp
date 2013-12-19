/*
 ID: hjguyue1
 PROG: dualpal
 LANG: C++
 */

#include <cstdio>
#include <utility>
#include <string.h>
#include <climits>

char getChar(int a){
    if(a >= 10)
        return char(a+55);
    else
        return char(a+48);
}

// get num in base
void getNumB(char* squs, int a, int B){
    int len = 0;
    while(a > 0){
        squs[len] = getChar(a % B);
        a = a / B;
        len++;
    }
    squs[len]='\0';
    for(int i = 0; 2*i < len-1; i++){
        std::swap(squs[i], squs[len-1-i]);
    }
}

int main(int argc, const char * argv[])
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    
    int N = 0;
    scanf("%d",&N);
    
    int S = 0;
    scanf("%d", &S);
    
    for(int num = S+1; num < LONG_MAX && N != 0; num++){
        int match = 0;
        for (int b = 2; b <= 10; b++) {
            char strs[100] = {0};
            getNumB(strs, num, b);
            bool PAL = true;
            for(int j = 0; j < strlen(strs) / 2; j++){
                if(strs[j] != strs[strlen(strs)-1-j]){
                    PAL = false;
                    break;
                }
            }
            if (PAL) {
                match++;
            }
        }
        if (match >= 2) {
            printf("%d\n",num);
            N--;
        }
    }
    
    
    return 0;
}

