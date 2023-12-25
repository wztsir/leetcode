#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
// #include"TreeNode.h"
using namespace std;
string pushDominoes(string dominoes) {
    int l = dominoes.size();
    string s(dominoes);
    unordered_map<int, int> memo;
    for(int i = 0; i < l; ++i){
        if(dominoes[i] == 'R'){
            int k = 0;
            while(i+1 < l && dominoes[i+1] == '.'){//犯错，在while条件中放入++i
                s[++i] = 'R';
                k++;

            }
            if(i+1 < l && dominoes[i+1] == 'L')memo[i+1] = k;
        }
    }
    for(int i = l-1; i >= 0; --i){
        if(dominoes[i] == 'L'){
            if(memo.count(i)){
                int temp = memo[i];
                int k = memo[i] / 2;
                while(k--){
                    s[--i] = 'L';
                }
                if(temp % 2)s[--i] = '.';
            }else{
                while(i-1 >= 0 && dominoes[i-1] == '.'){
                    s[--i] = 'L';
                    
                }
            }

        }
    }
    return s;
}
int main(){
    string s = ".L.R...LR..L..";
    pushDominoes(s);
}