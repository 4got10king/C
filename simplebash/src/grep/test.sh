#!/bin/bash
echo Test 1-------------------------------------------------
# Test_1
./s21_grep -e f test.txt > s21_grep_test
grep -e f test.txt > grep
diff -s s21_grep_test grep
echo Test 2-------------------------------------------------
# Test_2
./s21_grep -i f test.txt > s21_grep_test
grep -i f test.txt > grep
diff -s s21_grep_test grep
echo Test 3-------------------------------------------------
# Test_3
./s21_grep -v f test.txt > s21_grep_test
grep -v f test.txt > grep
diff -s s21_grep_test grep
echo Test 4-------------------------------------------------
# Test_4
./s21_grep -c f test.txt > s21_grep_test
grep -c f test.txt > grep
diff -s s21_grep_test grep
echo Test 5-------------------------------------------------
# Test_5
./s21_grep -l f test.txt > s21_grep_test
grep -l f test.txt > grep
diff -s s21_grep_test grep
echo Test 6-------------------------------------------------
# Test_6
./s21_grep -n f test.txt > s21_grep_test
grep -n f test.txt > grep
diff -s s21_grep_test grep
echo Test 7-------------------------------------------------
# Test_7
./s21_grep f test.txt > s21_grep_test
grep f test.txt > grep
diff -s s21_grep_test grep
echo Test 8-------------------------------------------------
# Test_8
./s21_grep f test.txt test2.txt > s21_grep_test
grep f test.txt test2.txt > grep
diff -s s21_grep_test grep
echo Test 9-------------------------------------------------
# Test_9
./s21_grep -i f test.txt test2.txt > s21_grep_test
grep -i f test.txt test2.txt > grep
diff -s s21_grep_test grep
echo Test 10-------------------------------------------------
# Test_10
./s21_grep -v f test.txt test2.txt > s21_grep_test
grep -v f test.txt test2.txt > grep
diff -s s21_grep_test grep
echo Test 11-------------------------------------------------
# Test_11
./s21_grep -c f test.txt test2.txt > s21_grep_test
grep -c f test.txt test2.txt > grep
diff -s s21_grep_test grep
echo Test 12-------------------------------------------------
# Test_12
./s21_grep -l f test.txt test2.txt > s21_grep_test
grep -l f test.txt test2.txt > grep
diff -s s21_grep_test grep
echo Test 13-------------------------------------------------
# Test_13
./s21_grep -n f test.txt test2.txt > s21_grep_test
grep -n f test.txt test2.txt > grep
diff -s s21_grep_test grep
