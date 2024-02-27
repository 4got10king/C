CC = gcc 
Flags = -Wall -Werror -Wextra

s21_cat: s21_cat.c
	$(CC) $(Flags) s21_cat.c -o s21_cat

test: s21_cat
	bash test.sh

check:
	cp ../../materials/linters/.clang-format .clang-format
	leaks -atExit -- ./s21_cat -n s21_cat.h
	clang-format -i *.c
	clang-format -i *.h
	clang-format -n *.c
	clang-format -n *.h

clean:
	rm -rf .clang-format
	rm -rf s21_cat_test
	rm -rf s21_cat
	rm -rf cat
	