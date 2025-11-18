#include<stdio.h>
#include<stdlib.h>
struct Node *head1=NULL;
struct Node *head2=NULL;
struct Node *temp=NULL;
struct Node{
    int data;
    struct Node *next; 
};
struct Node*createnode(int val){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
void append(struct Node** head, int data) {
    struct Node* newNode = createnode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void concatenate(struct Node** listA, struct Node* listB) {
    if (*listA == NULL) {
        *listA = listB;
        return;
    }
    struct Node* temp = *listA;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = listB;
}
void reverse(){
    struct Node *next=NULL;
    struct Node *curr=head1;
    struct Node *prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head1=prev;
}
void swap(struct Node *a,struct Node *b){
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}
void bubbleSort()
{
    int swapped;
    struct Node *first;
    struct Node *last = NULL;

    if (head1 == NULL)
        return;

    do
    {
        swapped = 0;
        first = head1;

        while (first->next != last)
        {
            if (first->data > first->next->data)
            {
                swap(first, first->next);
                swapped = 1;
            }
            first = first->next;
        }
        last = first;
    } while (swapped);
}


void display(){
   temp=head1;
   while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }  
    return;
}
int main(){
    int choice;
    int val;
    printf("menu 1)append to list-1 2)append to list-2 3)reverse_list1 4)concatenate_l1_an_l2  5)sort list 1 6)display 7)exit");
    while(1){
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:   

            printf("enter value to insert at end of list1");
            scanf("%d",&val);
            append(&head1,val);
            break;

            case 2:   
            printf("enter value to insert at end of list2");
            scanf("%d",&val);
            append(&head2,val);
            break;

            case 3:   
            reverse();
            break;

            case 4:
            concatenate(&head1,head2);
            break;

            case 5:
            bubbleSort();
            break;

            case 6:
            display(head1);
            break;
            
            case 7:
            exit(0);
            
            default:
            printf("wrong option");
            
            
        }
        
    }
}


