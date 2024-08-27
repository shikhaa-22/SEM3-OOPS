//Binary Search tree

#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* lchild;
  struct Node* rchild;
};

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  return newNode;
}

struct Node* insert(struct Node* root, int data) {
  if (root == NULL) {
    root = createNode(data);
  }
  else if (data < root->data) {
    root->lchild = insert(root->lchild, data);
  }
  else if (data > root->data) {
    root->rchild = insert(root->rchild, data);
  }
  return root;
}
struct Node* insertNonRecursive(struct Node* root, int data) {
  struct Node* newNode = createNode(data);
  if (root == NULL) {
    root = newNode;
    return root;
  }
  struct Node* current = root;
  struct Node* parent = NULL;
  while (current != NULL) {
    parent = current;
    if (data < current->data) {
      current = current->lchild;
    } else {
      current = current->rchild;
    }
  }
  if (data < parent->data) {
    parent->lchild = newNode;
  } else {
    parent->rchild = newNode;
  }
  return root;
}

void inorderTraversal(struct Node* root) {
  if (root != NULL) {
    inorderTraversal(root->lchild);
    printf("%d ", root->data);
    inorderTraversal(root->rchild);
  }
}
struct Node* search(struct Node* root, int key) {
  if (root == NULL || root->data == key) {
    return root;
  }
  if (key < root->data) {
    return search(root->lchild, key);
  }
  return search(root->rchild, key);
}
struct Node* searchNonRecursive(struct Node* root, int key) {
  while (root != NULL && root->data != key) {
    if (key < root->data) {
      root = root->lchild;
    } else {
      root = root->rchild;
    }
  }
  return root;
}
struct Node* delete(struct Node* root, int key) {
  if (root == NULL) {
    return root;
  }
  if (key < root->data) {
    root->lchild = delete(root->lchild, key);
  } else if (key > root->data) {
    root->rchild = delete(root->rchild, key);
  } else {
    if (root->lchild == NULL) {
      struct Node* temp = root->rchild;
      free(root);
      return temp;
    } else if (root->rchild == NULL) {
      struct Node* temp = root->lchild;
      free(root);
      return temp;
    }
    struct Node* successor = root->rchild;
    while (successor->lchild != NULL) {
      successor = successor->lchild;
    }
    root->data = successor->data;
    root->rchild = delete(root->rchild, successor->data);
  }
  return root;
}
int main(){
struct Node* root = NULL;
    int choice, data;
    while (1) {
      printf("1. Insert\n");
      printf("2. Search\n");
      printf("3. Inorder Traversal\n");
      printf("4. Delete\n");
      printf("5. Exit\n"); 
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        int insertChoice;
        printf("Choose insert method:\n");
        printf("1. Recursive\n");
        printf("2. Non-Recursive\n");
        printf("Enter your choice: ");
        scanf("%d", &insertChoice);
        switch (insertChoice) {
        case 1:
          root = insert(root, data);
          break;
        case 2:
          root = insertNonRecursive(root, data);
          break;
        default:
          printf("Invalid choice\n");
        }
        break;
      case 2:
        printf("Enter the key to be searched: ");
        scanf("%d", &data);
        int searchChoice;
        printf("Choose search method:\n");
        printf("1. Recursive\n");
        printf("2. Non-Recursive\n");
        printf("Enter your choice: ");
        scanf("%d", &searchChoice);
        switch (searchChoice) {
        case 1:
          if (search(root, data) != NULL) {
        printf("Key found in the BST\n");
          } else {
        printf("Key not found in the BST\n");
          }
          break;
        case 2:
          if (searchNonRecursive(root, data) != NULL) {
        printf("Key found in the BST\n");
          } else {
        printf("Key not found in the BST\n");
          }
          break;
        default:
          printf("Invalid choice\n");
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
    }
    return 0;
}