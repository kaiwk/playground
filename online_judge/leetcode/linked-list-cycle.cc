#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *p1 = head;
        ListNode *p2 = head->next;

        for (; p1 != NULL && p2 != NULL;) {
            if (p1 == p2) {
                return true;
            }
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == NULL) return false;
            p2 = p2->next;
        }
        return false;
    }
};
