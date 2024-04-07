#include<bits/stdc++.h>
using namespace std;
const int N = 300;
int tr[N], ans[N];
int n;
int lowbit(int x){
    return x & -x;
}
void add(int x, int v){
    for(int i = x; i <= N; i += lowbit(i))
        tr[i] += v;
}
int qurry(int x){
    int res = 0;
    for(int  i = x; i != 0; i -= lowbit(i))
        res += tr[i];
    return res;
}
int main(){
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        x++; //细节，让数据整体右移一位
        ans[qurry(x)]++;//不计算到本身，所以先查询
        add(x, 1);
    }
    for(int i = 0; i < n; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}