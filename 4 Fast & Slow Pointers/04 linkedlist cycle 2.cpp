#include<bits/stdc++.h>
using namespace std;
  
struct ListNode {
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
                slow = slow->next; 
                fast = fast->next; 
            }
            return slow; // start of cycle
        }
    }
    return NULL;
}

int main() {
    // Create nodes
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // create cycle (last node connects to node index 1 -> value 2)
    head->next->next->next->next = head->next;

    // Test detectCycle
    ListNode* cycleNode = detectCycle(head);

    if (cycleNode)
        cout << "Cycle starts at node with value: " << cycleNode->val << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
