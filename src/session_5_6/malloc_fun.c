#include "session_5_6/session5.h"

#include <limits.h>
#include <stdlib.h>

static bool int_array_resize(IntArray *array, size_t new_capacity)
{
  if (!array)
  {
    return false;
  }

  if (new_capacity < array->size)
  {
    return false;
  }

  int *new_data = realloc(array->data, new_capacity * sizeof(int));

  if (!new_data)
  {
    return false;
  }

  array->data     = new_data;
  array->capacity = new_capacity;

  return true;
}

bool int_array_init(IntArray *array, size_t initial_capacity)
{
  if (!array)
  {
    return false;
  }
  if (initial_capacity == 0)
  {
    initial_capacity = 1;
  }

  array->data = (int *)malloc(initial_capacity * sizeof(int));

  if (!array->data)
  {
    array->size     = 0;
    array->capacity = 0;

    return false;
  }

  array->size     = 0;
  array->capacity = initial_capacity;

  return true;
}

bool int_array_append(IntArray *array, int value)
{
  if (!array) {
    return false;
  }

  if (array->size == array->capacity) {
    size_t new_capacity = array->capacity < (SIZE_MAX / 2) ? array->capacity * 2 : SIZE_MAX;

    if (new_capacity == array->capacity)
    {
      return false;
    }

    if (!int_array_resize(array, new_capacity))
    {
      return false;
    }
  }

  array->data[array->size++] = value;

  return true;
}

long int_array_sum(const IntArray *array)
{
  if (!array || array->size == 0)
  {
    return 0;
  }

  long sum = 0;
  for (size_t i = 0; i < array->size; ++i)
  {
    sum += array->data[i];
  }

  return sum;
}

double int_array_average(const IntArray *array)
{
  if (!array || array->size == 0) {
    return 0.0;
  }

  return (double)int_array_sum(array) / (double)array->size;
}

void int_array_free(IntArray *array)
{
  if (!array) {
    return;
  }

  free(array->data);
  array->data     = NULL;
  array->size     = 0;
  array->capacity = 0;
}

static bool read_int(FILE *input, int *out_value) {
  if (!input || !out_value) {
    return false;
  }
  return fscanf(input, "%d", out_value) == 1;
}

void run_number_prompt(IntArray *array, FILE *input)
{
  if (!array || !input)
  {
    return;
  }

  printf("nbr. prompt demo (egative num to stop)\n");

  int value;
  while (read_int(input, &value))
  {
    if (value < 0)
    {
      break;
    }

    if (!int_array_append(array, value))
    {
      printf("  faild to append value\n");
      break;
    }
  }

  printf("  numbers:\n");
  for (size_t i = 0; i < array->size; ++i)
  {
    printf("    %d\n", array->data[i]);
  }

  long sum = int_array_sum(array);

  printf("  sum: %ld\n", sum);
  printf("  avg: %.2f\n", int_array_average(array));
  printf("\n");
}

