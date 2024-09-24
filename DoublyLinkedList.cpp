#include <iostream>

// A doubly linked list consists of nodes where each node contains data and
// pointers to the next and previous nodes in the sequence.

class DoublyLinkedList {
private:
    // Definition of a node in the linked list
    struct Node {
        int data;      // The value stored in the node
        Node* next;    // Pointer to the next node in the list
        Node* prev;    // Pointer to the previous node in the list

        // Constructor to initialize a node with a given value
        Node(int value) : data{ value }, next{ nullptr }, prev{ nullptr } {}
    };

    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list

public:
    // Constructor to initialize the linked list
    DoublyLinkedList() : head{ nullptr }, tail{ nullptr } {}

    // Destructor to clean up memory when the list is destroyed
    ~DoublyLinkedList() {
        clear(); // Free all nodes to prevent memory leaks
    }

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        // Create a new node with the provided value
        Node* newNode{ new Node(value) };

        // If the list is empty
        if (!head) {
            head = tail = newNode; // Both head and tail point to the new node
        }
        else {
            newNode->next = head; // Link the new node to the current head
            head->prev = newNode; // Link the current head to the new node
            head = newNode;       // Update the head to the new node
        }
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        // Create a new node with the provided value
        Node* newNode{ new Node(value) };

        // If the list is empty
        if (!head) {
            head = tail = newNode; // Both head and tail point to the new node
        }
        else {
            newNode->prev = tail; // Link the new node to the current tail
            tail->next = newNode; // Link the current tail to the new node
            tail = newNode;       // Update the tail to the new node
        }
    }

    // Function to insert a new node after a given node
    void insertAfter(int value, int afterValue) {

        Node* current{ head };
        // Use a while loop to find the node after which to insert the new node


        if (current) {
            Node* newNode{ new Node(value) };

            // Insert the new node after the current node
            // by updating the necessary pointers
            
            // if there is a next node, update the next node's previous
            // else update the tail

        }
        else {
            std::cout << "Node with value " << afterValue << " not found." << '\n';
        }
    }

    // Function to delete the first node that contains the specified value
    void deleteNode(int value) {
        // if list is empty, end the function

        // Find the node to delete
        Node* current{ head };
        while (current && current->data != value) {
            current = current->next;
        }

        if (current) {
            if (current->prev) {
                // Update the previous node's next pointer to skip the current node
            }
            else {
                // update the head
            }

            if (current->next) {
                // Update the next node's previous pointer to skip the current node
            }
            else {
                // update the tail
            }

            // Free memory of the deleted node
        }
        else {
            std::cout << "Node with value " << value << " not found." << '\n';
        }
    }

    // Function to search for a node with the specified value
    bool searchNode(int value) const {
        Node* current{ head }; // Start from the head of the list

        // Traverse the list node by node
        while (current) {
            if (current->data == value)
                return true; // Value found
            current = current->next; // Move to the next node
        }
        return false; // Value not found in the list
    }

    // Function to clear the entire linked list and free memory
    void clear() {
        Node* current{ head }; // Start from the head

        // Traverse and delete each node
        while (current) {
            Node* nextNode = current->next; // Keep track of the next node
            delete current;                  // Delete the current node
            current = nextNode;              // Move to the next node
        }

        head = tail = nullptr; // Reset head and tail to indicate the list is now empty
    }

    // Function to display the contents of the linked list from head to tail
    void display() const {
        Node* current{ head }; // Start from the head

        // Traverse the list and print each node's data
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next; // Move to the next node
        }
        std::cout << "nullptr" << '\n'; // Indicate the end of the list
    }

    // Function to display the contents of the linked list from tail to head
    void displayBackward() const {
        // Start from the tail

        // Traverse the list and print each node's data

        // Indicate the end of the list
    }
};

int main() {
    DoublyLinkedList list;

    // Inserting nodes into the list
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    // Display the list after insertions
    std::cout << "List after insertions: ";
    list.display(); // Expected Output: 5 <-> 10 <-> 20 <-> 30 <-> nullptr

    // Insert a node after a specific value
    list.insertAfter(25, 20);
    std::cout << "List after inserting 25 after 20: ";
    list.display(); // Expected Output: 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> nullptr

    // Searching for nodes in the list
    std::cout << "Searching for 20: " << (list.searchNode(20) ? "Found" : "Not Found") << '\n'; // Found
    std::cout << "Searching for 99: " << (list.searchNode(99) ? "Found" : "Not Found") << '\n'; // Not Found

    // Deleting a node from the list
    list.deleteNode(20);
    std::cout << "List after deleting 20: ";
    list.display(); // Expected Output: 5 <-> 10 <-> 25 <-> 30 <-> nullptr

    // Display the list backward
    std::cout << "List displayed backward: ";
    list.displayBackward(); // Expected Output: 30 <-> 25 <-> 10 <-> 5 <-> nullptr

    // Clearing the entire list
    list.clear();
    std::cout << "List after clearing: ";
    list.display(); // Expected Output: nullptr

    return 0;
}