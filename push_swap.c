#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;
    int     size;

    b = NULL;
    size = 0;
    a = my_check(ac, av, &size);
    if (!a || size == 1 || my_issorted(a))
        exit(0);
    if (!my_issorted(a) && size > 3)
    {
        put_index(a, size);
        while (a)
            list_sort(&a, &b, size);
    }
    sort_3(&a, size);
    while (b)
        empty_b(&a, &b, &size);
    if (a && a -> next && a -> data > a -> next -> data)
    {
        my_swap(&a);
        my_putstr("sa", 2);
    }
    my_putstr(NULL, 0);
}