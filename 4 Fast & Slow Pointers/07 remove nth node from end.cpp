#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n){
        ListNode *res = new ListNode(0, head);
        ListNode *dummy = res;

        for (int i = 0; i < n; i++){
            head = head->next;
        }

        while (head != nullptr){
            head = head->next;
            dummy = dummy->next;
        }

        dummy->next = dummy->next->next;

        ListNode *result = res->next;
        delete res;
        return result;
    }
};

// Helper function to print the linked list
void printList(ListNode *head){
    ListNode *current = head;
    while (current != nullptr){
        cout << current->val << " -> ";
        current = current->next;
    }
}

int main(){
    // Create the input linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // We want to remove the 2nd node from the end (which is 4)

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode *newHead = solution.removeNthFromEnd(head, n);

    cout << "List after removing the " << n << "th node from the end: ";
    printList(newHead);

    return 0;
}