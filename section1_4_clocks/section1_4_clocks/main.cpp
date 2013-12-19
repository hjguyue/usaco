/*
 ID: hjguyue1
 PROG: clocks
 LANG: C++
 */

#include <cstdio>
#include <cmath>
//1	 ABDE
//2	 ABC
//3	 BCEF
//4	 ADG
//5	 BDEFH
//6	 CFI
//7	 DEGH
//8	 GHI
//9	 EFHI
//ABCDEFGHI
//012345678
int clock[9] = {0};
int num[9] = {0};
char answers[10000][30] = {0};
int answer = 0;
int size[9] = {4,3,4,3,5,3,4,3,4};
int group[9][5] = {{0,1,3,4},{0,1,2},{1,2,4,5},{0,3,6},{1,3,4,5,7},{2,5,8},{3,4,6,7},{6,7,8},{4,5,7,8}};

int main(int argc, const char * argv[])
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    
    for(int i = 0; i < 9; i++){
        scanf("%d",&clock[i]);
        clock[i] = (12 - clock[i])/3;
    }
    int K = 0;
    bool STOP = false;
    
    while(!STOP){
        K++;
        if (K > pow(4, 9)) {
            break;
        };
        int temp = K;
        int tempClock[9] = {0};
        for(int i = 0; i < 9; i++){
            num[i] = temp % 4;
            temp = temp / 4;
            tempClock[i] = clock[i];
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < size[i]; j++){
                tempClock[group[i][j]] -= num[i];
            }
        }
        bool OK = true;
        for(int i = 0; i < 9; i++){
            if (tempClock[i] % 4 != 0) {
                OK = false;
            }
        }
        if(OK){
            char ans[100] = {0};
            int len = 0;
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < num[i]; j++){
                    ans[len] = 49+i;
                    ans[len+1] = ' ';
                    len+=2;
                }
            }
            for(int i = 0; i < len-1; i++){
                printf("%c",ans[i]);
            }
            printf("\n");
        }
    }
    
    
    
    
    return 0;
}

