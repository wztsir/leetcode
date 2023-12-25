#include"ListNode.h"
using namespace std;
bool hasCycle(ListNode *head) {
    if(head == nullptr)return false;
    ListNode* fast = head, *slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)return true;
    }
    return false;
}