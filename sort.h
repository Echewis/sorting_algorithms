#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/* This is  the comparison direction macro for the bitonis sorting */
#define DOWN 1
#define UP 0

/**
 * enum bool - This will enumerate the boolean values
 * @false: this equals to 0
 * @true: this equals to 1
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct lisint_s - This is the double linked list node
 * @n: This the integer sorted in the node
 * @prev: this thepointer the previous item on the list
 * @next: This is the pointer to the next item on the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* This is the printing helper function */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* for the sorting algorithm function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_the_int(int *a, int *b);

#endif
