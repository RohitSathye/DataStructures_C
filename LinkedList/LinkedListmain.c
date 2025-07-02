#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* CreateNode(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void PrintList(struct Node* H){
    
    struct Node *ptr = H;
    
    if (H == NULL){
        printf("Linked List Does not exist. No Head");
    }
    
    while (ptr){
        if (ptr->next){
            printf("%d--->",ptr->data);
        }
        else{
            printf("%d",ptr->data);
        }
        
        ptr = ptr->next;
    }
}

void InsertAthead(struct Node **H, int val){
    struct Node *NN = CreateNode(val);
    struct Node *curr = *H;
    
    if (*H == NULL){
        *H = NN;
    }
    else{
        NN->next = *H;
        *H = NN;
    }
}

void InsertAtEnd(struct Node **H,int val){
    struct Node *NN = CreateNode(val);
    struct Node *ptr = *H;
    
    if (*H == NULL){
        *H = NN;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = NN;
    }
}

void InsertNode(struct Node **H,int val,int pos){

    if(pos <= 0){
        InsertAthead(H,val);
        return;
    }
    else{
        int count = 0;
        struct Node *ptr = *H;
        struct Node *NN = CreateNode(val);
        
        while(ptr){
            if (count == pos-1){
                NN->next = ptr->next;
                ptr->next = NN;
                return;
            }
            ptr = ptr->next;
            count++;
        }
        
        InsertAtEnd(H,val);
        return;
    }
}

void Reverse(struct Node **H){
    struct Node *ptr = NULL;
    struct Node *prev = NULL;
    struct Node *curr = NULL;

    curr = *H;

    while(curr){
        ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }

    *H = prev;
}

void main(){
    struct Node* head = CreateNode(1);
    
    InsertAtEnd(&head,2);
    InsertAtEnd(&head,4);
    InsertNode(&head,3,2);

    PrintList(head);
    printf("\n");

    Reverse(&head);
    PrintList(head);
    printf("\n");
}
