#include "s21_cat.h"

Flags CatReadFlags(int argc, char *argv[]) {
  int currentFlag = getopt_long(argc, argv, "+bevEnstT", LongOptions, NULL);
  Flags flags = {false, false, false, false, false, false};
  for (; currentFlag != -1;
       currentFlag = getopt_long(argc, argv, "bevEnstT", LongOptions, NULL)) {
    switch (currentFlag) {
      case 'b':
        flags.numberNonBlank = true;
        break;
      case 'e':
        flags.markEndl = true;
        flags.printNonPrintable = true;
        break;
      case 'v':
        flags.printNonPrintable = true;
        break;
      case 'E':
        flags.markEndl = true;
        break;
      case 'n':
        flags.numberAll = true;
        break;
      case 's':
        flags.squeeze = true;
        break;
      case 't':
        flags.printNonPrintable = true;
        flags.tab = true;
        break;
      case 'T':
        flags.tab = true;
        break;
    }
  }
  return flags;
}

void CatNoArgs() {
  char infinity;
  while (true) {
    infinity = getchar();
    putchar(infinity);
  }
}

void output(char *argv[], Flags flags) {
  FILE *file = NULL;
  file = fopen(*argv, "r");
  if (file == NULL) {
    printf("Cat: %s: No such file or diectory", *argv);
  } else {
    char last = '\n';
    char c;
    int counter_line = 1;
    int emerty_line = 0;
    int counter_for_empty = 0;
    while ((c = fgetc(file)) != EOF) {
      if (flags.squeeze == 1 && c == '\n') {
        if (emerty_line >= 1) {
          continue;
        }
        emerty_line++;
      } else {
        emerty_line = -1;
      }
      if ((flags.numberNonBlank != 1 && flags.numberAll == 1 && last == '\n') ||
          (flags.numberNonBlank == 1 && c != '\n' && last == '\n')) {
        if (counter_for_empty == 1) {
        } else {
          fprintf(stdout, "%6d\t", counter_line++);
          counter_for_empty++;
        }
      }
      if (flags.printNonPrintable == 1 && c != '\t' && c != '\n') {
        if (c >= 32 && c <= 126) {
          fprintf(stdout, "%c", c);
          continue;
        } else {
          fprintf(stdout, "^%c", c + 64);
          continue;
        }
      }
      if (flags.markEndl == 1 && c == '\n') {
        fprintf(stdout, "$");
      }
      if (flags.tab == 1 && c == '\t') {
        fprintf(stdout, "^I");
        continue;
      }
      fprintf(stdout, "%c", c);
      last = c;
      counter_for_empty = 0;
    }
  }
  fclose(file);
}

int main(int argc, char *argv[]) {
  if (argc == 1) CatNoArgs();

  Flags Flags = CatReadFlags(argc, argv);

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      output(&argv[i], Flags);
    }
  }

  return 0;
}
