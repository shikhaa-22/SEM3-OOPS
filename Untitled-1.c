#include<stdio.h>
#include<stdlib.h>
struct node {
  int info;
  struct node* lchild;
  struct node* rchild;
};

void inorderTraversal(struct node* root) {
  if (root != NULL) {
    inorderTraversal(root->lchild);
    printf("%d ", root->info);
    inorderTraversal(root->rchild);
  }
}

struct node* createnode(int info) {
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  newnode->info = info;
  newnode->lchild = NULL;
  newnode->rchild = NULL;
  return newnode;
}

struct node *search(struct node * ptr,int skey){
    if (ptr==NULL){
        printf("KEY NOT FOUND\n");
        return NULL;
    }
    if(skey<ptr->info)
        return search(ptr->lchild,skey);
    else if(skey>ptr->info)
        return search(ptr->rchild,skey);
    else
        return ptr;
}

struct node *insert(struct node *ptr,int ikey){
    struct node *tmp,*succ;
    if(ptr==NULL){
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->info=ikey;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
    }
    else if(ikey<ptr->info)
    ptr->lchild=insert(ptr->lchild,ikey);
    else if(ikey>ptr->info)
    ptr->rchild=insert(ptr->rchild,ikey);
    else
    printf("DUPLICATE\n");
    return ptr;
}

struct node *delete(struct node *ptr,int dkey){
    struct node *tmp,*succ;
    if(ptr==NULL){
        printf("KEY NOT FOUND\n");
        return ptr;
    }
    if(dkey<ptr->info)
    ptr->lchild=delete(ptr->lchild,dkey);
    else if(dkey>ptr->info)
    ptr->rchild=delete(ptr->rchild,dkey);
    else{
        if(ptr->lchild!=NULL && ptr->rchild!=NULL){
            succ=ptr->rchild;
            while(succ->lchild!=NULL)
            succ=succ->lchild;
            ptr->info=succ->info;
            ptr->rchild=delete(ptr->rchild,succ->info);
             
        }
        else{
            tmp=ptr;
            if(ptr->lchild!=NULL)
            ptr=ptr->lchild;
            else if(ptr->rchild!=NULL)
            ptr=ptr->rchild;
            else
            ptr=NULL;
            free(tmp);
        }
    }
    return ptr;
}
int main(){
    struct node* root = NULL;
    int choice, data;
    do{
      printf("1. To Insert\n");
      printf("2. To Search\n");
      printf("3. Inorder Traversal is\n");
      printf("4. To Delete\n");
      printf("5. To Exit\n"); 
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        root = insert(root, data);
        break;
        
      case 2:
        printf("Enter the key to be searched: ");
        scanf("%d", &data);
        if (search(root, data) != NULL) {
        printf("Key found in the BST\n");
        } 
        else {
        printf("Key not found in the BST\n");
        }
        break;
      case 3:
        printf("Inorder traversal of the binary search tree: ");
        inorderTraversal(root);
        printf("\n");
        break;
      case 4:
        printf("Enter the key to be deleted: ");
        scanf("%d", &data);
        root = delete(root, data);
        break;
      case 5:
        printf("Exiting the program\n");
        exit(0);
      default:
        printf("Invalid choice\n");
      }
    }while(choice!=5);
    return 0;
}