// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     long long n, m;
//     cin >> n >> m;
//     int a = 0, b = 1;
//     if(n == 1){
//         printf("%d", 1%m);
//         return 0;
//     }
//     long long temp, s = 1;
//     for(int i = 2; i <= n; i++){
//         temp = (a + b) % m;
//         a = b;
//         b = temp;
//         s = (s + temp) % m;
//     }
//     printf("%lld", s);
//     return 0;
// }

// 矩阵乘法加快速幂
#include<bits/stdc++.h>
using namespace std;
const int N =3;
int n, m;
// c = a * b
void qmul(int a[][N], int b[][N], int c[][N]){

    int t[N][N];
    memset(t, 0, sizeof(t));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                t[i][j] =(t[i][j] + ((long long)a[i][k] * b[k][j]) % m) % m;
            }
        }
    }
    memcpy(c, t, sizeof(t));

}
int main(){
    
    cin >> n >> m;
    int a[N][N] = {0, 1, 0};
    int b[N][N] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 1}
    };
    while(n){
        if(n & 1)qmul(a, b, a);
        qmul(b, b, b);
        n >>= 1;
    }
    cout << a[0][2] << endl;
    return 0;
}