#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(-1);
    ListNode *current = &dummy;

    while (list1 && list2) {
        if (list1->val <= list2->val){
            current->next = list1;
            list1 = list1->next; 
        } 
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // append remaining nodes
    if (list1) current->next = list1;
    if (list2) current->next = list2;

    return dummy.next;
}

// Helper function to print linked list
void  printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

// Helper function to create a linked list from array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 0; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);
    std::cout << "Merged List: ";
    printList(mergedList);
    
    return 0;
}
