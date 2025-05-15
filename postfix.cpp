#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    stack[++top] = value;
}
int pop() {
    return stack[top--];
}
int evaluatePostfix(char* expression) {
    int i;
    for (i = 0; i < strlen(expression); i++) {
        char ch = expression[i];
        if (ch == ' ') continue;
        if (isdigit(ch)) {
            push(ch - '0');  
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = pop();
            int operand1 = pop();
            int result;
        
            if (ch == '+') result = operand1 + operand2;
            if (ch == '-') result = operand1 - operand2;
            if (ch == '*') result = operand1 * operand2;
            if (ch == '/') result = operand1 / operand2;
            
            push(result);
        }
    }
    return pop();
}

int main() {
    char expression[MAX];
    printf("Enter postfix expression: ");
    fgets(expression, MAX, stdin);
    
    // Remove newline character from input (if present)
    expression[strcspn(expression, "\n")] = 0;  // strcspn finds newline position and replaces it
    
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    
    return 0;
}
