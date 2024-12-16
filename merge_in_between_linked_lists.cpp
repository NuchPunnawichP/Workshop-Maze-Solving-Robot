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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* now = list1;
        ListNode *node_a_prev, *node_b_next;
        int cnt = 0;
        while(now != nullptr) {
            if(cnt + 1 == a) {
                node_a_prev = now;
            }
            if(cnt == b + 1) {
                node_b_next = now;
            }
            now = now->next;
            cnt++;
        }
        now = list2;
        while(now->next != nullptr) {
            now = now->next;
        }
        now->next = node_b_next;
        node_a_prev->next = list2;
        return list1;
    }
};