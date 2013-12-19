/*
 ID: hjguyue1
 PROG: barn1
 LANG: C++
 */

#include <cstdio>
#include <cstdlib>

int nums[300] = {0};
int interval[300] = {0};

int compare_1 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int compare_2 (const void * a, const void * b)
{
    return ( - *(int*)a + *(int*)b );
}

int main(int argc, const char * argv[])
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    int M,S,C;
    scanf("%d %d %d", &M, &S, &C);
    
    if(M >= C){
        printf("%d\n",C);
        return 0;
    }
    
    for(int i = 0; i < C; i++)
        scanf("%d",&nums[i]);
    qsort(nums, C, sizeof(int), compare_1);
    
    for(int i = 0; i < C-1; i++)
        interval[i] = nums[i+1] - nums[i];
    
    qsort(interval, C-1, sizeof(int), compare_2);
    int sum = nums[C-1] - nums[0];
    
    for(int i = 0; i < M-1; i++){
        sum -= interval[i];
    }
    
    printf("%d\n",sum+M);
    
    return 0;
}

