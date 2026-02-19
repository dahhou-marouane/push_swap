#ifndef TURK_DEMO_H
#define TURK_DEMO_H

typedef struct s_node
{
    int             idx;
    int             pos;
    int             cost_a;
    int             cost_b;
    struct s_node   *next;
}   t_node;

t_node  *turk_node_new(int idx);
void    turk_node_push_back(t_node **stack, t_node *new_node);
void    turk_node_free(t_node **stack);


void    turk_sort(t_node **a, t_node **b);

#endif
 