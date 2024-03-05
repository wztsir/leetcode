//写一个if-else语句都出现问题，代码功底出现问题
// elseif是对上一个if的否定，上一个if如果有两个条件，否定范围很大
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int g[50];
    for(int i = 0; i < n; i++){
        scanf("%d", &g[i]);
    }
    int begin = g[0];
    int ans = 1, temp = 0;
    int k = 0;
    for(int i = 1; i < n; i++){

            if(begin * g[i] < 0 && g[i] < -begin){
                k = 1;
                ans++;
                // 错误}else if(  g[i] < begin){
            }else if(begin * g[i] >0  && g[i] < begin){
                temp++;
            }
        
        
    }

    printf("%d", k ? ans+temp : ans);
}