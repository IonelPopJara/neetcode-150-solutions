// @leet start
// TODO: Do this again in python
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int val;
    struct node* next;
    struct node* prev;
} Node;

typedef struct {
    int capacity;
    int size;
    Node** hashmap; // Array of pointers to nodes
    Node* head;
    Node* tail;
} LRUCache;

#define HASHMAP_SIZE 10000

int hash(int key) {
    return key % HASHMAP_SIZE;
}

LRUCache* lRUCacheCreate(int capacity) {
    // Create a LRU cache with size capacity
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    cache->hashmap = (Node**)calloc(HASHMAP_SIZE, sizeof(Node*));

    return cache;
}

void moveToHead(LRUCache* obj, Node* node) {
    if (obj->head == node) {
        return;
    }

    // Detach node from current posistion
    if (node->prev) {
        node->prev->next = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    }

    if (node == obj->tail) obj->tail = node->prev;

    // Move node to the head
    node->next = obj->head;
    node->prev = NULL;

    // If we are inserting the first node
    if (obj->head) {
        obj->head->prev = node;
    }
    obj->head = node;

    // Update the tail if it was empty
    if (obj->tail == NULL) {
        obj->tail = node;
    }
}

void removeTail(LRUCache* obj) {
    if (obj->tail == NULL) return;

    Node* node = obj->tail;
    if (node->prev) {
        node->prev->next = NULL;
    } else {
        obj->head = NULL;
    }

    obj->tail = node->prev;
    obj->hashmap[hash(node->key)] = NULL;
    free(node);
    obj->size--;
}

void printLRU(LRUCache* obj, const char* text) {
    Node* current = obj->head;
    printf("%s LRU:\n", text);
    printf("    Capacity: %d\n", obj->capacity);
    printf("    Size: %d\n", obj->size);
    printf("    head->");
    while (current) {
        printf("(%d, %d)->", current->key, current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int lRUCacheGet(LRUCache* obj, int key) {
    int h = hash(key);
    Node *node = obj->hashmap[h];

    if (node == NULL || node->key != key) {
        return -1; // Key not found
    }

    moveToHead(obj, node);
    return node->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    int h = hash(key);
    Node* node = obj->hashmap[h];

    if (node != NULL && node->key == key) {
        // Key exists, update the value
        node->val = value;
        moveToHead(obj, node);
    } else {
        // Key doesn't exist, create a new node
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->val = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        // Insert at the head of the list
        newNode->next = obj->head;
        if (obj->head) {
            obj->head->prev = newNode;
        }

        obj->head = newNode;

        if (obj->tail == NULL) {
            obj->tail = newNode;
        }

        // Add to the hashmap
        obj->hashmap[h] = newNode;
        obj->size++;

        if (obj->size > obj->capacity) {
            removeTail(obj);
        }
    }
    /*printLRU(obj, "Put");*/
}

void lRUCacheFree(LRUCache* obj) {
    Node* current = obj->head;
    while (current) {
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }

    free (obj->hashmap);
    free (obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/
// @leet end
