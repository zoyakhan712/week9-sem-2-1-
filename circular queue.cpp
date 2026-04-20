#include <stdio.h>
#include <stdlib.h>

/* -------- NODE STRUCTURE -------- */
struct node {
    int data;
    struct node *left, *right;
};

/* -------- CREATE NODE -------- */
struct node* create(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* -------- INSERT -------- */
struct node* insert(struct node* root, int value) {
    if(root == NULL)
        return create(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* -------- FIND MIN (FOR DELETE) -------- */
struct node* findMin(struct node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

/* -------- DELETE -------- */
struct node* deleteNode(struct node* root, int key) {
    if(root == NULL)
        return NULL;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found

        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if(root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

/* -------- SEARCH -------- */
int search(struct node* root, int key) {
    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

/* -------- INORDER (DISPLAY) -------- */
void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* -------- MAIN -------- */
int main() {
    struct node* root = NULL;
    int choice, value;

    while(1) {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if(search(root, value))
                    printf("Element Found\n");
                else
                    printf("Element Not Found\n");
                break;

            case 4:
                printf("BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
