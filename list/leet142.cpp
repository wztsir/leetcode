#include"ListNode.h"
using namespace std;
//环形链表解法很巧妙，与数学有一点点关系，就那么一点点
ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)break;
    }
    if(fast == nullptr || fast->next == nullptr)return nullptr;
    slow = head;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}