#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// implement ll pivot with recursion in O(n)
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (!head) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    // place head in correct list
    if (head->val <= pivot) {
        smaller = head;
        head = head->next;
        llpivot(head, smaller->next, larger, pivot);
    } else {
        larger = head;
        head = head->next;
        llpivot(head, smaller, larger->next, pivot);
    }
}
