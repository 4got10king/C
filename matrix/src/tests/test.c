#include <check.h>

#include "../s21_matrix.h"

void fill_matrix(matrix_t *A, double start, double step) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = start;
      start += step;
    }
  }
}

START_TEST(s21_matrix_create_1) {
#line 13
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(5, 6, &A), 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_matrix_create_2) {
#line 18
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_matrix_create_3) {
#line 23
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(-10, 2, &A), 1);
}
END_TEST

START_TEST(s21_matrix_create_4) {
#line 27
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 0, &A), 1);
}
END_TEST

START_TEST(s21_matrix_create_5) {
#line 31
  ck_assert_int_eq(s21_create_matrix(3, 2, NULL), 1);
}
END_TEST

START_TEST(s21_eq_matrix_1) {
#line 34
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  fill_matrix(&A, 0.25, 0.85);
  fill_matrix(&B, 0.25, 0.85);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
#line 45
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 7, &A);
  s21_create_matrix(4, 7, &B);
  fill_matrix(&A, -12.00000223, 2.011);
  fill_matrix(&B, -12.00000223, 2.011);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
#line 56
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  fill_matrix(&A, 1, 1);
  fill_matrix(&B, 1, 1);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
#line 67
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  fill_matrix(&A, 1, 1);
  fill_matrix(&B, 1, 1);
  B.matrix[3][2] = 100;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
#line 79
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(4, 5, &B);
  fill_matrix(&A, 1, 1.1);
  fill_matrix(&B, 1, 1.1);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
#line 90
  ck_assert_int_eq(s21_eq_matrix(NULL, NULL), 0);
}
END_TEST

START_TEST(s21_sum_matrix_1) {
#line 93
  matrix_t A;
  matrix_t B;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(2, 3, &expected);
  fill_matrix(&A, 1, 1);
  fill_matrix(&B, 1, 1);
  fill_matrix(&expected, 2, 2);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
#line 111
  matrix_t A;
  matrix_t B;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(9, 9, &A);
  s21_create_matrix(9, 9, &B);
  s21_create_matrix(9, 9, &expected);
  fill_matrix(&A, -1.22, 1.22);
  fill_matrix(&B, -1.22, 1.22);
  fill_matrix(&expected, -2.44, 2.44);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
#line 129
  matrix_t A;
  matrix_t B;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(9, 9, &A);
  s21_create_matrix(9, 9, &B);
  s21_create_matrix(9, 9, &expected);
  fill_matrix(&A, -1.22, 1.22);
  fill_matrix(&B, -1.22, 1.22);
  fill_matrix(&expected, -2.44, 2.44);
  expected.matrix[2][6] = 0;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
#line 148
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 5, &B);
  fill_matrix(&A, 5.33, 0.212);
  fill_matrix(&B, 5.33, 0.212);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
#line 160
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  fill_matrix(&A, 5.33, 0.212);
  fill_matrix(&B, 5.33, 0.212);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
#line 172
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  fill_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, &result), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_sub_matrix_1) {
#line 180
  matrix_t A;
  matrix_t B;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);
  fill_matrix(&A, 2, 1);
  fill_matrix(&B, 1, 1);
  fill_matrix(&expected, 1, 0);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
#line 198
  matrix_t A;
  matrix_t B;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(5, 4, &B);
  s21_create_matrix(5, 4, &expected);
  fill_matrix(&A, -4, -2);
  fill_matrix(&B, -3, -1);
  fill_matrix(&expected, -1, -1);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
#line 216
  matrix_t A;
  matrix_t B;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(5, 4, &B);
  s21_create_matrix(5, 4, &expected);
  fill_matrix(&A, -4, -2);
  fill_matrix(&B, -3, -1);
  fill_matrix(&expected, -1, -1);
  expected.matrix[2][0] = 4;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
#line 235
  matrix_t A;
  matrix_t B;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 4, &expected);
  fill_matrix(&A, -4, -2);
  fill_matrix(&B, -3, -1);
  fill_matrix(&expected, -1, -1);
  expected.matrix[2][0] = 4;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
#line 251
  matrix_t B;
  matrix_t result;
  s21_create_matrix(3, 3, &B);
  fill_matrix(&B, 1, 1);
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &result), 1);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
#line 259
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, NULL), 1);
}
END_TEST

START_TEST(s21_mult_number_1) {
#line 262
  matrix_t A;
  matrix_t result;
  matrix_t expected;
  double val = 2;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &expected);
  fill_matrix(&A, 1, 1);
  fill_matrix(&expected, 2, 2);
  ck_assert_int_eq(s21_mult_number(&A, val, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_2) {
#line 277
  matrix_t A;
  matrix_t result;
  matrix_t expected;
  double val = -0.1;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);
  fill_matrix(&A, 2, 0.5);
  fill_matrix(&expected, -0.2, -0.05);
  ck_assert_int_eq(s21_mult_number(&A, val, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_3) {
#line 292
  matrix_t A;
  matrix_t result;
  matrix_t expected;
  double val = -0.1;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);
  fill_matrix(&A, 2, 0.5);
  fill_matrix(&expected, -0.2, -0.05);
  ck_assert_int_eq(s21_mult_number(&A, val, &result), 0);
  result.matrix[2][2] = 1000;
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_4) {
#line 308
  matrix_t A;
  double val = 2;
  s21_create_matrix(2, 3, &A);
  fill_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_mult_number(&A, val, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_5) {
#line 316
  ck_assert_int_eq(s21_mult_number(NULL, 2.3, NULL), 1);
}
END_TEST

START_TEST(s21_mult_matrix_1) {
#line 319
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);
  fill_matrix(&A, 1, 1);
  fill_matrix(&B, -1, 2);
  expected.matrix[0][0] = 42;
  expected.matrix[0][1] = 54;
  expected.matrix[0][2] = 66;
  expected.matrix[1][0] = 87;
  expected.matrix[1][1] = 117;
  expected.matrix[1][2] = 147;
  expected.matrix[2][0] = 132;
  expected.matrix[2][1] = 180;
  expected.matrix[2][2] = 228;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
#line 345
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &expected);
  fill_matrix(&A, -7.21, -3.5);
  fill_matrix(&B, 9.9, -2.45);
  expected.matrix[0][0] = -124.929;
  expected.matrix[0][1] = -81.025;
  expected.matrix[1][0] = -229.229;
  expected.matrix[1][1] = -151.025;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
#line 366
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(4, 3, &B);
  fill_matrix(&A, 1, 1);
  fill_matrix(&B, -1, 2);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
#line 378
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(4, 3, &B);
  fill_matrix(&A, 1, 1);
  fill_matrix(&B, -1, 2);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
#line 389
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, NULL), 1);
}
END_TEST

START_TEST(s21_transpose_1) {
#line 392
  matrix_t A;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);
  fill_matrix(&A, 1, 2);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = 7;
  expected.matrix[0][2] = 13;
  expected.matrix[1][0] = 3;
  expected.matrix[1][1] = 9;
  expected.matrix[1][2] = 15;
  expected.matrix[2][0] = 5;
  expected.matrix[2][1] = 11;
  expected.matrix[2][2] = 17;
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_2) {
#line 414
  matrix_t A;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(2, 4, &A);
  s21_create_matrix(4, 2, &expected);
  fill_matrix(&A, -12, 4);
  expected.matrix[0][0] = -12;
  expected.matrix[0][1] = 4;
  expected.matrix[1][0] = -8;
  expected.matrix[1][1] = 8;
  expected.matrix[2][0] = -4;
  expected.matrix[2][1] = 12;
  expected.matrix[3][0] = 0;
  expected.matrix[3][1] = 16;
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_3) {
#line 435
  matrix_t A;
  s21_create_matrix(2, 4, &A);
  fill_matrix(&A, -12, 4);
  ck_assert_int_eq(s21_transpose(&A, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_4) {
#line 442
  matrix_t result;
  ck_assert_int_eq(s21_transpose(NULL, &result), 1);
}
END_TEST

START_TEST(s21_calc_complements_1) {
#line 446
  matrix_t A;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &expected);
  fill_matrix(&A, 1, 2);
  expected.matrix[0][0] = 7;
  expected.matrix[0][1] = -5;
  expected.matrix[1][0] = -3;
  expected.matrix[1][1] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_2) {
#line 463
  matrix_t A;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &expected);
  fill_matrix(&A, -8.33, 0);
  expected.matrix[0][0] = -8.33;
  ck_assert_int_eq(s21_calc_complements(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_3) {
#line 477
  matrix_t A;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);
  fill_matrix(&A, -3.5, 3.1);
  A.matrix[0][0] = -1;
  expected.matrix[0][0] = -28.83;
  expected.matrix[0][1] = 57.66;
  expected.matrix[0][2] = -28.83;
  expected.matrix[1][0] = 57.66;
  expected.matrix[1][1] = -62.07;
  expected.matrix[1][2] = 12.16;
  expected.matrix[2][0] = -28.83;
  expected.matrix[2][1] = 27.66;
  expected.matrix[2][2] = -6.58;
  ck_assert_int_eq(s21_calc_complements(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_4) {
#line 500
  matrix_t A;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &expected);
  fill_matrix(&A, 15.4, -2.7);
  A.matrix[0][0] = A.matrix[3][3] = 2;
  expected.matrix[0][0] = -790.236;
  expected.matrix[0][1] = 1580.472;
  expected.matrix[0][2] = -790.236;
  expected.matrix[0][3] = 0;
  expected.matrix[1][0] = 1580.472;
  expected.matrix[1][1] = 1442.224;
  expected.matrix[1][2] = -2432.962;
  expected.matrix[1][3] = 390.744;
  expected.matrix[2][0] = -790.236;
  expected.matrix[2][1] = 508.472;
  expected.matrix[2][2] = 82.774;
  expected.matrix[2][3] = -781.488;
  expected.matrix[3][0] = 0;
  expected.matrix[3][1] = 390.744;
  expected.matrix[3][2] = -781.488;
  expected.matrix[3][3] = 390.744;
  ck_assert_int_eq(s21_calc_complements(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_5) {
#line 530
  matrix_t A;
  matrix_t result;
  s21_create_matrix(3, 2, &A);
  fill_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_calc_complements(&A, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_6) {
#line 538
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  fill_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_7) {
#line 545
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(NULL, &result), 1);
}
END_TEST

START_TEST(s21_determinant_1) {
#line 549
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  fill_matrix(&A, -7.5, -2.3);
  ck_assert_int_eq(s21_determinant(&A, &result), 0);
  ck_assert_double_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
#line 558
  matrix_t A;
  double result;
  s21_create_matrix(5, 3, &A);
  fill_matrix(&A, -7.5, -2.3);
  ck_assert_int_eq(s21_determinant(&A, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
#line 566
  double result;
  ck_assert_int_eq(s21_determinant(NULL, &result), 1);
}
END_TEST

START_TEST(s21_inverse_matrix_1) {
#line 570
  matrix_t A;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &expected);
  fill_matrix(&A, -5, 1);
  A.matrix[0][0] = 3;
  A.matrix[1][1] = -3;
  expected.matrix[0][0] = 0.125;
  expected.matrix[0][1] = 0;
  expected.matrix[0][2] = -0.375;
  expected.matrix[0][3] = 0.25;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = -0.333333333;
  expected.matrix[1][2] = 0.666666667;
  expected.matrix[1][3] = -0.333333333;
  expected.matrix[2][0] = -0.375;
  expected.matrix[2][1] = 0.666666667;
  expected.matrix[2][2] = -2.708333333;
  expected.matrix[2][3] = 1.416666667;
  expected.matrix[3][0] = 0.25;
  expected.matrix[3][1] = -0.333333333;
  expected.matrix[3][2] = 2.166666667;
  expected.matrix[3][3] = -1.083333333;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
#line 601
  matrix_t A;
  matrix_t expected;
  matrix_t result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &expected);
  A.matrix[0][0] = 5;
  expected.matrix[0][0] = 0.2;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
#line 615
  matrix_t A;
  matrix_t result;
  s21_create_matrix(4, 5, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
#line 622
  matrix_t A;
  matrix_t result;
  s21_create_matrix(4, 4, &A);
  fill_matrix(&A, -5, 1);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
#line 630
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_matrix_create_1);
  tcase_add_test(tc1_1, s21_matrix_create_2);
  tcase_add_test(tc1_1, s21_matrix_create_3);
  tcase_add_test(tc1_1, s21_matrix_create_4);
  tcase_add_test(tc1_1, s21_matrix_create_5);
  tcase_add_test(tc1_1, s21_eq_matrix_1);
  tcase_add_test(tc1_1, s21_eq_matrix_2);
  tcase_add_test(tc1_1, s21_eq_matrix_3);
  tcase_add_test(tc1_1, s21_eq_matrix_4);
  tcase_add_test(tc1_1, s21_eq_matrix_5);
  tcase_add_test(tc1_1, s21_eq_matrix_6);
  tcase_add_test(tc1_1, s21_sum_matrix_1);
  tcase_add_test(tc1_1, s21_sum_matrix_2);
  tcase_add_test(tc1_1, s21_sum_matrix_3);
  tcase_add_test(tc1_1, s21_sum_matrix_4);
  tcase_add_test(tc1_1, s21_sum_matrix_5);
  tcase_add_test(tc1_1, s21_sum_matrix_6);
  tcase_add_test(tc1_1, s21_sub_matrix_1);
  tcase_add_test(tc1_1, s21_sub_matrix_2);
  tcase_add_test(tc1_1, s21_sub_matrix_3);
  tcase_add_test(tc1_1, s21_sub_matrix_4);
  tcase_add_test(tc1_1, s21_sub_matrix_5);
  tcase_add_test(tc1_1, s21_sub_matrix_6);
  tcase_add_test(tc1_1, s21_mult_number_1);
  tcase_add_test(tc1_1, s21_mult_number_2);
  tcase_add_test(tc1_1, s21_mult_number_3);
  tcase_add_test(tc1_1, s21_mult_number_4);
  tcase_add_test(tc1_1, s21_mult_number_5);
  tcase_add_test(tc1_1, s21_mult_matrix_1);
  tcase_add_test(tc1_1, s21_mult_matrix_2);
  tcase_add_test(tc1_1, s21_mult_matrix_3);
  tcase_add_test(tc1_1, s21_mult_matrix_4);
  tcase_add_test(tc1_1, s21_mult_matrix_5);
  tcase_add_test(tc1_1, s21_transpose_1);
  tcase_add_test(tc1_1, s21_transpose_2);
  tcase_add_test(tc1_1, s21_transpose_3);
  tcase_add_test(tc1_1, s21_transpose_4);
  tcase_add_test(tc1_1, s21_calc_complements_1);
  tcase_add_test(tc1_1, s21_calc_complements_2);
  tcase_add_test(tc1_1, s21_calc_complements_3);
  tcase_add_test(tc1_1, s21_calc_complements_4);
  tcase_add_test(tc1_1, s21_calc_complements_5);
  tcase_add_test(tc1_1, s21_calc_complements_6);
  tcase_add_test(tc1_1, s21_calc_complements_7);
  tcase_add_test(tc1_1, s21_determinant_1);
  tcase_add_test(tc1_1, s21_determinant_2);
  tcase_add_test(tc1_1, s21_determinant_3);
  tcase_add_test(tc1_1, s21_inverse_matrix_1);
  tcase_add_test(tc1_1, s21_inverse_matrix_2);
  tcase_add_test(tc1_1, s21_inverse_matrix_3);
  tcase_add_test(tc1_1, s21_inverse_matrix_5);
  tcase_add_test(tc1_1, s21_inverse_matrix_6);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
