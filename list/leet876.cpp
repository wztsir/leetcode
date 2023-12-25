#include"ListNode.h"
#include<stack>
using namespace std;
ListNode* middleNode(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}