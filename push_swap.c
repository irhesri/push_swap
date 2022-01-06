#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;
    int lasta;
    int lastb;

    a = NULL;
    b = NULL;
    lastb = 0;
    if (!my_check(ac, av, &a) || !a || !(a -> next))
        return (0);
    while (!my_issorted(a))
        my_sort(&a, &b, &lasta, &lastb);
    while (b)
    {
        my_push(&a, my_pop(&b));
        my_putstr("pa", 0);
        while (!my_issorted(a))
            my_sort(&a, &b, &lasta, &lastb);
    }
    my_putstr(NULL, 0);
    return (0);
}