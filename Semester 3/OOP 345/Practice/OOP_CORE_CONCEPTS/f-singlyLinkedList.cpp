#include <iostream>

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}

void insertAtEnd(Node*& head, int data) {
    if (head == nullptr) {
        std::cout << "List is empty. Inserting " << data << " as head.\n";
        head = new Node{ data, nullptr };
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node{ data, nullptr };
        std::cout << "Inserted " << data << " at the end.\n";
    }
}

void deleteNode(Node*& head, int key) {
    if (head == nullptr) {
        std::cout << "List is empty. Doing Nothing.\n";
        return;
    }

    // Handle deletion of the head node
    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Handle deletion of non-head nodes
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
    std::cout << key << " has been deleted.\n";
}

int main() {
    Node* head = new Node{ 1, nullptr };
    head->next = new Node{ 2, nullptr };
    head->next->next = new Node{ 3, nullptr };

    printList(head);
    insertAtEnd(head, 35);
    printList(head);
    deleteNode(head, 2);
    printList(head);
    return 0;
}