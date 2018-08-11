#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "doubly-linked-list.h"

typedef struct tag_creature {
    int8_t *name;
    uint16_t hit_points, experience;
} creature_t;

void dump_node(const node_t *node)
{
    creature_t *creature = (creature_t *) node->data;

    printf(
        "[%s's node]\n"
        "node addr\t\t0x%x\n"
        "prev addr\t\t0x%x\n"
        "next addr\t\t0x%x\n"
        "data addr\t\t0x%x\n"
        "\n",
        creature->name,
        node,
        node->prev,
        node->next,
        node->data
    );
}

void dump_list(const list_t *list)
{
    node_t *front = (node_t *) list->front;
    node_t *back = (node_t *) list->back;

    printf(
        "list addr\t\t0x%x\n"
        "count\t\t\t%u\n"
        "\n"
        "front node addr\t\t0x%x\n"
        "front data addr\t\t0x%x\n"
        "\n"
        "back node addr\t\t0x%x\n"
        "back data addr\t\t0x%x\n"
        "\n",
        list,
        list->count,
        front,
        front->data,
        back,
        back->data
    );

    node_t *j = list->front;
    while (0 != j) {
        dump_node(j);

        j = j->next;
    }
}

int32_t main(int32_t argc, int8_t **argv)
{
    list_t *list = init();
    if (0 == list) {
        return -1;
    }

    creature_t *orc = calloc(1, sizeof(creature_t));
    if (0 == orc) {
        return -2;
    }

    orc->name = "Orc";
    orc->hit_points = 70;
    orc->experience = 25;

    push_back(list, orc);

    creature_t *troll = calloc(1, sizeof(creature_t));
    if (0 == troll) {
        return -3;
    }

    troll->name = "Troll";
    troll->hit_points = 50;
    troll->experience = 20;

    push_front(list, troll);

    creature_t *goblin = calloc(1, sizeof(creature_t));
    if (0 == goblin) {
        return -4;
    }

    goblin->name = "Goblin";
    goblin->hit_points = 75;
    goblin->experience = 52;

    push_back(list, goblin);

    dump_list(list);

    free(orc);
    free(troll);
    free(goblin);

    destroy(list);

    return 0;
}
