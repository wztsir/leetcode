#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
using namespace std;
vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
    vector<int> res(k);
    vector<pair<int, int>> memo;
    unordered_map<string, int> words;
    for(auto& it : positive_feedback){
        words[it] = 3;
    }
    for(auto& it : negative_feedback){
        words[it] = -1;
    }
    for(int i = 0; i<report.size(); ++i){
        stringstream ss;
        ss << report[i];
        string word;
        int score = 0;
        while(ss >> word){
            if(words.count(word)){
                score += words[word];
            }
        }
        memo.push_back(pair(score, student_id[i]));
    }
    sort(memo.begin(), memo.end(), [](pair<int, int>& a, pair<int, int>& b){
        if(a.first != b.first)return a.first > b.first;
        return a.second < b.second;
    });
    for(int i = 0; i<k;++i){
        res[i] = memo[i].second;
    }
    return res;
}