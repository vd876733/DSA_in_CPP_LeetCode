class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 != nullptr && l2 != nullptr) {

            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        if (l1 != nullptr)
            curr->next = l1;
        else
            curr->next = l2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        // 0 or 1 node is already sorted
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list
        prev->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge
        return merge(left, right);
    }
};