#ifndef S21_CAT
#define S21_CAT

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

struct option LongOptions[] = {{"number-nonblank", 0, NULL, 'b'},
                               {"number", 0, NULL, 'n'},
                               {"squeeze-blank", 0, NULL, 's'},
                               {NULL, 0, NULL, 0}};

typedef struct {
  bool numberNonBlank;
  bool markEndl;
  bool numberAll;
  bool squeeze;
  bool tab;
  bool printNonPrintable;
} Flags;

#endif
