//低级错误， 异或运算写错， 输入数据格式写错int，其实应该是char
#include<iostream>
#include<cstring>
using namespace std;
char q[5][5];
const int INF = 10000000;
int res = INF;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
void turn (int x, int y, char arr[][5]){
    for(int i = 0; i < 5; i++){
        int tx = x + dx[i], ty = y + dy[i];
        if(tx >= 0 && tx < 5 && ty >= 0 && ty < 5){
            arr[tx][ty] ^= 1;
        }
    }
}
void work(){
    res = INF;
    for(int k = 0; k < 1 << 5; k++){
        char temp[5][5];
        memcpy(temp, q, sizeof(q));
        // 对第一行32选择操作
        int ans = 0;
        for(int j = 0; j < 5; j++){
            if(k >> j & 1){
                turn(0, j, temp);
                ans++;
            }
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 5; j++){
                if(temp[i][j] == '0'){
                    turn(i+1, j, temp);
                    ans++;
                }
            }
        }
        bool success = 1;
        for(int j = 0; j < 5; j++){
            if(temp[4][j] == '0')success = 0;
        }
        if(success)res = min(ans, res);
    }
    if(res > 6)res = -1;
}
int main(){
    int n; 
    cin >> n;
    while(n--){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cin >> q[i][j];
            }
        }
        work();
        cout << res << endl;
    }
}
