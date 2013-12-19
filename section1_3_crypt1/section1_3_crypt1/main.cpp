/*
 ID: hjguyue1
 PROG: crypt1
 LANG: C++
 */

#include <cstdio>

int N = 0;
int nums[10]={0};

bool judge(int check[]){
    for(int i = 0; i < 5; i++){
        while (check[i] > 0) {
            bool match = false;
            int temp = check[i] % 10;
            for(int j = 0; j < N; j++){
                if (temp == nums[j]) {
                    match = true;
                }
            }
            if (!match)
                return false;
            check[i] /= 10;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    
    scanf("%d",&N);
    
    for(int i = 0; i < N; i++)
        scanf("%d", &nums[i]);

    int sum = 0;
    for(int i = 100; i <= 999; i++){
        for(int j = 10; j <= 99; j++){
            int check[5] = {0};
            check[0] = i;
            check[1] = j;
            check[2] = i * (j%10);
            check[3] = i * (j/10);
            check[4] = i * j;
            if(check[2] >= 1000 || check[3] >= 1000 || check[4] >= 10000)
                continue;
            else if(judge(check)){
                sum++;
            }
        }
    }
    
    printf("%d\n",sum);
    
    return 0;
}

