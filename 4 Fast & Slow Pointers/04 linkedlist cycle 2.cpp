#include<bits/stdc++.h>
using namespace std;
  

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
    ListNode* detectCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;       // move +1
            fast = fast->next->next; // move +2
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next; // move +1
                    fast = fast->next; // move +1
                }
                return slow;
            }
        }

        return NULL;
    }

int main(){

return 0;
}