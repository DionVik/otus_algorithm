// Реализация хэш таблицы фиксированного размера. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

struct node {
    char *key;
    int val;
    struct node *next;
};

char * get_bytes(char *, int);
int get_crc(char *, int);
void init(struct node **);
void add(char *, int, int, struct node **);
struct node * find(char *, int, struct node **);
int get_hash(char *, int);
int remove_element(char *, int, struct node **);


int main() {
    char* keys[] = {"cat", "dog", "pig", "rose"};
    int keys_len = sizeof(keys) / sizeof(keys[0]);
    int values[] = {11, 22, 33, 44};
    struct node *primary[SIZE];
    init(primary);
    for (int i = 0; i < keys_len; i++){
        int key_len = strlen(keys[i]);
        add (keys[i], key_len, values[i], primary);
    }
    struct node *pinfo = NULL;
    pinfo = find("cat", strlen("cat"), primary);
    if (pinfo) printf("found info: %s, %d\n", pinfo->key, pinfo->val);
    
    int flag = remove_element("cat", strlen("cat"), primary);
    if (flag == 1) printf("deleted %s\n", "cat");
    
    return 0;
}

// Первоначальная инициализация массива структур
void init(struct node **primary) {
    for (int i = 0; i < SIZE; i++) {
        primary[i] = NULL;
    }
}

// преобразуем ключ в массив байт
char * get_bytes(char *key, int length) {
    char *bytes = (char *)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        bytes[i] = (int)key[i];
    }
    return bytes;
}

// получение числового кода ключа
int get_crc(char *bytes, int length) {
    int CRC = 0xFFFF;
    for (int p = 0; p < length; p++) {
        CRC ^= (int)bytes[p];
        for (int i = 8; i != 0; i--) {
            if ((CRC & 0x001) != 0) {
                CRC >>= 1;
                CRC ^= 0xA001;
            } else {
                CRC >>=1;
            }
        }
    }
    return CRC;
}

// получение хэша - индекса массива структур
int get_hash(char *key, int length) {
    char *byte_array;
    byte_array = get_bytes(key, length);
    int crc = get_crc(byte_array, length);
    int hash = crc % SIZE;
    free(byte_array);
    return hash;
}

// добавление элемента в хэш таблицу
void add(char *key, int length, int value, struct node **primary) {
    struct node *new_item = NULL;
    int hash = get_hash(key, length);
    new_item = (struct node *) malloc(sizeof(struct node));
    new_item->key = key;
    new_item->val = value;
    new_item->next = primary[hash];
    primary[hash] = new_item;
}

// поиск элемента по ключу
struct node * find(char *key, int length, struct node **primary) {
    struct node *item_ptr = NULL;
    int hash = get_hash(key, length);
    item_ptr = primary[hash];
    while (item_ptr) {
        if (!strcmp(key, item_ptr->key)){
            return item_ptr;
        }
        item_ptr = item_ptr->next;
    }
    return NULL;
}

// удаление элемента по ключу
int remove_element(char *key, int length, struct node **primary) {
    struct node *pcurrent = NULL;
    struct node *phead = NULL;
    struct node *pprev = NULL;
    int hash = get_hash(key, length);
    
    phead = primary[hash];
    if (!strcmp(key, phead->key)){
        phead = phead->next;
        printf("Key %s deleted", key);
        return 1;
    }
    pprev = phead;
    pcurrent = phead->next;
    while (pcurrent) {
        if (!strcmp(key, pcurrent->key)){
            pprev->next = pcurrent->next;
            return 1;
        }
        pprev = pcurrent;
        pcurrent = pcurrent->next;
    }
    printf("Key %s do not found", key);
    return 0;
}

