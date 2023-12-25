#include"ListNode.h"
#include<vector>
#include<queue>
#include<functional>
using namespace std;
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(
        [](ListNode* a, ListNode* b){return a->val > b->val;});
    for(auto it : lists){
        if(it != nullptr)pq.push(it);
    }
    ListNode *dummyNode = new ListNode(-1), *cur = dummyNode;
    while(!pq.empty()){
        cur->next = pq.top();
        pq.pop();
        cur = cur->next;
        if(cur->next != nullptr)pq.push(cur->next);
    }
    return dummyNode->next;
}