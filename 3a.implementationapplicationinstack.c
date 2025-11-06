#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// Stack for characters
typedef struct {
    char data[MAX];
    int top;
} Stack;
// Stack functions
void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX - 1; }
void push(Stack *s, char c) {
    if (!isFull(s)) s->data[++(s->top)] = c;
}
char pop(Stack *s) {
    if (!isEmpty(s)) return s->data[(s->top)--];
    return '\0';
}
char peek(Stack *s) {
    if (!isEmpty(s)) return s->data[s->top];
    return '\0';
}
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int i = 0, k = 0;
    char c;
    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[k++] = pop(&s);
            pop(&s); // Remove '('
        } else { // Operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c))
                postfix[k++] = pop(&s);
            push(&s, c);
        }
    }
    while (!isEmpty(&s))
        postfix[k++] = pop(&s);
    postfix[k] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
