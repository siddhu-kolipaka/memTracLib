#include <stdio.h>
#include <stdlib.h>

typedef struct mem_block {
    void *ptr;
    size_t size;
    int line;
    struct mem_block *next;
} mem_block;

mem_block *head = NULL;

void *my_malloc(size_t size, int line) {
    void *ptr = malloc(size);
    if (ptr) {
        mem_block *new_block = (mem_block *)malloc(sizeof(mem_block));
        new_block->ptr = ptr;
        new_block->size = size;
        new_block->line = line;
        new_block->next = head;
        head = new_block;
    }
    return ptr;
}

void my_free(void *ptr) {
    mem_block *current = head;
    mem_block *prev = NULL;
    while (current) {
        if (current->ptr == ptr) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
    free(ptr);
}

void report() {
    mem_block *current = head;
    while (current) {
        printf("Memory not freed: %zu bytes at line %d\n", current->size, current->line);
        current = current->next;
    }
    printf("\n");
}

