#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define SIZE 4093

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT_HASH 1
typedef struct __PHONE_BOOK_DATA {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} pDATA;
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct pDATA *pDATA;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

int findName(char lastName[], entry *hash_table_index[]);
void *append(char lastName[], entry *hash_table_index[]);

#endif
