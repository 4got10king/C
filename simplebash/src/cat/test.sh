#!/bin/bash
echo Test 1-------------------------------------------------
# Test_1
./s21_cat test/test1.txt > s21_cat_test
cat test/test1.txt > cat
diff -s s21_cat_test cat
echo Test 2-------------------------------------------------
# Test_2
./s21_cat test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 3-------------------------------------------------
# Test_3
./s21_cat -b test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -b test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 4-------------------------------------------------
# Test_4
./s21_cat -e -v test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -e -v test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 5-------------------------------------------------
# Test_5
./s21_cat -n test/test1.txt test/test2.txt > s21_cat_test
cat -n test/test1.txt test/test2.txt > cat
diff -s s21_cat_test cat
echo Test 6-------------------------------------------------
# Test_6
./s21_cat -s test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -s test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 7-------------------------------------------------
# Test_7
./s21_cat -t -v test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -t -v test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 8-------------------------------------------------
# Test_8
./s21_cat -v test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -v test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 9-------------------------------------------------
# Test_9
./s21_cat -E test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -e test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 10-------------------------------------------------
# Test_10
./s21_cat --number test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -n test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 11-------------------------------------------------
# Test_11
./s21_cat --squeeze-blank test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -s test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 12-------------------------------------------------
# Test_12
./s21_cat -E test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -e test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 13-------------------------------------------------
# Test_13
./s21_cat -T test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -t test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 14-------------------------------------------------
# Test_14
./s21_cat --number-nonblank test/test1.txt test/test2.txt test/test3.txt > s21_cat_test
cat -b test/test1.txt test/test2.txt test/test3.txt > cat
diff -s s21_cat_test cat
echo Test 15-------------------------------------------------
# Test_15
./s21_cat -e -v test/test2.txt > s21_cat_test
cat -e -v test/test2.txt > cat
diff -s s21_cat_test cat

