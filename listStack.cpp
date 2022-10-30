#include<stdio.h>
#include<stdlib.h>

struct list{
    int item;
    struct list* next;
};

void push(struct list** stack , int value){
    struct list *s = (struct list*)malloc(sizeof(struct list));
    s->item = value;
    s->next = *stack;
    (*stack) = s;
}

int pop(struct list** stack){
    if(*stack != NULL){
        int popped = (*stack)->item;
        struct list* temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    return popped;
    }
    else{
        return -1;
    }
}

void display(struct list* stack){
    if(stack != NULL){
        printf("\tstack elements : ");
        while(stack != NULL){
            printf("%d ",stack->item);
            stack = stack->next;
        }
    }
    else{
        printf("\tstack is empty\n");
    }
}

int main(){
    struct list *stack = (struct list*)malloc(sizeof(struct list));
    stack = NULL;
    printf("\n\tstack operations");
    printf("\n\t----------------");
    int choice , val;
    printf("\n\t 1.Push");
    printf("\n\t 2.Pop");
    printf("\n\t 3.Display");
    printf("\n\t 4.Exit");
    while(1){
        printf("\n\tenter your choice: ");
        scanf("%d",&choice);
           switch(choice){
            case 1:
                {
                    printf("\tenter a element to be pushed : ");
                    scanf("%d",&val);
                    push(&stack,val);
                    break;
                }
            case 2:
                {
                    val = pop(&stack);
                    if(val == -1)
                        printf("\n\tstack is empty");
                    else
                        printf("\tpopped value is : %d ",val);
                    break;
                }
            case 3:
                {
                    display(stack);
                    break;
                }
            case 4:
                {
                   exit(0);
                }
           }
   }
return 0;
}
