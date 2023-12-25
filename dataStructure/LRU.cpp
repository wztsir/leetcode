#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
//get -O(1), put -O(1)
//get 如果不存在直接返回-1
//    如果存在，找到该点，删除该点，将其插入到队首

//put 如果不存在，如果容量小于c，插入到队首
//               如果容量等于c, 删除队尾, 插入到队首
//    如果存在，变更v, 删除该点， 将其插入到队首

//既要删除队尾，又要插入队首，使用双向队列. 由于要快速查找到节点，所以需要使用哈希
//双向队列要删除队尾，同时要在哈希表中删除需要获得key，所以节点中需要带key

struct Node{
    int key, value;
    Node* pre = nullptr, *next = nullptr;
    Node(int _k, int _v): key(_k), value(_v){}
};
class LRUCache {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int capacity = 0;
    unordered_map<int, Node*> map;
    void remove(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        map.erase(node->key);
    }
    void remove_back(){
        int key = tail->pre->key;
        map.erase(key);
        tail->pre = tail->pre->pre;
        tail->pre->next = tail; 
    }
    void push_front(Node* node){
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
        node->pre = head;
        map[node->key] = node;
    }
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())return -1;
        Node* node = map[key];
        remove(node);
        push_front(node);
        return node->value; 
    }
    
    void put(int key, int value) {
        Node * node = new Node(key, value);
        if(map.find(key) == map.end()){
            if(map.size() == capacity){
                remove_back();
            }
            push_front(node);
        }else{
            remove(map[key]);
            push_front(node);
        }
    }
};