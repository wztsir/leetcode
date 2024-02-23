//低级错误，终止条件忘记return
//没有立刻思考出使用回溯
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int st[16];
int N;
void f(int i){
    if(i > N){
        for(int j = 1; j <= N; j++){
            if(st[j] == 1)printf("%d ", j);
        }
        puts("");
        return;
    }
    st[i] = 1;
    f(i+1);
    st[i] = 0;
    f(i+1);
}
int main(){
    cin >> N;
    f(1);
}