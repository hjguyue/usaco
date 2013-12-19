/*
 ID: hjguyue1
 PROG: palsquare
 LANG: C++
 */

#include <cstdio>
#include <utility>
#include <string.h>

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
//    freopen("palsquare.in", "r", stdin);
//    freopen("palsquare.out", "w", stdout);

    int B = 0;
    scanf("%d",&B);
    
    for(int i = 1; i <= 300; i++){
        int square = i * i;
        char squs[100] = {0};
        getNumB(squs, square, B);
        bool PAL = true;
        for(int j = 0; j < strlen(squs) / 2; j++){
            if(squs[j] != squs[strlen(squs)-1-j]){
                PAL = false;
                break;
            }
        }
        if (PAL) {
            char original[100] = {0};
            getNumB(original, i, B);
            printf("%s %s\n",original, squs);
        }
        
    }
    
    return 0;
}

