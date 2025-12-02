#include<stdio.h>
struct Node* head=NULL;
struct Node* temp=NULL;
struct Node{
    int data;
    struct Node *next; 
    struct Node *prev; 
};
struct Node*createnode(int val){
    struct Node *newnode=(struct node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert(int val){
    struct Node *newnode=createnode(val);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;
    }
}
void delete(int val){
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found\n", val);
        return;
    }
    if (temp == head) {
        head = temp->next; 
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    else if (temp->next != NULL) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    else {
        temp->prev->next = NULL;
    }

    free(temp);
    printf("Deleted %d\n", val);
}
void display(){
     temp=head;
     while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }  
    return;
}
int main(){
    int choice;
    int val;
    printf("1)insert 2)delete 3)display 4)exit");
    while(1){
        printf("\nenter choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter value to insert");
            scanf("%d",&val);
            insert(val);
            break;

            case 2:
            printf("enter value to delete");
            scanf("%d",&val);
            delete(val);
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);

            default:
            printf("wrong choice");
        }
    }
}





