/*
 ID: hjguyue1
 PROG: namenum
 LANG: C++
 */

#include <cstdio>
#include <string.h>

#define MAXN 20

char words[50000][MAXN] = {0};
char nums[50000][MAXN];
char input[MAXN];
bool FIND = false;

int main(int argc, const char * argv[])
{    
    FILE *dict = fopen("dict.txt", "r");
//    FILE *dict = fopen("/Users/Harry/Documents/xcode/usaco/section1_2_namenum/dict.txt", "r");
    
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    
    int N = 0;
    while (fscanf(dict, "%s", words[N]) == 1) {
        N++;
    }
    scanf("%s",input);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < strlen(words[i]); j++){
            if (words[i][j] <= 80) 
                nums[i][j] = (words[i][j] - 59) / 3 + 48;
            else
                nums[i][j] = (words[i][j] - 60) / 3 + 48;
        }
//        printf("%s %s \n", words[i], nums[i]);
        if (strcmp(nums[i], input) == 0) {
            FIND = true;
            printf("%s\n", words[i]);
        }
    }
    if(!FIND){
        printf("NONE\n");
    }
    
    return 0;
}



