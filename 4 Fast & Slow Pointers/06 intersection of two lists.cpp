#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* t1 = headA;
    ListNode* t2 = headB;

    while (t1 != t2) {
        t1 = (t1 == NULL) ? headB : t1->next;
        t2 = (t2 == NULL) ? headA : t2->next;
    }
    return t1;
}

int main() {
    // Create first list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // Create second list: 9 -> 10 -> (intersects at 3)
    ListNode* headB = new ListNode(9);
    headB->next = new ListNode(10);

    // Make intersection at node with value 3
    headB->next->next = headA->next->next; 

    // Find intersection
    ListNode* inter = getIntersectionNode(headA, headB);

    if (inter) 
        cout << "Intersection at node with value: " << inter->val << endl;
    else 
        cout << "No intersection" << endl;

    return 0;
}
