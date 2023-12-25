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
#include"TreeNode.h"
using namespace std;
class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        for(auto& c : word){
            if(node -> next[c-'a'] == nullptr){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(auto& c : word){
            if(node -> next[c-'a'] == nullptr){
                return false;
            }
            node = node->next[c-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto& c : prefix){
            if(node -> next[c-'a'] == nullptr){
                return false;
            }
            node = node->next[c-'a'];
        }
        return true;
    }

    
    bool search(string word) {
        Trie* node = this;
        for(auto& c : word){
            if(node -> next[c-'a'] == nullptr){
                return false;
            }
            node = node->next[c-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto& c : prefix){
            if(node -> next[c-'a'] == nullptr){
                return false;
            }
            node = node->next[c-'a'];
        }
        return true;
    }
};