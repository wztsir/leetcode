#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    // cout << int(14/ 3.0 + 0.5);
    cin >> n;
   
    vector<int> q(n);
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> q[i];
        total += q[i];
    }
    sort(q.begin(), q.end());
    for(int i = 0; i < n; i++){
        if(int( 1.0 * total / n + 0.5) == 5){
            cout << i;
            return 0;
        }
        total = total - q[i] + 5;
    }
}