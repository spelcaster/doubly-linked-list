#include "doubly-linked-list.h"

int32_t push_back(list_t *list, void *data)
{
    if (0 == list) {
        return -1;
    }

    node_t *node = calloc(1, sizeof(node_t));
    if (0 == node) {
        return -2;
    }

    node->data = data;
    list->count++;

    if (0 == list->back) {
        list->front = list->back = node;

        return 0;
    }

    node->prev = list->back;
    list->back->next = node;
    list->back = node;

    return 0;
}

int32_t push_front(list_t *list, void *data)
{
    if (0 == list) {
        return -1;
    }

    node_t *node = calloc(1, sizeof(node_t));
    if (0 == node) {
        return -2;
    }

    node->data = data;
    list->count++;

    if (0 == list->front) {
        list->front = list->back = node;

        return 0;
    }

    node->next = list->front;
    list->front->prev = node;
    list->front = node;

    return 0;
}

void *drop(list_t *list, node_t *node)
{
    if (0 == list->count || 0 == node) {
        return 0;
    }

    if (node == list->back) {
        list->back = node->prev;
        list->back->next = 0;
    } else if (node == list->front) {
        list->front = node->next;
        list->front->prev = 0;
    } else if (node == list->front && node == list->back) {
        list->front = list->back = 0;
    } else {
        node_t *prev_node = node->prev;
        node_t *next_node = node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    list->count--;
    void *data = node->data;
    free(node);

    return data;
}

void *pop_front(list_t *list)
{
    return drop(list, list->front);
}

void *pop_back(list_t *list)
{
    return drop(list, list->back);
}

list_t *init()
{
    return calloc(1, sizeof(list_t));
}

void destroy(list_t *list)
{
    node_t *j = list->back;
    while (0 != j) {
        if (j->next) {
            free(j->next);
        }

        j = j->prev;
    }

    free(list);
}
