#include<bits/stdc++.h>
using namespace std;
int n, m;//树状数组长度, 操作数
const int N = 100009;
int a[N], tr[N];
int lowbit(int x){
    return x & -x;
}
//第x个数加上v
void add(int x, int v){
    for(int i = x; i <= n; i += lowbit(i)){
        tr[i] += v;
    }
}
//返回x的前缀和
int qurry(int x){
    int res = 0;
    for(int i = x; i != 0; i -= lowbit(i))
        res += tr[i];
    
    return res;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){//构造tr
        add(i, a[i]);
    }
    int k, x, y;
    while(m--){
        scanf("%d%d%d", &k, &x, &y);
        if(k == 0)printf("%d\n", qurry(y) - qurry(x-1));
        else add(x, y);
    }
    return 0;
}


