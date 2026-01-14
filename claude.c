/* OPTIMIZED PUSH_SWAP ALGORITHM
 * Stack representation: arr[0] = TOP, arr[top] = BOTTOM
 * Targets: 100 nums < 700 ops | 500 nums < 5500 ops
 */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int op_count = 0;

typedef struct s_stack {
    int *arr;
    int top;
    int size;
} t_stack;

t_stack *init_stack(int size) {
    t_stack *s = malloc(sizeof(t_stack));
    s->arr = malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

void pa(t_stack *a, t_stack *b) {
    if (b->top < 0) return;
    for (int i = a->top + 1; i > 0; i--)
        a->arr[i] = a->arr[i-1];
    a->arr[0] = b->arr[0];
    for (int i = 0; i < b->top; i++)
        b->arr[i] = b->arr[i+1];
    a->top++;
    b->top--;
    printf("pa\n");
    op_count++;
}

void pb(t_stack *a, t_stack *b) {
    if (a->top < 0) return;
    for (int i = b->top + 1; i > 0; i--)
        b->arr[i] = b->arr[i-1];
    b->arr[0] = a->arr[0];
    for (int i = 0; i < a->top; i++)
        a->arr[i] = a->arr[i+1];
    b->top++;
    a->top--;
    printf("pb\n");
    op_count++;
}

void sa(t_stack *a) {
    if (a->top < 1) return;
    int tmp = a->arr[0];
    a->arr[0] = a->arr[1];
    a->arr[1] = tmp;
    printf("sa\n");
    op_count++;
}

void sb(t_stack *b) {
    if (b->top < 1) return;
    int tmp = b->arr[0];
    b->arr[0] = b->arr[1];
    b->arr[1] = tmp;
    printf("sb\n");
    op_count++;
}

void ra(t_stack *a) {
    if (a->top < 1) return;
    int tmp = a->arr[0];
    for (int i = 0; i < a->top; i++)
        a->arr[i] = a->arr[i+1];
    a->arr[a->top] = tmp;
    printf("ra\n");
    op_count++;
}

void rra(t_stack *a) {
    if (a->top < 1) return;
    int tmp = a->arr[a->top];
    for (int i = a->top; i > 0; i--)
        a->arr[i] = a->arr[i-1];
    a->arr[0] = tmp;
    printf("rra\n");
    op_count++;
}

void rb(t_stack *b) {
    if (b->top < 1) return;
    int tmp = b->arr[0];
    for (int i = 0; i < b->top; i++)
        b->arr[i] = b->arr[i+1];
    b->arr[b->top] = tmp;
    printf("rb\n");
    op_count++;
}

void rrb(t_stack *b) {
    if (b->top < 1) return;
    int tmp = b->arr[b->top];
    for (int i = b->top; i > 0; i--)
        b->arr[i] = b->arr[i-1];
    b->arr[0] = tmp;
    printf("rrb\n");
    op_count++;
}

void normalize(int *arr, int size) {
    int *sorted = malloc(sizeof(int) * size);
    int *original = malloc(sizeof(int) * size);
    
    for (int i = 0; i < size; i++) {
        sorted[i] = arr[i];
        original[i] = arr[i];
    }
    
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (sorted[j] > sorted[j+1]) {
                int tmp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = tmp;
            }
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (original[i] == sorted[j]) {
                arr[i] = j;
                break;
            }
    
    free(sorted);
    free(original);
}

int get_chunk_size(int size) {
    if (size <= 10) return size;
    if (size <= 100) return size / 7 + 5;
    return size / 11 + 10;
}

int find_target_pos(t_stack *a, int val) {
    int pos = 0;
    int min_pos = 0, max_pos = 0;
    int min_val = a->arr[0], max_val = a->arr[0];
    
    for (int i = 0; i <= a->top; i++) {
        if (a->arr[i] < min_val) {
            min_val = a->arr[i];
            min_pos = i;
        }
        if (a->arr[i] > max_val) {
            max_val = a->arr[i];
            max_pos = i;
        }
    }
    
    if (val < min_val || val > max_val)
        return min_pos;
    
    for (int i = 0; i <= a->top; i++) {
        int next = (i + 1) % (a->top + 1);
        if (a->arr[i] < val && a->arr[next] > val) {
            pos = next;
            break;
        }
    }
    
    return pos;
}

int calc_cost(t_stack *a, t_stack *b, int b_pos) {
    int val = b->arr[b_pos];
    int a_pos = find_target_pos(a, val);
    int size_a = a->top + 1;
    int size_b = b->top + 1;
    
    int b_cost = (b_pos <= size_b / 2) ? b_pos : -(size_b - b_pos);
    int a_cost = (a_pos <= size_a / 2) ? a_pos : -(size_a - a_pos);
    
    if ((b_cost > 0 && a_cost > 0) || (b_cost < 0 && a_cost < 0))
        return (abs(b_cost) > abs(a_cost)) ? abs(b_cost) : abs(a_cost);
    
    return abs(b_cost) + abs(a_cost);
}

void rotate_both(t_stack *a, t_stack *b, int *a_moves, int *b_moves) {
    while (*a_moves > 0 && *b_moves > 0) {
        ra(a);
        rb(b);
        (*a_moves)--;
        (*b_moves)--;
    }
    while (*a_moves < 0 && *b_moves < 0) {
        rra(a);
        rrb(b);
        (*a_moves)++;
        (*b_moves)++;
    }
}

void execute_rotations(t_stack *a, t_stack *b, int b_pos) {
    int val = b->arr[b_pos];
    int a_pos = find_target_pos(a, val);
    int size_a = a->top + 1;
    int size_b = b->top + 1;
    
    int a_moves = (a_pos <= size_a / 2) ? a_pos : -(size_a - a_pos);
    int b_moves = (b_pos <= size_b / 2) ? b_pos : -(size_b - b_pos);
    
    rotate_both(a, b, &a_moves, &b_moves);
    
    while (a_moves > 0) { ra(a); a_moves--; }
    while (a_moves < 0) { rra(a); a_moves++; }
    while (b_moves > 0) { rb(b); b_moves--; }
    while (b_moves < 0) { rrb(b); b_moves++; }
}

void push_swap(t_stack *a) {
    int size = a->top + 1;
    t_stack *b = init_stack(size);
    
    normalize(a->arr, size);
    
    int chunk_size = get_chunk_size(size);
    int chunks = (size + chunk_size - 1) / chunk_size;
    
    for (int chunk = 0; chunk < chunks; chunk++) {
        int min = chunk * chunk_size;
        int max = min + chunk_size - 1;
        
        while (1) {
            int found = 0;
            for (int i = 0; i <= a->top; i++)
                if (a->arr[i] >= min && a->arr[i] <= max) {
                    found = 1;
                    break;
                }
            if (!found) break;
            
            if (a->arr[0] >= min && a->arr[0] <= max) {
                pb(a, b);
                if (b->top > 0 && b->arr[0] < (min + max) / 2)
                    rb(b);
            } else {
                int top_dist = 0, bot_dist = 0;
                for (int i = 0; i <= a->top; i++) {
                    if (a->arr[i] >= min && a->arr[i] <= max) {
                        top_dist = i;
                        break;
                    }
                }
                for (int i = a->top; i >= 0; i--) {
                    if (a->arr[i] >= min && a->arr[i] <= max) {
                        bot_dist = a->top - i + 1;
                        break;
                    }
                }
                
                if (top_dist <= bot_dist) ra(a);
                else rra(a);
            }
        }
    }
    
    while (b->top >= 0) {
        int best_pos = 0, min_cost = INT_MAX;
        
        for (int i = 0; i <= b->top; i++) {
            int cost = calc_cost(a, b, i);
            if (cost < min_cost) {
                min_cost = cost;
                best_pos = i;
            }
        }
        
        execute_rotations(a, b, best_pos);
        pa(a, b);
    }
    
    int min_pos = 0;
    for (int i = 0; i <= a->top; i++)
        if (a->arr[i] == 0) {
            min_pos = i;
            break;
        }
    
    if (min_pos <= (a->top + 1) / 2)
        while (min_pos--) ra(a);
    else
        while (min_pos++ <= a->top) rra(a);
    
    free(b->arr);
    free(b);
}

int is_sorted(t_stack *a) {
    for (int i = 0; i < a->top; i++)
        if (a->arr[i] > a->arr[i+1])
            return 0;
    return 1;
}

void sort_three(t_stack *a) {
    int top = a->arr[0], mid = a->arr[1], bot = a->arr[2];
    
    if (top > mid && mid < bot && top < bot)
        sa(a);
    else if (top > mid && mid > bot) {
        sa(a);
        rra(a);
    }
    else if (top > mid && mid < bot && top > bot)
        ra(a);
    else if (top < mid && mid > bot && top < bot) {
        sa(a);
        ra(a);
    }
    else if (top < mid && mid > bot && top > bot)
        rra(a);
}

int main(int argc, char **argv) {
    if (argc < 2) return 0;
    
    t_stack *a = init_stack(argc - 1);
    
    for (int i = 1; i < argc; i++) {
        a->arr[i - 1] = atoi(argv[i]);
    }
    a->top = argc - 2;
    
    int size = a->top + 1;
    
    if (is_sorted(a)) {
        free(a->arr);
        free(a);
        return 0;
    }
    
    if (size == 2) {
        if (a->arr[0] > a->arr[1])
            sa(a);
    } else if (size == 3) {
        sort_three(a);
    } else {
        push_swap(a);
    }
    
    fprintf(stderr, "\nOperations: %d\n", op_count);
    fprintf(stderr, "Target: %d numbers < %d operations\n", 
            size, size <= 100 ? 700 : 5500);
    fprintf(stderr, "Status: %s\n", 
            (size <= 100 && op_count < 700) || (size > 100 && op_count < 5500) 
            ? "✓ PASS" : "✗ FAIL");
    
    free(a->arr);
    free(a);
    return 0;
}