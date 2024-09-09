#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
#include"ListNode.h"
using namespace std;
ListNode* mergeNodes(ListNode* head) {
    ListNode* dummmy = new ListNode(-1, head);
    ListNode* temp = dummmy;
    int ans = 0;
    while(head != nullptr){
        if(head->val == 0){
            if(temp->val == 0){
                ListNode* node = new ListNode(ans);
                dummmy->next = node;
                dummmy = dummmy->next;
                ans = 0;
            }
            temp->val = 0;
        }
        ans += head->val;
        head = head->next;
    }
    return temp->next;
}
int main()
{
   system("pause");
   return 0;
}
