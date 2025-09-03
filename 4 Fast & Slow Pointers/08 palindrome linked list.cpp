#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* revLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = revLL(slow);

        while (slow) {
            if (head->val != slow->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
int main(){
      // Create the input linked list: 1 -> 2 -> 2 -> 1
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution s;
    cout<<s.isPalindrome(head);

return 0;
}