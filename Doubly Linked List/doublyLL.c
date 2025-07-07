#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int val;
    struct Node *next;
    struct Node *prev;
}Node;

Node *CreateNode(int data){
    Node *NN = (Node *)malloc(sizeof(Node));
    if (NULL == NN){
        printf("Memory Allocation failed...\n");
        exit(1);
    }
    NN->val = data;
    NN->next = NULL;
    NN->prev = NULL;

    return NN;
}

int listsize(Node *H){
    int count = 0;
    Node *curr = H;

    while(curr){
        count++;
        curr = curr->next;
    }

    return count;
}

void printlist(Node *H){
    Node *curr = H;

    while(curr->next != NULL){
        printf("%d->",curr->val);
        curr = curr->next;
    }
    printf("%d\n",curr->val);
}

void printrev(Node *T){
    Node *curr = T;

    while(curr->prev != NULL){
        printf("%d->",curr->val);
        curr = curr->prev;
    }
    printf("%d\n",curr->val);
}

void InsertNode(Node **H, int data, int pos, Node **T){
    int size = listsize(*H);
    Node *NN = (Node *)malloc(sizeof(Node));
    if (NULL == NN){
        printf("Memory Allocation failed in f(InsertNode)\n....");
        exit(1);
    }
    NN->val = data;
    NN->next = NULL;
    NN->prev = NULL;

    Node *curr = *H;

    if (pos == 0){
        NN->next = curr;
        curr->prev = NN;
        *H = NN;
        *T = *H;
    }
    else if(pos == 1){
        curr->next = NN;
        NN->prev = curr;
        *T = NN;
    }
    else if(pos >= size){
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = NN;
        NN->prev = curr;
        *T = NN;
    }
    else{
        Node *before = NULL;

        while(pos > 0){
            before = curr;
            curr = curr->next;
            pos--;
        }
        NN->next = curr;
        before->next = NN;
        curr->prev = NN;
        NN->prev = before;
    }

    printf("Node Inserted.\n");
}

void RemoveNode(Node **H,int pos,Node **T){
    int size = listsize(*H);
    Node *curr = *H;
    Node *temp = NULL;

    if (pos == 0){
        temp = curr;
        curr = curr->next;
        *H = curr;
        curr->prev = NULL;
        free(temp);
        printf("Node at Head Removed\n");
        temp = NULL;
    }
    else if(pos > size){
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        temp = curr->next;
        *T = curr;
        free(temp);
        printf("Last Node Deleted...\n");
        temp = NULL;
        curr->next = NULL;
    }
    else{
        Node *before = NULL;
        while(pos > 0){
            before = curr;
            curr = curr->next;
            pos--;
        }
        before->next = curr->next;
        curr->next->prev = before;
        free(curr);
        printf("Deleted node...\n");
        curr = NULL;
        
    }
    
}

void main(){

    Node *head = CreateNode(1);
    Node *tail = NULL;
    InsertNode(&head,2,3,&tail);
    InsertNode(&head,3,5,&tail);
    InsertNode(&head,4,6,&tail);

    InsertNode(&head,5,3,&tail);

    //printlist(head);
    //printrev(tail);

    RemoveNode(&head,0,&tail);
    RemoveNode(&head,7,&tail);
    RemoveNode(&head,1,&tail);

    printlist(head);
    printrev(tail);

}