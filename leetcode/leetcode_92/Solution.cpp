struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reversseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Move prev to the node before left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: reverse the sublist
        ListNode* curr = prev->next;
        ListNode* nextNode = nullptr;
        ListNode* prevNode = nullptr;
        for (int i = 0; i <= right - left; i++) {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        // Step 3: Connect the reversed part with the remaining list
        prev->next->next = curr;
        prev->next = prevNode;

        return dummy.next;
    }    
};