#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 100

typedef struct
{
    char *key;
    int value;
} item;

void Print_Hashmap(item *Map, int len){

    for(int i = 0; i < len; i++){
        printf("Key = ");
        printf("%s\n",Map[i].key);
        printf("Data = ");
        printf("%d\n",Map[i].value);
    }
}

int Return_value(item *Map,int len,char *Lookup_Key){

    for (int i = 0; i < len; i++){
        if (strcmp(Map[i].key,Lookup_Key) == 0){
            return Map[i].value;
        }
        else{
            continue;
        }
    }
    return -1;
}

void main(){
    int size = 0;
    char search_key[100] = "";
    int res;

    printf("Begin Inputs for Hashmap....\n");
    printf("Enter number of entries in Hashmap: ");

    scanf("%d",&size);
    printf("\n");

    item Hashmap[MAX_CAPACITY] = {};

    for(int i = 0; i < size; i++){
        char K[100] = "";
        int data;

        printf("Enter Key : ");
        scanf("%s",K);
        printf("Enter Value (integer): ");
        scanf("%d",&data);

        Hashmap[i].key = (char *)malloc(strlen(K) + 1);
        if (Hashmap[i].key == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        
        strcpy(Hashmap[i].key, K);
        Hashmap[i].value = data;

        printf("\n");
    }

    printf("Enter Key to Search: ");
    scanf("%s",search_key);
    printf("\n");

    res = Return_value(Hashmap,size,search_key);
    
    if (res == -1){
        printf("Value not found, Key does not exist\n");
    }
    else{
        printf("Value of Key : %d\n",res);
    }
    //Print_Hashmap(Hashmap,size);
}
