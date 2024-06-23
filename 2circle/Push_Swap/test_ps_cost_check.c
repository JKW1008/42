#include <stdio.h>
#include "push_swap.h"

void test_find_pivot_rank() {
    t_stack stack;
    stack.head = NULL;
    stack.size = 0;

    // Add elements to the stack
    for (int i = 1; i <= 500; i++) {
        push(&stack, i);
    }

    int pivot = 209;
    int l_rank = find_pivot_rank(&stack, pivot);
    printf("l_rank = %d\n", l_rank);  // Expected output: 209

    pivot = 420;
    int m_rank = find_pivot_rank(&stack, pivot);
    printf("m_rank = %d\n", m_rank);  // Expected output: 420

    pivot = 0;
    int h_rank = find_pivot_rank(&stack, pivot);
    printf("h_rank = %d\n", h_rank);  // Expected output: 0
}

int main() {
    test_find_pivot_rank();
    return 0;
}