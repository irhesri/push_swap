#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;
    int     size[2] = {0};

    b = NULL;
    a = my_check(ac, av, size);
    put_index(a, size);
    if (!my_issorted(a))
        list_sort(&a, &b, size);
    sort_3(&a, size);
    while (b)
        empty_b(&a, &b, size);
    
    my_putstr(NULL, 0);
}