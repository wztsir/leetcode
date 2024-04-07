#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
int like[100005];
int main(){
    int N,D,K;
    cin >> N >> D >> K;
    vector<pair<int, int>> mp;
    int a,b;
    for(int i = 0; i < N; i++){
        scanf("%d%d", &a, &b);
        mp.emplace_back(a, b);
    }
    sort(mp.begin(), mp.end(), cmp);//默认根据第一项排序
    set<int> res;
    int j = 0;
    for(int i = 0; i < N; i++){//细节,用for循环控制右进
        like[mp[i].second]++;
        //左边出
        while(mp[i].first-mp[j].first >= D){
            like[mp[j].second]--;//细节的,先出,后移动
            j++;
        }
        if(like[mp[i].second] >= K)res.insert(mp[i].second);
    }
    for(auto& r : res){
        printf("%d\n", r);
    }    
}