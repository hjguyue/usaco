/*
 ID: hjguyue1
 PROG: transform
 LANG: C++
 */

#include <cstdio>
#include <string.h>
#define N 20

int main(int argc, const char * argv[])
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    
    int n = 0;
    scanf("%d\n",&n);
    
    char before[N][N] = {0};
    char after[N][N] = {0};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%c",&before[i][j]);
        scanf("\n");
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%c",&after[i][j]);
        scanf("\n");
    }
    
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            printf("%c ",before[i][j]);
//        }
//        printf("\n");
//    }
    
    bool match;

    // 1:
    match = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (before[i][j] != after[j][n-1-i]) {
                match = false;
            }
        }
    }
    if (match) {
        printf("1\n");
        return 0;
    }
    
    // 2:
    match = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (before[i][j] != after[n-1-i][n-1-j]) {
                match = false;
            }
        }
    }
    if (match) {
        printf("2\n");
        return 0;
    }

    // 3:
    match = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (before[i][j] != after[n-1-j][i]) {
                match = false;
            }
        }
    }
    if (match) {
        printf("3\n");
        return 0;
    }

    // 4:
    match = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (before[i][j] != after[i][n-1-j]) {
                match = false;
            }
        }
    }
    if (match) {
        printf("4\n");
        return 0;
    }
    
    // 5:
    match = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (before[i][j] != after[n-1-j][n-1-i]) {
                match = false;
            }
        }
    }
    if (match) {
        printf("5\n");
        return 0;
    }
    
    // 5:
    match = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (before[i][j] != after[n-1-i][j]) {
                match = false;
            }
        }
    }
    if (match) {
        printf("5\n");
        return 0;
    }
    
    // 5:
    match = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (before[i][j] != after[j][i]) {
                match = false;
            }
        }
    }
    if (match) {
        printf("5\n");
        return 0;
    }
    
    // 6:
    match = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (before[i][j] != after[i][j]) {
                match = false;
            }
        }
    }
    if (match) {
        printf("6\n");
        return 0;
    }
    
    printf("7\n");
    return 0;
}

