#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define TBL_SIZE 10000

typedef enum bool_e {
    false = 0,
    true
} bool;

struct hash_set {
    int table[TBL_SIZE];
    bool used[TBL_SIZE];
};


void init_hash_set(struct hash_set *hash)
{
    for(int i = 0; i < TBL_SIZE; i++){
        hash->table[i] = INT_MIN;
        hash->used[i] = false;
    }
}

unsigned int hash(int key)
{
    return (unsigned int)(key % TBL_SIZE + TBL_SIZE) % TBL_SIZE;
}

void insert(struct hash_set *set, int key)
{

    int idx = hash(key);
    int start_idx = idx;

    while(set->used[idx])
    {
        if (set->table[idx] == key)
            return;
        idx = (idx + 1) % TBL_SIZE;

        if (idx == start_idx)
            return;
    }

    set->table[idx] = key;
    set->used[idx] = true;
}

bool find(struct hash_set set, int key)
{
    int idx = hash(key);
    int start_idx = idx;

    while(set.table[idx] != key)
    {
        idx = (idx + 1) % TBL_SIZE;
        if(start_idx == idx)
            return false;
    }
    return true;
}

int main()
{
    struct hash_set set;

    init_hash_set(&set);

    insert(&set, 3);
    insert(&set, 5);
    insert(&set, 6);
    insert(&set, 7);
    insert(&set, 8);
    insert(&set, 100);
    insert(&set, -400);

    if (find(set, -400))
        printf("Found -400\n");

    if (!find(set, 200))
        printf("100 not found in hash\n");
}

