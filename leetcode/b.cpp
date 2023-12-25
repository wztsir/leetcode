#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

int I() {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> map(n + 1, 0);
    map[0] = 1;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int temp = I();
        if(map[temp]<k)map[temp] ++;
        if (map[temp] >= map[max])max = temp;
        cout << max<<" ";
              
    }
}