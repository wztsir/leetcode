//画出递归树，则非常好理解，最后边界的行为，要先写边界
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int st[10];
int N;
vector<int> q;
void f(int i){
    if(i > N){
        for(auto & it : q){
            printf("%d ", it);
        }
        puts("");
        return;
    }
    for(int j = 1; j <= N; j++){
        if(st[j] == 0){
            st[j] = 1;
            q.push_back(j);
            f(i+1);
            q.pop_back();
            st[j] = 0;
        }
    }
}
int main(){
    cin >> N;
    f(1);
}