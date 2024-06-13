#include <stdio.h>
#define MAX_SIZE 100 // Define the maximum size of the stack

int stack[MAX_SIZE];
int top = -1; // Initialize the top pointer to -1 (empty stack)

// Function prototypes
void push(int data);
int pop();
int peek();
int isEmpty();
int isFull();

int main() {
  push(10);
  push(20);
  printf("Top element: %d\n", peek());
  int popped_value = pop();
  printf("Popped value: %d\n", popped_value);
  printf("Top element after popping: %d\n", peek());
  return 0;
}

// Function to push an element onto the stack
void push(int data) {
  if (isFull()) {
    printf("Stack overflow!\n");
    return;
  }
  stack[++top] = data;
}

// Function to pop an element from the stack
int pop() {
  if (isEmpty()) {
    printf("Stack underflow!\n");
    return -1; // Indicate error or use a different value
  }
  return stack[top--];
}

// Function to return the top element without removing it
int peek() {
  if (isEmpty()) {
    printf("Stack is empty!\n");
    return -1; // Indicate error or use a different value
  }
  return stack[top];
}

// Function to check if the stack is empty
int isEmpty() {
  return top == -1;
}

// Function to check if the stack is full
int isFull() {
  return top == MAX_SIZE - 1;
}
