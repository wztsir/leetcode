#include"ListNode.h"
using namespace std;
ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr)return head;
    int num = 0;
    ListNode* dummy = new ListNode(-1, head);
    ListNode* cur = dummy, * hail = dummy;
    while(cur->next != nullptr){
        cur = cur->next;
        num++;
    }
    k %= num;
    k = num - k;
    while(k--){
        hail = hail->next;
    }
    cur->next = dummy->next;
    dummy->next = hail->next;
    hail->next = nullptr;
    return dummy->next;
}