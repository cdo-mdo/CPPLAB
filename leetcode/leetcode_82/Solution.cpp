struct ListNode
{
    int val;
    ListNode *next;

    ListNode() {}
    ListNode(int val) : val(val) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Soluton
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head); // Dummy before head
        ListNode *prev = dummy;

        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                {
                    head = head->next; // skip duplaicates
                }
                prev->next = head->next; // Remove duplicates
            }
            else
            {
                prev = prev->next; // move forward
            }
            head = head->next; // move to next node
        }

        return dummy->next;
    }
};