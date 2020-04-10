#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
    int i; 
    struct node *left, *right; 
};  
struct node *newNode(int n) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->i = n; 
    temp->left = temp->right = NULL; 
    return temp; 
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->i); 
        inorder(root->right); 
    } 
} 
struct node* insert(struct node* node, int i) 
{ 
    if (node == NULL)
    return newNode(i); 
    if (i < node->i) 
        node->left  = insert(node->left, i); 
    else
        node->right = insert(node->right, i); 
    return node; 
} 
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
struct node* deleteNode(struct node* root, int i) 
{
    if (root == NULL) return root; 
    if (i < root->i) 
        root->left = deleteNode(root->left, i); 
    else if (i > root->i) 
        root->right = deleteNode(root->right, i); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->i = temp->i; 
        root->right = deleteNode(root->right, temp->i); 
    } 
    return root; 
} 
int main() 
{ 
   struct node *root = NULL; 
    root = insert(root, 23); 
    root = insert(root, 06); 
    root = insert(root, 30); 
    root = insert(root, 11); 
    root = insert(root, 17); 
    root = insert(root, 32); 
    root = insert(root, 75); 
    root = insert(root, 12);
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 23\n"); 
    root = deleteNode(root, 23); 
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 06\n"); 
    root = deleteNode(root, 06); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 75\n"); 
    root = deleteNode(root, 75); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 61\n"); 
    root = deleteNode(root, 61); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    return 0; 
}
