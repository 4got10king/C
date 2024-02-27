#include "s21_grep.h"

void GrepReadFlags(int argc, char *argv[], opt *options) {
  int o;
  while ((o = getopt(argc, argv, "+eivcln")) != -1) {
    switch (o) {
      case 'e':
        options->e = true;
        break;
      case 'i':
        options->i = true;
        break;
      case 'v':
        options->v = true;
        break;
      case 'c':
        options->c = true;
        break;
      case 'l':
        options->l = true;
        break;
      case 'n':
        options->n = true;
        break;
      default:
        printf("Usage [-e, -i, -v, -c, -l, -n] template [file_name]");
        exit(1);
    }
  }
}

void Output(opt *options, char *filename, char *pattern, int files_count) {
  FILE *file = fopen(filename, "r");
  if (file) {
    char text[buffer] = {0};
    int lines = 1, status, success = 0, loses = 0;
    int print_later = 0;
    int cflags = REG_EXTENDED;
    if (options->i) cflags = REG_ICASE;
    regex_t reg;
    regmatch_t pmatch[1];
    regcomp(&reg, pattern, cflags);
    while (fgets(text, buffer - 1, file) != NULL) {
      status = regexec(&reg, text, 1, pmatch, 0);
      if (strchr(text, '\n') == NULL) strcat(text, "\n");

      if (!status) {
        success++;

        if (options->c || options->l) {
          print_later = 1;
          continue;
        }
        if (!options->v) {
          if (files_count > 1) printf("%s:", filename);
        }
        if (options->n && !options->v) printf("%d:", lines);
        if (!options->v) printf("%s", text);

      } else if (options->v) {
        loses++;
        if (options->c || options->l) {
          print_later = 1;
          continue;
        }
        if (files_count > 1) printf("%s:", filename);
        if (options->n) printf("%d:", lines);
        printf("%s", text);
      }
      lines++;
    }

    if (print_later) {
      if (!options->l && files_count > 1) printf("%s:", filename);
      if (options->c && !options->v) printf("%d\n", success);
      if (options->c && options->v && !options->l) printf("%d\n", loses);
      if (options->l) printf("%s\n", filename);
    }

    regfree(&reg);
    fclose(file);
  } else {
    fprintf(stderr, "Cannot open the file\n");
  }
}

int main(int argc, char *argv[]) {
  opt options = {0};
  GrepReadFlags(argc, argv, &options);
  char *pattern = argv[optind];
  optind++;
  int files_count = argc - optind;
  for (int i = optind; i < argc; i++) {
    char *filename = argv[i];
    Output(&options, filename, pattern, files_count);
  }
  return 0;
}
