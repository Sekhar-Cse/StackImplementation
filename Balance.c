#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a character onto the stack
void push(struct StackNode** top, char data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a character from the stack
char pop(struct StackNode** top) {
    if (*top == NULL) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    struct StackNode* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Function to check if brackets are balanced
int areBracketsBalanced(char* expression) {
    struct StackNode* stack = NULL;
    int length = strlen(expression);
    
    for (int i = 0; i < length; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (stack == NULL) {
                return 0; // Unbalanced expression
            }
            char popped = pop(&stack);
            if ((expression[i] == ')' && popped != '(') ||
                (expression[i] == ']' && popped != '[') ||
                (expression[i] == '}' && popped != '{')) {
                return 0; // Unbalanced expression
            }
        }
    }
    
    return (stack == NULL) ? 1 : 0; // 1 if expression is balanced, 0 otherwise
}

// Main function
int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    
    if (areBracketsBalanced(expression)) {
        printf("Brackets are balanced\n");
    } else {
        printf("Brackets are not balanced\n");
    }
    
    return 0;
}
