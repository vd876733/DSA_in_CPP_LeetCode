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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;
        while (curr != nullptr) {
            // Save the next node
            ListNode* next = curr->next;
            // Start from the beginning of sorted list
            ListNode* prev = &dummy;
            // Find correct position
            while (prev->next != nullptr &&
                   prev->next->val < curr->val) {
                prev = prev->next;
            }
            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;
            // Move to next original node
            curr = next;
        }
        return dummy.next;
    }
};