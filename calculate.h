//
// Created by simon on 2021/4/4.
//

#pragma once

#ifndef C_LINK_PRAC_CALCULATE_H
#define C_LINK_PRAC_CALCULATE_H

#endif //C_LINK_PRAC_CALCULATE_H

typedef struct
{
    int (*add)(int num1, int num2);
    int (*multi)(int num1, int num2);
    int (*sub)(int num1, int num2);
    int (*div)(int num1, int num2);
} calculate_t;

typedef struct
{
    int a;
    int b;
    calculate_t *fake;
} prepare_data_t;

typedef int (*aam_t)(calculate_t *c);
typedef int (*div_and_add)(calculate_t *c);

/**
 *
 * @param num1 the first number to add.
 * @param num2 the second number to add.
 * @return value.
 */
int add_(int num1, int num2);

/**
 *
 * @param num1 the first number to multi.
 * @param num2 the second number to multi.
 * @return value.
 */
int multi_(int num1, int num2);

/**
 *
 * @param num1 the first number to subtract.
 * @param num2 the second number to subtract.
 * @return value.
 */
int sub_(int num1, int num2);

/**
 *
 * @param num1 the first number to divide.
 * @param num2 the second number to divide.
 * @return value.
 */
int div_(int num1, int num2);