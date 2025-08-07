#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define true 1
#define false 0

typedef struct node_t
{
    int val;
    struct node_t *left;
    struct node_t *right;
} node;


node* create_node(int val)
{
    node *tmp = calloc(1, sizeof(node));
    if ( tmp == NULL)
    {
        printf("ERR: Unable to create new node\n");
        return NULL;
    }
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void add_node(node **root, int val)
{
    node *new_node = create_node(val);

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    node *iter = *root;
    node *prev = *root;
    while (iter)
    {
        prev = iter;
        if (val <= iter->val)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if (val <= prev->val)
        prev->left = new_node;
    else
        prev->right = new_node;
}

void pre_order_print(node *root)
{
    if ( root == NULL)
        return;
    
    pre_order_print(root->left);
    printf("%d ", root->val);
    pre_order_print(root->right);
}

int heightOfTree(node *root)
{
    if (root == NULL)
        return -1;
    
    int l_h = heightOfTree(root->left);
    int r_h = heightOfTree(root->right);

    return l_h > r_h ? l_h +1 : r_h + 1;
}

int main()
{
    int count, numOfNodes;
    int val;
    printf("Enter node count : ");
    scanf("%d", &count);

    node *root = NULL;
    numOfNodes = count; 
    while(count)
    {
        scanf("%d",&val);
        add_node(&root, val);
        count--;
    }

    pre_order_print(root);
    printf("\n%d\n", heightOfTree(root));
}
