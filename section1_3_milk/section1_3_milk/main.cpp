/*
 ID: hjguyue1
 PROG: milk
 LANG: C++
 */

#include <cstdio>
#include <utility>
#include <climits>

int price[6000];
int amount[6000];

int main(int argc, const char * argv[])
{
//    freopen("milk.in", "r", stdin);
//    freopen("milk.out", "w", stdout);
    
    int N,M;
    scanf("%d %d",&N,&M);
    
    for(int i = 0; i < M; i++){
        scanf("%d %d",&price[i],&amount[i]);
    }
    
    for(int i = 0; i < M-1; i++){
        for(int j = 0; j < M-1-i; j++){
            if(price[j] > price[j+1]){
                std::swap(price[j], price[j+1]);
                std::swap(amount[j], amount[j+1]);
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i < M && N > 0; i++){
        if(N > amount[i]){
            sum += price[i] * amount[i];
        }
        else
            sum += price[i] * N;
        N -= amount[i];
    }
    printf("%d\n",sum);
    
    return 0;
}

