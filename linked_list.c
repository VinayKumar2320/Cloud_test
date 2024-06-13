#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
  int data;
  struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head_ref, int new_data);
void insertAtEnd(struct Node** head_ref, int new_data);
void printList(struct Node* node);

int main() {
  struct Node* head = NULL; // Initially list is empty

  // Insert elements at the beginning
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);

  // Print the linked list
  printf("Linked list: ");
  printList(head);

  // Insert element at the end
  insertAtEnd(&head, 40);

  // Print the modified linked list
  printf("\nLinked list after insertion at end: ");
  printList(head);

  return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int new_data) {
  struct Node* newNode = createNode(new_data);
  newNode->next = (*head_ref);
  (*head_ref) = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* newNode = createNode(new_data);

  if (*head_ref == NULL) {
    *head_ref = newNode;
    return;
  }

  // Traverse to the last node
  struct Node* last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }

  // Append the new node at the end
  last->next = newNode;
}

// Function to print the contents of the linked list
void printList(struct Node* node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}
