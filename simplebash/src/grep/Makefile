CC = gcc
CFLAGS = -Wall -Wextra -Werror

s21_grep: s21_grep.c
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep

test: s21_grep
	bash test.sh

check:
	cp ../../materials/linters/.clang-format .clang-format
	leaks -atExit -- ./s21_grep -e if s21_grep.c
	clang-format -n s21_grep.c
	clang-format -n s21_grep.h
	clang-format -i s21_grep.c
	clang-format -i s21_grep.h 

clean: 
	rm -rf .clang-format
	rm -rf s21_grep
	rm -rf s21_grep_test
	rm -rf grep