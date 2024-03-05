//用了vector比别人的代码慢2s
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int res = 0;
int n;
int st[10];
vector<int> q;
int calc(int l, int r){
    int ans = 0;
    for(int i = l; i <= r; i++){
        ans = ans * 10 + q[i]; 
    }
    return ans;
}
void dete(){
    for(int i = 0; i < 9; i ++){
        for(int j = i+1; j < 8; j++){
            int a = calc(0, i);
            int b = calc(i+1, j);
            int c = calc(j+1, 8);
            if(a * c + b == n * c)res++;
        }
    }
}
void bfs(int i){
    if(i >= 9){
        dete();
    }
    for(int u = 1; u <= 9; u++){
        if(st[u] == 0){
            st[u] = 1;
            q.push_back(u);
            bfs(i+1);
            q.pop_back();
            st[u] = 0;
        }
    }
}
int main(){
    scanf("%d", &n);
    bfs(0);
    printf("%d", res);
}