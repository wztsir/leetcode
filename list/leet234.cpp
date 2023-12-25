#include"ListNode.h"
#include<stack>
using namespace std;
//暴力解法很简单，但是如果要减小空间，减小时间复杂度还是比较有意思的
bool isPalindrome(ListNode* head) {
   stack<int> s;
   ListNode* c = head;
   while(c!=nullptr){
    s.push(c->val);
    c = c->next;
   }
   while(!s.empty()){
    if(s.top() != head->val)return false;
    head = head->next;
    s.pop();
   } 
   return true;
}