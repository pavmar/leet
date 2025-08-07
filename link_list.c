#include <stdio.h>
#include <stdlib.h>

struct list_node
{
    int val;
    struct list_node *next;
};

struct list_node *create_node(int val)
{
    struct list_node *new_node;

    new_node = malloc(sizeof(struct list_node));
    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

void insert_node(struct list_node **root, int val)
{
    struct list_node *new_node = create_node(val);

    if (*root == NULL){
        *root = new_node;
        return;
    }

    struct list_node *iter = *root;
    while(iter->next)
        iter = iter->next;
    
    iter->next = new_node;
}

void print_list(struct list_node *root)
{
    while(root)
    {
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}

void free_list(struct list_node **root)
{
    struct list_node *iter = *root;
    struct list_node *del_node = NULL;
    while(iter){
        del_node = iter;
        iter = iter->next;

        free(del_node);
    }
}

void reverse_list(struct list_node **root)
{
    struct list_node *iter = *root;
    struct list_node *new_list = NULL;
    struct list_node *tmp;

    while(iter)
    {
        tmp = iter;
        iter = iter->next;
        tmp->next = new_list;
        new_list = tmp;
    }
    *root = new_list;
}

int main()
{
    struct list_node *root = NULL;
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 3);
    insert_node(&root, 4);
    insert_node(&root, 5);
    insert_node(&root, 6);

    print_list(root);
    reverse_list(&root);
    print_list(root);

    free_list(&root);

}