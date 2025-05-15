#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to perform infix to postfix conversion
void infixToPostfix(char exp[]) {
    int len = strlen(exp);
    char result[100];
    char stack[100];
    int j = 0;
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = exp[i];

        // If the scanned character is an operand, add it to the output string.
        if (isalnum(c)) {
            result[j] = c;
            j++;
        }
        // If the scanned character is '(' push it to the stack.
        else if (c == '(') {
            top++;
            stack[top] = '(';
        }
        // If the scanned character is ')', pop and add to the output string from the stack 
        // until an '(' is encountered.
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j] = stack[top];
                j++;
                top--;
            }
            top--; // Remove '(' from stack
        }
        // If an operator is scanned
        else {
            while (top != -1 && (prec(c) < prec(stack[top]) ||
                                 prec(c) == prec(stack[top]))) {
                result[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = c;
        }
    }

    // Pop all the remaining elements from the stack
    while (top != -1) {
        result[j] = stack[top];
        j++;
        top--;
    }

    result[j] = '\0'; // Null-terminate the string
    printf("Postfix Expression: %s\n", result);
}

int main() {
    char exp[100];

    // Get input from the user
    printf("Enter infix expression: ");
    scanf("%s", exp);

    // Convert infix to postfix
    infixToPostfix(exp);

    return 0;
}

