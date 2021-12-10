#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_node
{
    int     value;
    struct  s_node  *next;
}               t_node;

void    sa(t_node *a)
{
    int     tmp;

    if (a == NULL || a->next == NULL)
        return ;
    tmp = a->value;
    a->value = a->next->value;
    a->next->value = tmp;
    write(1, "sa", 2);
}

void    swap(t_node **a, t_node **b)
{
    t_node *c;
    c = *a;
    *a = *b;
    *b = c;
}
int main()
{
    t_node *a = malloc(sizeof(t_node));
    t_node *b = malloc(sizeof(t_node));
    a->next = b;
    a->value = 1;
    a->next->value = 2;
    swap(&a,&b);
    printf("%d", a->value);
    free(a);
    free(b);
    return 0;
}