/*
 ID: hjguyue1
 PROG: calfflac
 LANG: C++
 */


#include <cstdio>
#include <string.h>
#include <ctype.h>

char text[20000] = {0};
char concise[20000]={0};
int location[20000] = {0};
int val[20000]={0};
int val_old[20000];

int main(int argc, const char * argv[])
{
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
    
    text[0] = '\0';
    while (fgets(text + strlen(text), 100, stdin) > 0);
    
//    printf("%s\n",text);
    
    int num = 0;
    for(int i = 0; i < strlen(text); i++){
        if ( isalpha(text[i]) ) {
            concise[num] = tolower(text[i]);
            location[num]= i;
            num++;
        }
    }
    concise[num] = '\0';
    
    int n = (int)strlen(concise);
    int left = 0, right = 0;
    int maxLen = 0;
    
    for(int i = 0; i < n; i++){
        int len = 0;
        // odd:
        while(i-len >= 0 && i + len <= n){
            if (concise[i-len] == concise[i+len])
                len++;
            else
                break;
        }
        if (2*len-1 > maxLen) {
            maxLen = 2*len-1;
            left = i - len + 1;
            right = i + len - 1;
        }
        
        len = 0;
        // even:
        while(i-len >= 0 && i + len <= n){
            if (concise[i-len] == concise[i+1+len])
                len++;
            else
                break;
        }
        if (2*len > maxLen) {
            maxLen = 2*len;
            left = i - len + 1;
            right = i + len;
        }
    }
    printf("%d\n",maxLen);
    for(int i = location[left]; i <= location[right]; i++){
        printf("%c",text[i]);
    }
    printf("\n");
    
    return 0;
}

