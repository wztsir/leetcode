#include"ListNode.h"
using namespace std;
//反转a，b区间，并且返回当前的头递归，返回head后已反转的头节点
ListNode* reverse(ListNode* a, ListNode* b){//返回反转后的头节点
    ListNode *pre = nullptr, *cur = a, *next;
    while(cur!=b){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {//递归，返回反转后的头节点
    ListNode* b = head;
    for(int i = 0; i < k;++i ){
        if(b == nullptr)return head;
        b = b->next;
    }
    ListNode* last = reverse(head, b);
    head->next = reverseKGroup(b, k);
    return last;
}