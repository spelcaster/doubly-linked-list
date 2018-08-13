#include <stdint.h>
#include <stdlib.h>

typedef struct tag_node {
    void *data;
    struct tag_node *prev, *next;
} node_t;

typedef struct tag_list {
    uint32_t count;
    node_t *front, *back;
} list_t;

int32_t push_back(list_t *, void *);
int32_t push_front(list_t *, void *);
void *drop(list_t *, node_t *);
void *pop_front(list_t *);
void *pop_back(list_t *);
list_t *init();
void destroy(list_t *);
