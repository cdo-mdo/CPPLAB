struct ListNode {
    int val;
    ListNode* next;

    ListNode() {}

    ListNode(int val) : val(val) {}

    ListNode(int val, ListNode* next) : val(val), next(next) {}

};

class Solution {
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast ahead by n + 1 step
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both fast and slow until fast reaches the end
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node
        slow->next = slow->next->next;

        return dummy->next;
    }
};

