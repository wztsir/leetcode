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
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
Node* copyRandomList(Node* head) {
    if(head == nullptr)return head;
    unordered_map<Node*, Node*> map;
    // unordered_map<int, Node*> after;
    Node* dummy = new Node(-1);
    Node* cur = dummy,* h = head;
    int index = 0;
    while(h != nullptr){
        cur->next = new Node(h->val);
        map[h] = cur->next;
        // before[h] = index;
        // after[index] = cur->next;
        index++;
        cur = cur->next;
        h = h->next;
    }
    h = head;
    cur = dummy->next;
    while(h != nullptr){
        if(h->random)cur->random = map[h->random];
        cur = cur->next;
        h = h->next;
    }
    return dummy->next;
}
