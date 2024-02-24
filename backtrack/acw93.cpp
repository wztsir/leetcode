//一开始没有想明白，直接25的25次方，直接超时，视角为被一个位置的选择，其实视角应该是每个数字选择去或者不去
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n, m;
vector<int> q;
int st[26];
void work(int i){
    if(q.size() >= m){
        for(auto& it : q){
            printf("%d ", it);
        }
        puts("");
        return;
    }
    int begin = q.empty() ? 1 : q.back()+1;
    for(int i = begin; i <= n; i++){
        q.push_back(i);
        work(i+1);
        q.pop_back();
        
    }
}
int main(){
    
    cin >> n >> m;
    work(0);
}