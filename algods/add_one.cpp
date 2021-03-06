#include <iostream>

struct Node {
    int val;
    Node* next;
    Node(int value, Node* next): val(value), next(next)
    {}
};

// Recursive function to add One to the end of linked list.
int AddOneUtil(Node *n) {
    if (n->next == NULL) {
        int val = n->val + 1;
        n->val = val % 10;
        return val / 10;
    } else {
        int c = AddOneUtil(n->next);
        int val = n->val + c;
        n->val = val % 10;
        return val / 10;
    }
}

Node* AddOne(Node *head) {
    int c = AddOneUtil(head);
    if (c == 1) {
        Node* n100 = new Node(1, NULL);
        n100->next = head;
        head = n100;
    }
    return head;
}

int main() {
    Node* n1 = new Node(9, NULL);
    Node* n2 = new Node(5, NULL);
    n1->next = n2;
    Node* head = n1;
    head = AddOne(head);
    Node *curr = head;
    while (curr != NULL) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    return 0;
}

