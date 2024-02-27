#ifndef S21_GREP
#define S21_GREP

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer 4096

typedef struct options {
  bool e, i, v, c, l, n;
} opt;

#endif
