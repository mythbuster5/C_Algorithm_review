#include <stdio.h>
#include "calculate.h"

int add_(int num1, int num2)
{
    return num1 + num2;
}

int multi_(int num1, int num2)
{
    return num1 * num2;
}

int div_(int num1, int num2)
{
    return (num2 == 0) ? 0 : num1 / num2;
}

int sub_(int num1, int num2)
{
    return num1 - num2;
}

calculate_t cal = {
        .add = add_,
        .multi = multi_,
        .div = div_,
        .sub = sub_,
};

prepare_data_t run_main_task = {
        .a = 2,
        .b = 3,
        .fake = &cal,
};

int add_and_multi_(calculate_t *c)
{
    return c->add(1,2)+c->multi(3,4);
}

int div_and_add_(calculate_t *c)
{
    return c->div(5,6)+c->add(7,8);
}

int f(prepare_data_t *p, int (*func)(calculate_t *))
{
    return (*func)(p->fake);
}
aam_t add_and_multi;
int main()
{
    aam_t add_and_multi = add_and_multi_;
    prepare_data_t *real_c = &run_main_task;
    printf("the value is %d\n", real_c->fake->add(run_main_task.a,run_main_task.b));
    printf("value is %d\n", f(real_c, add_and_multi));
}