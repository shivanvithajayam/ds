#include<stdio.h>
struct Node *head=NULL;
struct Node *temp=NULL;
struct Node *last=NULL;
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
void insert_at_back(int val){
    struct Node *newnode=createnode(val);
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        return;
    }
}
void insert_at_position(int pos,int val){
    struct Node *newnode=createnode(val);
    int i;
    struct Node *temp=head;
    if(pos==1){
        temp->next=head;
        head=newnode;
    }
    else{
        for(i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return;
    }
}
void display(){
    struct Node *temp=head;
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
    printf("menu 1)insert_at_front 2)insert_at_back 3)insert_at_position 4)display 5)exit");
    while(1){
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:   
            printf("enter value to insert at front:");
            scanf("%d",&val);
            insert_at_front(val);
            break;
            
            case 2:   
            printf("enter value to insert at back:");
            scanf("%d",&val);
            insert_at_back(val);
            break;
            
            case 3:
            printf("enter position and value to insert:");
            scanf("%d %d",&pos,&val);
            insert_at_position(pos,val);
            break;
            
            case 4:
            
            display();
            break;
            
            case 5:
            
            exit(0);
            
            default:
            
            printf("wrong option");
            
            
        }
        
    }
}

