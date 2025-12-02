#include<stdio.h>
#include<stdlib.h>
struct Node *root=NULL;
struct Node *temp=NULL;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createnode(){
    struct Node * temp;
    printf("\nenter value:");
    temp=(struct Node *)malloc(sizeof(struct Node));
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insertnode(struct Node *root,struct Node *temp){
    if(temp->data < root->data){
        if(root->left!=NULL){
            insertnode(root->left,temp);
        }
        else{
            root->left=temp;
        }
    }
    if(temp->data > root->data){
        if(root->right!=NULL){
            insertnode(root->right,temp);
        }
        else{
            root->right=temp;
        }
    }
}
void inorder(struct Node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    int choice;
    printf("menu 1)insert 2)preorder display 3)postorder display 4)inorder display 5)exit\n");
    while(1){
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                temp=createnode();
                if(root==NULL){
                    root=temp;
                }
                else{
                    insertnode(root,temp);
                }
                break;
            }
            case 2:
            {
                printf("preorder:");
                preorder(root);
                break;
            }
            case 3:
            {
                printf("postorder:");
                postorder(root);
                break;
            }
            case 4:
            {
                printf("inorder:");
                inorder(root);
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                printf("wrong option");
            }
        }
    }
}