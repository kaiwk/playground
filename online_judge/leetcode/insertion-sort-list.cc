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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre_target = head, *target = head->next;

        for (;target != NULL;) {

            ListNode *pre_walk = dummy, *walk = dummy->next;

            for (; walk != target; walk = walk->next) {
                if (target->val < walk->val) {
                    pre_target->next = target->next;
                    target->next = pre_walk->next;
                    pre_walk->next = target;

                    target = pre_target->next;
                    break;
                }
                pre_walk = walk;
            }

            if (walk == target) {
                pre_target = pre_target->next;
                target = pre_target->next;
            }
        }
        return dummy->next;
    }
};
