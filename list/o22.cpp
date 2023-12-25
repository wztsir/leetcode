#include"ListNode.h"
using namespace std;
//双指针
ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode *fast = head, *slow = head;
    while(k--){
        fast = fast->next;
    }
    while(fast!=nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}