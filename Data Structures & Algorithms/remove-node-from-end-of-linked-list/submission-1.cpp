/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        int size = 0;
        while (tail->next) {
            tail = tail->next;
            size++;
        }
        ListNode* to_remove = head;
        if (size - n == -1) {
    ListNode* new_head = head->next;
    delete head;
    return new_head;
        }
        for ( int i = 0; i < size-n; i++) {
            to_remove = to_remove->next;
        }
        ListNode* tmp = to_remove->next->next;
        delete to_remove->next;
        to_remove->next = tmp;
        return head;
    }
};
