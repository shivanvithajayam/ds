#include<stdio.h>
#include<stdlib.h>
struct Node *shead=NULL;
struct Node *temp=NULL;
struct Node *qhead=NULL;
struct Node{
    int data;
    struct Node *next; 
};
struct Node*createnode(int val){
    struct Node *newnode=(struct node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
void insert_stack(int val){
    struct Node *newnode=createnode(val);
    if(shead==NULL){
        shead=newnode;
    }
    else{
        newnode->next=shead;
        shead=newnode;
        return;
    }
}
void insert_queue(int val){
    struct Node *newnode=createnode(val);
    if(qhead==NULL){
        qhead=newnode;
    }
    else{
        temp=qhead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        return;
    }
}
void delete_stack(){
    if(shead==NULL){
        printf("Empty list,cannot delete");
    }
    else{
        temp=shead;
        shead=temp->next;
        free(temp);

    }
}
void delete_queue(){
    if(qhead==NULL){
        printf("Empty list,cannot delete");
    }
    else{
        temp=qhead;
        qhead=temp->next;
        free(temp);

    } 
}
void display(struct Node * head){
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
    printf("menu 1)insert_stack 2)insert_queue 3)delete_stack 4)delete_queue 5)display_stack  6)dislay_queue 7)exit");
    while(1){
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:   
            printf("enter value to insert to stack");
            scanf("%d",&val);
            insert_stack(val);
            break;
            
            case 2:   
            printf("enter value to insert to queue");
            scanf("%d",&val);
            insert_queue(val);
            break;

            case 3:
            delete_stack();
            break;
            
            case 4:
            delete_queue();
            break;
            
            case 5:
            display(shead);
            break;
            
            case 6:
            display(qhead);
            break;

            case 7:
            exit(0);
            
            default:
            printf("wrong option");
            
            
        }
        
    }
}


   