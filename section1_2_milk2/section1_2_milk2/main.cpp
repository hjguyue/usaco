/*
 ID: hjguyue1
 LANG: C++
 TASK: milk2
 */

#include <cstdio>      /* printf */
#define MAXN 10000+100

class Point {
public:
    int loc;
    int type;
    Point(){}
    Point(int x, int y = 0){
        loc = x;
        type = y;
    }
};

class Line{
public:
    int left;
    int right;
    Line(){}
    Line(int l, int r){
        left = l; right = r;
    }
};

Point points[MAXN] = {0};
Line lines[MAXN];

int main ()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    
    int N = 0;
    scanf("%d",&N);
    
    int left;
    int right;
    for (int i = 0; i < N; i++) {
        scanf("%d",&left);
        scanf("%d",&right);
        lines[i] = Line(left,right);
        points[2*i] = Point(left,1);
        points[2*i+1] = Point(right,-1);
    }
    
    int total = 2*N;
    for(int i = 1; i < total; i++){
        for(int j = 0; j < total-i; j++){
            if (points[j].loc > points[j+1].loc) {
                int tempLoc = points[j+1].loc;
                int tempType= points[j+1].type;
                points[j+1].loc = points[j].loc;
                points[j+1].type= points[j].type;
                points[j].loc = tempLoc;
                points[j].type= tempType;
            }
        }
    }
    
//    for (int i = 0; i < total; i++) {
//        printf("%d %d \n", points[i].loc, points[i].type);
//    }
    
    int len[MAXN] = {0};
    int type[MAXN]= {0};
    for (int i = 0; i < total-1; i++) {
        len[i] = points[i+1].loc - points[i].loc;
        bool IN = false;
        for(int j = 0; j < N; j++){
            if (points[i].loc >= lines[j].left && points[i+1].loc <= lines[j].right) {
                IN = true;
                break;
            }
        }
        if (IN)
            type[i] = 1;
        else
            type[i] = -1;
//        printf("%d %d\n",len[i],type[i]);
    }
    
    int max1 = 0;
    int max2 = 0;
    int current = type[0];
    int sum = len[0];
    if (type[0] == 1)
        max1 = len[0];
    else
        max2 = len[0];
    for(int i = 1; i < total; i++){
//        printf("sum %d\n",sum);
        if (current == type[i]) {
            sum += len[i];
        }
        else{
            sum = len[i];
            current = type[i];
        }
        if (current == 1 && max1 < sum)
            max1 = sum;
        else if(current == -1 && max2 < sum)
            max2 = sum;
    }
    
    printf("%d %d\n",max1,max2);
    
    return 0;
}
