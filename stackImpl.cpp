#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top , capacity;
    int* arr;
};

struct Stack* createStack(int cap)
{
    struct Stack* stck = (struct Stack*)malloc(sizeof(struct Stack));
    stck->capacity = cap;
    stck->top = -1;
    stck->arr = (int*)malloc((stck->capacity)*sizeof(int));
    return stck;
};

void push(struct Stack* stck,int item)
{
    if((stck->top)!=(stck->capacity-1)){
        stck->top++;
        stck->arr[stck->top] = item;
    }
    else
        printf("stack is Full");
}
int pop(struct Stack* stck)
{
    int item;
    if((stck->top) == -1){
         printf("stack is empty");
         return -1;
    }
    else{
        item = stck->arr[stck->top];
        stck->top--;
    }
    return item;
}
void displayStack(struct Stack* stck)
{
    int i=0;
    while(i <= stck->top){
        printf("%d ",stck->arr[i]);
        i++;
    }
    printf("\n");
}

