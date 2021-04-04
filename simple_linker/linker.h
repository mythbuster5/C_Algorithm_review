//
// Created by simon on 2021/4/4.
//

#ifndef LINKER_LINKER_H
#define LINKER_LINKER_H

#endif //LINKER_LINKER_H


typedef struct Link
{
    int num;
    struct Link *next;
}link;

/**
 *
 * @return pointer to link
 */
link *init_link();

/**
 *
 * @param linker: Pointer of link.
 * @param num: Which node to be deleted.
 */
void delete_node(link *linker, int num);

/**
 *
 * @param linker: Pointer of link.
 * @param num: Which to add.
 */
void insert_node(link *linker, int num);

/**
 *
 * @param linker: Pointer of link.
 */
void print_ll(link *linker);

/**
 *
 * @param linker: The pointer of link.
 * @return : New link.
 */
link *revert_link(link *linker);
