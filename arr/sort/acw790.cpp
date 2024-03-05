//低级错误，double 类型的读入应该写成%lf, %f是float的读入方式
#include<cstdio>
using namespace std;
int main(){
    double n;
    scanf("%lf", &n);
    double l = -10000, r = 10000;
    while(r-l >= 1e-8){
        double mid = (l+r)/2;
        if(mid * mid * mid <= n)l = mid;
        else r = mid; 
    }
    printf("%lf", l);
    return 0;
}