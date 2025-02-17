class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->next = nullptr;
    }
};

class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: create new nodes and interweave them with the original list
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: assign random pointers for the new nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and the copied list
        Node* newHead = head->next;
        Node* copy = newHead;
        while (curr) {
            curr->next = curr->next->next;
            if (copy->next) copy->next = copy->next->next;
            curr = curr->next;
            copy = copy->next;
        }
        return newHead;
    }    
};
