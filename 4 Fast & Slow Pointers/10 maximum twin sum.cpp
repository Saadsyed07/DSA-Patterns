#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int ans = 0;
        ListNode* newList = NULL;
        ListNode* current = head;
        ListNode* currHalf = head;
        while (currHalf) {
            currHalf = currHalf->next->next;
            ListNode* temp = current->next;
            current->next = newList;
            newList = current;
            current = temp;
        }

        while (current) {
            ans = std::max(ans, (current->val + newList->val));
            current = current->next;
            newList = newList->next;
        }
        return ans;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to delete the linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example 1: A twin-linked list of 4 nodes
    vector<int> vals1 = {5, 4, 2, 1};
    ListNode* head1 = createList(vals1);

    Solution sol;
    int result1 = sol.pairSum(head1);
    cout << "For list 5 -> 4 -> 2 -> 1, the max pair sum is: " << result1 << endl;

    deleteList(head1);

    // Example 2: A twin-linked list of 6 nodes
    vector<int> vals2 = {4, 2, 2, 3, 1, 3};
    ListNode* head2 = createList(vals2);

    int result2 = sol.pairSum(head2);
    cout << "For list 4 -> 2 -> 2 -> 3 -> 1 -> 3, the max pair sum is: " << result2 <<endl;

    deleteList(head2);

    return 0;
}