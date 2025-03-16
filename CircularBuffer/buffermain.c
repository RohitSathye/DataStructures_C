#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char *data;
    int head;
    int tail;
    int size;
    int capacity;
}Buffer;

Buffer* create_buffer(int cap){
    
    Buffer *buf = (Buffer*)malloc(sizeof(Buffer));
    if (!buf){
        printf("Memory Allocation Failure\n");
        return NULL;
    }

    buf->data = (char *)calloc(cap,sizeof(char));
    if(!buf->data){
        printf("Data Array could not be allocated. Buffer Failure...\n");
        return NULL;
    }

    buf->head = 0;
    buf->tail = 0;
    buf->size = 0;
    buf->capacity = cap;

    return buf;
}

void free_buffer(Buffer *B){
    if (B){
        free(B->data);
        free(B);
        printf("Buffer memory freed...\n");
    }
}

bool Buffer_full(Buffer *buf){
    if (buf->size == buf->capacity){
        return true;
    }
    return false;
}

bool Buffer_empty(Buffer *buf){
    if (buf->size == 0){
        return true;
    }
    return false;
}

void Buffer_enqueue(Buffer *buf,char c){
    if (Buffer_full(buf)){
        printf("Buffer Full. Cannot add more elements\n");
        return;
    }
    buf->data[buf->tail] = c;
    buf->tail = (buf->tail + 1) % buf->capacity;
    buf->size++;
    return;
}

char Buffer_dequeue(Buffer *buf){
    char c;
    if (Buffer_empty(buf)){
        printf("Buffer Empty, Nothing to return....\n");
        return NULL;
    }
    c = buf->data[buf->head];
    buf->head = (buf->head + 1) % buf->capacity;
    buf->size--;

    return c;
}

void main(){
    Buffer *mybuffer = create_buffer(10);

    if (!mybuffer){
        printf("Resource Allocation Failure...\n");
    }

    Buffer_enqueue(mybuffer,'A');
    Buffer_enqueue(mybuffer,'B');
    Buffer_enqueue(mybuffer,'C');

    char data;

    data = Buffer_dequeue(mybuffer);
    if (data){
        printf("Dequeue Element: %c\n",data);
    }
    
    data = Buffer_dequeue(mybuffer);
    if (data){
        printf("Dequeue Element: %c\n",data);
    }

    data = Buffer_dequeue(mybuffer);
    if (data){
        printf("Dequeue Element: %c\n",data);
    }

    data = Buffer_dequeue(mybuffer);
    if (data){
        printf("Dequeue Element: %c\n",data);
    }

    free_buffer(mybuffer);

}




