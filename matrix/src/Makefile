FLAGS = -Wall -Wextra -Werror
FLAGS_CHECK=$(shell pkg-config --cflags --libs check)
FLAGS_GCOV=-fprofile-arcs -ftest-coverage

all: test gcov_report

clean:
	rm -rf ./report *.out *.a *.o *.info *.gcov *.gcda *.gcno s21_matrix

test: s21_matrix.a
	gcc $(CFLAGS) tests/test.c s21_matrix.a -o test.out $(FLAGS_CHECK)
	./test.out

s21_matrix.a: s21_matrix.o
	ar src s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a

gcov_report: clean s21_matrix.a
	gcc $(FLAGS_GCOV) tests/test.c s21_matrix.c -o report.out $(FLAGS_CHECK)
	./report.out
	gcov -f s21_matrix.c
	lcov -t "report" -o report.info -c -d .
	genhtml -o ./report report.info
	open ./report/src/index.html
	rm -f *.gcov *.gcda *.gcno *.info report.out

s21_matrix.o: s21_matrix.c
	gcc $(FLAGS)  -c -o s21_matrix.o s21_matrix.c

valgrind: clean s21_matrix
	valgrind --leak-check=full --track-origins=yes -s ./s21_matrix

s21_matrix: s21_matrix.a
	gcc $(FLAGS) s21_matrix.c -o s21_matrix

check:
	clang-format -style=Google -n *.c *.h tests/test.c
	clang-format -style=Google -i *.c *.h tests/test.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h tests/test.c

