#include <stdlib.h>
#include <string.h>
#include "phonebook_opt.h"


/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
int hash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    hash &= 0x7FFFFFFF;
    return (hash% = SIZE);
}
int findName(char lastName[], entry *hash_table_index[])
{
    unsigned long key = hash(lastName);
    entry *now = hash_table_index[key];
    while (now->pNext! = NULL) {
        if (strcasecmp(lastName, now->lastName) == 0)
            return 1;
        now = now->pNext;
    }
    return 0;
}

void *append(char lastName[], entry *hash_table_index[])
{
    int key = hash(lastName);
    entry *temp = hash_table_index[key];
    hash_table_index[key] = (entry *) malloc(sizeof(entry));
    strcpy(hash_table_index[key]->lastName,lastName);
    hash_table_index[key]->pNext = (temp == NULL) ? NULL : temp;
    return NULL;
}
