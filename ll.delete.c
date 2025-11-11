#include<stdio.h>
#include<stdlib.h>
struct Node *head=NULL;
struct Node *temp=NULL;
struct Node *prev=NULL;
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
void insert_at_front(int val){
    struct Node *newnode=createnode(val);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
        return;
    }
}
void delete_at_front(){
    if(head==NULL){
        printf("Empty list,cannot delete");
    }
    temp=head;
    head=temp->next;
    free(temp);

    
}
void delete_at_end(){
    if(head==NULL){
        printf("empty");
    }
    struct Node* temp=head;
    struct Node* prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void delete_at_pos(int pos){
    if(head==NULL){
        printf("Empty list,cannot delete");
    }
    if(pos==1){
        delete_at_front();
    }
    else{
        temp=head;
        prev=NULL;
        for(int i=1;i<pos;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
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
    int pos;
    printf("menu 1)insert_at_front 2)delete_at_front 3)delete_at_end4)delete_at_pos 5)display 6)exit");
    while(1){
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:   
            printf("enter value to insert at front:");
            scanf("%d",&val);
            insert_at_front(val);
            break;
            
            case 2:   
            delete_at_front();
            break;

            case 3:
            delete_at_end();
            break;
            
            case 4:
            printf("enter position to delete");
            scanf("%d",&pos);
            delete_at_pos(pos);
            break;
            
            case 5:
            display();
            break;
            
            case 6:
            exit(0);
            
            default:
            printf("wrong option");
            
            
        }
        
    }
}

