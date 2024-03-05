// 对于不存在的数据没有及时判断
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int g[100000];
int findLeft(int l, int r, int node){
    if(g[l] > node || g[r] < node)return -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(g[mid] >= node)r = mid-1;
        else if(g[mid] < node)l = mid + 1; 
    }
    return g[r+1] != node ? -1 : r+1;
}
int findRight(int l, int r, int node){
    if(g[l] > node || g[r] < node)return -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(g[mid] > node)r = mid-1;
        else if(g[mid] <= node)l = mid + 1; 
    }
    return g[l-1] != node ? -1 : l-1;
}
int main()
{   
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++)scanf("%d", &g[i]);
    int find;
    while(q--){
        scanf("%d", &find);
        int l = findLeft(0, n-1, find);
        int r = findRight(0, n-1, find);
        printf("%d %d", l, r);
        puts("");
    }
   system("pause");
   return 0;
}
