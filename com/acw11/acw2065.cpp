#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    while(n){
        printf("%lld ", n);
        n /= 2;
    }
}