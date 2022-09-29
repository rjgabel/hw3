#include "llrec.h"
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head == nullptr) {
        // We need to set smaller and larger to nullptr here because otherwise a
        // garbage value could be copied into the next pointer of the final node
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    llpivot(head->next, smaller, larger, pivot);
    if (head->val <= pivot) {
        head->next = smaller;
        smaller = head;
    } else {
        head->next = larger;
        larger = head;
    }
    head = nullptr;
}