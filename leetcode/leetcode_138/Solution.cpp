#include <unordered_map>

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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        std::unordered_map<Node*, Node*> mp;
        Node* curr = head;

        // First pass: create all nodes and store in a map
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: set the next and random pointer
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }    
};

