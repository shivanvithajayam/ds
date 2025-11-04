#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define size 5
int queue[size];
int f=-1;
int r=-1;
int isempty(){
    if(f==-1&&r==-1){
        return true;
    }
    else{
        return false;
    }   
}
int isfull(){
    if((r+1)%size==f){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int item){
    if(isfull()){
        printf("queue overflow\n");
    }
    else{
        if(isempty()){
            f=0;
            r=0;
        }
        else{
            r=(r+1)%size;
        }
        queue[r]=item;
    }
}
void dequeue(){
    if(isempty()){
        printf("queue underflow\n");
    }
    else if(f==r){
        f=-1;
        r=-1;
    }
    else{
        f=(f+1)%size;
    }
}
void display(){
    if(isempty()){
        printf("stack is empty");
    }
    else{
        printf("queue elements are:");
        for(int i=f;i!=r;i=(i+1)%size){
            printf("%d\t",queue[i]);
        }
        printf("%d",queue[r]);
    }
}
int main()
{
    int item;
    int choice;
    while(1){
        printf("\nselect choice: 1)insert 2)delete 3)display 4)exit :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter element to insert:");
            scanf("%d",&item);
            enqueue(item);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("wrong choice");
        }
    }
}
