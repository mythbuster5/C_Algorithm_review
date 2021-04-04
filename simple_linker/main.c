#include <stdio.h>
#include <stdlib.h>
#include "linker.h"

#define RED           "\033[0;32;31m"
#define LINK_LENGTH (5)

link *init_link()
{
    link *head, *node, *end;
    head = (link*)malloc(sizeof(link));
    head->next = NULL;
    end = head;
    for (int i = 0; i < LINK_LENGTH; i++) {
        node = (link*)malloc(sizeof(link));
        end->num = i;
        node->next=NULL;
        if (i != LINK_LENGTH - 1) {
            end->next = node;
            end = end->next;
        }
        if (i == LINK_LENGTH - 1) {
            free(node);
        }
    }

    return head;
}

void delete_node(link *linker, int num)
{
    link *t = linker, *in;
    for (int i = 0; i<num; i++) {
        in = t;
        t = t->next;
    }
    if (t != NULL) {
        in->next = t->next;
        free(t);
    }
}

void insert_node(link *linker, int num)
{
    link *new_node = (link*)malloc(sizeof(link));
    new_node->num = 100;
    link *t = linker;
    for (int i = 0; i < num; i++) {
        t = t->next;
    }
    new_node->next = t->next;
    t->next = new_node;
}

void print_ll(link *linker)
{
    link *t = linker;
    while (t != NULL) {
        printf(RED"num is %d\n", t->num);
        t = t->next;
    }
}

link *revert_link(link *linker)
{
    link *p0 = NULL;
    link *p1 = linker;
    link *p2 = linker->next;

    while(p1 != NULL) {
        p1->next=p0;
        p0=p1;
        p1=p2;
        if(p2 != NULL){
            p2 = p2->next;
        }
    }
    printf("[debug]: num is %d\n", p0->num);
    return p0;
}

int main() {
    link *linker;
    linker = init_link();
    print_ll(linker);
    printf("********************\n");
    delete_node(linker, 2);
    print_ll(linker);
    printf("********************\n");
    insert_node(linker, 3);
    print_ll(linker);
    printf("********************\n");
    print_ll(revert_link(linker));
    printf("********************\n");
}
