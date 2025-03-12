#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void stack_init(struct Stack *stack);
bool isStack_full(struct Stack *stack);
bool isStack_empty(struct Stack *stack);
void push(struct Stack *stack,int val);
int pop(struct Stack *stack);
int peek(struct Stack *stack);

void main(){
    
    struct Stack st;
    int top_element;
    stack_init(&st);
    
    push(&st,1);
    push(&st,2);
    push(&st,3);
    
    top_element = peek(&st);
    printf("Current Top : %d\n",top_element);
    
    pop(&st);
    pop(&st);
    
    top_element =peek(&st);
    printf("Current Top : %d\n",top_element);
    
}

void stack_init(struct Stack *stack){
    
    stack->top = -1;
}

bool isStack_full(struct Stack *stack){
    if (stack->top == MAX_SIZE - 1){
        return true;
    }
    else{
        return false;
    }
}

bool isStack_empty(struct Stack *stack){
    if (stack->top == -1){
        return true;
    }
    else{
        return false;
    }
}

void push(struct Stack *stack,int val){
    
    if (isStack_full(stack)){
        printf("Stack is Already Full.\n");
    }
    else{
        printf("Element Pushed in Stack: %d\n",val);
        stack->top++;
        stack->arr[stack->top] = val;
    }
    return;
}

int pop(struct Stack *stack){
    
    if (isStack_empty(stack)){
        printf("Stack is Empty.\n");
        return -1;
    }
    else{
        int pop_element = stack->arr[stack->top];
        stack->top--;
        printf("Element popped : %d\n",pop_element);
        return pop_element;
    }
}

int peek(struct Stack *stack){

    if (isStack_empty(stack)){
        printf("Stack is Empty.\n");
        return -1;
    }
    
    return stack->arr[stack->top];
}