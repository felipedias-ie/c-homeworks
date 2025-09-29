#ifndef SESSION5_H
#define SESSION5_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;} IntArray;

void swap_ints(int *a, int *b);

void pointer_shenanigans_demo(void);
void memory_layout_1_demo(void);
void memory_layout_2_demo(void);
void memory_layout_3_demo(void);
void casting_1_demo(void);
void casting_2_demo(void);

char *concat(const char *lhs, const char *rhs);

bool int_array_init(IntArray *array, size_t initial_capacity);
bool int_array_append(IntArray *array, int value);
long int_array_sum(const IntArray *array);
double int_array_average(const IntArray *array);
void int_array_free(IntArray *array);

void run_number_prompt(IntArray *array, FILE *input);

void run_privilege_escalation_demo(void);

void run_all(void);

#endif