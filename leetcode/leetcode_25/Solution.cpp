struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;
        ListNode* curr = head;

        while (true) {
            // Check if there are k nodes left to reverse
            ListNode* check = curr;
            for (int i = 0; i < k; i++) {
                if (!check) return dummy.next;
                check = check->next;
            }

            // Reverse k nodes
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;
            ListNode* groupStart = curr;
            for (int i = 0; i < k; i++) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect the reversed part with the previous part
            prevGroup->next = prev;
            groupStart->next = curr;
            prevGroup= groupStart;
        }

        return dummy.next;
    }    
};
